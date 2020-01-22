#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	struct node* next;
	int data;
};

struct node* new_node(int data){
	struct node *temp_node = (struct node*)malloc(sizeof(struct node));
	temp_node->data = data;
	temp_node->next = NULL;
	return temp_node;
};

int empty(struct node* heads){
	if(!heads){
		printf("stack is empty\n");
		return 1;
	}
	else return 0;
}

void push(struct node **head,int data){
	struct node* temp_node = new_node(data);
	temp_node->next = *head;
	*head = temp_node;		
}

int pop(struct node **head)
{
	struct node* temp_node = *head;
	*head = (*head)->next;
	int element =  temp_node->data;
	free(temp_node);

	return element;
}

