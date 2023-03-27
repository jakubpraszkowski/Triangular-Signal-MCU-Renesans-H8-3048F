#include <_ansi.h>
#include <sys/types.h>

int _write(int file,char *ptr,int len)
{
    int i;
 
    /* PutChar : Your implementation to send the character to the 
       serial port.*/

    for(i=0;i<len;i++)
    {      
	  //PutChar(*ptr++);
    } 
    return len;
}
