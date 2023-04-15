# delay
delay library for microcontroller

Loop 1000mS Example:

switch(expression) {
  case 0:
    uint32_t wTimer = tbSetDelay(1000);
    expression = 1;
  case 1:
    if(tbDelayIsElapsed(wTimer)) {
      /* code */
      expression = 0;
    }
  default:
    break;
}

