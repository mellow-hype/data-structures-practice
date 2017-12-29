#include <stdio.h>
#include <stdlib.h>

// Node struct
typedef struct node {
    int key;
    struct node * next;
} node_t;


// Function declarations
unsigned int count_nodes(node_t * head);
int get_top(node_t * head);
int get_back(node_t * head);
void append(node_t * head, int key_val);
void print_list(node_t * head);
node_t * alloc_list(int init_val);
void lfree(node_t * list);


// Function definitions

// Allocate a new node
node_t * alloc_node(int init_val){
    node_t * head = malloc(sizeof(node_t));
    if (head == NULL){
        perror("Malloc failed.\n");
        exit(1);
    }
    head->key = init_val;
    head->next = NULL;
    return head;
}

// Count nodes
unsigned int count_nodes(node_t * head){
    unsigned int i = 1;
    node_t * current = head;
    while (current->next != NULL){
        i++;
        current = current->next;
    }
    return i;
}

//  Get the first node
int get_top(node_t * head) {
    return head->key;
}

// Get the last node
int get_back(node_t * head) {
    node_t * current = head;
    while (current->next != NULL){
        current = current->next;
    }

    return current->key;
}

// Append an item to the end of the list
void append(node_t * head, int key_val) {
    node_t * current = head;
    while(current->next != NULL){
        current = current->next;
        append(current, key_val);
        return;
    }

    current->next = alloc_node(key_val);
}

// Print the contents of the list
void print_list(node_t * head){
    node_t * current = head;
    while(current->next != NULL){
        printf("%d,", current->key);
        current = current->next;
    }
    if(current->next == NULL){
        printf("%d\n", current->key);
    }
}

// Free memory for each node
void lfree(node_t * list){
    node_t * current = list;
    while(current->next != NULL){
        node_t * tmp = current;
        current = current->next;
        free(tmp);
    }
}




int main() {
    // Create the head pointer
    node_t * head = alloc_node(2);

    // Print the current list
    printf("The current value of the list is: ");
    print_list(head);

    // append a 3 items to the list
    printf("Items appended to list (4, 5, 7)\n");
    append(head, 4);
    append(head, 5);
    append(head, 7);

    // Print the whole list again
    printf("The new list now contains: ");
    print_list(head);

    // Print the first item in the list
    printf("The first item in the list is: %d\n", get_top(head));

    // Print the second item in the list
    printf("The last item in the list is: %d\n", get_back(head));

    printf("There are %d items in the list\n", count_nodes(head));

    lfree(head);
    return 0;
}

