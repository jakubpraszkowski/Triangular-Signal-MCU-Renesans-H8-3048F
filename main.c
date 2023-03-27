
#include "iodefine.h"
#include "lcd.h"
#include "inline.h"
#include "inthandler.h"
#define klawiatura_Obszar 0x20000
#define klawiatura_bufor (*(volatile unsigned char *)(klawiatura_Obszar + 1))



// zmienne
	short counter1;
	short counter2;
	short wy_filtr=0, reszta=0;
	char stan_pracy=0;
	short wypelnienie=5;
	short Fzadane=70;
	short Dzadane=1;

//napisy
	const char *napis_witaj = "Witaj swiecie!";
	const char *napis_hello = "Hello World!";
	const char *napis_STOP = "STOP ";
	const char *napis_START = "START";
	const char *napis_F = "F=7,0Hz";
	const char *napis_D = "D=";
//deklaracje funkcji z main
void ekranStartowy(void);
void init_AC(unsigned char l_kanalow);
unsigned short odczyt_AC(unsigned char l_kanalow);
void filtr_cyfrowy(short wejscie, short * wyjscie);
void odczytaj_klawiature(void);
void czestotliwosc_zadana(void);
//------------ wlasciwy program -----------------------------------

int main (void)
{
	IniLCD();
	//putchar('a');
	//putString(napis_hello);
	//bin2bcd(2000);
	//init_ITU0();
	init_AC('1');
	ekranStartowy();
	

	while(1) 
	{ //pêtla g³ówna
		if(ITU0.TSR.BIT.IMFA==1) {
			ITU0.TSR.BIT.IMFA=0;
			filtr_cyfrowy(odczyt_AC('2'), &wy_filtr);
			
		//	counter1++;
			counter2++;
		//	if(counter1 == 100){
			//	PA.DR.BIT.B6 ^= 1;
			//	counter1 = 0;	
		//	}
			if(counter2 == 100) {
			//	PA.DR.BIT.B0 ^= 1;
				amplituda_zadana();
				odczytaj_klawiature();
				GotoXY(1,1);
				
				if(stan_pracy == 0) {
					putString(napis_START);	
					startPWM(Fzadane,Dzadane);
				} else {
					putString(napis_STOP);	
					stopPWM();	
				}
				
				//bin2bcd(wy_filtr);
				counter2 = 0;
			}
			
		} 
	}
}



//------- funkcje ----------
//--------- procedura wyœwietlaj¹ca na ekranie zawartosc


void ekranStartowy(void) {
	GotoXY(0,0);
	putString(napis_STOP);
	GotoXY(2,11);
	putString(napis_F);
	bin2bcd(5);
	GotoXY(2,1);
	putString(napis_D);
	GotoXY(2,3);
	bin2bcd(10);
}

/*void init_ITU0(void){
	ITU.TSTR.BIT.STR0=0;
	ITU0.TIER.BYTE=0xF8;
	ITU0.GRA=1999;
	ITU0.TCR.BYTE=0xA3;
	ITU0.TIOR.BYTE=0x88;
	ITU.TSTR.BIT.STR0=1;	
}*/

void init_AC(unsigned char l_kanalow) {
	switch(l_kanalow) {
		case '1':
			AD.ADCSR.BYTE = 0x3A;
			break;
		case '2':
			AD.ADCSR.BYTE = 0x3B;
			break;
		case '3':
			AD.ADCSR.BYTE = 0x3C;
			break;
		case '4':
			AD.ADCSR.BYTE = 0x3D;
			break;
	}
}
unsigned short odczyt_AC(unsigned char l_kanalow) {
	switch(l_kanalow) {
		case '0':
			return AD.ADDRA >> 6;
			break;
		case '1':
			return AD.ADDRB >> 6;
			break;
		case '2':
			return AD.ADDRC >> 6;
			break;
		case '3':
			return AD.ADDRD >> 6;
			break;
	}
}
void filtr_cyfrowy(short wejscie, short * wyjscie) {
	long temp, temp1;
	temp=(255*(long)*wyjscie)+((255*(long)reszta)>>8)+wejscie;
	temp1 = (temp>>8);
	*wyjscie = (short)temp1;
	reszta = (short)(temp - (temp1<<8));
}

