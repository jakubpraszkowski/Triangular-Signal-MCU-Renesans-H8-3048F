//LCD.C


#include "iodefine.h"
#include "inline.h"
#include "lcd.h"

//---- deklaracja adresow buforow sterownika wyswietlacza LCD

#define LCDObszar 						0x20000
#define LCD_data				 		(*(volatile unsigned char *) (LCDObszar))
#define LCD_IO	  						(*(volatile unsigned char *) (LCDObszar+1))	




//--------------procedura inicjalizacji wyswietlacza, 8-bitowa magistrala, 2 linie, kursor w prawo, niewidoczny	

void IniLCD(void)
{                                
  	unsigned short Licznik;

	WriteSterLCD(0x38);		//ustawienie s³owa inicjalizujacego wyswietlacz
  	Licznik=0x500;
  	while (Licznik--) 		//opoznienie
	{
		no_operation();
	}		
  	
	WriteSterLCD(0x38);		//powtorzenie slowa
  	Licznik=0x12C;
  	while (Licznik--)
	{
		no_operation();
	}
	WriteSterLCD(0x38);		//powtorzenie slowa
  	Licznik=0x12C;
  	while (Licznik--)
	{
		no_operation();
	}		
  													//teraz operacja poprzedzona sprawdzeniem gotowosci
	if(GotowoscLCD())	WriteSterLCD(0x0C);			//wlacz wyswietlacz, kursor niewidoczny

	if(GotowoscLCD())	WriteSterLCD(0x01);			//kasuj wyswietlacz


}


//----------procedura kontroli gotowosci wyswietlacza

unsigned char GotowoscLCD(void)
{

	while ((ReadSterLCD()&0x80)==0x80)		//czytaj bit busy
	{
		no_operation();						//jesli b7=1 czekaj
	}
	
	return(1);								//pokaz gotowosc 1
}

//------ procedura wyslania rozkazu do rej sterujacego wyswietlacza

void WriteSterLCD(unsigned char znak)
{  
	LCD_data=znak;
	LCD_IO=0x00;
  	LCD_IO=0x01;
  	LCD_IO=0x00;
}

//---------- procedura odczytu slowa statusowego z wyswietlacza

unsigned char ReadSterLCD(void)
{
	unsigned char ch;
	
	LCD_IO=0x02;
	LCD_IO=0x03;
  	ch=LCD_data;
  	LCD_IO=0x02;
  	return(ch);
}

//---------- ustaw kursor na wyswietlaczu, x-rzad (1-2), y-kolumna(1-16)

void GotoXY(unsigned char x, unsigned char y)
{
	if (GotowoscLCD())
	{
  		if (x==1) WriteSterLCD(0x80+y-1);		
  		if (x==2) WriteSterLCD(0xC0+y-1);
		
	}
}

//--------- procedura wyslania znaku ASCII na wyswietlacz
#undef putchar
int putchar(int ch)
{ 
	if (ch==0x0A);
 	else 
 	{
		if (GotowoscLCD())
		{
   			LCD_data=ch&0xFF;
 			LCD_IO=0x04;
 			LCD_IO=0x05;
			LCD_IO=0x04;
			LCD_IO=0x02;
		}
	}
	return(ch);
}

//--------- procedura wyslania ³añcucha znaków ASCII na wyswietlacz
#undef putString
void putString(const char *string)
{ 	
	int i;
	for(i=0; i<15; i++) {
		if(string[i] == '\0') {
			return;
		}
		if (string[i]==0x0A);
		else {
			if (GotowoscLCD()) {
				LCD_data=string[i]&0xFF;
	 			LCD_IO=0x04;
	 			LCD_IO=0x05;
				LCD_IO=0x04;
				LCD_IO=0x02;
			}
		}
	}
}

//--------- procedura wyswioetlajaca liczbe binarana na wyswietlaczu

#undef bin2bcd
void bin2bcd(short liczba)
{ 	
	if(liczba >= 1000) { return;}
	
	int setki = liczba / 100 % 10;
	putchar(setki + 48);
	putchar(',');
	int dziesiatki = liczba / 10 % 10;
	putchar(dziesiatki + 48);
	int jednosci = liczba % 10;
	putchar(jednosci + 48);
	
}

//-------- procedura ustawiajaca kursor w polozeniu i uwidaczniajaca go

void KursorOn(unsigned char x, unsigned char y)
{
	GotoXY(x,y);
   	if (GotowoscLCD()) WriteSterLCD(0x0D);		
}

//-------- procedura ustawiajaca kursor w polozeniu i wylaczajaca go

void KursorOff(void)
{
	if (GotowoscLCD()) WriteSterLCD(0x0C);		
}


//--------- procedura kasowania wyswietlacza

void ClrScr(void)
{
	if (GotowoscLCD()) WriteSterLCD(0x01);
}
