#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include <stdio.h>

#define I2C_PORT i2c0
#define SDA_PIN  0
#define SCL_PIN  1
#define BH1750_ADDR 0x23
#define BH1750_CMD_CONT_H_RES_MODE 0x10

void bh1750_init() {
    uint8_t cmd = BH1750_CMD_CONT_H_RES_MODE;
    i2c_write_blocking(I2C_PORT, BH1750_ADDR, &cmd, 1, false);
}

float bh1750_read_lux() {
    uint8_t data[2];
    i2c_read_blocking(I2C_PORT, BH1750_ADDR, data, 2, false);
    uint16_t raw = (data[0] << 8) | data[1];
    return raw / 1.2;
}

int main() {
    stdio_init_all();
    i2c_init(I2C_PORT, 100 * 1000);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    sleep_ms(500);
    bh1750_init();

    while (true) {
        float lux = bh1750_read_lux();
        // printf("Luminosidade: %.2f lux\n", lux);
        if (lux < 10)
            printf("Luminosidade: %.2f lux (Ambiente escuro)\n", lux);
        else if (lux < 100)
            printf("Luminosidade: %.2f lux (Iluminação moderada)\n", lux);
        else if (lux < 500)
            printf("Luminosidade: %.2f lux (Ambiente claro)\n", lux);
        else
            printf("Luminosidade: %.2f lux (Luz intensa)\n", lux);

        sleep_ms(1000);
    }

    return 0;
}
