
/*///////////////////////////////////
Name   : Dynamic alocation "Linked List"
Author : Mostafa Mahmoud 
Date   :  03/2022
*////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//create structure for node

struct node{
int data;
struct node* link;
};

//global pointer to refer to the Nodes

struct node* head = NULL;
struct node* prev = NULL;
struct node* current = NULL;


//function to get size of list
int sizelist(void){
    int size = 0;
    if(head == NULL){
            return -1; //empty list 
    }
    current = head;
    size = 1;
    while(current->link != NULL){
        current = current->link;
        size++;
    }
    return size;
}

//to insert number in start of list

void insertAtstart(int x){
  struct node* temp1 = (struct node*)malloc(sizeof(struct node)); //creation of Node 
  temp1 ->data = x;  //put value in the node
  if(head == NULL){
    head = temp1;  // refer to first Node 
    return;
  }
  current = head;  //save the adress which head refer to it 
  head = temp1;    // head refer to the new node 
  temp1 ->link = current;   //now node refer to the prev node 
}


//to insert number in end of list

void insertAtend(int x){
  struct node* temp1 = (struct node*)malloc(sizeof(struct node));
  temp1 ->data = x;
  temp1 -> link = NULL;
  if(head == NULL){
    head = temp1;
    return;
  }
  current = head;
  while (current->link != NULL){
    current = current->link;
  }
  current->link = temp1;
}

// function to insert number in "n" order in list
void insertinlist(int x,int n){
    int total = sizelist();
    int pos = 0;
    struct node* state = (struct node*)malloc(sizeof(struct node));
    if(n == 1){
        insertAtstart(x);
    }
    if(n == total){
        insertAtend(x);
    }
    current = head;
    while(pos < n){
        prev = current;
        current = current->link;
        pos++;
    }
    state->data = x;
    state->link = current;
    prev->link = state;
}

//function to print data in the list
void printList(void)
{
   struct node *ptr = head;

   printf("[head] =>");

   //start from the beginning
   while(ptr != NULL)
   {
      printf(" %d =>",ptr->data);
      ptr = ptr->link;
   }

   printf(" [null]\n");
}

//to find min value in list 

int min_in_list(){
struct Node *temp = head;
int min;
min = head->value;
while(temp != NULL){
    if(min > temp->value){
        min = temp ->value;
    }
    temp = temp->next;
}
return min;
}

//to find max value in list 

int mix_in_list(){
struct Node *temp = head;
int mix;
mix = head->value;
while(temp != NULL){
    if(mix < temp->value){
        mix = temp ->value;
    }
    temp = temp->next;
}
return mix;
}




int main(){
 insertAtend(10);
 insertAtend(20);
 insertAtstart(30);
 insertAtend(50);
 insertinlist(60,2);
 
 printList();

 int min_value,max_value;
 min_value = min_in_list();
 printf("the min value in list is : %d",min_value);

max_value = max_in_list();
 printf("the max value in list is : %d",max_value);
 }
