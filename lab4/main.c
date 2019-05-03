#include <stdio.h>
#include <string.h>

int main()
{
    char string[200], substring[200];
    printf("Enter a string: ");
    gets(string);
    printf("Enter a substring: ");
    gets(substring);
    char words[100][100], *p = string;
    int i = 0, j = 0, k, length, count = 0;

    do{
        p = strstr(p, substring);

	if (p != NULL){
	  ++count;
	  p = &p[strlen(substring)];
	}

  } while (p != NULL);

  printf("Number of substrings in a string = %d\n", count);
    return 0;
}
