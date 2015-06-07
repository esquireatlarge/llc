//Filename: list.cpp
//Author:  EsquireAtLarge
//Date written: April 29th, 2008
//Class description:  Contains function definitions for list.h file.
//Function definitions to determine if list is empty or full, and if the 
//list needs to be destroyed or updated.

template <typename T>
list<T>::list()
//Constructor
//Precondition:  None
//Postcondition: Sets head to NULL.
{
	head = NULL;
}//end constructor

template <typename T>
list<T>::list(const list<T>& clist)
//Copy constructor
//Precondition:  Intakes an instance of list.
//Postcondition:  Calls the copylist function.
{
	copyList(clist);
}

template <typename T>
list<T>::~list()
//Destructor
//Precondition:  Destructor to deallocate list's space in memory.
//Postcondition:  Calls function to destroy the list.
{
	destroyList();
}

template <typename T>
bool list<T>::isEmpty() const
//Precondition:  None
//Postcondition: Returns boolean value to determine if head is equivalent
//to NULL, indicating that there are no nodes in the list.
{
	return bool(head==NULL);
}//end function

template <typename T>
void list<T>::destroyList()
//Precondition:  None
//Postcondition: Clears the list and destroys the nodes.
{
	node* cur = head;

	//Delete list
	while(cur!=NULL){
		//Head points to node after one cur points to
		head = head->next;
		delete cur;
		cur = head;
	}
		
}//end function

template <typename T>
ostream& operator<<(ostream& out, const list<T>& l)
//Precondition: l is a constant of type list, while out is lefthand operand. 
//Postcondition: Outputs a list of items in sorted order.
{	
	struct list<T>::node* cur = l.head;

	//While not and end of list
	while(cur != NULL){
		//Output the node items.
		out << cur->p;
		cur = cur->next;	
	}
	return out;		
}//end function

template <typename T>
void list<T>::insert(const T& p) throw (ListException)
//Precondition:  The item to be inserted is passed as an argument.
//Postcondition:  An exception occurs if the list is full or
//the item is a duplicate.  If no errors arise, the item is inserted
//in the proper place after it is compared to other existing elements
//within the list.
{
	node *cur = head, *prev = NULL;	
	//Locate position in list for insert.
	while(cur != NULL && cur->p < p){
		prev = cur;
		cur = cur->next;
	} 
	//Check for duplicate
	while(cur !=NULL && cur->p == p) 
		throw ListException("Duplicate item.");
	//Allocate space
	node* newPtr = new node;
	if(newPtr == NULL)
		throw ListException("Cannot allocate memory.");
	//Insert node
	newPtr->p=p;
	//Head insert
	if(cur==head){
		newPtr->next = head;
		head = newPtr;
	}
	else{ //Not a head insert
		newPtr->next=prev->next;
		prev->next=newPtr;
	}
}

template <typename T>
void list<T>::retrieve(T & p) const throw(ListException)
//Precondition:  Intakes an item's specifications.
//Postcondition:  Sets p equal to the item found in the list, if any.
{
	node* cur = head;
	//Locate item
	while(cur != NULL && cur->p < p){
		cur = cur->next;
	}
	if(cur!= NULL && cur->p == p)
		p = cur->p;
	else //Not found
		throw ListException("Item not found.");
}

template <typename T>
void list<T>::remove(T & p) throw(ListException)
//Precondition: Intakes an item's specifications.
//Postcondition: Removes an item through left shift logic.
{
	node* cur = head, *prev = NULL;
	//Locate node with item to remove.
	while(cur != NULL && cur->p<p){
		prev = cur;
		cur = cur-> next;
	}
	if(cur != NULL && cur->p == p){
		//Item found
		if(prev == NULL){ //Head removal, also cur = head.
			head = head->next; //or head = cur->next.
			//Head now points to the node after the first 
			//node.
		}
		else{ //Not a head removal
			prev->next = cur->next;
			//Change pointer from node before one to be deleted 
			//to point to node after one to be deleted.
		
		}
	}
	else //Item not found
		throw ListException("Item not found.");
	delete cur;
}

template <typename T>
void list<T>::copyList(const list<T>& l)
//Precondition:  Intakes original list.
//Postcondition:  Returns the copy of the list.
{
	if(l.head == NULL)
			//Original list is empty
			head = NULL;
	else{
		//Copy first node.
		head = new node;
		//If it ends up that an empty list is being copied,
		//crash the program.
		assert(head != NULL);
		//Copy first pointer
		head->p = l.head->p;

		//Copy the rest of the list.
		node* newPtr = head;
		for(node* origPtr = l.head->next; origPtr != NULL;
			 origPtr = origPtr->next)
		{
			newPtr->next = new node;
			assert(newPtr->next != NULL);
			newPtr = newPtr->next;
			newPtr->p=origPtr->p;
		}
		//Sent ending for new list.
		newPtr->next = NULL;

	}
}

template <typename T>
const list<T>& list<T>::operator=(const list<T>& rhs)
//Precondition:  Intakes an instance of list.
//Postcondition:  Makes a deep copy of a list.
{
	if(this != &rhs)
		//Deallocate left-hand side;
		destroyList();
	copyList(rhs);

	return *this;
}

template <typename T>
void list<T>::print_reverse_list() const throw(ListException)
//Precondition:  None
//Postcondition: Calls the print_reverse function, which then
//performs a recursive print of the list in reverse order.
{
	if(head == NULL)
		throw ListException("The list is empty.");
	else{
		print_reverse(head);
	}
}

template <typename T>
void list<T>:: print_reverse(node* nodeptr) const{
	if(nodeptr == NULL)
		return;
	else{
		print_reverse(nodeptr->next);
	}
	cout << nodeptr->p;
	return;
}
