#include <mbed.h>

enum {On, Off};

DigitalOut blue(LED_BLUE,Off); /* initialise to 1 == OFF */

Ticker  pit;

void flash(void) {
   static unsigned int tick_ms=0; /* tick_ms is a better name */
   tick_ms++; /* count 1 ms */

   if(tick_ms>1000) tick_ms = 0; /* reset for 1s */

   if(  0<tick_ms && tick_ms< 100) blue.write(On);
   if(100<tick_ms && tick_ms< 200) blue.write(Off);
   if(200<tick_ms && tick_ms< 500) blue.write(On);
   if(500<tick_ms && tick_ms<1000) blue.write(Off);

}

int main(void) {
  pit.attach_us(flash,1000); /* 1000μs is 1ms */
  while(1);
}