void odczytaj_klawiature(void) {
	unsigned char temp = klawiatura_bufor&0x7f;
	
	if(temp == 0x7d) { //start
		stan_pracy = 1;	
	} else if(temp == 0x7e) { //stop
		stan_pracy = 0;
	} 
	/*else if(temp == 0x7b) { //plus
		if(wypelnienie < 95) {
			wypelnienie++;
			GotoXY(1,11);
			putString(napis_D);
			bin2bcd(wypelnienie);
		}
	} else if(temp == 0x77) { //minus
		if(wypelnienie > 5) {
			wypelnienie--;
			GotoXY(1,11);
			putString(napis_D);
			bin2bcd(wypelnienie);
		}
	}*/
}

void amplituda_zadana(void) {
	short temp = 0;
	short odczyt = wy_filtr;
	
	temp = (short)( ( (99 * (long)(odczyt) ) >> 10));
	Dzadane=temp;	
	
	GotoXY(2,1);
	putString(napis_D);
	GotoXY(2,3);
	bin2bcd(Dzadane);
}



void startPWM(short f, short D){
	ITU.TSTR.BIT.STR4 = 0; 
	ITU4.TCNT = 0; 
	ITU4.TCR.BYTE = 0xA3; 
	ITU4.TIOR.BYTE = 0x88;
	ITU.TFCR.BYTE = 0xC8;
	ITU4.GRA = 499; 
	ITU4.GRB = 250; 
	ITU4.BRB = ITU4.GRB; 
	ITU4.TIOR.BIT.IOB=0; 
	
	ITU.TMDR.BIT.PWM4 = 1; 
	ITU4.TSR.BYTE = 0xF8; 
	ITU4.TIER.BYTE = 0xF8;
	ITU.TSTR.BIT.STR4 = 1; 
}

void stopPWM(void){
	ITU.TSTR.BIT.STR4 = 0; 
	ITU4.BRB = ITU4.GRA; 
	ITU4.TIER.BYTE = 0xF8; 

	ITU.TSTR.BIT.STR4 = 1; 
}
#include "iodefine.h"
#include "lcd.h"
#include "inline.h"
#include "inthandler.h"
#define klawiatura_Obszar 0x20000 // obszar z pamieci z ktorego bedzie pobierany stan klawiatury
#define klawiatura_bufor (*(volatile unsigned char *)(klawiatura_Obszar + 1))

// zmienne
short counter2;
short wy_filtr=0, reszta=0;
char stan_pracy=0;
short Fzadane = 70;
long Dzadane=1;
int i = 0;

//napisy
const char *napis_STOP = "STOP ";
const char *napis_START = "START";
const char *napis_F = "F=7,0";
const char *napis_D = "D=";

//deklaracje funkcji z main
void ekranStartowy(void);
void init_AC(unsigned char l_kanalow);
unsigned short odczyt_AC(unsigned char l_kanalow);
void filtr_cyfrowy(short wejscie, short * wyjscie);
void odczytaj_klawiature(void);
void czestotliwosc_zadana(void);
void startPWM(void);

//------------ wlasciwy program -----------------------------------

int main (void)
{
    IniLCD();
    init_ITU0();
    init_AC('1');
    ekranStartowy();


    while(1) //pÃªtla glÃ³wna
    {
        if(ITU0.TSR.BIT.IMFA==1) {
            ITU0.TSR.BIT.IMFA=0;
            filtr_cyfrowy(odczyt_AC('2'), &wy_filtr);
            counter2++; // zwiekszanie licznika czasu o 1ms

            if(counter2 == 100) { // jezeli licznik == 100ms
                amplituda_zadana(); // odczytaj amplitude
                odczytaj_klawiature(); // odczytaj klawiature
                GotoXY(1,1);

                if(stan_pracy == 0) { // jezeli flaga stanu pracy = 0
                    putString(napis_STOP); // ustaw napis na STOP

                } else {
                    putString(napis_START); // w innym wypadku ustaw napis na START
                }

                counter2 = 0; // wyzeruj licznik
            }
        }
    }
}



//------- funkcje ----------

void ekranStartowy(void) {
    GotoXY(0,0);
    putString(napis_STOP); // ustawienie napisu STOP
    GotoXY(2,11);
    putString(napis_F); // ustawienie napisu 'F', czestotliwosc
    bin2bcd(5);
    GotoXY(2,1);
    putString(napis_D); // ustawienie napisu 'D', wypelnienie
    GotoXY(2,3);
    bin2bcd(10);
}

