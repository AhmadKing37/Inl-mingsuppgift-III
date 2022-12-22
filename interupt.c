#include "header.h"



ISR(PCINT0_vect)
{
	if (NEXT1_BUTTON_PRESSED)
	{
		fsm_update();
	}
}