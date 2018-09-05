#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int value;
	struct Node *next;
	struct Node *cur;
} node_t;

void insert_node(int value);
void print_list(node_t *head);
void remove_node(int value);


node_t *head = NULL;
node_t *current = NULL;

int main(int argc, char const *argv[])
{
	insert_node(12);
	insert_node(13);
	insert_node(16);
	print_list(head);
	printf("\n");
	remove_node(13);
	print_list(head);
	return 0;
}

void insert_node(int value){
    node_t *node = malloc(sizeof(node_t));


    node->value = value;
    node -> next = NULL;

    if(head == NULL) {
        head = node;
        return;
    }
    current = head;


    while(current->next!=NULL)
        current = current->next;

    current->next = node;
}

void print_list(node_t *head){
	node_t *cur = head;
	while(cur != NULL){
		printf("%d ", cur->value);
		cur = cur->next;
	}
}

void remove_node(int value){
    current = head;
    if(current == NULL){
        printf("Error");
        return;
    }
    while(current -> next -> value != value){
        current = current -> next;
    }

    current -> next = current ->next->next;
    free(current->next);
}