void init_ITU0(void) { // inicjalizacja itu0
    ITU.TSTR.BIT.STR0=0;
    ITU0.TIER.BYTE=0xF8;
    ITU0.GRA=1999;
    ITU0.TCR.BYTE=0xA3;
    ITU0.TIOR.BYTE=0x88;
    ITU.TSTR.BIT.STR0=1;
}

void init_AC(unsigned char l_kanalow) { // inicjalizacja AC
    switch(l_kanalow) { // sprawdzenie podanego jako argument kanalu
        case '1':
            AD.ADCSR.BYTE = 0x3A; // ustawienia rejestru wzgledem liczby kanalow
            break;
        case '2':
            AD.ADCSR.BYTE = 0x3B;
            break;
        case '3':
            AD.ADCSR.BYTE = 0x3C;
            break;
        case '4':
            AD.ADCSR.BYTE = 0x3D;
            break;
    }
}

unsigned short odczyt_AC(unsigned char l_kanalow) {
    switch(l_kanalow) { // sprawdzenie podanego jako argument kanalu
        case '0':
            return AD.ADDRA >> 6; // zwrocenie rejestru przesunietego o 6 bitow
            break;
        case '1':
            return AD.ADDRB >> 6; // zwrocenie rejestru przesunietego o 6 bitow
            break;
        case '2':
            return AD.ADDRC >> 6; // zwrocenie rejestru przesunietego o 6 bitow
            break;
        case '3':
            return AD.ADDRD >> 6; // zwrocenie rejestru przesunietego o 6 bitow
            break;
    }
}

void filtr_cyfrowy(short wejscie, short * wyjscie) { // obsluga filtru cyfrowego
    long temp, temp1;
    temp=(255*(long)*wyjscie)+((255*(long)reszta)>>8)+wejscie;
    temp1 = (temp>>8);
    *wyjscie = (short)temp1;
    reszta = (short)(temp - (temp1<<8));
}

void odczytaj_klawiature(void) { // obsluga klawiatury
    unsigned char temp = klawiatura_bufor&0x7f; // przypisanie bufora klawiszy do zmiennej pomocniczej

    if(temp == 0x7d) { // obsluga klawisza odpowiedzialnego za start
        stan_pracy = 1; // zmiana flagi 
        startPWM();     // wywolanie funkcji wlaczajacej PWM
    } else if(temp == 0x7e) { // obsluga klawisza odpowiedzialnego za stop
        stan_pracy = 0; // zmiana flagi 
        stopPWM(); // wywolanie funkcji wylaczajacej PWM
    }
}

void amplituda_zadana(void) { // obsluga wskazania z potencjometru
    short temp = 0; // pomocniczna zmienna 
    short odczyt = wy_filtr;

    temp = (long)( ( (99 * (long)(odczyt) ) >> 10)); // obliczenie procentu z potencjometru
    Dzadane = temp; // przypisanie wyniku do zmiennej

    GotoXY(2,1);
    putString(napis_D);
    GotoXY(2,3);
    bin2bcd(Dzadane); // ustawienie wartosci na ekranie na obliczona wartosc
}

void startPWM(void){ // inicjalizacja PWM
    ITU.TSTR.BIT.STR4 = 0; // zatrzymanie licznika 4
    ITU4.TCNT = 0;  // zerowanie TCNT
    ITU4.TCR.BYTE = 0xA0;
    ITU4.TIOR.BYTE = 0x88;
    ITU4.GRA = 1524; // ustawienie czestotliwosci polaczenia
    ITU4.GRB = 250; // ustawienie amplitudy sygnalu wejsciowego

    ITU.TMDR.BIT.PWM4 = 1; // ustawienie licznika 4 w tryb PWM
    ITU4.TIER.BYTE = 0xF9; // kasowanie flagi przerwania
    ITU.TSTR.BIT.STR4 = 1; // wlaczenie licznika 4
}

void stopPWM(void){ // zatrzymanie PWM
    ITU.TSTR.BIT.STR4 = 0; // zatrzymanie licznika 4
    ITU4.BRB = ITU4.GRA; // przypisanie rejestru GRA do rejestru BRB
    ITU4.TIER.BYTE = 0xF8; // blokowanie lub odblokowywanie zdarzen 
    ITU.TSTR.BIT.STR4 = 1; // wlaczenie licznika 4
}
