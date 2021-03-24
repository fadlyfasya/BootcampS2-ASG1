#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 4. Given a sorted linked list, remove all the duplicates.

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

void popMid(int value){
    if(!head){
        return;
    }
    else if(head->value == value){
        popHead();
    }
    else if(tail->value == value){
        popTail();
    }
    else{
        Node *curr = head;
        while(curr && curr->next->value != value){
            curr = curr->next;
        }

        Node *del = curr->next;
        Node *temp = del->next;

        curr->next = temp;
        free(del);
        del = NULL;
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
    pushTail(1);
    pushTail(1);
    pushTail(8);
    pushTail(9);
    pushTail(11);
    pushTail(11);
    pushTail(30);
    pushTail(30);
    pushTail(30);
    pushTail(30);
    pushTail(31);
    pushTail(31);
    pushTail(31);
    pushTail(31);
    pushTail(32);
    


    printLinkedList();
    

    Node *curr = head;
    Node *temp = curr->next;
    while(temp != NULL){
        if(curr->value == temp->value){
            popMid(curr->value);
        }
        curr = temp;
        temp = temp->next;
    }
    printLinkedList();

    return 0;
}