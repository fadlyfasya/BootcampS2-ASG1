#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 5. Find the Nth node from the end of the linked list. 

struct Node{
    int value;
    Node *next;
} *head, *tail;

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



int main(){
    
    pushTail(1);
    pushTail(10);
    pushTail(13);
    pushTail(18);
    pushTail(31);
    pushTail(45);
    pushTail(49);
    pushTail(77);
    pushTail(96);

    printLinkedList();

    int len = 9; //linkedlist len
    int N = 4; //Nth node from back to find

    Node *curr = head;
    for(int i=0; i<len-N; i++){
        curr = curr->next;
    }
    printf("The element of %dth node from back is %d\n", N, curr->value);


    return 0;
}