#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};
struct node *head = NULL;

struct node* createNode(int data){
	struct node* newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void pushtail(int data){
	if(head == NULL){
		head = createNode(data);
	}else{
		struct node* temp;
		temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = createNode(data);
	}
}

void pushhead(int data) {
    if(head == NULL) {
        head = createNode(data);
    } else {
        struct node *temp;
        temp = createNode(data);
        temp->next = head;
        head = temp;
    }
}

void pushMid(int data) {
    if(head == NULL) {
        head = createNode(data);
    } else {
        struct node* slowPtr = head;
        struct node* fastPtr = head->next;

        while (fastPtr != NULL && fastPtr->next != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        struct node* newNode = createNode(data);
        newNode->next = slowPtr->next;
        slowPtr->next = newNode;
    }
}

int popMid() {
    if(head == NULL) {
        printf("List empty!\n");
        return -1;
    } else {
        struct node* slowPtr = head;
        struct node* prevPtr = NULL;
        struct node* fastPtr = head->next;

        while (fastPtr != NULL && fastPtr->next != NULL) {
            prevPtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        int data;
        if (prevPtr == NULL) {
            data = slowPtr->data;
            head = head->next;
            free(slowPtr);
        } else {
            data = slowPtr->data;
            prevPtr->next = slowPtr->next;
            free(slowPtr);
        }
        return data;
    }
}

void printAll() {
    struct node *temp;
    temp = head;
    while(temp != NULL) {
        printf("Isi : %d\n", temp->data);
        temp = temp->next;
    }   
}

int main() {
    pushtail(10);
    pushtail(20);
    pushtail(30);

    pushMid(15);

    printAll();

    return 0;
}
