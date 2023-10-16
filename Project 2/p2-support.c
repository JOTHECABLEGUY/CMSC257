////////////////////////////////////////////////////////////////////////
////
////  File           : p2-support.c
////  Description    : This is the support code for for the second
////                                       project of CMSC257.
////
////   Author        : Jordan Dube
////   Last Modified : 04/15/2021
//

//Include statements
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//Project includes
#include "p2-support.h"
void initialize (struct Mailbox *ib)
{
	//allocate memory for 2000 emails
	ib->emails = malloc (sizeof (struct Email) * MAILBOX_SIZE);
	ib->size = 0;
	create_email ("asonmez@mail.com", user_email, "Welcome to your inbox.", "Welcome to your inbox, just wanted to say hi. Here's hoping you get all your code done.", 11,20,2020, ib);
	create_email ("mmartinez@mail.com", user_email, "Padding out your inbox.", "Yet another email just to pad out your inbox, have fun!", 11,30,2020, ib);
	create_email ("dboyle@mail.com", user_email, "3rd email!", "Alright, time for another email for your inbox. Not going too lie, it's a bit of a pain coming up with stuff for these strings. Anyways, have fun with your code!", 12,2,2020, ib);
	create_email ("cbluer@mail.com", user_email, "4th email!", "Content of fourth email. More coding, more fun!", 12,8,2020, ib);
	create_email ("cboyle@mail.com", user_email, "5th email!", "Content of fifth email. Coding is fun-tastic!", 12,18,2020, ib);
	create_email ("sblack@mail.com", user_email, "6th email!", "Content of fifth email. Coding is fun-tastic!", 1,1,2021, ib);
	create_email ("sblack@mail.com", user_email, "7th email!", "Body of sixth email. Coding is fun-tastic!", 1,5,2021, ib);
	create_email ("sblack@mail.com", user_email, "8th email!", "Body of eighth email. Coding is fun-tastic!", 2,15,2021, ib);
	create_email ("sblack@mail.com", user_email, "9th email!", "Body of ninth email. Coding is fun-tastic!", 2,25,2021, ib);
	create_email ("dboyle@mail.com", user_email, "Last email!", "Body of tentth email. Coding is fun-tastic!", 3,15,2021, ib);
}
// Displays a Menu of Options for the user to choose from
void printMenu(struct Mailbox* ib){
	printf("***************    DUBEJZ INBOX    ***************\n*************** TOTAL INBOX: %04d ***************\n", ib->size);
	printf("1. Show Inbox\n");
	printf("2. Show Email by ID\n");
	printf("3. Sort Inbox by Sender\n");
	printf("4. Sort Inbox by ID\n");
	printf("5. Search Inbox by Keyword\n");
	printf("6. Delete\n");
	printf("7. Exit Inbox\n");
	printf("\nEnter an option 1-7: ");
}
void showInbox(struct Mailbox* ib){
	int i;
	printf("\nID   SENDER--------------   MM/DD/YYYY   Subject--------\n");
	printf(  "--   --------------------   --/--/----   ---------------\n");
	for(i = 0; i < ib->size; i++){
		printf("%02d - ", ib->emails[i].id);
		printf("%-20s - ", ib->emails[i].sender);
		printf("%02d/%02d/%04d - ", ib->emails[i].sent_date.month, ib->emails[i].sent_date.day, ib->emails[i].sent_date.year);
		printf("%.15s", ib->emails[i].subject);
		printf("\n");
	}
	printf("\n");
}
void create_email(char* sendr, char* receivr, char* sub, char* bod, int m, int d, int y, struct Mailbox* ib){
	ib->emails[ib->size].id = ib->size;
	strcpy(ib->emails[ib->size].sender, sendr);
	strcpy(ib->emails[ib->size].receiver, receivr);
	strcpy(ib->emails[ib->size].subject, sub);
	strcpy(ib->emails[ib->size].body, bod);
	ib->emails[ib->size].sent_date.day = d;
	ib->emails[ib->size].sent_date.month = m;
	ib->emails[ib->size].sent_date.year = y;
	ib->size++;
}

void sortInboxByID(struct Mailbox* ib){
	int i, j, min;
	struct Email temp;
	for (i = 0; i < ib->size; i++){
		min = i;
		for (j = i; j < ib->size; j++){
			if(ib->emails[min].id > ib->emails[j].id){
				min = j;
			}
		}

		temp = ib->emails[min];
		ib->emails[min] = ib->emails[i];
		ib->emails[i] = temp;
	}
}
void sortInboxBySender(struct Mailbox* ib){
	int i, j, min;
	struct Email temp;
	for(i = 0; i < ib->size; i++){
		min = i;
		for(j = i; j < ib->size; j++){
			if(strcmp(ib->emails[min].sender, ib->emails[j].sender) > 0){
				min = j;
			}
		}
		temp = ib->emails[min];
		ib->emails[min] = ib->emails[i];
		ib->emails[i] = temp;
	}
}
void showEmailByID(struct Mailbox *ib, int id){
	int hits = 0; 
	int i;

	for(i = 0; i < ib->size; i++){
		if (id == ib->emails[i].id){
			printf("%-s - %s\n", ib->emails[i].sender, ib->emails[i].subject);
			printf("Email Received on: %02d/%02d/%04d", ib->emails[i].sent_date.month, ib->emails[i].sent_date.day, ib->emails[i].sent_date.year);
			printf("\n\n");
			printf("%s", ib->emails[i].body);     
			hits++;

		}
		}
	if(hits == 0) {
			printf("No matches found for \\""%d\"\n", id);
}
}
void searchInboxByKeyword(struct Mailbox *ib, char *key){
	int hits = 0; 
	int i;
	for(i = 0; i < ib->size; i++){
		if (strstr(ib->emails[i].sender, key) || strstr(ib->emails[i].subject, key) || strstr(ib->emails[i].body, key)){
			if(hits == 0) {
				printf("\nFound email(s): \n\n");
				printf("\nID   SENDER--------------   MM/DD/YYYY   Subject--------\n");
				printf(  "--   --------------------   --/--/----   ---------------\n");
			}
			printf("%02d - ", ib->emails[i].id);
			printf("%-20s - ", ib->emails[i].sender);
			printf("%02d/%02d/%04d - ", ib->emails[i].sent_date.month, ib->emails[i].sent_date.day, ib->emails[i].sent_date.year);
			printf("%.15s", ib->emails[i].subject);
			printf("\n");

			hits++;

		}
		

	}
	printf("\n");
	if(hits == 0) {
		printf("No matches found for \"\"%s\"\n", key);
	}
}
void deleteEmailByID(struct Mailbox* ib, int id){
	int i, j;
	for(i = 0; i < ib->size; i++){
		if (id == ib->emails[i].id){
			printf("\n Email with ID = %d is deleted\n", id);
			//ib->emails[i] = NULL;
			for (j = i; j < ib->size - 1; j++) {
				ib->emails[j] = ib->emails[j + 1];
			}
			//ib->emails[ib->size] = NULL;
			ib->size--;
			return;
		}
	}
	printf("\nNo email found with ID: \\""%d\"\n", id);
}

