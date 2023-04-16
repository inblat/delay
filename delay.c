
#include "delay.h"

static volatile uint32_t dwTimebase = 0;

void tbInit(void) {
    dwTimebase = 0;
//     timerInit();
}

uint32_t tbGetMs(void) {
    return dwTimebase;
}

uint32_t tbSetDelay(const uint32_t dwDelay) {
    return dwTimebase + dwDelay;
}

bool tbDelayIsElapsed(const uint32_t hTimer) {
    return ((dwTimebase - hTimer) < (1UL << 31));
}

uint32_t tbDelayRemainMs(const uint32_t hTimer) {
    if ((dwTimebase - hTimer) > (1UL << 31)) {
        return (hTimer - dwTimebase);
    } else {
        return 0;
    }
}

void tbInterruptHandler() {
    dwTimebase++;
}

