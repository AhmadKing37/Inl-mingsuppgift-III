#include "header.h"

int main()
{
	setup();

	while (1)
	{
		leds_blink(100);
		fsm_set_output();
	}

	return 0;
}