
#include <stdio.h>
#include "file.h"
#include"contact.h"
void saveContactsToFile(AddressBook *addressBook)
 {
   FILE *fptr_temp;
   fptr_temp = fopen("temp.csv","w");
   if(fptr_temp == NULL)
   {
     perror("fopen");
     return;
   }
   fprintf(fptr_temp , "%d\n",addressBook->contactCount);
   for(int i=0;i<addressBook->contactCount;i++)
    {
      
     fprintf(fptr_temp , "%s" , addressBook ->contacts[i].name);
    //rintf(fptr_temp , "%c" ,',');
     fprintf(fptr_temp , "%s" , addressBook ->contacts[i].phone);
      //intf(fptr_temp , "%c" ,',');
      fprintf(fptr_temp ,"%s\n",addressBook->contacts[i].email);
      //intf(fptr_temp , "%c" , ',');
    }
     remove("add.csv");
     rename("temp.csv","add.csv");
fclose(fptr_temp);

}
int openfile(AddressBook *addressBook)
{
   addressBook -> fptr_file = fopen("add.csv","w");
   if( addressBook->fptr_file == NULL)
   {
     perror("fopen");
     printf("file not get\n");
    return 0;
  }
  return 1;
}

   

void loadContactsFromFile(AddressBook *addressBook)
{
     addressBook -> fptr_file = fopen("add.csv","r");
     fscanf(addressBook->fptr_file,"%d\n",&(addressBook->contactCount));
    for (int i=0;i<addressBook->contactCount;i++)
    {
     fscanf(addressBook-> fptr_file," %[^,]",addressBook->contacts[i].name);
     fseek(addressBook-> fptr_file,1,SEEK_CUR);
    fscanf(addressBook->fptr_file," %[^,]",addressBook->contacts[i].phone);
     fseek(addressBook-> fptr_file,1,SEEK_CUR);  
    fscanf(addressBook->fptr_file," %[^,]",addressBook->contacts[i].email);
    fseek(addressBook-> fptr_file,1,SEEK_CUR);
    }
   printf("contact loaded successfully from file\n");
   fclose(addressBook->fptr_file);    
}
