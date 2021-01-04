#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Bill
{
	char name[100];
	int cost;
	struct Bill *next;
};
struct Bill *head_ref;


void push(char new_data[50], int new_cost) {
	struct Bill new_node = (struct Bill)malloc(sizeof(struct Bill));
	strcpy(new_node->name, new_data);
	new_node->cost = new_cost;
	new_node->next = NULL;
	if(head_ref == NULL) {
		head_ref = new_node;
	}
	else {
		new_node->next = head_ref;
		head_ref = new_node;
	}
}


void pop() {
	struct Bill *ptr = head_ref;
	if(head_ref == NULL){
		printf("List is empty\n");
	}
	else {
		head_ref = ptr->next;
		ptr->next = NULL;
		free(ptr);
	}
}


void display() {
	struct Bill *node = head_ref;
	if (head_ref == NULL)
	{
		printf("List is Empty\n");	
	}
	while(node != NULL) {
		printf("%s::> %d\n", node->name, node->cost);
		node = node->next;
	}
}


int main() {
	int a;
	char data[50];
	int x;
	do {
		printf("***MENU***\n\n");
		printf("(1)Enter the name and cost of the item::>\n");
		printf("(2)Pop the item\n");
		printf("(3)Display the Bill\n");
		printf("(4)Exit\n\n");
		printf("\n\nEnter your choice: \n");
		scanf("%d", &a);
		switch(a) {
			case 1: printf("\nEnter name of item: ");
					scanf("%s", data);
					printf("\nEnter cost of item: ");
					scanf("%d", &x);
					push(data, x);
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: exit(0);
					break;
			default: printf("\nInvalid option entered.");
		}
	} while(a >= 1 && a <= 9);
	return 0;
}
