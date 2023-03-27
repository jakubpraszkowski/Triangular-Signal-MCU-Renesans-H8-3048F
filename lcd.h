#ifndef LCD_H

	#define LCD_H
	
void IniLCD(void);
int putchar(int ch);
void putString(const char *string);
void bin2bcd(short liczba);
void WriteSterLCD(unsigned char znak);
void GotoXY(unsigned char x, unsigned char y);
void KursorOn(unsigned char x, unsigned char y);
void KursorOff(void);
void ClrScr(void);
unsigned char ReadSterLCD(void);
unsigned char GotowoscLCD(void);
void startPWM(short f, short D);

#endif
