/*  
Student record system using linked list
data structure.
*by Ermias Antigegn
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct student
{
	string ID;
	string name;
	string fatherName;
	string sex;
	float CGPA;

	student *next;
};
student *Head = NULL;


void Add_newNode(int position);
void del_accademicDismisal();
void searchName(string keyWord);
void sort();
void Display();
int main()
{
       cout<<"\n\n\t\t                                             WELL COME!                   \n"    ;
       cout<<"\t\t ========================= STUDENT LINKED LIST DATA STRUCTURE IMPLEMENTATION ========================\n\n\n";
       cout<<"                               Choose your operation from the list below.\n\n";
	int check=0;
                  choice:
	do
	{
	    cout<<"\t\t\t\t||\n\t\t\t\t||\n";
	cout<<"\t\t\t\tPress 1 to add the node in the linked list."                                   <<endl;
     cout<<"\t\t\t\tPress 2 to display data ."                                                      <<endl;
      cout<<"\t\t\t\tPress 3 to delete node that has student with academic dismissal(CGPA <  1.7)."   <<endl;
       cout<<"\t\t\t\tPress 4 to search the node in the linked list by the name."                       <<endl;
        cout<<"\t\t\t\tPress 5 to sort the node in the linked list by the name."                          <<endl;
         cout<<"\t\t\t\tPress 0 to Exit the system."                                                       <<endl;
          cout<<"\t\t\t\t||\n\t\t\t\t||\n";

          cout<<"Please Enter your choice here: ";
      cin>>check;
      while(cin.fail())
      {
          system("cls");
          cin.clear();
          cin.ignore();
          cout<<"Invalid choice.\nPlease try again."<<endl;
          goto choice;
      }

	if(check == 1)
	{
	    int n;
	    int i = 0;
	    cout<<"Enter number of students you want to add:";
	    cin>>n;
	    while(i < n)
        {

	   int position;
	   cIn:
	   cout<<"\t\tEnter position: ";
	   cin>>position;
	   while(cin.fail())
       {
	   system("cls");
	   cin.clear();
	   cin.ignore();
	   cout<<"\t\tYou have entered invalid choice.\n\t\tPlease try again.\n\n";
	   goto cIn;
       }

	   Add_newNode(position);
	   i++;
    }
	}

	   else if(check == 2)
       {

	   Display();
       }

	   else if(check == 3)
	   del_accademicDismisal();

	   else if(check == 4)
	   {
	   	string keyWord;
	   	cout<<"\n\n\t\tEnter name you want to be search: ";
	   	cin>>keyWord;
	   	searchName(keyWord);
	   }

	   else if(check == 5)
	   sort();
	}while(check!=0);
	if(check == 0)
        {
        cout<<"\n\n\t\t\t*********************************  THANK YOU  ****************************************\n\n";
	    }


	return 0;

}



void Add_newNode(int position)
{
	student *newNode = new student;
     cInID:
         cout<<"\n\n\t\tStore student data here:\n\n";
	cout<< "Enter ID:";
	cin>>newNode->ID;
    while(cin.fail())
    {
        system("cls");
        cin.clear();
        cin.ignore();
        cout<<"Invalid input.\n\t\tPlease try again.\n\n";
        goto cInID;
    }
		cout<< "Enter Name:";
	cin>>newNode->name;

		cout<< "Enter Father Name:";
	cin>>newNode->fatherName;

		cout<< "Enter Sex:";
	cin>>newNode->sex;
             cInCGPA:
		cout<< "Enter CGPA:";
	cin>>newNode->CGPA;
       while(cin.fail())
    {
        system("cls");
        cin.clear();
        cin.ignore();
        goto cInCGPA;
        cout<<"Invalid input.\n\t\tPlease try again.\n\n";
        goto cInCGPA;
    }
	  newNode ->next =NULL;

	if(position < 1)
{
     cout<<"Invalid position\n\n"<<endl;
}

else if(position == 1)
   {
       newNode->next = Head;
     Head = newNode;
     cout<<"\n\n\t\tNode added successfully as Head.\n\n";
}

else
{
    student *temp = Head;
      for(int i = 1; i < position-1; i++)
{
if(temp != NULL)
{
   temp = temp->next;
     }
}
if (temp !=NULL)
{
newNode->next = temp->next;
temp->next = newNode;
cout<<"\n\n\t\tNod added successfully at position "<<position<<".\n\n";
}
else
{
   cout<<"The previous node is null."<<endl;
}
}
}

void del_accademicDismisal()
{
	student *deletingNode;
	while(Head != NULL && Head->CGPA <= 1.7)
	{
		deletingNode = Head;
	     Head = Head->next;
	     free(deletingNode);
	     cout<<"Head deleting successfully."<<endl;
	}
		student *temp = Head;
		if(temp != NULL)
		{
		while(temp->next != NULL)
		{
			if( temp->next->CGPA<1.7)
			{
			deletingNode = temp->next;
			temp->next = temp->next->next;
			free(deletingNode);
			cout<<"\n\nNode deleted successfully.\nYou can use Display option to see the result.\n\n"<<endl;
			break;
		}

	else
	{
	 temp = temp->next;
	         }
         }
     }
     else
        cout<<"\n\t\tThere is no node\n\n";
}

void searchName(string keyWord)
{
		student *temp = Head;
		if(temp != NULL)
		{ 
              cout<<"\n\n\t\tDisplaying your searching result:\n\n";
		while(temp != NULL)
	  	 {
		if(temp->name == keyWord)
			{
                 cout<<"ID: "<<temp->ID                <<endl;
		          cout<<"Name: "<<temp->name              <<endl;
		           cout<<"Father Name: "<<temp->fatherName  <<endl;
                    cout<<"Sex: "<<temp->sex                  <<endl;
                     cout<<"CGPA: "<<temp->CGPA                  <<endl;				
			    break;
			}
		 	   else
               {
				 temp = temp->next;
            }
		}
    }

    else
    cout<<"\n\n\t\tNode with "<<keyWord<<" is not found\n\n"<<endl; 
}

void sort()
   {
     student *temp1;
     student *temp2;
     if(Head == NULL)
     cout<<"\n\n\t\tThere is no linked list.\n\n"<<endl;
       else
       {
           for(temp1 = Head; temp1 != NULL; temp1 = temp1->next)
           {
           	for(temp2 = temp1->next; temp2 != NULL; temp2= temp2->next)
           	{
           		if(temp1->name > temp2->name)
           		{
                    swap(temp1->ID,temp2->ID);
           			swap(temp1->name,temp2->name);
           			swap(temp1->fatherName,temp2->fatherName);
           			swap(temp1->sex,temp2->sex);
           			swap(temp1->CGPA,temp2->CGPA);

				   }
			   }
		   }
		   cout<<"\n\n\t\tThe node sorted by name successfully.\n\t\tYou can use display option to see the sorted list.\n\n ";
       }
   }

void Display()
{

		student *temp = Head;
	if(Head == NULL)
	{
	cout<<"\n\n\t\tTheir is no linked list.\n\n"<<endl;     }
	else
	{
	    cout<<"\n\n\t\tDisplaying student data:\n\n";
	while(temp != NULL)
	{
		cout<<"\t\tID: "<<temp->ID                                   <<endl;
		 cout<<"\t\tFull Name: "<<temp->name <<" "<<temp->fatherName   <<endl;
		   cout<<"\t\tSex: "<<temp->sex                                  <<endl;
		    cout<<"\t\tCGPA: "<<temp->CGPA<<endl<<endl                     <<endl;
                     temp = temp->next;
		}
    }
}
