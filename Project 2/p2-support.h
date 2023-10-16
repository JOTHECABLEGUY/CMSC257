////////////////////////////////////////////////////////////////////////
////
////  File           : p2-support.h
////  Description    : This is the header file for CMSC257 Project #2. Methods are implemented in p2-support.c
////
////   Author        : Jordan Dube
////   Last Modified : 04/15/2021
//

//Include statements
#define MAILBOX_SIZE 2000
#define ADRESS_SIZE 20
#define SUBJECT_SIZE 200
#define BODY_SIZE 2000
#define NAME_SIZE 20
//CHANGE TO VCU email below
#define user_email "dubejz@vcu.edu"
//add other define Macros as needed
struct Email
{
	int id; 
	char sender[ADRESS_SIZE];
	char receiver[ADRESS_SIZE];
	char subject[SUBJECT_SIZE];
	char body[BODY_SIZE];
	struct sent_date{
		int day;
		int month;
		int year;
	}sent_date;
};

struct Mailbox
{
	int size;
	struct Email* emails;
};
////////////////////////////////////////////////////////////////////////////////////
//// Function : initialize
//// Description : Initializes the mailbox by manually entering the emails using the create_email function
//// Inputs : struct Mailbox* ib - pointer to the database
//// Outputs : void
//
void initialize (struct Mailbox *ib);

/////////////////////////////////////////////////////////////////////////////////////
//// Function : displayMenu
//// Description : Displays the user with options to choose from to mainpulate the specified Mailbox
//// Inputs : struct Mailbox* ib - pointer to the mailbox
//// Outputs : void
//
void printMenu(struct Mailbox* ib);

/////////////////////////////////////////////////////////////////////////////////////
//// Function : sortInboxByID
//// Description : Sorts the emails in the given mailbox by their sent_date, with newest being last and oldest being first
//// Inputs : struct Mailbox* ib - pointer to the mailbox
//// Outputs : void
//
void sortInboxByID(struct Mailbox* ib);

/////////////////////////////////////////////////////////////////////////////////////
//// Function : showInbox
//// Description : Displays all the emails in the mailbox
//// Inputs : struct Mailbox* ib - pointer to the mailbox
//// Outputs : void
//
void showInbox(struct Mailbox* ib);

/////////////////////////////////////////////////////////////////////////////////////
//// Function : sortInboxBySender
//// Description : sorts inbox by sender in lexicographical order
//// Inputs : struct Mailbox* ib - pointer to the mailbox
//// Outputs : void
//
void sortInboxBySender(struct Mailbox* ib);

/////////////////////////////////////////////////////////////////////////////////////
//// Function : showEmailByID
//// Description : Displays all emails with the specified ID
//// Inputs : struct Mailbox* ib - pointer to the mailbox
////          int id - integer that contains the ID of the email to be displayed
//// Outputs : void
//
void showEmailByID(struct Mailbox *ib, int id);

/////////////////////////////////////////////////////////////////////////////////////
//// Function : searchInboxByKeyword
//// Description : Displays all emails containing the specified keyword within the subject, sender, or body fields
//// Inputs : struct Mailbox* ib  - pointer to the mailbox
////          char* key - string that contains the keyword that the user wants to search for
//// Outputs : void
//
void searchInboxByKeyword(struct Mailbox* ib, char* key);

/////////////////////////////////////////////////////////////////////////////////////
//// Function : deleteEmailByID
//// Description : Deletes the email in the mailbox with the specified ID
//// Inputs : struct Mailbox* ib  - pointer to the mailbox
////          int id - ID of email to be deleted
//// Outputs : void
//
void deleteEmailByID(struct Mailbox *ib, int id);

/////////////////////////////////////////////////////////////////////////////////////
//// Function : create_email
//// Description : Adds a new email to the Mailbox
//// Inputs : char* sendr - string for the sender field
////          char* receivr - string for the receiver field
////          char* sub - string containing the subject field
////          char* bod - string for the body field
////          int m - integer for the month field of the sent_date struct
////          int d - integer for the day field of the sent_date struct
////          int y - integer for the year field of the sent_date struct
////          struct Mailbox* ib - pointer to the mailbox
//// Outputs : void
//
void create_email(char* sendr, char* receivr, char* sub, char* bod, int m, int d, int y,  struct Mailbox* ib);

