#include "header.h"


/* H�r skrivs det i vilken ordning lamporna kommer blinkar i */
void leds_blink(const uint16_t delay_time_ms)
{

	if (diod == LEDS_STATE_BLINK)
	{
		LED3_OFF;
		LED1_ON;
		delay_ms(delay_time_ms);
		LED1_OFF;
		LED2_ON;
		delay_ms(delay_time_ms);
		LED2_OFF;
		LED3_ON;
		delay_ms(delay_time_ms);

		return;
	}
}


/* Det Tal som skrivs in i leds_blink(.) �r det som avg�r hur l�ng delayen �r mellan lamporna blir i Main */
void delay_ms(const uint16_t delay_time_ms)
{
	for (uint16_t i = 0; i < delay_time_ms; ++i)
	{
		_delay_ms(1);
	}

	return;
}


/* Koden som skrivs i Static inline blir uppl�st eng�ng och sedan kopieras den in i Setup */
static inline void init_ports(void);
static inline void init_interrupts(void);


led_state_t diod = LEDS_STATE_OFF;

/* I Setup avg�rs vilka porter som anv�nds */
void setup()
{
	init_interrupts();
	init_ports();

	return;
}

/* H�r skrivs vilka portar varje Led respektive knappar tillh�r */
static inline void init_ports()
{
	DDRB = (1 << LED1) | (1 << LED2) | (1 << LED3);
	PORTB = (1 << NEXT1_BUTTON);

	return;
}

static inline void init_interrupts()
{
	asm("SEI"); 
	PCICR = (1 << PCIE0);
	PCMSK0 = (1 << NEXT1_BUTTON);

	EICRA = (1 << ISC00) | (1 << ISC01); 
	EIMSK = (1 << INT0);

	return;
}