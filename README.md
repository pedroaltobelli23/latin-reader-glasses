# latin-reader-glasses
Augmented Reality Glasses for Latin

## Etapa Inicial

Para aquecer novamente meus conhecimentos de C++ (SEM IA PARA O CÓDIGO):
- Pequeno projeto que é uma versão modificada de [donut.c](https://www.a1k0n.net/2011/07/20/donut-math.html), para ser um cubo, tetaedro e uma piramide triangular rodando no proprio eixo, e andando de um lado para o outro
- 5 algoritmos de sort, com representação visual
- servidor TCP multithread (será usado posteriormente para a conexão entre o raspberryPI e o ESP32)
- Parser de JSON do zero
- Compressor de arquivos simples (RLE e Huffman)

## Objetivo

Este projeto tem como objetivo desenvolver um óculos de realidade aumentada capaz de identificar textos em latim no campo de visão do usuário e exibir sua tradução em tempo real, sobreposta à cena observada. A primeira versão do projeto conta com realidade aumentada em apenas um dos lados (monocular), como forma de simplificar a construção física sem comprometer a validação do conceito.

O projeto reúne visão computacional, sistemas embarcados, comunicação sem fio e óptica aplicada, e foi pensado após uma viagem que fiz para a Roma, aonde não gostaria de ver as igrejas sem ter que ficar o tempo todo com o google tradutor aberto.

## Etapas do projeto

**Etapa 1 - Prova de conceito em software**
Desenvolvimento do pipeline de captura, reconhecimento de texto (OCR) e tradução, rodando localmente no computador com uma webcam comum. Nesta fase, o resultado é exibido apenas em console, com foco em validar a lógica de processamento e o uso de threading para não bloquear a captura durante o reconhecimento.

**Etapa 2 - Captura remota**
Substituição da webcam por um módulo ESP32-CAM, responsável apenas pela captura e envio das imagens via rede local. O processamento (OCR e tradução) continua ocorrendo em um dispositivo mais potente, que recebe os frames pela rede. O resultado traduzido passa a ser exibido em um display simples (OLED), validando a comunicação entre dispositivos.

**Etapa 3 - Sistema autocontido**
Migração do processamento para um Raspberry Pi, que passa a hospedar sua própria rede local (modo access point), eliminando a dependência de qualquer infraestrutura externa. Nesta etapa também é desenvolvida a parte óptica e física do óculos, permitindo que a tradução seja projetada diretamente no campo de visão do usuário.

## Arquitetura inicial

O sistema é dividido em três blocos principais, que se comunicam por rede local:

```
[ ESP32-CAM ]          [ Raspberry Pi ]           [ Display óptico ]
   Captura     ----->    Processamento    ----->     Exibição
  de imagem              (OCR + tradução)            (overlay AR)
```

- **Captura**: o ESP32-CAM obtém os frames de vídeo e os envia via WiFi.
- **Processamento**: o Raspberry Pi recebe os frames, detecta e reconhece o texto em latim (OCR), realiza a tradução e gera a imagem de saída.
- **Exibição**: o resultado é enviado a um display óptico posicionado na lente do óculos, sobrepondo a tradução à visão do usuário.

Na versão final, o Raspberry Pi opera como ponto de acesso WiFi próprio, tornando o sistema independente de redes externas e adequado para uso em qualquer ambiente.

## Tecnologias principais

- C++
- OpenCV
- Tesseract OCR
- ESP32-CAM
- Raspberry Pi

## Status

Projeto em desenvolvimento, atualmente na Etapa 1.