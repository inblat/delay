#ifndef _DELAY_H
#define _DELAY_H

void tb_init(void);
uint32_t tb_get_ms(void);
uint32_t tb_set_delay(const uint32_t delay);
bool tb_delay_is_elapsed(const uint32_t timer);
uint32_t tb_delay_remain_ms(const uint32_t timer);

#endif
