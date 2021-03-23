#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1. Given two sorted linked lists L1 and L2 of size M and N respectively, merge them into one sorted linked list.

struct Node{
    int value;
    Node *next;
} *head, *tail, *head1, *tail1, *head2, *tail2;

Node *createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void pushHead(int value){
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

void pushTail1(int value){
    Node *temp = createNode(value);
    if(!head1){
        head1 = tail1 = temp;
    }
    else{
        tail1->next = temp;
        tail1 = temp;
    }
}

void pushTail2(int value){
    Node *temp = createNode(value);
    if(!head2){
        head2 = tail2 = temp;
    }
    else{
        tail2->next = temp;
        tail2 = temp;
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

void printLinkedList1(){
    Node *curr = head1;
    while(curr){
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    puts("NULL");
}

void printLinkedList2(){
    Node *curr = head2;
    while(curr){
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    puts("NULL");
}


int main(){
    
    pushTail(1);
    pushTail(5);
    pushTail(9);
    pushTail(10);
    pushTail(22);

    pushTail1(3);
    pushTail1(4);
    pushTail1(7);
    pushTail1(11);
    pushTail1(25);
    pushTail1(26);

    // printLinkedList();

    int M = 5; //size of L1
    int N = 6; //size of L2

    Node *curr = head;
    Node *curr1 = head1;


    for(int i=0; i<M+N; i++){
        if(curr != NULL && curr1 != NULL && curr->value < curr1->value ){
            pushTail2(curr->value);
            curr = curr->next;
        }
        else if(curr1 != NULL && curr != NULL && curr1->value < curr->value){
            pushTail2(curr1->value);
            curr1 = curr1->next;
        }
        else if(curr == NULL){
            pushTail2(curr1->value);
            curr1 = curr1->next;
        }
        else{
            pushTail2(curr->value);
            curr = curr->next;
        }
    }

    printLinkedList2();

    return 0;
}