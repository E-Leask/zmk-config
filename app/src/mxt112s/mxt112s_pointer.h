#ifndef MXT112S_POINTER_H
#define MXT112S_POINTER_H

#include <zephyr.h>
#include <device.h>
#include <drivers/i2c.h>
#include <zmk/hid.h>

// I2C Device and Address
#define MXT112S_ADDR 0x4A

// Touch Event Structure
struct touch_event {
    uint16_t x;
    uint16_t y;
};

// Function Prototypes
void init_i2c(void);
uint8_t read_touch_data(uint8_t reg);
bool is_touch_active(void);
bool debounce_touch_release(void);
struct touch_event get_touch_position(void);
void send_pointer_event(struct touch_event event);
void send_pointer_stop(void);
void process_touch_input(void);

#endif // MXT112S_POINTER_H