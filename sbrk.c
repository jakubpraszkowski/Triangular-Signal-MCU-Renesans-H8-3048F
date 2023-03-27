#include <_ansi.h>
#include <sys/types.h>
register char *stack_ptr asm ("sp");
caddr_t _sbrk(int incr)
{
  extern  char end;		/* Defined by the linker */
  static char *heap_end;
  char *prev_heap_end;
  if (heap_end == 0) 
    {
      heap_end = &end;
    }
  prev_heap_end = heap_end;
  if (heap_end + incr > stack_ptr)
    {
      //printf("Heap and Stack Collision occured\n\r");
      return (caddr_t)NULL;
    }
  heap_end += incr;
  return (caddr_t)prev_heap_end;
}
