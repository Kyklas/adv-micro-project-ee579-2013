/*******************************************************************************

  LCD_DISPLAY.h

  Displays Character string on LCD display module
  4 bit mode
  

*******************************************************************************/

#include "iom16c62p.h"

#define RS_PIN 	             p2_0  /* RS Register Select pin */
#define EN_PIN	             p2_1  /* Display Enable pin */	
#define DATA_PORT            p2    /* Data bus port */
#define DATA_PORT_MASK       0xF0  /* Bit mask from entire port */	
#define DATA_PORT_SHIFT      4     /* Number of bits data needs to shift */		
#define DATA_WR              1
#define CTRL_WR              0

#define DELAY_TIMING          0x01  /* Set to ensure base delay of 1mS minimum */
#define NUMB_CHARS_PER_LINE   8     /* number of lines on the LCD display */
#define MAXIMUM_LINES         2     /* Maximum charactors per line of LCD display. */		
#define LCD_LINE1             0
#define LCD_LINE2             16

#define LCD_CLEAR             0x01  /* Clear LCD display and home cursor */
#define LCD_HOME_L1           0x80  /* move cursor to line 1 */
#define LCD_HOME_L2           0xC0  /* move cursor to line 2 */ 
#define CURSOR_MODE_DEC       0x04  /* Cursor auto decrement after R/W */ 
#define CURSOR_MODE_INC       0x06  /* Cursor auto increment after R/W */
#define FUNCTION_SET          0x28  /* Setup, 4 bits,2 lines, 5X7 */
#define LCD_CURSOR_ON         0x0E  /* Display ON with Cursor */
#define LCD_CURSOR_OFF        0x0C  /* Display ON with Cursor off */
#define LCD_CURSOR_BLINK      0x0D  /* Display on with blinking cursor */
#define LCD_CURSOR_LEFT       0x10  /*Move Cursor Left One Position */
#define LCD_CURSOR_RIGHT      0x14  /* Move Cursor Right One Position */
#define LCD_DISPLAY_ON        0x04
#define LCD_TWO_LINE          0x08
#define SET_BIT_HIGH          1					
#define SET_BIT_LOW	      0

void InitialiseDisplay( void );
void DisplayString(unsigned char position, char *string);
void LCD_write(unsigned char data_or_ctrl, unsigned char value);
void LCD_nibble_write(unsigned char data_or_ctrl, unsigned char value);
void DisplayDelay(unsigned long int units);


/*****************************************************************************
Name:          	InitialiseDisplay 
Description:    Intializes the LCD display. 
*****************************************************************************/

void InitialiseDisplay( void )
{
	pd2=0xFF;  //Sets port P2 to output
        /* Power Up Delay for LCD Module */
	EN_PIN = SET_BIT_HIGH;
	DisplayDelay(7000);
	EN_PIN = SET_BIT_LOW;

	/* Display initialises in 8 bit mode - so send one write (seen as 8 bit)
	to set to 4 bit mode. */
	/* Function Set */
	LCD_nibble_write(CTRL_WR,0x03);
	//LCD_nibble_write(CTRL_WR,0x03);
	DisplayDelay(39);
 
	/* Configure display */
	//LCD_nibble_write(CTRL_WR,0x03);
	LCD_nibble_write(CTRL_WR,0x02);
	LCD_nibble_write(CTRL_WR,(LCD_DISPLAY_ON | LCD_TWO_LINE ));
	LCD_nibble_write(CTRL_WR,(LCD_DISPLAY_ON | LCD_TWO_LINE ));
	DisplayDelay(39);

	/* Display ON/OFF control */
	LCD_write(CTRL_WR,LCD_CURSOR_BLINK);
	DisplayDelay(39);

	/* Display Clear */
	LCD_write(CTRL_WR,LCD_CLEAR);
	DisplayDelay(1530);

	/* Entry Mode Set */
	LCD_write(CTRL_WR,0x06);
	LCD_write(CTRL_WR,LCD_HOME_L1);
}

