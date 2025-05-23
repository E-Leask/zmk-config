#include "input_mxt112s.h"

const struct device *i2c_dev;

// Initialize I2C communication
void init_i2c() {
    i2c_dev = device_get_binding(DT_LABEL(DT_NODELABEL(i2c0)));
    if (!i2c_dev) {
        printk("Failed to bind I2C device\n");
        return;
    }
    printk("I2C initialized\n");
}

// Read data from mXT112S register
uint8_t read_touch_data(uint8_t reg) {
    uint8_t data;
    int ret = i2c_reg_read_byte(i2c_dev, MXT112S_ADDR, reg, &data);
    return (ret < 0) ? 0 : data;
}

// Check if touch is active
bool is_touch_active() {
    uint8_t touch_status = read_touch_data(0x12); // Example status register
    return (touch_status & 0x01); // Touch detected
}

// Debounce touch release
bool debounce_touch_release() {
    int stable_count = 0;
    for (int i = 0; i < 5; i++) {
        if (!is_touch_active()) {
            stable_count++;
        }
        k_msleep(10);
    }
    return (stable_count >= 5);
}

// Retrieve touch position
struct touch_event get_touch_position() {
    struct touch_event event;
    event.x = read_touch_data(0x10);
    event.y = read_touch_data(0x11);
    return event;
}

// Send pointer movement event to ZMK
void send_pointer_event(struct touch_event event) {
    struct zmk_hid_mouse_report report = {
        .x = event.x / 10,
        .y = event.y / 10,
        .buttons = 0
    };
    zmk_hid_mouse_send_report(&report);
}

// Stop pointer movement on release
void send_pointer_stop() {
    struct zmk_hid_mouse_report report = {
        .x = 0,
        .y = 0,
        .buttons = 0
    };
    zmk_hid_mouse_send_report(&report);
}

// Main loop for touch input processing
void process_touch_input() {
    while (1) {
        if (is_touch_active()) {
            struct touch_event event = get_touch_position();
            send_pointer_event(event);
        } else if (debounce_touch_release()) {
            send_pointer_stop();
        }
        k_msleep(50);
    }
}

void main() {
    printk("Initializing mXT112S pointer driver...\n");
    init_i2c();
    process_touch_input();
}