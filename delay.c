
#include "delay.h"

static volatile uint32_t wTimebase = 0;

void tbInit(void) {
    wTimebase = 0;
//     timerInit();
}

uint32_t tbDelayGetMs(void) {
    return wTimebase;
}

uint32_t tbSetDelay(const uint32_t wDelay) {
    return wTimebase + wDelay;
}

bool tbDelayIsElapsed(const uint32_t wTimer) {
    return ((wTimebase - wTimer) < (1UL << 31));
}

uint32_t tbDelayRemainMs(const uint32_t wTimer) {
    if ((wTimebase - wTimer) > (1UL << 31)) {
        return (wTimer - wTimebase);
    } else {
        return 0;
    }
}

void tbInterruptHandler() {
    wTimebase++;
}

