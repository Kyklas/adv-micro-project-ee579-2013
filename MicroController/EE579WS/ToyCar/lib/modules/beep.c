
#include "msp430.h"
#include "beep.h"


int* pSong = 0; // the next note to be played
long tNote = 0; // duration of a note

/* Start playing the song passed as a pointer of int (couple note, duration) */
void ISR_startSong( int* song)
{
	startbeep(*song);
	tNote = ((long)(*(song+1))) *((long)1000); // duration are stored in ms, watchdog call it every 682 탎 so work in 탎
	pSong = song+2;
}

/* Continue to play a song which has been started by startSong */
void ISR_playSong(void)
{
	if(pSong != 0)
	{
		tNote -= 682; // called by the watchdog so decrement the elapsed time
		if( tNote <= 0) // if the duration of the current note is over, read the next note, update the pointer
		{
			startbeep(*pSong);
			tNote = ((long)(*(pSong+1))) *((long)1000); // duration are stored in ms, watchdog call it every 682 탎 so work in 탎
			pSong = pSong+2;
			if( (pSong[0] == 0) && (pSong[1] == 0) ) // end of the song reached
			{
				pSong = 0; // reset the song pointer and stop the timer of the PWM to actually stop playing the song
				stopbeep(); // and avoiding going to far in the array...
			}
		}
	}
}


/* play a note given a frequency */
inline void startbeep(int frequency)
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



/* stop playing a note */
inline void stopbeep()
{
	// Stop Timer_A
	TA0CTL &= ~(MC1 + MC0); // Clear MCx bits to stop timer
}

// stop playing the current song
void ISR_stopSong()
{
	pSong = 0; // reset the song pointer and stop the timer of the PWM to actually stop playing the song
	stopbeep(); // and avoiding going to far in the array...
}

/* play a song stored in an array (couple note, duration) */
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
