#include <TiESC.h>

/**
* initializing the ESC controller
**/
TiESC propellor = TiESC(4, 5, 6, 7);

void setup() {
	/**
	* firing up the ESC controller in setup
	**/
	propellor.fire();
}
  
void loop() {
	/**
	* throttling up the ESC controller
	**/
	propellor.throttle(100);
}