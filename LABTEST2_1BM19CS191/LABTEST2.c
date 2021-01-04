#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void push();
void pop();
void display();
struct node
{
    float cost;
    char name[50];
    struct node *next;
};
struct node *top=NULL;

int main(int argc, char **argv)
{
	int choice;
    char ch;
    do
    {
    printf("\n1. Add item to cart \n2. Display cart  \n3. Remove item from cart\n4.exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: push(); break;
        case 2: display();break;
        case 3: pop(); break;
        case 4:break;
        default:printf("wrong choice\n");
    }    
    }while(choice!=4);
}


void push()
{
    float item;
    char name1[50];
    struct node *newnode;
    printf("Enter the name of item\n");
    scanf("%s",name1);
    printf("Enter the cost of item\n");
    scanf("%f",&item);
    
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->cost=item;
    strcpy(newnode->name,name1);
    newnode->next=NULL;
    if(top==NULL)
        top=newnode;
    else
        newnode->next=top;
        top=newnode;
}
void pop()
{
    if(top==NULL)
        printf("Cart is empty\n");
    else
    {
      
      printf("name of element removed is %s:\n", top->name);
      
      top=top->next;
        
    }
        
        
}

void display()
{
struct node *temp;
temp=top;
if(top==NULL)
    printf("Cart is empty\n");
printf("-------------ABC MALL----------\n");
while(temp!=NULL)
{
    printf("------------------------\n");
    printf("Name:%s\n",temp->name);
    printf("Cost:%f\n",temp->cost);
    
    temp=temp->next;
    printf("-------------------------\n");
}
    
}
