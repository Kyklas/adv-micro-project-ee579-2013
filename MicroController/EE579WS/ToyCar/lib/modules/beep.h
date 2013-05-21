

#ifndef BEEP_H
#define BEEP_H


extern int* psong;

static const int tetris[]={
		330,150,
		0,40,
		494,159,
		0,40,
		660,150,
		0,40,
		590,150,
		660,150,
		494,100,
		494,100,
		523,150,
		0,40,
		440,150,
		0,40,
		494,150,
		0,40,
		392,100,
		392,100,
		440,150,
		370,150,
		0,40,
		392,150,
		0,40,
		330,100,
		330,100,
		370,150,
		0,40,
		294,150,
		0,40,
		330,150,
		247,100,
		247,100,
		261,150,
		0,40,
		311,150,
		0,40,
		330,150,
		0,40,
		247,100,
		247,100,
		262,150,
		0,40,
		370,150,
		0,40,
		330,150,
		0,40,
		494,159,
		0,40,
		660,150,
		0,40,
		590,150,
		660,150,
		494,100,
		494,100,
		523,150,
		0,40,
		440,150,
		0,40,
		494,150,
		0,40,
		392,100,
		392,100,
		440,150,
		370,150,
		0,40,
		392,150,
		0,40,
		330,100,
		330,100,
		370,150,
		0,40,
		294,150,
		0,40,
		330,150,
		247,100,
		247,100,
		261,150,
		0,40,
		311,150,
		0,40,
		330,150,
		0,40,
		247,100,
		247,100,
		262,150,
		0,40,
		370,150,
		0,40,
		330,150,
		0,40,
		0,0
};

static const int starwars[]={
		392,350,
		0,100,
		392,350,
		0,100,
		392,350,
		0,100,
		311,250,
		0,100,
		466,25,
		0,100,
		392,350,
		0,100,
		311,250,
		0,100,
		466,25,
		0,100,
		392,700,
		0,100,
		587,350,
		0,100,
		587,350,
		0,100,
		587,350,
		0,100,
		622,250,
		0,100,
		466,25,
		0,100,
		370,350,
		0,100,
		311,250,
		0,100,
		466,25,
		0,100,
		392,700,
		0,100,
		784,350,
		0,100,
		392,250,
		0,100,
		392,25,
		0,100,
		784,350,
		0,100,
		740,250,
		0,100,
		698,25,
		0,100,
		659,25,
		0,100,
		622,25,
		0,100,
		659,50,
		0,400,
		415,25,
		0,200,
		554,350,
		0,100,
		523,250,
		0,100,
		494,25,
		0,100,
		466,25,
		0,100,
		440,25,
		0,100,
		466,50,
		0,400,
		311,25,
		0,200,
		370,350,
		0,100,
		311,250,
		0,100,
		392,25,
		0,100,
		466,350,
		0,100,
		392,250,
		0,100,
		466,25,
		0,100,
		587,700,
		0,100,
		784,350,
		0,100,
		392,250,
		0,100,
		392,25,
		0,100,
		784,350,
		0,100,
		740,250,
		0,100,
		698,25,
		0,100,
		659,25,
		0,100,
		622,25,
		0,100,
		659,50,
		0,400,
		415,25,
		0,200,
		554,350,
		0,100,
		523,250,
		0,100,
		494,25,
		0,100,
		466,25,
		0,100,
		440,25,
		0,100,
		466,50,
		0,400,
		311,25,
		0,200,
		392,350,
		0,100,
		311,250,
		0,100,
		466,25,
		0,100,
		392,300,
		0,150,
		311,250,
		0,0

};

