#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int i;
  i = 0;
  
    while (argv[i])
    {
      printf("%s", argv[i]);
      i++;
    }
  return (0);
}
