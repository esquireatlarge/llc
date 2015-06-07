//Filename:  list.h
//Author:  EsquireAtLarge
//Date written:  April 29th, 2008
//Class description:  Contains function declarations for list containing
//items.

#pragma once
#include "ListException.h"
#include "pet.h"
#include <iostream>
using namespace std;

template <typename T>
class list;
//Contains function declarations for a list containing items.

template <typename T>
ostream& operator<<(ostream&, const list<T>&);

template <typename T>
class list{

	friend ostream& operator<< <>(ostream&, const list<T>&);
	//Precondition:  Intakes an instance of list.
	//Postcondition:  Outputs the items of the list in sorted order.

public:
	list();
	//Constructor
	//Precondition: None
	//Postcondition: Sets head to null.
	
	list(const list<T>& clist);
	//Copy constructor
	//Precondition:  Intakes an instance of list.
	//Postcondition:  Calls the copylist function.

	~list();
	//Destructor
	//Precondition:  Destructor to deallocate list's space in memory.
	//Postcondition:  Calls function to destroy the list.

	bool isEmpty() const;
	//Precondition: None
	//Postcondition: Returns boolean value to determine if head is
	//equivalent to NULL, meaning that the list contains no items.
	
	void destroyList();
	//Precondition:  None
	//Postcondition:  Clears list and deletes each node.
	void copyList(const list& l);
	//Precondition:  Intakes original list.
	//Postcondition:  Returns the copy of the list.

	void insert(const T& p) throw(ListException);
	//Precondition:  The item to be inserted is passed as an argument.
	//Postcondition:  An exception occurs if the list is full or
	//the item is a duplicate.  If no errors arise, the item is inserted
	//in the proper place after it is compared to other existing elements
	//within the list.
	
	void retrieve(T & p) const throw(ListException);
	//Precondition:  Intakes item species and name.
	//Postcondition:  Sets p equal to the item found in the list, if any.

	void remove(T & p) throw(ListException);
	//Precondition: Intakes an item's specifications.
	//Postcondition: Removes the item through left shift logic.

	const list& operator=(const list<T>& rhs);
	//Precondition:  Intakes an instance of list.
	//Postcondition:  Makes a deep copy of a list by calling
	//copylist function.
	
	void print_reverse_list() const throw(ListException);
	//Precondition:  None
	//Postcondition: Calls the print_reverse function, which then 
	//performs a recursive print of the list in reverse order.


private:
        struct node{
                T p;
                node* next;

        };
	
	node*head;
	void print_reverse(node* nodeptr) const;
	//Precondition: Intakes a node pointer.
	//Postcondition: Prints the item of the node pointer
	//and then moves back and repeats recursively.
};

#include "list.cpp"
