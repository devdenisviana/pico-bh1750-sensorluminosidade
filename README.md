# Leitura de Luminosidade com Sensor BH1750 no Raspberry Pi Pico

Este projeto demonstra como utilizar o microcontrolador Raspberry Pi Pico para realizar a leitura de luminosidade ambiente utilizando o sensor digital BH1750 via comunicação I2C.

## Funcionamento do Programa

O programa inicializa a comunicação I2C nos pinos 0 (SDA) e 1 (SCL) do Pico, configura o sensor BH1750 no modo de medição contínua de alta resolução e, a cada segundo, lê o valor de luminosidade (em lux) fornecido pelo sensor.

A leitura é convertida para lux e classificada em quatro faixas:
- **Ambiente escuro**: lux < 10
- **Iluminação moderada**: 10 ≤ lux < 100
- **Ambiente claro**: 100 ≤ lux < 500
- **Luz intensa**: lux ≥ 500

O resultado é impresso no terminal serial, indicando o valor da luminosidade e a classificação correspondente.

## Principais Funções
- `bh1750_init()`: Inicializa o sensor BH1750 no modo contínuo de alta resolução.
- `bh1750_read_lux()`: Lê o valor de luminosidade do sensor e converte para lux.

## Requisitos
- Raspberry Pi Pico
- Sensor BH1750
- Conexão I2C (SDA: GPIO 0, SCL: GPIO 1)
- SDK do Pico configurado

## Compilação e Execução
1. Compile o projeto utilizando o sistema de build do Pico SDK (CMake + Ninja).
2. Grave o firmware gerado na placa Pico.
3. Abra um terminal serial para visualizar as leituras de luminosidade.

## Exemplo de Saída
```
Luminosidade: 5.23 lux (Ambiente escuro)
Luminosidade: 45.10 lux (Iluminação moderada)
Luminosidade: 320.00 lux (Ambiente claro)
Luminosidade: 800.50 lux (Luz intensa)
```

## Observações
- O programa realiza leituras a cada 1 segundo.
- Certifique-se de que o sensor BH1750 esteja corretamente conectado ao barramento I2C do Pico.
