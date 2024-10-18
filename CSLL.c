//CSLL
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* TAIL;

struct node* createnode(int ele){
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    if (newnode!=NULL){
        newnode->data= ele;
        newnode->next=newnode;//CSLL
    }
    return newnode;
}
void insert(int ele){
    struct node* newnode=createnode(ele);
    if (TAIL==NULL){
        TAIL=newnode;
    }
    else{
        
        newnode->next=TAIL->next;//CSLL
        TAIL->next=newnode;
    }
    TAIL=newnode;
}
int insertPos(int ele, int pos){
    struct node* p=TAIL->next;
    struct node* newnode=createnode(ele);
    if(TAIL!=NULL){
    
        for(int i=0;i<pos-2;i++){
            p=p->next;
        }
        newnode->next=p->next;
        p->next=newnode;
        }
    else
       printf("Empty list:(");

}
int insertBeg(int ele){
    struct node* newnode=createnode(ele);
    if(TAIL->next!=NULL){
        newnode->next=TAIL->next;
        TAIL->next=newnode;
        }
    else
       printf("Empty list:(");

}
int delete(){
    struct node* p=TAIL->next;
    struct node* prev;
    if(TAIL==NULL)
       printf("Empty list nothing to delete.");
    else if(TAIL->next==NULL){
        TAIL=NULL;
    }
    else{
        while(p->next!=TAIL->next){
            prev=p;
            p=p->next;
        }
        prev->next=TAIL->next;
        TAIL=prev;
        free(p);
    }
}
int deleteBeg(){
    struct node* p=TAIL->next;
    if(TAIL->next!=NULL){
        TAIL->next=TAIL->next->next;
        free(p);
    }
    else 
      printf("single element in list.");
}
int deletePos(int index){
    struct node* p=TAIL->next;
    struct node* prev;
    if(TAIL->next!=NULL){
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
    struct node* p=TAIL->next;
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=TAIL->next);
    printf("\n");
}
int main()
{
    TAIL=NULL;
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