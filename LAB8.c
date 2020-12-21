#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head;

void insert_left(){
	int item;
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr==NULL){
		printf("LIST IS EMPTY!!!");
		ptr->next=NULL;
		ptr->prev=NULL;
		ptr->data=item;
		head=ptr;
	}
	else{
		printf("Enter the value to be added::>\n");
		scanf("%d", &item);
		printf("Node Inserted at Left!\n");
	}
	ptr->data=item;
	ptr->prev=NULL;
	ptr->next=head;
	head->prev=ptr;
	head=ptr;
}

void delete(){
	struct node *ptr, *temp;
	int value;
	printf("Enter the Vakue of positioin to be deleted::>");
	scanf("%d", &value);
	temp=head;
	while(temp->data!=value){
		temp=temp->next;
		if(temp->next==NULL){
			printf("Cannot Delete!!!");
		}
		else if(temp->next->next==NULL){
			temp->next=NULL;
			printf("The Node has Been DELETED!!!");
		}
		else{
			ptr=temp->next;
			temp->next=ptr->next;
			ptr->next->prev=temp;
			free(ptr);
			printf("The Node has been DELETED!!!");
		}
	}
}
	
void display(){
	struct node *ptr;
	ptr=head;
	if(ptr==NULL){
		printf("Nothing to Display\n");
	}
	else
	{
		while(ptr!=NULL){
			printf("\n%d", ptr->data);
			ptr=ptr->next;
		}
	}
}

int main(){
	int option=0;
	while(1){
		printf("\n\n*****************MENU****************\n");
		printf("Choose an option from the list::>>");
		printf("\n[1]Insert at Left\n[2]Delete at Specific Position\n[3]Display\n[4]EXIT\n");
		printf("\nEnter your Option::>>");
		scanf("%d",&option);
		switch(option)
		{
			case 1: insert_left();
					break;
			case 2: delete();
					break;		
			case 3: display();
					break;		
			case 4: exit(1);
			default:
				printf("\nINVALID OPTION!!!\n");								
		}
	}
}
