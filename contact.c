#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
int valid_fun(AddressBook *addressBook , char name[])
{
	int i ;
	for(i=0;i<strlen(name);i++)
	{
		if(!((name[i] >='A' &&  name[i]<='Z') || (name[i]>='a' && name[i]<='z')))
		{ 
			return 0;

		}       
	}	
	for(i=0;i<addressBook->contactCount;i++)
	{
		if(strcmp(addressBook->contacts[i].name,name)==0)
		{
			//	printf("\ncontact found \n name is %s \n phone no is %s \n Email id is %s\n\n",
			//			addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
			return -1;
		}
        }
	return 1;
}                                                         
int check_phone(AddressBook *addressBook , char phone[])
{
	int i;
	for(i=0;i<strlen(phone);i++)
	{
		if(!(phone[i] >='0' &&  phone[i] <='9'))
		{
			return 0;

		}
	}	
         if(strlen(phone) != 10)
	  {
	  return 0 ;
	  }


	for(i=0;i < addressBook->contactCount ;i++)
	{
		if(strcmp(addressBook->contacts[i].phone,phone)==0)
		{
			return -1;
		}

	}
	return 1 ;
}
int read_id( AddressBook *addressBook , char email[])
{
	int count=0;
	if( strstr(addressBook->contacts[addressBook->contactCount].email,"@") !=NULL)
	{
	
		count++;
	}
	if( strstr(addressBook->contacts[addressBook->contactCount].email,".com") !=NULL)
	{
		
		count++;
	}
	if( strstr(addressBook->contacts[addressBook->contactCount].email,"@.com") !=NULL)
	{
		
		return 0;
	}
	if(count != 2)
	{
		
		return 0;
        }	
	for(int i=0;i<addressBook->contactCount ; i++)
	{
		if(strcmp(addressBook->contacts[i].email,email)==0)
	        {
			return 0;
		}
	}
	return 1 ;
}     




/*int got_name(AddressBook *addressBook,char *name) 
{

	for(int i=0;i<addressBook->contactCount;i++)

	{  
		if(strcmp(addressBook->contacts[i].name,name)==0)
		{
			return i;
		}

	}
	return -1 ;


}
int get_number(AddressBook *addressBook,char *mobile)
{
	for(int i=0;i<addressBook->contactCount;i++)
	{
		if(strcmp(addressBook->contacts[i].phone,mobile)==0)
		{
			return i;
		}

	}
	return -1 ;
}
int get_email(AddressBook *addressBook,char *email)
{
	for(int i=0;i<addressBook->contactCount;i++) 
	{     

		if(strcmp(addressBook->contacts[i].email,email)==0)
		{
			return i;
		}  

	} 
	return -1 ;
}*/



