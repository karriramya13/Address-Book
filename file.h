#ifndef FILE_H
#define FILE_H

#include "contact.h"
int openfile(AddressBook *addressBook);
void saveContactsToFile(AddressBook *addressBook);
void loadContactsFromFile(AddressBook *addressBook);

#endif
