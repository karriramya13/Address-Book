#ifndef CONTACT_H
#define CONTACT_H
#include <stdio.h>
#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
    FILE *fptr_file;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook); 
int valid_fun(AddressBook *addressBook,char name[]);
int check_phone(AddressBook *addressBook , char mobile[]);
int read_id(AddressBook *addressBook , char email[]);
int got_name(AddressBook *addressBook,char *name);
int get_number(AddressBook *addressBook,char *number);
int get_email(AddressBook *addressBook,char *email);
#endif
