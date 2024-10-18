//DLL

#include<stdio.h>
#include<stdlib.h>
void displayDlList();
void insertlast(int);  
struct node  
{  
    int data;  
    struct node *next;  
    struct node *prev;  
}*stnode;  
struct node *head;  
int main ()  
{
    //stnode= NULL; 
    //head= NULL;
    //ennode= NULL;  
    int choice,item;  
    do   
    {  
        printf("\nEnter the item which you want to insert?\n");  
        scanf("%d\n",&item);  
        insertlast(item);  
        printf("\nPress 0 to insert more ?\n");  
        scanf("%d",&choice);  
    }while(choice == 0);
    displayDlList();   
}  
void insertlast(int item)  
{  
    
   struct node *stnode = (struct node *) malloc(sizeof(struct node));  
   struct node *temp;  
   stnode->data=item;  
    /*if(head == NULL)  
    {  
           stnode->next = NULL;  
           stnode->prev = NULL;  
           head = stnode;  
    }  
    else  
    {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = stnode;  
          stnode ->prev=temp;  
          stnode->next = NULL;*/
   if(stnode == NULL)  
   {  
       printf("\nOVERFLOW");         
   }  
   else  
   {  
       
        stnode->data=item;  
       if(head == NULL)  
       {  
           stnode->next = NULL;  
           stnode->prev = NULL;  
           head = stnode;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = stnode;  
          stnode ->prev=temp;  
          stnode->next = NULL;  
       } 
    } 
printf("\nNode Inserted\n");
printf("Printing DLL...\n");
             
  
}  
void displayDlList() {
    struct node *tmp;
    int n = 1;
    if (stnode == NULL) {
        printf(" No data found in the List yet.");
    } else {
        tmp = stnode;
        printf("\n\n Data entered on the list are :\n");

        // Traverse and display each node's data in the list
        while (tmp != NULL) {
            printf(" node %d : %d\n", n, tmp->data);
            n++;
            tmp = tmp->next; // Move to the next node
        }
    }