static const int mario[]={
		660,100,
		0,150,
		660,100,
		0,300,
		660,100,
		0,300,
		510,100,
		0,100,
		660,100,
		0,300,
		770,100,
		0,550,
		380,100,
		0,575,
		510,100,
		0,450,
		380,100,
		0,400,
		320,100,
		0,500,
		440,100,
		0,300,
		480,80,
		0,330,
		450,100,
		0,150,
		430,100,
		0,300,
		380,100,
		0,200,
		660,80,
		0,200,
		760,50,
		0,150,
		860,100,
		0,300,
		700,80,
		0,150,
		760,50,
		0,350,
		660,80,
		0,300,
		520,80,
		0,150,
		580,80,
		0,150,
		480,80,
		0,500,
		510,100,
		0,450,
		380,100,
		0,400,
		320,100,
		0,500,
		440,100,
		0,300,
		480,80,
		0,330,
		450,100,
		0,150,
		430,100,
		0,300,
		380,100,
		0,200,
		660,80,
		0,200,
		760,50,
		0,150,
		860,100,
		0,300,
		700,80,
		0,150,
		760,50,
		0,350,
		660,80,
		0,300,
		520,80,
		0,150,
		580,80,
		0,150,
		480,80,
		0,500,
		500,100,
		0,300,
		760,100,
		0,100,
		720,100,
		0,150,
		680,100,
		0,150,
		620,150,
		0,300,
		650,150,
		0,300,
		380,100,
		0,150,
		430,100,
		0,150,
		500,100,
		0,300,
		430,100,
		0,150,
		500,100,
		0,100,
		570,100,
		0,220,
		500,100,
		0,300,
		760,100,
		0,100,
		720,100,
		0,150,
		680,100,
		0,150,
		620,150,
		0,300,
		650,200,
		0,300,
		1020,80,
		0,300,
		1020,80,
		0,150,
		1020,80,
		0,300,
		380,100,
		0,300,
		500,100,
		0,300,
		760,100,
		0,100,
		720,100,
		0,150,
		680,100,
		0,150,
		620,150,
		0,300,
		650,150,
		0,300,
		380,100,
		0,150,
		430,100,
		0,150,
		500,100,
		0,300,
		430,100,
		0,150,
		500,100,
		0,100,
		570,100,
		0,420,
		585,100,
		0,450,
		550,100,
		0,420,
		500,100,
		0,360,
		380,100,
		0,300,
		500,100,
		0,300,
		500,100,
		0,150,
		500,100,
		0,300,
		500,100,
		0,300,
		760,100,
		0,100,
		720,100,
		0,150,
		680,100,
		0,150,
		620,150,
		0,300,
		650,150,
		0,300,
		380,100,
		0,150,
		430,100,
		0,150,
		500,100,
		0,300,
		430,100,
		0,150,
		500,100,
		0,100,
		570,100,
		0,220,
		500,100,
		0,300,
		760,100,
		0,100,
		720,100,
		0,150,
		680,100,
		0,150,
		620,150,
		0,300,
		650,200,
		0,300,
		1020,80,
		0,300,
		1020,80,
		0,150,
		1020,80,
		0,300,
		380,100,
		0,300,
		500,100,
		0,300,
		760,100,
		0,100,
		720,100,
		0,150,
		680,100,
		0,150,
		620,150,
		0,300,
		650,150,
		0,300,
		380,100,
		0,150,
		430,100,
		0,150,
		500,100,
		0,300,
		430,100,
		0,150,
		500,100,
		0,100,
		570,100,
		0,420,
		585,100,
		0,450,
		550,100,
		0,420,
		500,100,
		0,360,
		380,100,
		0,300,
		500,100,
		0,300,
		500,100,
		0,150,
		500,100,
		0,300,
		500,60,
		0,150,
		500,80,
		0,300,
		500,60,
		0,350,
		500,80,
		0,150,
		580,80,
		0,350,
		660,80,
		0,150,
		500,80,
		0,300,
		430,80,
		0,150,
		380,80,
		0,600,
		500,60,
		0,150,
		500,80,
		0,300,
		500,60,
		0,350,
		500,80,
		0,150,
		580,80,
		0,150,
		660,80,
		0,550,
		870,80,
		0,325,
		760,80,
		0,600,
		500,60,
		0,150,
		500,80,
		0,300,
		500,60,
		0,350,
		500,80,
		0,150,
		580,80,
		0,350,
		660,80,
		0,150,
		500,80,
		0,300,
		430,80,
		0,150,
		380,80,
		0,600,
		660,100,
		0,150,
		660,100,
		0,300,
		660,100,
		0,300,
		510,100,
		0,100,
		660,100,
		0,300,
		770,100,
		0,550,
		380,100,
		0,575,
		0,0
};

static const int portal[]={
		784,200,
		740,200,
		659,200,
		659,200,
		740,200,
		0,800,
		784,200,
		740,200,
		659,200,
		659,200,
		0,300,
		740,200,
		587,200,
		0,300,
		659,200,
		440,200,
		0,800,
		440,200,
		659,300,
		740,200,
		784,300,
		659,300,
		554,200,
		0,100,
		587,200,
		659,300,
		0,100,
		440,300,
		440,200,
		740,200,
		0,1000,
		784,200,
		740,200,
		659,200,
		659,200,
		740,200,
		0,800,
		784,200,
		740,200,
		659,200,
		659,200,
		0,300,
		740,200,
		587,200,
		0,300,
		659,200,
		440,200,
		0,800,
		659,300,
		740,200,
		784,300,
		659,200,
		554,300,
		587,200,
		659,400,
		0,100,
		440,200,
		587,200,
		659,200,
		698,200,
		659,200,
		587,200,
		523,200,
		0,400,
		440,200,
		466,300,
		523,300,
		698,200,
		0,100,
		659,200,
		587,200,
		587,200,
		523,200,
		0,50,
		587,200,
		523,200,
		0,50,
		523,300,
		0,50,
		523,200,
		0,200,
		440,200,
		466,300,
		523,300,
		698,200,
		0,100,
		783,200,
		698,200,
		659,250,
		587,200,
		587,200,
		659,200,
		698,300,
		0,50,
		698,300,
		0,100,
		783,200,
		880,200,
		932,200,
		932,200,
		880,200,
		0,50,
		783,300,
		698,200,
		783,200,
		880,200,
		880,200,
		783,200,
		0,50,
		698,300,
		0,100,
		587,200,
		523,200,
		587,200,
		698,200,
		698,200,
		659,300,
		0,50,
		659,200,
		739,100,
		739,400,
		0,0
};

#define SIZE_SONG(x) (sizeof((x))/sizeof(int))

void ISR_startSong( int* song);
void ISR_playSong(void);
void ISR_stopSong();

void startbeep(int frequency);
inline void stopbeep();
void playsong(const int song[],unsigned int size);

#endif // BEEP_H
