#include<stdio.h>
#include<stdlib.h>

struct LinkedList{
	int data;
	struct LinkedList *next; 
};
void Insert(struct LinkedList** head, int newData) {
    struct LinkedList* newNode = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}


void Delete(struct LinkedList** head, int delData) {
    struct LinkedList* temp = *head;
    struct LinkedList* prev = NULL;

    if (temp != NULL && temp->data == delData) {
        *head = temp->next; // Change head
        free(temp);         // Free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != delData) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not present in the linked list
    if (temp == NULL) {
        printf("%d not found in the list.\n", delData);
        return;
    }

    // Unlink the node from linked list
    if (prev != NULL) {
        prev->next = temp->next;
    } else {
        *head = temp->next; // If the node to be deleted is the head
    }

    // Free the node
    free(temp);
}
void printLinkedList(struct LinkedList* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main()
{
    struct LinkedList *head=NULL;
    int i,del_num;
    
    for(i=0;i<10;i++)
    {
        Insert(&head,i);
    }
    printLinkedList(head);
	
    printf("Enter del_num:");
    scanf("%d",&del_num);	
    Delete(&head,del_num);
    printLinkedList(head);
	
}