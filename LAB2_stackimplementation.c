#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

void push(int);
void pop();
void display();

int stack[SIZE],top=-1;

int main()
{
	int n,choice;
	while(1)
	{
		printf("\nMENU\n\n");
		printf("(1)Push\n");
		printf("(2)Pop\n");
		printf("(3)Display\n");
		printf("(4)Exit\n");
		printf("Enter your choice: \n\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter the value to be inserted:");
				scanf("%d",&n);
				push(n);
				break;
			
			case 2:
				pop();
				break;
			
			case 3:
				display();
				break;
				
			case 4:
				exit(0);
				
			default: printf("Incorrect Selection.Select Again!\n\n");
		}
	}
	return 0;
}

void push(int n)
{
	if(top==SIZE-1)
	{
		printf("Stack is Full.Insertion is not possible!\n\n");
	}
	else
	{
		top++;
		stack[top]=n;
		printf("Insertion Successful\n\n");
	}
}

void pop()
{
	if(top==-1)
	{
		printf("Stack is empty.Deletion is not possible!\n\n");
	}
	else
	{
		printf("Deleted: %d\n\n",stack[top]);
		top--;
	}
}

void display()
{
	if(top==-1)
	{
		printf("Stack is Empty\n\n");
	}
	else
	{
		int i;
		printf("Stack elemrnts are: \n\n");
		for(i=top;i>=0;i--)
			printf("%d\n",stack[i]);	
	}
}
