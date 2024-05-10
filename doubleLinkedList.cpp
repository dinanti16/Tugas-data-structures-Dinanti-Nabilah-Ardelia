#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct mahasiswa{
	
	char name[101];
	char nim[101];
	int umur;
	mahasiswa *next;
	mahasiswa *prev;
};
mahasiswa *head = NULL, *tail = NULL;

mahasiswa *createNewNode(char nim[101], char name[101], int umur){
	
	mahasiswa *newNode = (mahasiswa*)malloc(sizeof(mahasiswa));
	
	newNode->umur = umur;
	strcpy(newNode->name, name);
	strcpy(newNode->nim, nim);
	newNode->next = NULL; 
	newNode->prev = NULL; 
	
	return newNode;
}

void pushHead(mahasiswa *newNode){
	
	if(head == NULL){
		head = tail = newNode;
	}
	else{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	
}


void pushTail(mahasiswa *newNode){
	
	if(head == NULL){
		head = tail = newNode;
	}
	else{
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
}


void pushMid(mahasiswa *newNode){
	
	if(head == NULL){
		head = tail = newNode;
	}
	else{
		
		if(strcmp(newNode->nim, head->nim) < 0 ){
			pushHead(newNode);
		}
		else if(strcmp(newNode->nim, tail->nim) > 0){
			pushTail(newNode);
		}
		else{
			mahasiswa *flag = head;
			while(flag != NULL && strcmp(flag->nim, newNode->nim) < 0){
				flag = flag->next;
			} 
			flag->prev->next = newNode;
			newNode->next = flag;
			newNode->prev = flag->prev;
			flag->prev = newNode;
		}
	}
}

void view(){
	
	mahasiswa *flag = head;
	while(flag != NULL){
		printf("%s %s %d\n", flag->nim, flag->name, flag->umur);
		flag = flag->next;
	}
	puts("NULL");
}

void popHead(mahasiswa *newNode){
	
	if(head == NULL){
		printf("no data");
	}
	else if(head == tail){
		free(head);
		head = tail = NULL;
	}
	else{
		mahasiswa *temp = head;
		head->next = head;
		head->prev = NULL;
		free(temp);
		temp = NULL;
	}
}

void popTail(){
	
	if(head == NULL){
		printf("NO DATA");
	}
	else if(head == tail){
		free(tail);
		head = tail = NULL;
	}
	else{
		mahasiswa *temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		free(temp);
		tail = NULL;
	}
}

void popMid(char nim[101]){
	
	if(head == NULL){
		printf("NO DATA");
	}	
	else if(strcmp(head->nim, nim) == 0){
		popHead;
	}
	else if(strcmp(tail->nim, nim) == 0){
		popTail;
	}
	else{
		mahasiswa *curr = head;
		
		while(curr!= NULL && strcmp(curr->nim, nim) != 0){
			curr = curr->next;
		}
		
		if(curr == NULL){
			return;
		}
		else{
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			free(curr);
			curr = NULL;
		}
	}
}


mahasiswa *search(char nim[101]){

	mahasiswa *curr = head;
	while(curr!= NULL){
		if(strcmp(curr->nim, nim) != 0){
		curr = curr->next;
		}
		else{
			return curr;
		}	
	}
	return NULL;
}



int main(){
	
	pushMid(createNewNode("125", "karina", 15));
	pushMid(createNewNode("123", "winter", 15));
	pushMid(createNewNode("126", "giselle", 15));
	pushMid(createNewNode("124", "ningning", 15));
	
	popMid("125");
	mahasiswa *result = search("126");
	printf("result : %s\n", result->name);
	return 0;
}
