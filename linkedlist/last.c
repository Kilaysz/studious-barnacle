#include<stdio.h>
#include<stdlib.h>
struct LinkedList{
	int data;
	struct LinkedList *next; 
};
void Insert(struct LinkedList** head,int newData){
    struct LinkedList* newNode = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}
void Reverse(struct LinkedList** head){
    struct LinkedList* prev = NULL;
    struct LinkedList* current = *head;
    struct LinkedList* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
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
    struct LinkedList *head = NULL;
	
    Insert(&head,3);
    Insert(&head,7);
    Insert(&head,10); 
    
    
    printf("before:\n");
    printLinkedList(head);
	
    printf("after:\n");
    Reverse(&head);
    printLinkedList(head);
}