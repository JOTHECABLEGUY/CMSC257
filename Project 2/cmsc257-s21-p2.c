////////////////////////////////////////////////////////////////////////
////
////  File           : main.c
////  Description    : This is the main source code for for the second
////                                       project of CMSC257.
////
////  Author        : Jordan Dube
////  Last Modified : 04/15/2021
//

#include <stdio.h>
#include <stdlib.h>

#include "p2-support.h"
int main ()
{
	struct Mailbox* ib;
	ib = (struct Mailbox*) malloc(sizeof(struct Mailbox));
	initialize(ib);
	printMenu(ib);
	int option;
	int ID;
	char key[10];
	scanf("%d", &option);
	printf("\n");
	while(1){
		switch (option)
		{
			case 1:
				showInbox(ib);
				printf("\nMailbox sorted by ID\n");
				break;
			case 2:
				printf("Enter the ID to search for: ");
				scanf("%d", &ID);
				showEmailByID(ib, ID);
				break;
			case 3:
				sortInboxBySender(ib);
				break;
			case 4:
				sortInboxByID(ib);
				break;
			case 5:
				printf("Enter the keyword to search for: ");
				scanf("%s", &key);
				searchInboxByKeyword(ib, key);
				break;
			case 6:
				printf("Enter the ID to delete: ");
				scanf("%d", &ID);
				deleteEmailByID(ib, ID);
				break;
			case 7:					
				free((ib->emails));
				free(ib);
				printf("Exiting Email CLient.\n");
				return 0;
				break;
			default:
				printf("Please enter a number 1-7\n");
		}
		printMenu(ib);
		scanf("%d", &option);
		printf("\n");
	}
}

