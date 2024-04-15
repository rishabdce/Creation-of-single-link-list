#include <stdio.h>
#include <stdlib.h>

struct node {
  int info;
  struct node *link;
};
struct node *first;
void delete_beg();
void delete_end();
void dis_beg();
void del_beg();
void del_end();
void dis_end();
void create();
void display();
void insert_beg();
void insert_end();
void main() {

  create();
  // display();
  insert_beg();
  insert_end();
  delete_beg();
  //delete_end();
}
void create() {
  int ch;
  struct node *ptr;
  ptr = (struct node *)malloc(sizeof(struct node));
  printf("enter the value of first node:");
  scanf("%d", &ptr->info);
  ptr->link = NULL;
  first = ptr;
  do {
    struct node *cpt;
    cpt = (struct node *)malloc(sizeof(struct node));
    printf("enter the value of next node:");
    scanf("%d", &cpt->info);
    ptr->link = cpt;
    ptr = cpt;
    printf("enter 1 to continue or 0 to exit:");
    // fflush(stdin);
    scanf("%d", &ch);
  } while (ch == 1);
  ptr->link = NULL;
  display();
}
void display() {
  struct node *ptr;
  ptr = first;
  while (ptr != NULL) {
    printf("%d\t", ptr->info);
    ptr = ptr->link;
  }
}
void insert_beg() {
  struct node *ptr;
  struct node *pt;
  ptr = first;
  pt = (struct node *)malloc(sizeof(struct node));
  printf("\nenter the value of inserted node at beginning:\t");
  scanf("%d", &pt->info);
  pt->link = ptr;
  first = pt;
  dis_beg();
}
void dis_beg() {
  struct node *pt;
  pt = first;
  while (pt != NULL) {
    printf("%d\t", pt->info);
    pt = pt->link;
  }
}
void insert_end() {
  struct node *ptr, *end;
  ptr = (struct node *)malloc(sizeof(struct node));
  end = first;
  printf("\nenter the value of inserted node at end:\t");
  scanf("%d", &ptr->info);
  while (end->link != NULL) {
    end = end->link;
  }
  ptr->link = NULL;
  end->link = ptr;
  dis_end();
}
void dis_end() {
  struct node *ptr;
  ptr = first;
  while (ptr != NULL) {
    printf("%d\t", ptr->info);
    ptr = ptr->link;
  }
}
void delete_beg() {
  struct node *ptr;
  ptr = first;
  first = first->link;
  free(ptr);
  printf("\nprinting LL after deletion at the beg\n");
  display();
}