/*****************************************************************************
Name:        	DisplayString   
Parameters:  	position	Line number of display
			    string		Pointer to data to be written to display.
			    			Last character should be null.
Returns:        none
Description:    This function controls LCD writes to line 1 or 2 of the LCD.
                You need to use the defines LCD_LINE1 and LCD_LINE2 in order
				to specify the starting position.
				For example, to start at the 2nd position on line 1...
				   DisplayString(LCD_LINE1 + 1, "Hello")
*****************************************************************************/
void DisplayString(unsigned char position,  char *string)
{
	static unsigned char next_pos = 0xFF;

	/* Set line position if needed. We don't want to if we don't need 
	   to because LCD control operations take longer than LCD data
	   operations. */
	if( next_pos != position)
	{
		if(position < LCD_LINE2)
		{
			/* Display on Line 1 */
		  	LCD_write(CTRL_WR, (unsigned char)(LCD_HOME_L1 + position) );
		}
		else
		{
			/* Display on Line 2 */
		  	LCD_write(CTRL_WR, (unsigned char)(LCD_HOME_L2 + position - LCD_LINE2) );
		}
		/* set position index to known value */
		next_pos = position;		
	}

	do
	{
		LCD_write(DATA_WR,*string++);
		/* increment position index */
		next_pos++;				
	}
	while(*string);


}

/*****************************************************************************
Name:           LCD_write
Parameters:     value - the value to write
				data_or_ctrl - To write value as DATA or CONTROL
								1 = DATA
								0 = CONTROL
Returns:        none
Description:    Writes data to display. Sends command to display.  
*****************************************************************************/
void LCD_write(unsigned char data_or_ctrl, unsigned char value)
{
	/* Write upper nibble first */
	LCD_nibble_write(data_or_ctrl, (value & 0xF0) >> 4);
	/* Write lower nibble second */
	LCD_nibble_write(data_or_ctrl, (value & 0x0F));
}

/*****************************************************************************
Name:           LCD_nibble_write
Parameters:     value - the value to write
				data_or_ctrl - To write value as DATA or CONTROL
								1 = DATA
								0 = CONTROL
Returns:        none
Description:    Writes data to display. Sends command to display.  
*****************************************************************************/
void LCD_nibble_write(unsigned char data_or_ctrl, unsigned char value)
{
	unsigned char ucStore;
	/* Set Register Select pin high for Data */
	if (data_or_ctrl == DATA_WR)
	{
		RS_PIN = SET_BIT_HIGH;
	}
	else
	{
		RS_PIN = SET_BIT_LOW;
	}
	/* There must be 40ns between RS write and EN write */
  	DisplayDelay(1);					
  	/* EN enable chip (HIGH) */
	EN_PIN = SET_BIT_HIGH;
	/* Tiny delay */  			
  	DisplayDelay(1);
	/* Clear port bits used */	
	ucStore = DATA_PORT;
	ucStore &= ~DATA_PORT_MASK;
	/* OR in data */	
	ucStore |= ((value << DATA_PORT_SHIFT) & DATA_PORT_MASK );
	/* Write data to port */	
	DATA_PORT = ucStore;
	/* write delay while En High */	            
	DisplayDelay(20);
	/* Latch data by dropping EN */					
    EN_PIN = SET_BIT_LOW;
	/* Data hold delay */				
	DisplayDelay(20);					
	if (data_or_ctrl == CTRL_WR)
	{
		/* Extra delay needed for control writes */
		DisplayDelay(0x7FF);				
	}				
}
/*****************************************************************************
Name:          DisplayDelay 
Parameters:    units - Approximately in microseconds                   
Returns:       none 
Description:   Delay routine for LCD display.   
*****************************************************************************/
void DisplayDelay(unsigned long int units)
{
	unsigned long counter = units * DELAY_TIMING;
	while(counter--)
	{
		asm("nop");
	}
}