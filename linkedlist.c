#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };

void * print_list( struct node *n1 ) {
  printf("%d\n",n1->i);
  if( n1->next ) {
    print_list(n1->next);
  }
}

struct node * insert_front( struct node *n1, int data1 ) {
  struct node * n2 = (struct node *)malloc(sizeof(struct node *));
  n2->i = data1;
  n2->next = n1;
  return n2;
}

struct node * free_list( struct node *n1 ) {
  while( n1 != NULL ) {
    struct node * n2 = n1;
    n2->next = n1->next;
    n1 = n1->next;
    free( n2 );
  }
  return n1;
}

int main() {
  struct node * n = (struct node *)malloc(sizeof(struct node *));
  n->i = 6;
  n->next = NULL;
  printf("linkedlist created. Printing...\n");
  print_list(n);
  int i = 5;
  printf("Adding (i = 5; i > 0; i--) to linkedlist...\n");
  for( ; i > 0; i-- ) {
    n = insert_front(n,i);
  }

  printf("new linkedlist:\n");
  print_list(n);

  printf("Now freeing memory...\n");
  free_list(n);
  printf("Done freeing memory. Testing...\n");
  print_list(n);
  
  return 0;
}
