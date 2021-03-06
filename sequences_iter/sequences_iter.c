#include <stdio.h>
#include <time.h>
#include <string.h>

void iter_sequence(char * alph, int length)
{
  char current_password[length];
  int current_symbol[length];
  int current_position = length - 1; // the index of symbol we currently modify
  int i;
  int alphabet_length = strlen(alph);

  for (i = 0; i < length; i++)
    {
      current_password[i] = alph[0];
      current_symbol[i] = 0;
    }

  while (1)
    {
      printf("%s\n", current_password);

      if (current_symbol[current_position] < alphabet_length - 1)
	{
	  current_password[current_position] = alph[++current_symbol[current_position]];
	}
      else
	{
	  while (current_symbol[current_position] == alphabet_length - 1)
	    {
	      current_symbol[current_position] = 0;
	      current_password[current_position--] = alph[0];
	    }

	  if (current_position < 0)
	    {
	      break;
	    }
	  
	  current_password[current_position] = alph[++current_symbol[current_position]];
	  current_position = length - 1;
	}
    }
  
}

int main(int argc, char * argv[])
{
  char * alphabet_first = "ab";
  int length_first = 30;

  clock_t start = clock();

  iter_sequence(alphabet_first, length_first);

  clock_t finish = clock();

  printf("Elapsed: %f seconds\n", (double)(finish - start) / (CLOCKS_PER_SEC));

  char * alphabet_second = "abcdefghijklmnopqrstuvwxyz[],.+-";
  int length_second = 6;

  start = clock();

  iter_sequence(alphabet_second, length_second);

  finish = clock();

  printf("Elapsed: %f seconds\n", (double)(finish - start) / (CLOCKS_PER_SEC));  

  // the line from here was removed 
  
  return 0;
}
