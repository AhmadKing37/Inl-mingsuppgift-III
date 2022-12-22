#include "header.h"


/* Update visar vad som h�nder n�r du trycker p� knappen och vilka state som finns f�r lamporna. */
void fsm_update(void)
{
	switch (diod)
	{
		case LEDS_STATE_OFF:
		{
			if (NEXT1_BUTTON_PRESSED)
			{
				diod = LEDS_STATE_BLINK;
			}

			break;
		}
		case LEDS_STATE_BLINK:
		{
			if (NEXT1_BUTTON_PRESSED)
			{
				diod = LEDS_STATE_OFF;
			}
			break;
		}
	}

}



/* Output anv�nds i main f�r att koden ska f�rst� vilken state den ska skicka ut */
void fsm_set_output(void)
{
	LEDS_OFF;

	if (diod == LEDS_STATE_OFF)LEDS_OFF;
	else if (diod == LEDS_STATE_BLINK) leds_blink();


	return;
}