//SLL
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* HEAD;

struct node* createnode(int ele){
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    if (newnode!=NULL){
        newnode->data= ele;
        newnode->next=NULL;
    }
    return newnode;
}
void insert(int ele){
    struct node* newnode=createnode(ele);
    struct node* p=HEAD;
    if (HEAD==NULL){
        HEAD=newnode;
    }
    else{
        
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=newnode;
    }
}
int insertPos(int ele, int pos){
    struct node* p=HEAD;
    struct node* newnode=createnode(ele);
    if(HEAD!=NULL){
        struct node* nextele;
        for(int i=0;i<pos-2;i++){
            p=p->next;
        }
        nextele=p->next;
        p->next=newnode;
        newnode->next=nextele;}
    else
       printf("Empty list:(");

}
int insertBeg(int ele){
    struct node* newnode=createnode(ele);
    struct node* nextele=HEAD;
    if(HEAD!=NULL){
        HEAD=newnode;
        newnode->next=nextele;}
    else
       printf("Empty list:(");

}
int delete(){
    struct node* p=HEAD;
    struct node* prev;
    if(HEAD==NULL)
       printf("Empty list nothing to delete.");
    else if(HEAD->next==NULL){
        HEAD=NULL;
    }
    else{
        while(p->next!=NULL){
            prev=p;
            p=p->next;
        }
        prev->next=NULL;
        free(p);
    }
}
int deleteBeg(){
    struct node* p=HEAD;
    if(HEAD->next!=NULL){
        HEAD=HEAD->next;
        free(p);
    }
    else 
      printf("single element in list.");
}
int deletePos(int index){
    struct node* p=HEAD;
    struct node* prev;
    if(HEAD->next!=NULL){
        for(int i=0;i<index;i++){
            prev=p;
            p=p->next;
        }
        prev->next=p->next;
        free(p);
    }
    else 
      printf("single element in list.");
}
void display(){
    struct node* p=HEAD;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    HEAD=NULL;
    int ch, ele,pos,index;
    printf("1)Insert\n2)display\n3)delete\n4)InsertatPos\n5)InsertBeg\n6)DeleteBeg\n7)deletepos\nyour choice: ");
    scanf("%d",&ch);
    do{
        switch(ch){
            case 1: printf("Enter element: ");
                    scanf("%d",&ele);
                    insert(ele);break;
            case 2: printf("elements are: ");
                    display();break;
            case 3: delete();break;
            case 4: printf("Enter element: ");
                    scanf("%d",&ele);
                    printf("Enter pos: ");
                    scanf("%d",&pos);
                    insertPos(ele,pos);break;
            case 5: printf("Enter element: ");
                    scanf("%d",&ele);
                    insertBeg(ele);break;
            case 6: deleteBeg();break;
            case 7: printf("Enter the index of element to be deleted: ");
                    scanf("%d",&index);
                    deletePos(index);break;

        }
        printf("1)Insert\n2)display\n3)delete\n4)InsertatPos\n5)InsertBeg\n6)DeleteBeg\n7)DeletePos\nyour choice: ");
        scanf("%d",&ch);
    }while(ch<=7);
    return 0;
}