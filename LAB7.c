#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head;
struct node *head1;


void push()
{
	struct node *ptr;
	int new_data;
	ptr = (struct node *)malloc(sizeof(struct node));
	
	if(ptr == NULL)
	{
		printf("\nOVERFLOW!!!");	
	}
	else
	{
		printf("\nEnter the Value to be inserted::>>");
		scanf("%d",&new_data);
		ptr->data = new_data;
		ptr->next = head;
		head = ptr;
		printf("\nNode inserted at the top of the Stack\n");	
	}
}
void pop()
{
	struct node *ptr;
	if(head == NULL)
	{
		printf("LIST IS EMPTY!!!");
	}
	else
	{
		ptr = head;
		head = ptr->next;
		free(ptr);
		printf("\nNode deleteed from the top of the Stack\n");
	}	
}


void enqueue()
{
	struct node *ptr,*temp;
	int new_data;
	ptr = (struct node *)malloc(sizeof(struct node));	
	
	printf("\nEnter the Value to be inserted::>>");
	scanf("%d",&new_data);
	ptr->data = new_data;
	if(head == NULL)
	{
		ptr->next = NULL;
		head = ptr;
		printf("\nNode inserted at the front of the Queue\n");	
	}
	else
	{
		temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = ptr;
		ptr->next = NULL;
		printf("\nNode inserted at the rear of the Queue\n\n");
	}	
}
void dequeue()
{
	struct node *ptr;
	if(head == NULL)
	{
		printf("LIST IS EMPTY!!!");
	}
	else
	{
		ptr = head;
		head = ptr->next;
		free(ptr);
		printf("\nNode deleted from the front of the Queue\n");
	}	
}


void display()
{
	struct node *ptr;
	ptr = head;
	if(ptr == NULL)
	{
		printf("LIST IS EMPTY!!!");
	}
	else
	{
		printf("\n\nThe LIST is >>>>>");
		while(ptr != NULL)
		{
			printf("\t%d",ptr->data);
			ptr = ptr->next;
		}
	}
}



void sort()
{
	struct node *ptr = head;
	struct node *temp = NULL;
	int i;
	
	if(head == NULL)
	{
		return;
	}
	else
	{
		while(ptr != NULL)
		{
			temp = ptr->next;
			while(temp != NULL)
			{
				if(ptr->data >temp->data)
				{
					i = ptr->data;
					ptr->data = temp->data;
					temp->data = i;
				}
				temp = temp->next;
			}
			ptr = ptr->next;
		}
	}
}


void reverse()
{
	struct node *prev = NULL;
	struct node *next = NULL;
	struct node *ptr = head;
	while(ptr != NULL)
	{
		next = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = next;
	}
	head = prev;
}


struct node *create_list(struct node *head)
{
	struct node *ptr,*temp;
	int i,n,new_data;
	
    printf("\nEnter the number of nodes ::>> ");
    scanf("%d",&n);
	head = NULL;
	if(n == 0)
	{
		return head;
	}
	for(i=1;i<=n;i++)
	{
		ptr = (struct node *)malloc(sizeof(struct node));	
		printf("Enter the element to be inserted ::>> ");
		scanf("%d",&new_data);
		ptr->data = new_data;
		if(head == NULL)
		{
			ptr->next = NULL;
			head = ptr;
		}
		else
		{
			temp = head;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = ptr;
			ptr->next = NULL;
		}	    
	}
	return head;
}


struct node *concatenate(struct node *head, struct node *head1)
{
	struct node *ptr;
	if(head == NULL)
	{
		head = head1;
		return head;
	}
	if(head1 == NULL)
	{
		return head;
	}
	ptr = head;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = head1;
	return head;
}



int main()
{
	int option = 0;
	while(1)
	{
		printf("\n\n*****************MENU****************\n");
		printf("Choose an option from the list::>>");
		printf("\n<-STACK OPERATIONS->\n[1]PUSH\n[2]POP");
		printf("\n\n\n<-QUEUE OPERATIONS->\n[3]ENQUEUE\n[4]DEQUEUE");
		printf("\n--------------------------");
		printf("\n[5]DISPLAY\n[6]SORT\n[7]REVERSE\n[8]CONCATENATION\n[9]EXIT\n");
		printf("\nEnter your Option::>>");
		scanf("%d",&option);
		switch(option)
		{
			case 1: push();
					break;
			case 2: pop();
					break;		
			case 3: enqueue();
					break;		
			case 4: dequeue();
					break;
			case 5: display();
					break;
			case 6: sort();
					printf("\nSorted LIST::>>");
					display();
					break;
			case 7: reverse();
					printf("\nReversed LIST::>>");
					display();
					break;				
			case 8: printf("\nCreate a Second LIST >>>>>");
					head1 = create_list(head1);
					printf("\nLIST 1::>>");
					display();
					struct node *ptr;
					ptr = head1;
					if(ptr == NULL)
					{
						printf("LIST 2 IS EMPTY!!!");
					}
					else
					{
						printf("\n\nLIST 2 >>>>>");
						while(ptr != NULL)
						{
							printf("\t%d",ptr->data);
							ptr = ptr->next;
						}
					}
					head = concatenate(head,head1);
					printf("\n\nConcatenated List::>>");
					display();
					break;
			case 9:	exit(1);
			default:
				printf("\nINVALID OPTION!!!\n");								
		}
	}
}
