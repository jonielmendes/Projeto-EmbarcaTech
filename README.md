# 🚀 Desafio EmbarcaTech 🚀

Este projeto foi desenvolvido como parte do Desafio EmbarcaTech, utilizando a placa BitDogLab e programado em C/C++. O objetivo é demonstrar o controle de LEDs e botões, além de utilizar interrupções para interação com o usuário.

## 📌 Descrição do Projeto

O projeto utiliza a placa Raspberry Pi Pico para controlar LEDs e botões. O sistema exibe números em uma matriz de LEDs e permite a interação do usuário através de botões. O código foi escrito em C/C++ e utiliza bibliotecas específicas para manipulação de LEDs, botões e interrupções.

## 🎥 Vídeo Demonstrativo

[Link para o vídeo demonstrativo](https://www.youtube.com/)

## 📂 Estrutura do Projeto

- `src/main.c`: Código principal do projeto.
- `src/lib/led.c`: Biblioteca para manipulação de LEDs.
- `src/lib/button.c`: Biblioteca para manipulação de botões.
- `src/lib/interrupt.c`: Biblioteca para manipulação de interrupções.
- `src/lib/matrix.c`: Biblioteca para manipulação da matriz de LEDs.
- `include/`: Diretório contendo os arquivos de cabeçalho das bibliotecas.

## 🖥 Publicação no GitHub

O código completo do projeto está disponível no GitHub: [Link para o repositório](https://github.com/SEU_USUARIO/NOME_DO_REPOSITORIO)

## 📑 Documentação

### Bibliotecas Utilizadas

- **pico/stdlib.h**: Biblioteca padrão para o Raspberry Pi Pico.
- **hardware/pwm.h**: Biblioteca para controle de PWM.
- **hardware/pio.h**: Biblioteca para controle de PIO.
- **ws2812.pio.h**: Biblioteca para controle de LEDs WS2812.
- **lib/led.h**: Biblioteca personalizada para manipulação de LEDs.
- **lib/button.h**: Biblioteca personalizada para manipulação de botões.
- **lib/interrupt.h**: Biblioteca personalizada para manipulação de interrupções.
- **lib/matrix.h**: Biblioteca personalizada para manipulação da matriz de LEDs.

### Configurações

1. **Instalação das Dependências:**
   - Certifique-se de ter o SDK do Raspberry Pi Pico instalado.
   - Instale as bibliotecas necessárias para manipulação de LEDs, botões e display OLED.

2. **Configuração do Projeto:**
   - Clone o repositório do projeto:
     ```sh
     git clone https://github.com/SEU_USUARIO/NOME_DO_REPOSITORIO.git
     cd NOME_DO_REPOSITORIO
     ```
   - Configure o ambiente de desenvolvimento:
     ```sh
     mkdir build
     cd build
     cmake ..
     make
     ```

3. **Carregamento do Código na Placa:**
   - Conecte a placa Raspberry Pi Pico ao computador enquanto mantém pressionado o botão BOOTSEL.
   - Solte o botão BOOTSEL e uma unidade USB aparecerá no seu computador.
   - Arraste e solte o arquivo `.uf2` gerado para a unidade USB.

### Componentes Utilizados

- **LEDs:** Utilizados para exibir números na matriz de LEDs.
- **Botões:** Utilizados para interagir com o sistema e alterar os números exibidos.
- **Interrupções:** Utilizadas para detectar eventos de pressionamento de botões.
- **Joystick:** Configurado para entrar em modo BOOTSEL quando pressionado, permitindo a atualização do firmware da placa.

### Monitor Serial

O projeto utiliza o monitor serial para exibir mensagens de depuração. Sempre que um botão é pressionado, o contador atual é exibido no monitor serial. Para visualizar essas mensagens:

1. **Conecte a placa ao seu computador via USB.**
2. **Abra o monitor serial no VS Code ou use um terminal serial como `minicom`, `PuTTY`, ou `screen`:**
   - No VS Code, vá para o menu "Terminal" e selecione "New Terminal".
   - No terminal, use um comando como `minicom`, `screen`, ou `PuTTY` para abrir o monitor serial. Por exemplo, se você estiver usando `minicom`, o comando seria algo como:
     ```sh
     minicom -b 115200 -o -D /dev/ttyUSB0
     ```
     Certifique-se de substituir `/dev/ttyUSB0` pela porta serial correta do seu dispositivo.

3. **Carregue o programa na placa:**
   - Compile e gere o arquivo `.uf2`.
   - Conecte a placa ao seu computador enquanto mantém pressionado o botão BOOTSEL para entrar no modo de carregamento.
   - Solte o botão BOOTSEL e uma unidade USB aparecerá no seu computador.
   - Arraste e solte o arquivo `.uf2` gerado para a unidade USB.

4. **Verifique as mensagens no monitor serial:**
   - Após carregar o programa, você deve ver as mensagens de depuração no monitor serial, como "Inicializando... Número exibido: 0" e "Botão A pressionado. Número atual: X" quando você pressiona os botões.

## 📞 Contato

Para mais informações, entre em contato:

- **Nome:** Seu Nome
- **Email:** seuemail@example.com
- **GitHub:** [Seu GitHub](https://github.com/SEU_USUARIO)

---

Espero que este README ajude a documentar seu projeto de forma clara e completa. Se precisar de mais alguma coisa, estou à disposição!
