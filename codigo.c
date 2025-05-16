#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x27
#define LCD_COLUMNS 16
#define LCD_LINES   2
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

#define DHTTYPE    DHT11
#define DHTPIN 2
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

int ledVermelho = 13;
int ledAmarelo = 12;
int ledVerde = 11;
int buzzer = 7;
int sensorLDR = A0;

void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(sensorLDR, INPUT);

  Serial.begin(9600);
  dht.begin();
  Serial.println("Usando o Sensor DHT");

  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor);
  delayMS = sensor.min_delay / 1000;

  lcd.init();
  lcd.backlight();
}

void loop()
{
  int somaLuminosidade = 0;
  for (int i = 0; i < 5; i++) {
    somaLuminosidade += analogRead(sensorLDR);
    delay(100);
  }
  int mediaLuminosidade = somaLuminosidade / 5;
  Serial.print("Media Luminosidade: ");
  Serial.println(mediaLuminosidade);

  if (mediaLuminosidade < 300) {
    tocarPiezzo();
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
  }
  else if (mediaLuminosidade >= 300 && mediaLuminosidade <= 600) {
    noTone(buzzer);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, LOW);
  }
  else {
    noTone(buzzer);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledVermelho, LOW);
  }

  float somaTemperatura = 0;
  float somaUmidade = 0;
  for (int i = 0; i < 5; i++) {
    sensors_event_t tempEvent, humEvent;
    dht.temperature().getEvent(&tempEvent);
    dht.humidity().getEvent(&humEvent);
    if (!isnan(tempEvent.temperature)) {
      somaTemperatura += tempEvent.temperature;
    }
    if (!isnan(humEvent.relative_humidity)) {
      somaUmidade += humEvent.relative_humidity;
    }
    delay(100);
  }
  float mediaTemperatura = somaTemperatura / 5;
  float mediaUmidade = somaUmidade / 5;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(mediaTemperatura);
  lcd.print("*C");
  lcd.setCursor(0, 1);
  if (mediaTemperatura < 10) {
    lcd.print("Temp: Baixa!");
  } else if (mediaTemperatura > 15) {
    lcd.print("Temp: Alta!");
  } else {
    lcd.print("Temperatura: OK!");
  }
  delay(1000); 

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Umidade: ");
  lcd.print(mediaUmidade);
  lcd.print("%");
  lcd.setCursor(0, 1);
  if (mediaUmidade < 50) {
    lcd.print("Umidade: Baixa!");
  } else if (mediaUmidade > 70) {
    lcd.print("Umidade: Alta!");
  } else {
    lcd.print("Umidade: OK!");
  }
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ambiente esta");
  lcd.setCursor(0, 1);
  if (mediaLuminosidade < 300) {
    lcd.print("muito claro.   ");
  }
  else if (mediaLuminosidade >= 300 && mediaLuminosidade <= 600) {
    lcd.print("a meia luz.    ");
  }
  else {
    lcd.print("OK!            ");
  }
  delay(3000);
}

void tocarPiezzo() {
  tone(buzzer, 500, 1000);
  delay(3000);
  noTone(buzzer);
  delay(1000);
}
