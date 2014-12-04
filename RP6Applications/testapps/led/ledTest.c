#include <core/core.h>

int main(void) {
    init();
    leds();
    
    uint8_t leds = 1;
    while (1) {
        setLEDs(leds);
        leds <<=1;
    }
    
    return 0;
}
