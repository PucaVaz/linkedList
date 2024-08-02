#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define node 
struct node{
	int value;
	struct node * next;
};
typedef struct node list;

// Itinerate the entire list to get the size
int length(struct node* head){
	struct node* current = head;
	int count = 0;
	while(current != 0){
		count++;
		current = current->next;
	}
	return count;
}
// Initialize list with NULL elements
list * initialize(void){
	return NULL;
}
// Print linkeadList 
void list_print(list * head){
	struct node * current = head;
	while (current != 0){
		print("%d\n", current->value);
	}
}
// Insertion a node at the begin of the list
list* insert_head(list * head, int i){
	list* new = (list* ) malloc(sizeof(list));
	new->value = i;
	new->next = head; 
	return new;
}

// Insertion a node at the mid of the list
void 
// Check if the list is empty
bool empty(list * head){
	if (head  == NULL){
		return false;
	}
}

// Find a element
list * find(list * head, int v){
	list * p;
	for (p = head; p != NULL; p = p->next)
	{
		if (p->value == v)
		{
			return p;
		}
	}
	return NULL;
}

// Remove an element from the list
 

int main(void){
	list * head = initialize();

}
