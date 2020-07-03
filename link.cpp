#include <fstream>
#include <iostream>
using namespace std;

//Singly linked list implementation 
class LinkList
{
	LinkList *next;
	int data;
public:
	LinkList * ifirst(LinkList *, int term);
	void traverse(LinkList *);
	LinkList * ilast(LinkList *, int term);
	void del(LinkList *, int Connor);
	int countList(LinkList *temp);
	void b_sort(LinkList *temp, int size);
};

LinkList * LinkList::ifirst(LinkList *temp, int term)// function is used to enter the element at the beginning of the link list
{
	LinkList *newlink;
	newlink=new LinkList;
	newlink->data = term;
	newlink->next=temp;
	temp=newlink;
	return temp;
}

void LinkList::traverse(LinkList *temp) //traverses the link list and prints the numbers in a link list from start(head) to end(tail)
{
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}

LinkList * LinkList::ilast(LinkList *temp, int term)// inserts an element at the end of the link list .
{
	LinkList *newlink;
	newlink=new LinkList;
	if (temp==NULL)
	{
		LinkList *newlink;
		newlink=new LinkList;
		newlink->data = term;
		newlink->next=temp;
		temp=newlink;		
	}
	else
	{
		LinkList *cur;
		cur=temp;
		while(cur->next!=NULL)
		{
			cur=cur->next;
		}
		cout<<"\nEnter Data :";
		cin>>newlink->data;
		newlink->next=NULL;
		cur->next=newlink;		
	}
	return temp;
}

int LinkList::countList(LinkList *temp)//Counts number entries in linked list
{
	int incre = 0;
	while(temp!=NULL)
	{
		temp=temp->next;
		incre++;
	}
	return incre;
}

void LinkList::del(LinkList *temp, int Connor) //<-This is the deletion function defintion, Connor is the value that is to be TERMINATED
{											   //This function cannot delete the head node of a linked list
	LinkList *tempD;
	while(temp!=NULL)//Checks to see if current node is NULL
	{	
		if(temp->data == Connor)//Checks node to see if data is the deleting value
		{						
			tempD = temp;
			temp = temp->next;
			delete(tempD);
		}
		if(temp->next->data == Connor)//Checks to see if next node has deleting value
		{
			tempD = temp->next;
			temp->next = tempD->next;
			delete(tempD);
		}
		temp = temp->next;//Advances position as in the traverse function
	}
}

void LinkList::b_sort(LinkList *temp, int size) //This function perfomrs the actual bubble sorting
{													  //Pre-condition: the head pointer and size can be read 
	int tmp; //temporary value holder
	LinkList *head, *tempN;
	head = temp; //head pointer
	tempN = temp->next; //next pointer

	bool not_sorted = true;	
	{
		while (not_sorted)  
		{ 
			not_sorted = false;  
			for (int i = 0; i < size - 1; i++) 
			{ 
				if(temp->next == NULL)//Checks to see if next value is NULL, and if so reset the pointers back to the beginning of the list
					{
						temp = head;
						tempN = temp->next;
					}

				if (temp->data > tempN->data)//Checks to see if initial value is greater than next value and if so swap places
					{						  
						tmp = temp->data;		 
						temp->data = tempN->data; 
						tempN->data = tmp;
						not_sorted = true;
					}
				temp = temp->next; //incrementation of pointers
				tempN = tempN->next;
			}
		}
	}
}

int main()
{
	LinkList *first=NULL,l1;
	int choice;
	ifstream getnum;
	int input;
	int count = 0;
	int destroy;
	getnum.open("input.txt");
	if (getnum.fail())
    {
        cerr << "Could Not open ' 'input.txt' '";
        return 0;
    }

	while(getnum >> input)
	{
		first = l1.ifirst(first, input);
	}
	l1.traverse(first);
	count = l1.countList(first);
	cout << "There are " << count << " nodes in the list" << endl;
	cout<<"Choices Are :-\n=> [1] For sorting\n=> [2] For Deleting\n";
	cout<<"\n\nEnter Your choice : ";
	cin>>choice;
	switch (choice)
		{
		case 1:
			l1.b_sort(first, count);
			l1.traverse(first);
			return 0;
		case 2:
			cout << "Enter a value you would like terminated from the list: ";
			cin >> destroy;
			l1.del(first, destroy);
			l1.traverse(first);
			return 0;
		}
}
