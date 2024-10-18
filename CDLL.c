#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}; 
struct Node *HEAD;

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    return newNode;
}

struct Node *insertAtBeginning(int value)//List is empty
{
    struct Node *newNode = createNode(value);
    newNode->prev = newNode;//CDLL
    newNode->next = newNode->prev;
    HEAD = newNode;
}
struct Node *insertAtBeg(int value)//List is not empty
{
    struct Node* TAIL;
    struct Node *newNode = createNode(value);
    newNode->prev = TAIL;//CDLL
    newNode->next = HEAD;
    HEAD->prev= newNode;
    TAIL->next=newNode;
    HEAD=newNode;

}
struct Node *insertAtEnd(int value)//List is not empty
{
    struct Node* TAIL= HEAD->prev;
    struct Node *newNode = createNode(value);
    newNode->prev = TAIL;//CDLL
    newNode->next = HEAD;
    HEAD->prev= newNode;
    TAIL->next=newNode;
}
void deletefir()//when head points to a single node
{
    free(HEAD);
    HEAD=NULL;
}
void delfir()//when head points to more than one node
{
    struct Node* TAIL= HEAD->prev;
    struct Node *temp = HEAD;
    HEAD=HEAD->next;
    TAIL->next=HEAD;
    HEAD->prev= TAIL;
    free(temp);
}
void dellast()//when head points to more nodes
{
    struct Node* TAIL= HEAD->prev;
    struct Node *TAILPrev = TAIL->prev;
    TAILPrev->next=HEAD;
    HEAD->prev=TAILPrev;
}
void printList()
{
    //if (last == NULL) return;
    struct Node *TAIL = HEAD->prev;
    struct Node *temp = HEAD;
    while (1){
        printf("%d->", temp->data);
        if (temp == TAIL)
            break;
        temp = temp->next;
    }
    printf("\n");
}
void deletemid(int j)
{
    struct Node* currnode= HEAD;
    for(int i=0; i<=j; i++)
    {
        currnode=currnode->next;
    }
    struct Node* nextnode=currnode->next;
    struct Node* nexxnode=nextnode->next;//nexxnode is the node that comes after nextnode(node to be deleted)
    currnode->next= nextnode->next;
    nexxnode->prev=currnode;
    free(nextnode);
}

void rotcounterclock(int p)//FIX NEEDEDS
{
    struct Node* currnode=HEAD->prev;
    for(int i=0; i<p; i++)
    {
        currnode=currnode->next;
    }
    HEAD=currnode;
    struct Node* prevnode=currnode->prev;
    printf("%d",prevnode->data);
    currnode->prev=HEAD;
    prevnode->next=NULL;

}
int main()
{
    
    int v,val,j,k,n,p;
    /*insertAtBeginning(5);
    insertAtEnd(6);
    insertAtEnd(7);
    insertAtEnd(8);
    insertAtEnd(9);
    insertAtBeg(3);*/
    printf("How many nodes: ");
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter node %d element: ",i);
        scanf("%d",&val);
        if(i==1)
            insertAtBeginning(val);
        else
            insertAtEnd(val);

    }

    //delete block if there is a single node
    /*printf("Before deleting only node...");
    printList();
    deletefir();                                     //deletes HEAD
    printf("After deleting only node..."); 
    printList();*/                                   //hence does not execute further
    
    printf("Before deleting first of many nodes...");
    printList();
    delfir();
    printf("After deleting first of many nodes...");
    printList();
    /*printf("Would you like to add node at beginning of the list (type '0' for yes): ");
    scanf("%d",&k);
    if(k==0)
    {
        printf("Enter element: ");
        scanf("%d",&v);
    }
    insertAtBeg(v);
    printList();*/

    insertAtBeg(4);
    printf("\nBefore rotating...");
    printList();
    printf("\nWhich node do you wish to rotate from (counter-clockwise) ?\n");
    scanf("%d",&p); //crashes at input 4(sometimes))!!!
    rotcounterclock(p);
    printf("After rotating...");
    printList();
    printf("\nBefore deleting last of many nodes...");
    printList();
    dellast();
    printf("After deleting last of many nodes...");
    printList();
    //printf("\n");
    printf("\nWhich node do you wish to delete?\n");
    scanf("%d",&j); //crashes at input 4(sometimes))!!!
    deletemid(j);
    printf("After deleting %d node: ",j);
    printList();             
    return 0;
}

