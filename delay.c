
#include "delay.h"

static volatile uint32_t timebase = 0;

void tb_init(void) {
    timebase = 0;
    /* timer_init(); */
}

uint32_t tb_get_ms(void) {
    return timebase;
}

uint32_t tb_set_delay(const uint32_t delay) {
    return timebase + delay;
}

bool tb_delay_is_elapsed(const uint32_t timer) {
    return ((timebase - timer) < (1UL << 31));
}

uint32_t tb_delay_remain_ms(const uint32_t timer) {
    if ((timebase - timer) > (1UL << 31)) {
        return (timer - timebase);
    } else {
        return 0;
    }
}

void tb_interrupt_handler() {
    timebase++;
}