void listContacts(AddressBook *addressBook ) 
{
        if(addressBook -> contactCount ==0)
        {
           printf("no contacts to display.\n");
           return;
        }
   
	printf("\nContacts List:\n");
        printf("name\tmobile\tgmail\n");

	for(int i=0;i<addressBook->contactCount;i++)
	{ 
		printf("%d %s\t%s\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
	} 

}

void initialize(AddressBook *addressBook)
{

	addressBook->contactCount = 0;
	populateAddressBook(addressBook);
	openfile(addressBook);
	loadContactsFromFile(addressBook);
	printf("HELLO");
	// Load contacts from file during initialization (After 
	{ // Save contacts to file
	  //	exit(EXIT_SUCCESS); // Exit the program
	}
}
void createContact(AddressBook *addressBook)
{
	if(addressBook->contactCount >= 100)
	{  
		printf("AddressBook fill\n");
		return;
	}
        int create_name,create_mobile,create_email;

label1:
	

		printf("enter the name:");
		scanf(" %[^\n]",addressBook -> contacts[addressBook -> contactCount].name);
                getchar();
		create_name = valid_fun(addressBook , addressBook -> contacts[addressBook -> contactCount].name);
                if(create_name == 0)
		{
			printf("invalid input .please enter a alphabet characters only...!\n");
                        goto label1;
		}
               else if(create_name == -1)
               {
		   printf("name is already exists please enter other name...!\n");
                   goto label1;
               }
	
label2:
	

		printf("enter the mobile:");
		scanf("%[^\n]",addressBook -> contacts[addressBook -> contactCount].phone);
                getchar();
		create_mobile = check_phone(addressBook , addressBook ->contacts[addressBook -> contactCount].phone);
                if(create_mobile == 0)
		{
			printf("invalid input.please enter a digits only ...!\n");
                        goto label2; 
		}
                else if(create_mobile == -1)
                {
		       printf("Duplicate phone is already exists please enter other phone number...!\n");
                       goto label2;
               }
	
label3:
	
		printf("enter email:");
		scanf("%s",addressBook -> contacts[addressBook -> contactCount].email);
                getchar();
		create_email = read_id(addressBook , addressBook ->contacts[addressBook -> contactCount].email);
                if(create_email == 0)
		{
			printf("invalid input  .please enter valid email id only ...!\n");
                        goto label3;
		}
                else if(create_email == -1)
                {
   
                          	printf("duplicate email id is found please enter valid email id...!\n");
                        goto label3;
                }
               addressBook -> contactCount++;
               printf("contact added successfully\n");
}



void searchContact(AddressBook *addressBook) 
{
  int search;
     printf("1.search by a name\n");
     printf("2.search by a mobile\n");
     printf("3.search by a email\n");
     printf("choose the option : ");
     scanf("%d",&search);
 
     char searchcontact[50];
     switch(search)
     {
       case 1:
          printf("enter the name to search: ");
          scanf(" %[^\n]",searchcontact);
          break;
       case 2:
          printf("enter the mobile to search: ");
          scanf(" %[^\n]",searchcontact);
          break;
       case 3:
          printf("enter the email to search: ");
          scanf(" %[^\n]",searchcontact);
           break;
        default:
          printf("Invalid option.\n");
          return;
     }

   for(int i=0;i<addressBook->contactCount;i++)
   {
     if((search == 1 && strcmp(addressBook->contacts[i].name,searchcontact)==0) ||
        (search == 2 && strcmp(addressBook->contacts[i].phone,searchcontact)==0) ||
        (search == 3 && strcmp(addressBook->contacts[i].email,searchcontact)==0))
     {
      printf("----------------------------------------------------------------\n");
      printf("\t\tCONTACT\n");
      printf("----------------------------------------------------------------\n");
      printf("name\t\t: %s\nemail Address  : %s\nmobile no. \t: %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);      printf("-----------------------------------------------------------------\n");
      return;
    }
  }
  printf("contact not found.\n");
}



void editContact(AddressBook *addressBook)
{
        if(addressBook->contactCount <= 0)
        {
         printf("No contacts avaliable to edit.\n");
         return;
        }
        int foundindices[100];
        int foundcount = 0;
        printf("search by:\n1");
        printf("1.name\n");
        printf("2.mobile\n");
        printf("3.email\n");
        printf("select an option:\n");
        int searchchoice;
        scanf("%d",&searchchoice);
        char name[50],phone[11],email[50];
   
        switch (searchchoice)
        {
          case 1:
                printf("enter the name: ");
                scanf(" %[^\n]",name);
                 int index = valid_fun(addressBook,name);
                  if(index == 1)
                  {
                     printf("contact not found ");
                      return;
                  }

                /*if(!valid_fun(addressBook,name))
                {
                    printf("invalid name format.\n");
                    return;
                }*/
               for(int i=0;i<addressBook->contactCount;i++)
               {  
                   if(strcmp(addressBook->contacts[i].name,name)==0)
                    {
                        foundindices[foundcount++] = i;
                    }
              }
              break;
          case 2:
               printf("enter mobile:\n");
               scanf("%s",phone);
               if(!check_phone(addressBook,phone))
               {
                    printf("invalid mobile number format.\n");
                    return;
               }
               for(int i=0;i<addressBook->contactCount;i++)
                { 
                        if(strcmp(addressBook->contacts[i].phone,phone)==0)
                         {     
                                 foundindices[foundcount++] = i;
                         }
               }
              break;
          case 3:
             printf("enter email:\n");
             scanf("%s",email);
            if(!read_id(addressBook,email))
             {
               printf("invalid emailformat.\n");
               return;
             }
             for(int i=0;i<addressBook->contactCount;i++)
               {
                   if(strcmp(addressBook->contacts[i].email,email)==0)
                    { 
                       foundindices[foundcount++] = i;
                    }
               }
                  break;
            default:
               printf("invalid option\n");
               return;
         }
         if(foundcount == 0)
         {
           printf("contact not found\n");
           return;
         }
         printf("found %d matching contacts :\n",foundcount);
           for(int i=0;i<foundcount;i++)
            {
                printf("%d %s %s %s\n",i+1,addressBook->contacts[foundindices[i]].name,addressBook->contacts[foundindices[i]].phone,
                                                      addressBook->contacts[foundindices[i]].email);
            }


          int editchoice;
          printf("\nenter the number corresponding to contact you want to edit:\n");
          scanf("%d",&editchoice);
          editchoice--;

               if(editchoice >=0 && editchoice < foundcount)
               {
                 int indextoedit = foundindices[editchoice];
             

                 int change;
                 printf("\n select the choice you want to edit:\n1. name\n2. mobile\n3. email\n");
                 
                 scanf("%d",&change);
                switch(change)
                  {
                   case 1:
                      {
                       char newname[50];
                       printf("enter new name:");
                       scanf(" %[^\n]",newname);
                      if(strlen(newname)>0 && valid_fun(addressBook,newname))
                      {
                         strcpy(addressBook->contacts[indextoedit].name,newname);
                         printf("name updated successfully.\n");
                     }
                     else
                     {
                            printf("invalid name format.\n");
                     }
                     break;
                    }
                  case 2:
                   {
                      char newmobile[50];
                      printf("enter newmobile:");
                      scanf("%10s",newmobile);
                      if(strlen(newmobile)>0 && check_phone(addressBook,newmobile))
                      {
                         strcpy(addressBook->contacts[indextoedit].phone,newmobile);
                         printf("name updated successfully.\n");
                      }
                     else
                     {
                        printf("invalid mobile number format.\n");
                     }
                     break;
                   }
                   case 3:
                   {
                     char newemail[50];
                     printf("enter newemail:");
                     scanf("%s",newemail);
                     if(strlen(newemail)>0 && read_id(addressBook,newemail))
                     {
                         strcpy(addressBook->contacts[indextoedit].email,newemail);
                         printf("email updated successfully.\n");
                     }
                     break;
                   }
                   default:
                       printf("invalid option.\n");
                 }
              }
                   else
                    {
                        printf("invalid choice.\n");
                    }
 }
	/*int found=-1,search,getindex;
	char name[100],mobile[100],email[100],edit_name[100],edit_mobile[100],edit_email[100];
	printf("Enter 1.edit by name\n2.edit by mobile\n3. edit by email\n");
	scanf("%d",&search);
	getchar();

	switch(search) 
	{
label1:
		case 1:
			printf("Enter name");
			scanf("%[^\n]",name);
			if(valid_fun(addressBook,name))
			{
				found=got_name(addressBook,name);
				if(found >1)
				{      
					printf("\nsimilar contact names found , so please enter phone number\n");
					scanf("%s",mobile);

					for(int i=0;i<addressBook->contactCount;i++)
					{
						if (strcmp(addressBook->contacts[i].name,name) == 0 && strcmp(addressBook->contacts[i].phone,mobile)==0)
						{
							getindex = i;
							break;
						}
					}
					if(getindex == -1)
					{
						printf("contact not found \n\n");
						return;
					}
				}
				else if( found == 1)
				{ 
					for(int i=0;i<addressBook->contactCount;i++)
					{
						if (strcmp(addressBook ->contacts[i].name,name)==0)
						{
							getindex = i;
						}
					}
				}
			}

			else
			{
				printf("Ivalid name please enter name,mobile,email");

				goto label1;
			}
			break;
     
label2:
		case 2:
			printf("Enter mobile");
			scanf("%s",mobile );
			if(check_phone(addressBook,mobile))
 
			{
                           found = get_number(addressBook,mobile);
                                
                                  
                               	if(found == -1)
				{
					printf("contact not found\n\n");
                                       break;
				}
                        }


				else
				{
					printf("please enter name,mobile,email");
                                        goto label2;

				}
                               break;
			
label3:
		case 3:
			printf("Enter email");
			scanf("%s",email);
			if(read_id(addressBook,email))
			{
                            
				found = get_email(addressBook,email);
                                
                                  
                        	if(found == -1)
				{
					printf("contact not found\n\n");
                                        break;
				}

                        }
				else
				{
					printf("please enter name,mobile,email");
                                        goto label3;

				}
			break;
		default:
			
				printf("Invalid input please enter 1 or 2 or 3\n\n");
                                goto label3;
			

	}
label9:
   
	int edit;
	printf("enter 1.name\n2.mobile\n3. email\n");
	scanf("%d",&edit);
        getchar();
	switch(edit)
	{

		case 1:
label4:
			printf("enter edit_name");
			scanf("%[^\n]",edit_name);
			if(valid_fun(addressBook,edit_name)==1)

			{

				strcpy(addressBook->contacts[found].name,edit_name);
				printf("upadtaed successfully");
			}
			else if(found == 1)
			{
				for(int i=0;i<addressBook->contactCount;i++)
                                {
                                     if(strcmp(addressBook->contacts[i].name,edit_name)==0)
                                     {
				       getindex = i;
                                         break;
                                     }
                                }
			}
                       else
                       {
                              printf("contact not found\n");  
                              return;
                        }
                      else
                       {
                              printf("invalid name . please enter valid name only\n\n");
                               goto label1;
                       }
		case 2:
label5:
			printf("Enter mobile");
			scanf("%s",mobile);
			if(check_phone(addressBook,mobile ))
			{
                               found = get_number(addressBook,mobile);
                                if(found == -1)
                                {
				   printf("contact not found\n\n");
                                   break;
                                }
                        }
	               else
                                {
                                   printf("Invalid mobile number.please enter valid mobile number\n\n");
                                }
                       

			else
			{
			 	strcpy(addressBook ->contacts[getindex];
				goto label2;
			}
                      break;
              case 2:
label6:
                     printf("enter edit_mobile");
                     scanf("%s",edit_mobile);
                     if(check_phone(addressBook , edit_mobile)==1)
                     {
                        if (get index != -1)
                        {
                            strcpy(addressBook->contacts[found].mobile,edit_mobile);
                         }
                       else
                       {
                            strcpy(addressBook->contacts[found].mobile,edit_mobile);
                       }
                    }
                    else
                    {
                          printf("invalid phone number or duplicate number enter valid mail\n\n");
                           goto label6;
                    }
                   break;

				

		case 3:
label7:
			printf("Enter edit_ email");
			scanf("%s",edit_email);
			if(read_id(addressBook,edit_email)==1)
			{
                                if(getindex != -1)
                                {
				   strcpy(addressBook->contacts[getindex].email,edit_email);
                                }
                            printf("email updated successfully\n\n");
                        }
	

			else
			{
			 	printf("invalid email id please enter valid email\n\n");
				goto label7;
			}

                      break;
                  default:
                              printf("invalid input please enter 1 or 2 or 3 \n");
                               goto label9;
				
                
                      
	}
}*/
void deleteContact(AddressBook *addressBook)
{
       int option;
      printf("choose the option:\n");
     printf("1.Delete by name\n");
     printf("2.Delete by phone\n");
     printf("3.Delete by email\n");
     scanf("%d",&option);
     getchar();//it clears a new line while the input gives buffer
     char searchkey[100];
      printf("enter the search term to delete:");
      fgets(searchkey, sizeof(searchkey),stdin);
      searchkey[strcspn(searchkey,"\n")] = '\0';

       for(int i =0;i<addressBook->contactCount;i++)
       {
             int found = 0; 
             switch(option)
             {
               case 1:
                   found = strcmp(addressBook->contacts[i].name,searchkey)==0;
                   break;
               case 2:
                   found = strcmp(addressBook->contacts[i].phone,searchkey)==0;
                   break;
              case 3:
                   found = strcmp(addressBook->contacts[i].email,searchkey)==0;
                   break;
              default:
                    printf("Invalid option:\n");
                    return;
            }
            if (found)
            {
             //shift contacts to fill the gap
             for(int j=i;j<addressBook->contactCount-1;j++)
             {
                addressBook->contacts[j] = addressBook->contacts[j+1];
             }
            addressBook->contactCount--; 
            printf("contact deleted successfully!\n");
            return;
           }
       }
       printf("contact not found.\n");
}


	

				
			
		
		


