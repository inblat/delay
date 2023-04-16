# delay
### delay library for microcontroller

##### Loop 1000mS Example:
```c
switch(expression) {
  case 0:
    uint32_t timer = tb_set_delay(1000);
    expression = 1;
  case 1:
    if(tb_delay_is_elapsed(timer)) {
      /* code */
      expression = 0;
    }
  default:
    break;
}
```
