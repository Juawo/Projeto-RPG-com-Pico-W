# Mini-RPG Interativo em Display OLED

Este projeto é um Mini-RPG interativo desenvolvido para a Raspberry Pi Pico (ou BitDogLab com Pico W). O jogo apresenta 4 escolhas sucessivas, onde em cada etapa duas opções são exibidas no display OLED. O jogador utiliza os botões A e B para selecionar a opção desejada. Ao final das 4 escolhas, o Serial Monitor exibe a "história" formada pelas escolhas realizadas. Após 5 segundos, o jogo reinicia automaticamente.

## 📌 Funcionalidades

- **Exibição de Opções:** O display OLED (128x64 pixels) mostra duas opções de escolha.
- **Interrupções de Botões:** Os botões A e B (conectados aos pinos 05 e 06, respectivamente) usam interrupção de borda para registrar a escolha do jogador.
- **História Gerada:** Ao final das 4 escolhas, o Serial Monitor mostra a história formada pela concatenação das escolhas.
- **Reinicialização Automática:** Após 5 segundos, o jogo é reiniciado para uma nova rodada.

## 🛠 Especificação do Hardware

- **Placa:** Raspberry Pi Pico / Pico W
- **Display OLED:** SSD1306 (128x64 pixels), comunicação via I2C  
  - **I2C SDA:** GPIO 14  
  - **I2C SCL:** GPIO 15
- **Botões:**
  - **Botão A:** GPIO 05  
  - **Botão B:** GPIO 06
- **Serial Monitor:** Usado para debug e exibição da história final.

## 📂 Estrutura do Projeto

O código está organizado de forma modular:
- **projeto-rpg.c:** Função `main()` e loop principal.
- **game_logic.c / game_logic.h:** Lógica do jogo, definição das escolhas e histórico.
- **display.c / display.h:** Funções para inicializar e desenhar no display OLED.
- **input.c / input.h:** Configuração dos botões e tratamento das interrupções.
- **globals.h:** (Opcional) Variáveis globais compartilhadas, como a flag `escolha_pendente`.

## 🚀 Como Executar

### 📌 Pré-requisitos

- Raspberry Pi Pico (ou placa compatível)
- Ambiente de desenvolvimento configurado com o Pico SDK (e CMake)
- Conexão com um Serial Monitor (via USB)

### 🏗 Instruções de Compilação

1. **Clone o Repositório**
   ```bash
   git clone https://github.com/seu-usuario/seu-repo-rpg.git
   cd seu-repo-rpg
   ```

2. **Crie a Pasta de Build e Compile**
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Upload para a Placa**
   - Conecte a Raspberry Pi Pico no modo UF2 e copie o arquivo `projeto-rpg.uf2` gerado para a placa.

### 🎮 Executando o Jogo

- **Início:** Assim que o firmware for carregado, o display OLED exibirá duas opções.
- **Escolha:** Utilize os botões A (GPIO 05) e B (GPIO 06) para selecionar sua opção.
- **Histórico:** Após 4 escolhas, a história completa será exibida no Serial Monitor.
- **Reinício:** Após 5 segundos, o jogo reinicia automaticamente para uma nova rodada.

## 🔄 Fluxo do Programa

O fluxo principal do programa é o seguinte:

1. **Inicialização:** Configuração dos pinos, do display, dos botões e das variáveis do jogo.
2. **Loop Principal:** Verifica continuamente se houve uma interrupção (flag `escolha_pendente` diferente de -1) e, se sim, processa a escolha.
3. **Interrupção:** Quando um botão é pressionado, a ISR atualiza a variável `escolha_pendente` para 0 (Botão A) ou 1 (Botão B).
4. **Processamento:** O loop principal lê essa variável, chama a função de processamento de escolha, exibe a nova opção ou o resultado final.
5. **Exibição de Resultado:** Ao final das 4 escolhas, a história resultante é exibida no Serial Monitor.
6. **Reinicialização:** O jogo aguarda 5 segundos e recomeça.

## 📚 Referências

1. [Banco de informações de Hardware da BitDogLab](https://docs.google.com/document/d/13-68OqiU7ISE8U2KPRUXT2ISeBl3WPhXjGDFH52eWlU/edit?tab=t.0)
2. [Pico SDK Examples](https://github.com/BitDogLab/BitDogLab-C/tree/main/display_oled)
3. Bibliotecas e exemplos para o display SSD1306.

## 📎 Anexos

- **Código Completo:** O código fonte completo está disponível neste repositório.
- **Vídeo de Demonstração:** [Link para o vídeo (YouTube)](https://youtu.be/IO--FurQlPk)
