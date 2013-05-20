
#include "msp430.h"

#include "beep.h"


void startbeep(int frequency)
{
	if(frequency==0)
	{
		TA0CTL &= ~(MC1 + MC0); // Clear MCx bits to stop timer
		return;
	}

	TA0CCR0 = (int) (1500000.0f/frequency);
	TA0CCR1 = TA0CCR0>>1; // half duty cycle

	// Start Timer_A
	TA0CTL |= MC_1; // Start timer in up mode
}

void playportal()
{
	extern unsigned long time;
	unsigned long waittime;
	unsigned int index;

	for(index=0;(index<(sizeof(portal)/sizeof(int)));index+=2)
	{
		startbeep(portal[index]);
		waittime = (unsigned long) portal[index+1];
		waittime *=1000;
		waittime += time;
		while(time<waittime)
		{
			__delay_cycles(400);
		}
	}
	stopbeep();
}

void stopbeep()
{
	// Stop Timer_A
	TA0CTL &= ~(MC1 + MC0); // Clear MCx bits to stop timer
}

void playmario()
{
	extern unsigned long time;
	unsigned long waittime;
	unsigned int index;

	for(index=0;(index<(sizeof(mario)/sizeof(int)));index+=2)
	{
		startbeep(mario[index]);
		waittime = (unsigned long) mario[index+1];
		waittime *=800;
		waittime += time;
		while(time<waittime)
		{
			__delay_cycles(400);
		}
	}
	stopbeep();
}

void playsong(const int song[],unsigned int size)
{
	extern unsigned long time;
	unsigned long waittime;
	unsigned int index;

	for(index=0;(index<size);index+=2)
	{
		startbeep(song[index]);
		waittime = (unsigned long) song[index+1];
		waittime *=1000;
		waittime += time;
		while(time<waittime)
		{
			__delay_cycles(400);
		}
	}
	stopbeep();
}
