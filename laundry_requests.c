/* This program maintains a list of laundry service requests from guests. Tahir Montgomery */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NAME_LEN 30

struct request{
	int room_number;
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	int num_items;
	struct request *next;
};


struct request *append_to_list(struct request *list);
void update(struct request *list);
void printList(struct request *list);
void clearList(struct request *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct request *new_list = NULL;  
  printf("Operation Code: a for appending to the list, u for updating a request"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': new_list = append_to_list(new_list);
                break;
      case 'u': update(new_list);
                break;
      case 'p': printList(new_list);
                break;
      case 'q': clearList(new_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
  
}

struct request *append_to_list(struct request *list){


 int roomNum,i,j;
 char firstName[30];
 char lastName[30];
 int quantity;
 int FLAG = 0;
 
 printf("Enter room number: ");
 scanf("%d", &roomNum);
 
 struct request *p;  
 for (p = list; p != NULL; p = p->next)   /* sees if the room number already exists */
      if (p->room_number == roomNum) 
        FLAG = 1;
        
 if (FLAG){
   printf("Request for this room already exists. To update number of items, use the operation code: u ");
   return 0;}
 
 printf("Enter guest first name: ");
 i = read_line(firstName, 30);
 
 printf("Enter guest last name: ");
 j = read_line(lastName, 30);
 
 printf("Enter number of items: ");
 scanf("%d", &quantity);
   
 char *c;
 char *d;
   
 c = malloc(i); /* allocate space for first and last name */
 d = malloc(j);   
 
strcpy(c,firstName);
strcpy(d,lastName); 

struct request *last = list; /* points to beginning of list */

struct request *newNode;
  newNode = malloc(sizeof(struct request));
  if (newNode == NULL) {    
   printf("mallocfailedinadd_to_list\n");    
   return 0;  } 
   
if (list == NULL){

   newNode->room_number = roomNum;  /* adds data to beginning of linked list. returns pointer to newly linked list */
   strcpy(newNode->first, c);
   strcpy(newNode->last, d);
   newNode->num_items = quantity;
   newNode->next = list;
   return newNode;
   }
else{
      struct request *a;
      a = last;
      while (a->next != NULL){  /* iterates until the end of the linked list */
          a = a->next;}
          
   newNode->room_number = roomNum;
   strcpy(newNode->first, c);
   strcpy(newNode->last, d);
   newNode->num_items = quantity;
   newNode->next = NULL;
    a->next = newNode;  /* appends data to end of the linked list. returns a pointer to the linked list */
    return last; }

}

void update(struct request *list)
{
  int roomNum;
  int quantityAdded;
  int FLAG = 1;
  
  printf("Enter the room number: ");
  scanf("%d", &roomNum);
  
  struct request *p;  
  for (p = list; p != NULL; p = p->next){   /* sees if the room number already exists */
      if (p->room_number == roomNum) {
            printf("Enter number of items to be updated: ");
            scanf("%d", &quantityAdded);
            p->num_items += quantityAdded;
            FLAG = 0;
            break;}
            }
  if (FLAG)
      printf("Room number was not found. Use the operation code: a' to add a guest");
}


void printList(struct request *list){

  struct request *q;
  q = list;
  
  printf("Room Number\t First Name\t Last Name\t Number of Items\n");
  while (q != NULL){
    printf("%d\t\t %s\t\t %s\t%d\n", q->room_number, q->first, q->last, q->num_items);
    q = q->next;}
}
void clearList(struct request *list)
{

 struct request *p;  
 while(list != NULL)  { 
 p = list;      
 list = list->next;      
 if( p!= NULL)           
   free(p);
}
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}
