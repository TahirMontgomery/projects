/* This program reads data from a file, orders data from file by name and outputs the ordered list to a file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct supply {  
char color[101];  
int quantity;  
char name[101];
} supply1 = {"null", 0, "null"}; /* variable supply1 is used to store a temporary struct */


int compare_list(const void *p, const void *q);

int main(void)
{
char file[100];
char str[100];
int num1;
char st2[100];
int i = 0;

printf("Enter file: ");
scanf("%100s", file);

char outputFile[100] = "sorted_";
strcat(outputFile, file);


struct supply list[201]; /* struct array */

FILE* numbers;
FILE* output;
numbers = fopen(file, "r");
output = fopen(outputFile, "w");

while (!feof(numbers) && !ferror(numbers)){
      
 if(fscanf (numbers, "%s%d%[^\n]\n", str, &num1,st2)==3){  /* Read a string, number , then a string of file and display */
      strcpy(list[i].color, str);
      list[i].quantity = num1;
      strcpy(list[i].name, st2);
      i++;}
      }
      
qsort(list, i, sizeof(struct supply), compare_list );

int j;
for (j = 0; j <i; j++)    {
fprintf( output, "%s %d %s\n", list[j].color, list[j].quantity, list[j].name);    } /* Outputs sorted list to text file. */

  
return 0;
}

int compare_list(const void *p, const void *q){ 
struct supply *a = (struct supply *)p;
struct supply *b = (struct supply *)q;

  return strcmp(a->name, b->name);}