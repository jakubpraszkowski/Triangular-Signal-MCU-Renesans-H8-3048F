/****************************************************************
KPIT Cummins Infosystems Ltd, Pune, India. - 05-Sept-2005.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*****************************************************************/
short iter = 0; // iteracja
int czyZwiekszac = 1; // flaga 
/*Include file for 3048F CPU */
#include "inthandler.h"
void INT_NMI(void)
{
	/*add your code here*/
}
void INT_TRAP1(void)
{
	/*add your code here*/
}
void INT_TRAP2(void)
{
	/*add your code here*/
}
void INT_TRAP3(void)
{
	/*add your code here*/
}
void INT_TRAP4(void)
{
	/*add your code here*/
}
void INT_IRQ0(void)
{
	/*add your code here*/
}
void INT_IRQ1(void)
{
	/*add your code here*/
}
void INT_IRQ2(void)
{
	/*add your code here*/
}
void INT_IRQ3(void)
{
	/*add your code here*/
}
void INT_IRQ4(void)
{
	/*add your code here*/
}
void INT_IRQ5(void)
{
	/*add your code here*/
}
void INT_WOVI(void)
{
	/*add your code here*/
}
void INT_CMI(void)
{
	/*add your code here*/
}
void INT_IMIA0(void)
{
	/*add your code here*/
}
void INT_IMIB0(void)
{
	/*add your code here*/
}
void INT_OVI0(void)
{
	/*add your code here*/
}
void INT_IMIA1(void)
{
	/*add your code here*/
}
void INT_IMIB1(void)
{
	/*add your code here*/
}
void INT_OVI1(void)
{
	/*add your code here*/
}
void INT_IMIA2(void)
{
	/*add your code here*/
}
void INT_IMIB2(void)
{
	/*add your code here*/
}
void INT_OVI2(void)
{
	/*add your code here*/
}
void INT_IMIA3(void)
{
	
}
void INT_IMIB3(void)
{
	/*add your code here*/
}
void INT_OVI3(void)
{
	/*add your code here*/
}
void INT_IMIA4(void)
{
    long wynik;
    // iteracja od 0 -> 750 i 750 -> 0 aby otrzymac przebieg trojkatny 
    if(czyZwiekszac == 1) // sprawdzenie czy zwiekszac zmienna
    {
        if(++iter < 749){
            ++iter; // inkrementacja iteracji
        }
        else{
            czyZwiekszac = 0; // jezeli wyjdzie poza zakres, zmien flage
        }
    }
    else{
        if(--iter > 0){
            --iter; // dekrementacja iteracji
        }
        else{
            czyZwiekszac = 1; // jezeli wyjdzie poza zakres, zmien flage
        }
    }

    wynik = (long)ITU4.GRA * iter; // czestotliwosc * iteracja
    ITU4.GRB = (short)(wynik/750) / (short)(100 / Dzadane); // przypisanie wyniku do rejestru GRB i dzielenie przez zadana z potencjometru wypelnienie
    ITU4.TSR.BIT.IMFA=0;
}
void INT_IMIB4(void)
{
	/*add your code here*/
}
void INT_OVI4(void)
{
	/*add your code here*/
}
void INT_DEND0A(void)
{
	/*add your code here*/
}
void INT_DEND0B(void)
{
	/*add your code here*/
}
void INT_DEND1A(void)
{
	/*add your code here*/
}
void INT_DEND1B(void)
{
	/*add your code here*/
}
void INT_ERI0(void)
{
	/*add your code here*/
}
void INT_RXI0(void)
{
	/*add your code here*/
}
void INT_TXI0(void)
{
	/*add your code here*/
}
void INT_TEI0(void)
{
	/*add your code here*/
}
void INT_ERI1(void)
{
	/*add your code here*/
}
void INT_RXI1(void)
{
	/*add your code here*/
}
void INT_TXI1(void)
{
	/*add your code here*/
}
void INT_TEI1(void)
{
	/*add your code here*/
}
void INT_ADI(void)
{
	/*add your code here*/
}
