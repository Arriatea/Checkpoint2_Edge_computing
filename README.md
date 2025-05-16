
<h1 align="center">🍷 Sistema de Monitoramento Ambiental para Vinhos</h1>
<h3 align="center">Projeto desenvolvido para a <strong>Vinheria Agnello</strong></h3>

<p align="center">
  <img src="https://img.shields.io/badge/Arduino-UNO-00979D?style=for-the-badge&logo=arduino&logoColor=white">
  <img src="https://img.shields.io/badge/Sensor-DHT22-yellow?style=for-the-badge">
  <img src="https://img.shields.io/badge/Sensor-LDR-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/Display-LCD_16x2-blue?style=for-the-badge">
</p>

---

## 📌 <span style="color:#A52A2A">Objetivo do Projeto</span>

Garantir que os vinhos da **vinícola** estejam armazenados nas **condições ideais de temperatura, umidade e luminosidade.**
---


## ⚙️ <span>Tecnologia e Componentes</span>

| Componente         | Função                              |
|--------------------|--------------------------------------|
| 🟦 **Arduino UNO**      | Unidade de controle principal        |
| 🌡 **Sensor DHT22**     | Medição de temperatura e umidade     |
| 💡 **Sensor LDR**       | Leitura da intensidade luminosa      |
| 🔊 **Buzzer**            | Alerta sonoro em caso de luz excessiva |
| 🔴🟡🟢 **LEDs (RGB)**     | Indicação visual do nível de luz     |
| 🖥 **LCD 16x2 (I2C)**   | Exibição dos dados das leituras     |

---

##  <span>Como Funciona</span>

### 🌡️ Temperatura

- **Faixa ideal:** entre <span style="color:green">10 °C</span> e <span style="color:green">15 °C</span>
- Alerta visual no LCD:
  - 🔵 *Temp: OK!* 
  - 🥶 *Temp: Baixa!* 
  - 🔥 *Temp: Alta!*

### 💧 Umidade

- **Faixa ideal:** entre <span style="color:green">50%</span> e <span style="color:green">70%</span>
- Alerta no LCD:
  - 🟦 *Umidade: OK!*  
  - 🟫 *Umidade: Baixa!*  
  - 💦 *Umidade: Alta!*

### 💡 Luminosidade

- **Baixa (ideal):** LED 🟢 Verde  
- **Moderada:** LED 🟡 Amarelo  
- **Alta:** LED 🔴 Vermelho + 🔊 Buzzer  
- Mensagem no LCD:
  - *Ambiente escuro*
  - *Meia luz*
  - *Muito claro*

---

## 📟 <span style="color:#2F4F4F">Interface do LCD</span>

O display LCD 16x2 exibe:

1. Temperatura atual + status
2. Umidade atual + status
3. Nível de luminosidade ambiente

⏱️ **Atualização a cada 5 segundos.**
 os dados apresentados são a média de 5 leituras.
---

## 🚨 <span style="color:#FF6347">Alertas</span>

| Situação              | LED      | Buzzer |
|-----------------------|----------|--------|
| Ambiente ideal        | 🟢 Verde  | ❌ Não |
| Luminosidade média    | 🟡 Amarelo| ❌ Não |
| Ambiente muito claro  | 🔴 Vermelho | ✅ Sim |


## Simulação no Wokwi
<p align="center">
 <a href="https://wokwi.com/projects/430521721277284353" target="_blank">
 <img src="https://img.shields.io/badge/Abrir%20no%20Wokwi-00C853?style=for-the-badge&logo=arduino&logoColor=white">
  </a>
  </p>

## Código do projeto


## 👥 Integrantes do Grupo
| [<img loading="lazy" src="./images/Vitor.png" width=115><br><sub>Vitor Alcantara</sub>](https://github.com/VitorAlcantara-tech) | [<img loading="lazy" src="./images/Thiago.png" width=115><br><sub>Thiago Lima</sub>](https://github.com/thiagolima-tech) |  [<img loading="lazy" src="./images/Matheus.png" width=115><br><sub>Matheus Vasques</sub>](https://github.com/maatvasques) | [<img loading="lazy" src="./images/Marco.png" width=115><br><sub>Marco Aurélio</sub>](https://github.com/Arriatea) | [<img loading="lazy" src="./images/Bernardo.png" width=115><br><sub>Bernardo Hanashiro</sub>](https://github.com/BernardoYuji) | 
| :---: | :---: | :---: | :---: | :---: |
