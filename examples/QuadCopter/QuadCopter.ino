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
	* Throttling up all ESC's to 15%
	**/
	propellor.throttle(15, 15, 15, 15);
}
