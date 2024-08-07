#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define Node 
typedef struct linkedList{
	int value;
	struct linkedList * next;
} linkedList;

// Initialize list with NULL elements
linkedList * initialize(void){
	return NULL;
}
// Check if the list is empty
bool is_empty(linkedList* head) {
    if (head == NULL) {
		return true;
	} else
	{
		return false;
	}
}
// Itinerate the entire list to get the size
int get_length(struct linkedList* head){
	struct linkedList* current = head;
	int count = 0;
	while(current != 0){
		count++;
		current = current->next;
	}
	return count;
}
// Find a element
linkedList * find_element(linkedList * head, int v){
	linkedList * p;
	for (p = head; p != NULL; p = p->next)
	{
		if (p->value == v)
		{
			return p;
		}
	}
	return NULL;
}
// Print list 
void print_list(linkedList * head){
	struct linkedList * current = head;
	while (current != NULL){
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}
// Insertion a Node at the begin of the list
linkedList* insert_head(linkedList * head, int i){
	linkedList* new = (linkedList* ) malloc(sizeof(linkedList));
	new->value = i;
	new->next = head; 
	return new;
}
// Insertion a Node at the end of the list
linkedList* insert_tail(linkedList * head, int i){
	linkedList* new = (linkedList* ) malloc(sizeof(linkedList));
	new->value = i;
	new->next = NULL;
	if (head == NULL){
		return new;
	}
	linkedList* current = head;
	while (current->next != NULL){
		current = current->next;
	}
	current->next = new;
	return head;
}
// Insertion a Node at the middle of the list
linkedList* insert_middle(linkedList * head, int i, int pos){
	linkedList* new = (linkedList* ) malloc(sizeof(linkedList));
	new->value = i;
	new->next = NULL;
	if (head == NULL){
		return new;
	}
	linkedList* current = head;
	int count = 0;
	while (current->next != NULL && count < pos){
		current = current->next;
		count++;
	}
	new->next = current->next;
	current->next = new;
	return head;
}

// Remove an element from the list
linkedList* remove_element(linkedList * head, int v){
	linkedList * previous = NULL;
	linkedList * current = head;
	while (current != NULL && current->value != v){
		previous = current;
		current = current->next;
	}
	if (current == NULL){
		return head;
	}
	if (previous == NULL){
		head = current->next;
	}else{
		previous->next = current->next;
	}
	free(current);
	return head;
}

// Remove the first element from the list
linkedList* remove_head(linkedList * head){
	if (head == NULL){
		return NULL;
	}
	linkedList * new_head = head->next;
	free(head);
	return new_head;
}

// Remove the last element from the list
linkedList* remove_tail(linkedList * head){
	if (head == NULL){
		return NULL;
	}
	linkedList * previous = NULL;
	linkedList * current = head;
	while (current->next != NULL){
		previous = current;
		current = current->next;
	}
	if (previous == NULL){
		return NULL;
	}
	previous->next = NULL;
	free(current);
	return head;
}

// Remove an element from the middle of the list
linkedList* remove_middle(linkedList * head, int pos){
	if (head == NULL){
		return NULL;
	}
	linkedList * previous = NULL;
	linkedList * current = head;
	int count = 0;
	while (current != NULL && count < pos){
		previous = current;
		current = current->next;
		count++;
	}
	if (current == NULL){
		return head;
	}
	if (previous == NULL){
		head = current->next;
	}else{
		previous->next = current->next;
	}
	free(current);
	return head;
}

//  Free the entire list
void free_list(linkedList * head){
	linkedList * current = head;
	while (current != NULL){
		linkedList * next = current->next;
		free(current);
		current = next;
	}
}

int main(void){
	linkedList * head = initialize();
	// Read elements from a file
	FILE * file = fopen("nums.txt", "r");
	int value;
	while (fscanf(file, "%d", &value) != EOF){
		head = insert_tail(head, value);
	}

	// Check if the list is null
	if (is_empty(head)){
		printf("The list is empty\n");
	}else{
		// Print the list
		print_list(head);
		// Get the size of the list
		printf("The size of the list is: %d\n", get_length(head));
		// Find an element
		linkedList * element = find_element(head, 5);
		if (element != NULL){
			printf("Element found: %d\n", element->value);
		}else{
			printf("Element not found\n");
		}
		// Insert an element at the begin of the list
		printf("Inserting an element at the begin of the list\n");
		head = insert_head(head, 0);
		print_list(head);

		// Get the size of the list
		printf("The size of the list is: %d\n", get_length(head));

		// Insert an element at the end of the list
		printf("Inserting an element at the end of the list\n");
		head = insert_tail(head, 11);
		print_list(head);

		// Insert an element at the middle of the list
		printf("Inserting an element at the middle of the list\n");
		head = insert_middle(head, 6, 5);
		print_list(head);

		// Remove an element from the list
		printf("Removing an element from the list\n");
		head = remove_element(head, 5);
		print_list(head);

		// Remove the first element from the list
		printf("Removing the first element from the list\n");
		head = remove_head(head);
		print_list(head);

		// Remove the last element from the list
		printf("Removing the last element from the list\n");
		head = remove_tail(head);
		print_list(head);
		// Remove an element from the middle of the list
		head = remove_middle(head, 5);
		print_list(head);
		// Free the entire list
		free_list(head);

	}

}
