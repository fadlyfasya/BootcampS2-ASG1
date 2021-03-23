#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1. Given two sorted linked lists L1 and L2 of size M and N respectively, merge them into one sorted linked list.

struct Node{
    int value;
    Node *next;
} *head, *tail, *head1, *tail1;

Node *createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void pushHead(const char *name, int value){
    Node *temp = createNode(value);
    if(!head){
        head = tail = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}

void pushTail(int value){
    Node *temp = createNode(value);
    if(!head){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }  
}

void pushTailCycle(int value){
    Node *temp = createNode(value);
    if(!head1){
        head1 = tail1 = temp;
    }
    else{
        tail1->next = temp;
        tail1 = temp;
        temp->next = head1;
    }  
}

void popHead(){
    if(!head){
        return;
    }
    else if(head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        Node *temp = head->next;
        head->next = NULL;
        free(head);
        head = temp;
    }
}

void popTail(){
    if(!head){
        return;
    }
    else if(head == tail){
        free(head);
        head = tail = NULL;
    }
    else{
        Node *curr = head;
        while(curr->next != tail){
            curr = curr->next;
        }
        curr->next = NULL;
        free(tail);
        tail = curr;
    }
}

void printLinkedList(){
    Node *curr = head;
    while(curr){
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    puts("NULL");
}

void printLinkedListCycle(){
    Node *curr = head1;
    printf("(head) ");
    do{
        printf("%d -> ", curr->value);
        curr = curr->next;
    }while(curr != head1);
    printf("%d (Head)\n", curr->value);
}


int main(){
    
    pushTail(1);
    pushTail(5);
    pushTail(9);
    pushTail(10);
    pushTail(22);
    

    pushTailCycle(1);
    pushTailCycle(2);
    pushTailCycle(3);
    pushTailCycle(4);
    pushTailCycle(5);

    // printLinkedList();
    // printLinkedListCycle();

    if(tail1->next == head1){
        puts("This linked list is a cycle");
    }
    else if(tail1 ->next == NULL){
        puts("This linked list is NOT a cycle");
    }

    if(tail->next == head){
        puts("This linked list is a cycle");
    }
    else if(tail ->next == NULL){
        puts("This linked list is NOT a cycle");
    }



    return 0;
}