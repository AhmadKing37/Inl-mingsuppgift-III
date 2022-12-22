#ifndef HEADERH
#define HEADERH

#define F_CPU 16000000UL // klockslaget ställs in till 16Mhz

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/* PORTB */
#define LED1 0
#define LED2 1
#define LED3 2

#define NEXT1_BUTTON 5

/* PORTD */
#define RESET_BUTTON 2

/* tilldelar dioder och knappar i sin angiven port */
#define LED1_OFF PORTB &= ~(1 << LED1)
#define LED2_OFF PORTB &= ~(1 << LED2)
#define LED3_OFF PORTB &= ~(1 << LED3)

#define LED1_ON PORTB |= (1 << LED1)
#define LED2_ON PORTB |= (1 << LED2)
#define LED3_ON PORTB |= (1 << LED3)

#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3))
#define LEDS_ON PORTB |= (1 << LED1) | (1 << LED2) | (1 << LED3)


#define NEXT1_BUTTON_PRESSED (PINB &(1 << NEXT1_BUTTON))


typedef enum { false, true } bool;

typedef    enum
{
	LEDS_STATE_OFF,
	LEDS_STATE_BLINK

}led_state_t;

extern led_state_t diod; /* Variabel som är synlig överallt. */


void setup(void);
void fsm_update(void);
void fsm_set_output(void);
void leds_blink();
void delay_ms(const uint16_t delay_time_ms);



#endif /* HEADERH */