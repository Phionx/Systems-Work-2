/*
Shantanu Jha
Systems pd4
HW2
2016-10-10
*/

#include <stdio.h>
#include <stdlib.h>


struct node { char data; struct node *next;};

void print_list(struct node *start){
	while(start){
		printf("Memory Location: %p | Value: %c\n", start, start->data);
		start = start->next;
	}
}

struct node *free_list(struct node *start){
	struct node *temp = start;
	struct node *next = (struct node *)malloc(sizeof(struct node));
	while(start){
		next = start->next;
		printf("Freed Memory Location: %p, Value: %c\n", start, start->data);
		free(start);
		start = next;
	}
	return temp;
}

struct node *insert_front(struct node *start, char newData){
	struct node *next;
	next = (struct node *)malloc(sizeof(struct node));
	next->data = start->data;
	next->next = start->next;
	
	start->next = next;
	start->data = newData;
	return start;
}


int main() {
	struct node *a2;
	a2 = (struct node *)malloc(sizeof(struct node));
	a2->next = NULL;
	a2->data = '1';

	struct node *a1;
	a1 = (struct node *)malloc(sizeof(struct node));
	a1->next = a2;
	a1->data = '0';


	//TEST print_list -----------------------------------------------------
	printf("Printing struct node a1\n");
	print_list(a1);

	//TEST insert_front ---------------------------------------------------
	insert_front(a1, '2');
	printf("Printing struct node a1 after \"a1 = insert_front(a1, '2')\"\n");
	print_list(a1);


	
	int i =0;
	for(;i<5;i++) insert_front(a1, 'a');
	printf("Printing struct node a1 after \"for(;i<5;i++) a1 = insert_front(a1, 'a');\"\n");
	print_list(a1);
	
	//TEST free_list  ------------------------------------------------------
	free_list(a1);
	printf("Printing struct node a1 after \"free_list(a1);\"\n");
	print_list(a1);



	return 0;
}
