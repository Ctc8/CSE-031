#include <stdio.h>
#include <stdlib.h>

struct Node {
    int iValue;
    float fValue;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;

    printf("Value of head: %p\n", head); //print out value of head
    printf("Address of head: %p\n", &head); //print out address of head
    printf("Address of iValue: %p\n", &head->iValue); //print out address of iValue
    printf("Address of fValue: %p\n", &head->fValue); //print out address of fValue
    printf("Address of next: %p\n", &head->next); //print out address of next pointed by head
	
	// Insert code here

    
    	
	return 0;
}