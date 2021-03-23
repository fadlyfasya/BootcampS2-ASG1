#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 3. Find the middle element of a linked list.

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
    pushTail(5);
    pushTail(9);
    pushTail(10);
    pushTail(22);
    pushTail(24);

    printLinkedList();
    
    Node *curr = head;
    int count = 0;
    while(curr){
        count++;
        curr = curr->next;
    }

    curr = head;
    count = count / 2;
    while(count!=1){
        count--;
        curr = curr->next;
    }

    printf("The middle element of the linked list is %d\n", curr->value);

    return 0;
}