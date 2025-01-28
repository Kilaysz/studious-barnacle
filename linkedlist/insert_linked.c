#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next; 
};

void search(struct node *head, int d){
    struct node *t = head, *prev=NULL;

    while (t != NULL && t->data != d){
         prev = t;
         if(t->next==NULL){
            printf("No data found");
            return;
         }
         t = t -> next;
    }

    // data is found
    printf("Successful");
    return;

}

void printLinkedList(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void deletelinklist(struct node* head, int d){
    struct node *t=head, *prev=NULL;

    while (t != NULL && t->data != d){
         prev = t;
         t = t -> next;
    }
    if(t==NULL) {return NULL;}
    if(prev==NULL) {head = t->next; t->next=NULL;free(t);return;}
    prev->next = t->next;
    t->next=NULL;
    free(t);
}

struct node *insert_linked_list(struct node *head, int value){
    struct node *curr = malloc(sizeof(struct node));
    curr -> data = value;
    curr -> next = NULL;
    
    curr -> next = head;
    head = curr;
    return head;
}

    int value;
int main(){
    struct node *head = malloc(sizeof(struct node));
    head -> data= 3;
    head -> next = NULL;
    
    struct node *current = malloc(sizeof(struct node));
    current -> data = 2;
    current -> next = NULL;
    head -> next = current;
    
    int i;
    scanf("%d",&i);
    for(int k = 1;k<=i;k++){
        scanf("%d", &value);
        head = insert_linked_list(head, value);
    }    
    int delete_value;
    scanf("%d", &delete_value);
    deletelinklist(head, delete_value);
    printLinkedList(head);
    int a;
    scanf("%d", &a);
    search(head, a);
    return 0;
}