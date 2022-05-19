//////////////////////////////////////////////////////////
//
//	Standard Template Library using C++
//
/////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

typedef int BOOL;

template<typename T>
struct node
{
	T data;
	struct node* next;
	struct node* prev;
};

//typedef struct node NODE;
//typedef struct node* PNODE;

template<class T>
class Singly_LinkedList
{
private:
	node<T>* first;
	int size;

public:
//////////////////////////////////////////////////////////
//
//	Singly Linear LinkedList using C++
//
/////////////////////////////////////////////////////////
	Singly_LinkedList();
	~Singly_LinkedList();
	BOOL InsertFirst(T);
	BOOL InsertLast(T);
	BOOL InsertAtPos(int, T);
	BOOL DeleteFirst();
	BOOL DeleteLast();
	BOOL DeleteAtPos(int);
	inline void Display();
	inline int Count();
};

//////////////////////////////////////////////////////////
//
//	Doubly Linear LinkedList using C++
//
/////////////////////////////////////////////////////////
template<class T>
class Doubly_LinkedList
{
private:
	node<T>* Head;
	int size;

public:
	Doubly_LinkedList();
	~Doubly_LinkedList();
	BOOL InsertFirst(T);
	BOOL InsertLast(T);
	BOOL InsertAtPos(int, T);
	BOOL DeleteFirst();
	BOOL DeleteLast();
	BOOL DeleteAtPos(int);
	inline void Display();
	inline int Count();
};

//////////////////////////////////////////////////////////
//
//	Singly Circular Linear LinkedList using C++
//
/////////////////////////////////////////////////////////
template<class T>
class SinglyCircular_LinkedList
{
private:
	node<T>* first;
	node<T>* last;
	int size;

public:
	SinglyCircular_LinkedList();
	~SinglyCircular_LinkedList();
	BOOL InsertFirst(T);
	BOOL InsertLast(T);
	BOOL InsertAtPos(int, T);
	BOOL DeleteFirst();
	BOOL DeleteLast();
	BOOL DeleteAtPos(int);
	inline void Display();
	inline int Count();
};

//////////////////////////////////////////////////////////
//
//	Doubly Circular Linear LinkedList using C++
//
/////////////////////////////////////////////////////////
template<class T>
class DoublyCircular_LinkedList
{
private:
	node<T>* first;
	node<T>* last;
	int size;

public:
	DoublyCircular_LinkedList();
	~DoublyCircular_LinkedList();
	BOOL InsertFirst(T);
	BOOL InsertLast(T);
	BOOL InsertAtPos(int, T);
	BOOL DeleteFirst();
	BOOL DeleteLast();
	BOOL DeleteAtPos(int);
	inline void Display();
	inline int Count();
};

//////////////////////////////////////////////////////////
//
//	 Create a Stack 
//
/////////////////////////////////////////////////////////
template<class T>
class Stack
{
private:
	node<T>* first;
	int size;

public:
	Stack();
	~Stack();
	BOOL Stack_Push(int);
	int Stack_Pop();
	inline void Display();
	inline int Count();
};


/////////////////////////////////////////////////////////
//
//	 Create a Queue 
//
/////////////////////////////////////////////////////////
template<class T>
class Queue
{
private:
	node<T>* first;
	int size;

public:
	Queue();
	~Queue();
	BOOL Enqueue(int);
	int Dequeue();
	inline void Display();
	inline int Count();
};


/*---------------------------------------------------------------------------------------------------*/

//////////////////////////////////////////////////////////
//
//	Singly Linear LinkedList using C++
//	Auther :- Saurabh Rama Nale
//	Date :- 19/11/2021
//	Input :- User define
//	Output : ..............
//	Descrition :- User use the class to create LinkedList 
//
/////////////////////////////////////////////////////////
template<class T>
Singly_LinkedList<T>::Singly_LinkedList()
{
	first = NULL;
	size = 0;
}

template<class T>
Singly_LinkedList<T>::~Singly_LinkedList()
{
	node<T>* temp = NULL;
	node<T>* Navigate = NULL;

	if(first != NULL){
		Navigate = first;
		while(Navigate != NULL)
		{
			temp = Navigate->next;
			delete Navigate;
			Navigate = temp;
		}
	}
}

template<class T>
BOOL Singly_LinkedList<T>::InsertFirst(T no)
{
	node<T>* newn = NULL;

	newn = new node<T>;
	if(newn == NULL){
		return FALSE;
	}

	newn->next = NULL;
	newn->data = no;

	if(first == NULL){
		first = newn;
	}
	else{
		newn->next = first;
		first = newn;
	}
	size++;

	return TRUE;
}

template<class T>
BOOL Singly_LinkedList<T>::InsertLast(T no)
{
	node<T>* newn = NULL;
	node<T>* temp = first;

	newn = new node<T>;
	if(newn == NULL){
		return FALSE;
	}

	newn->next = NULL;
	newn->data = no;

	if(first == NULL){
		first = newn;
	}
	else{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
	size++;

	return TRUE;
}

template<class T>
BOOL Singly_LinkedList<T>::InsertAtPos(int iPos, T no)
{
	if((first == NULL)||(iPos > size +1)||(iPos <= 0))
	{
		return FALSE;
	}
	if(iPos == 1){
		return(InsertFirst(no));
	}
	else if(iPos == size+1){
		return(InsertLast(no));
	}
	else{
		node<T>* newn = NULL;
		node<T>* temp = first;

		newn = new node<T>;
		if(newn == NULL){
			return FALSE;
		}

		newn->next = NULL;
		newn->data = no;

		for(int i = 1; i <= iPos-2; i++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		temp->next = newn;
	}
	size++;

	return TRUE;
}

template<class T>
BOOL Singly_LinkedList<T>::DeleteFirst()
{
	node<T>* temp = first;

	if(first == NULL){
		return FALSE;
	}
	else{
		first = first->next;
		delete temp;
	}
	size--;

	return TRUE;
}

template<class T>
BOOL Singly_LinkedList<T>::DeleteLast()
{
	if(first == NULL){
		return FALSE;
	}
	else if(first->next == NULL)
	{
		delete first;
		first = NULL;
	}
	else{
		node<T>* temp1 = first;
		node<T>* temp2 = NULL;

		while(temp1->next->next != NULL)
		{
			temp1 = temp1->next;
		}

		temp2 = temp1->next;
		temp1->next = NULL;
		delete temp2;
	}
	size--;

	return TRUE;
}

template<class T>
BOOL Singly_LinkedList<T>::DeleteAtPos(int iPos)
{
	if((first == NULL)||(iPos > size)||(iPos <= 0))
	{
		return FALSE;
	}
	else if(iPos == 1)
	{
		DeleteFirst();
	}
	else if(iPos == size)
	{
		DeleteLast();
	}
	else{
		node<T>* temp1 = first;
		node<T>* temp2 = NULL;

		for(int i = 1; i <= iPos-2; i++)
		{
			temp1 = temp1->next;
			i++;
		}

		temp2 = temp1->next;
		temp1->next = temp2->next;

		delete temp2;
	}
	size--;

	return TRUE;
}

template<class T>
void Singly_LinkedList<T>::Display()
{
	node<T>* temp = first;

	while(temp != NULL)
	{
		cout<<"|"<<temp->data<<"|-> ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

template<class T>
int Singly_LinkedList<T>::Count()
{
	return size;
}
/*---------------------------------------------------------------------------------------------*/

//////////////////////////////////////////////////////////
//
//	Doubly Linear LinkedList using C++
//	Auther :- Saurabh Rama Nale
//	Date :- 19/11/2021
//	Input :- User define
//	Output : ..............
//	Descrition :- User use the class to create LinkedList 
//
/////////////////////////////////////////////////////////

template<class T>
Doubly_LinkedList<T>::Doubly_LinkedList()
{
	Head = NULL;
	size  = 0;
}

template<class T>
Doubly_LinkedList<T>::~Doubly_LinkedList()
{
	node<T>* temp = Head;

	if(Head != NULL){
		while(Head != NULL)
		{
			Head = Head->next;
			delete temp;
			temp = Head;
		}
	}
}

template<class T>
BOOL Doubly_LinkedList<T>::InsertFirst(T no)
{
	node<T>* newn = NULL;

	newn = new node<T>;
	if(newn == NULL){
		return FALSE;
	}

	newn->next = NULL;
	newn->prev = NULL;
	newn->data = no;

	if(Head == NULL){
		Head = newn;
	}
	else{
		Head->prev = newn;
		newn->next = Head;
		Head = newn;
	}
	size++;

	return TRUE;
}

template<class T>
BOOL Doubly_LinkedList<T>::InsertLast(T no)
{
	node<T>* newn = NULL;
	node<T>* temp = Head;

	newn = new node<T>;

	if(newn == NULL){
		return FALSE;
	}

	newn->next = NULL;
	newn->prev = NULL;
	newn->data = no;

	if(Head == NULL){
		Head = newn;
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}

		temp->next = newn;
		newn->prev = temp;
	}
	size++;

	return TRUE;
}

template<class T>
BOOL Doubly_LinkedList<T>::InsertAtPos(int iPos, T no)
{
	if((Head == NULL)||(iPos > size+1)||(iPos <= 0))
	{
		return FALSE;
	}

	if(iPos == 1)
	{
		return(InsertFirst(no));
	}
	else if(iPos == size+1)
	{
		return(InsertLast(no));
	}
	else{
		node<T>* newn = NULL;
		node<T>* temp = Head;

		newn = new node<T>;
		if(newn == NULL){
			return FALSE;
		}

		newn->next = NULL;
		newn->prev = NULL;
		newn->data = no;

		for(int i = 1; i < iPos-1; i++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		temp->next->prev = newn;
		newn->prev = temp;
		temp->next = newn;
	}
	size++;

	return FALSE;
}

template<class T>
BOOL Doubly_LinkedList<T>::DeleteFirst()
{
	node<T>* temp = Head;

	if(Head == NULL){
		return FALSE;
	}
	else{
		Head = Head->next;
		Head->prev = NULL;

		delete temp;
	}
	size--;

	return TRUE;
}

template<class T>
BOOL Doubly_LinkedList<T>::DeleteLast()
{
	if(Head == NULL){
		return FALSE;
	}
	else if(Head->next == NULL)
	{
		delete Head;
		Head = NULL;
	}
	else{
		node<T>* temp = Head;

		while((temp->next) != NULL)
		{
			temp = temp->next;
		}

		temp->prev->next = NULL;
		delete temp;
	}
	size--;

	return TRUE;
}

template<class T>
BOOL Doubly_LinkedList<T>::DeleteAtPos(int iPos)
{
	if((Head == NULL)||(iPos > size+1)||(iPos <= 0))
	{
		return FALSE;
	}
	else if(iPos == 1)
	{
		return(DeleteFirst());
	}
	else if(iPos == size)
	{
		return(DeleteLast());
	}
	else{
		node<T>* temp = Head;

		for(int i = 1; i < iPos-1; i++)
		{
			temp = temp->next;
		}

		temp->next = temp->next->next;
		delete temp->next->prev;
		temp->next->prev = temp;
	}
	size--;

	return TRUE;
}

template<class T>
void Doubly_LinkedList<T>::Display()
{
	node<T>* temp = Head;

	while(temp != NULL)
	{
		cout<<"|"<<temp->data<<"|-> ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

template<class T>
int Doubly_LinkedList<T>::Count()
{
	return size;
}

/*-------------------------------------------------------------------------------------------------------*/

//////////////////////////////////////////////////////////
//
//	Singly Circular Linear LinkedList using C++
//	Auther :- Saurabh Rama Nale
//	Date :- 19/11/2021
//	Input :- User define
//	Output : ..............
//	Descrition :- User use the class to create LinkedList 
//
/////////////////////////////////////////////////////////

template<class T>
SinglyCircular_LinkedList<T>::SinglyCircular_LinkedList()
{
	first = NULL;
	last = NULL;
	size = 0;
}

template<class T>
SinglyCircular_LinkedList<T>::~SinglyCircular_LinkedList()
{
	node<T>* temp = NULL;
	node<T>* Navigate = NULL;

	if(first != NULL){
		Navigate = first;
		while(Navigate != NULL)
		{
			temp = Navigate->next;
			delete Navigate;
			Navigate = temp;
		}
	}
}

template<class T>
BOOL SinglyCircular_LinkedList<T>::InsertFirst(T no)
{
	node<T>* newn = new node<T>;

	if(newn == NULL){
		return FALSE;
	}

	newn->data = no;
	newn->next = NULL;

	if((first == NULL) && (last == NULL)){
		first = newn;
		last = newn;
	}
	else{
		newn->next = first;
		first = newn;
	}
	last->next = first;
	size++;

	return TRUE;
}

template<class T>
BOOL SinglyCircular_LinkedList<T>::InsertLast(T no)
{
	node<T>* newn = new node<T>;
	if(newn == NULL){
		return FALSE;
	}

	newn->data = no;
	newn->next = NULL;

	if((first == NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else{
		last->next = newn;
		last = newn;
	}
	last->next = first;
	size++;

	return TRUE;
}

template<class T>
BOOL SinglyCircular_LinkedList<T>::InsertAtPos(int iPos, T no)
{
	if((first == NULL)||(iPos < 1)||(iPos > (size +1)))
	{
		return FALSE;
	} 

	if(iPos == 1)
	{
		return(InsertFirst(no));
	}
	else if(iPos == size +1)
	{
		return(InsertLast(no));
	}
	else{
		node<T>* newn = new node<T>;

		newn->data = no;
		newn->next = NULL;

		node<T>* temp = first;
		for(int i = 1; i < iPos-1; i++){
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;

		size++;

		return TRUE;
	}
}

template<class T>
BOOL SinglyCircular_LinkedList<T>::DeleteFirst()
{
	if((first == NULL)&&(last == NULL))
	{
		return FALSE;
	}
	else if(first == NULL)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else{
		first = first->next;
		delete last->next;
		last->next = first;
	}
	size--;

	return TRUE;
}

template<class T>
BOOL SinglyCircular_LinkedList<T>::DeleteLast()
{
	if((first == NULL)&&(last == NULL)){
		return FALSE;
	}
	else if(first == last){
		delete first;
		first = NULL;
		last = NULL;
	}
	else{
		node<T>* temp = first;

		while(temp->next != last)
		{
			temp = temp->next;
		}
		delete last;
		last = temp;
		last->next = first;
	}
	size--;

	return TRUE;
}

template<class T>
BOOL SinglyCircular_LinkedList<T>::DeleteAtPos(int iPos)
{
	if((iPos < 1)||(iPos > size)||(first == NULL)){
		return FALSE;
	}

	if(iPos == 1)
	{
		return(DeleteFirst());
	}
	else if(iPos == size)
	{
		return(DeleteLast());
	}
	else{
		node<T>* temp = first;
		for(int i = 1; i < iPos -1; i++)
		{
			temp = temp->next;
		}
		node<T>* targated = temp->next;

		temp->next = targated->next;
		delete targated;

		size--;

		return TRUE;
	}
}

template<class T>
void SinglyCircular_LinkedList<T>::Display()
{
	node<T>* temp = first;
	if((first == NULL)&&(last == NULL)){
		return;
	}
	
	do{
		cout<<"|"<<temp->data<<"|-> ";
		temp = temp->next;
	}while(temp != last->next);

	cout<<"NULL"<<endl;
}

template<class T>
int SinglyCircular_LinkedList<T>::Count()
{
	return size;
}

/*-----------------------------------------------------------------------------------------------------------*/

//////////////////////////////////////////////////////////
//
//	Doubly Circular Linear LinkedList using C++
//	Auther :- Saurabh Rama Nale
//	Date :- 19/11/2021
//	Input :- User define
//	Output : ..............
//	Descrition :- User use the class to create LinkedList 
//
/////////////////////////////////////////////////////////

template<class T>
DoublyCircular_LinkedList<T>::DoublyCircular_LinkedList()
{
	first = NULL;
	last = NULL;
	size = 0;
}

template<class T>
DoublyCircular_LinkedList<T>::~DoublyCircular_LinkedList()
{
	node<T>* temp = NULL;
	node<T>* Navigate = NULL;

	if(first != NULL){
		Navigate = first;
		while(Navigate != NULL)
		{
			temp = Navigate->next;
			delete Navigate;
			Navigate = temp;
		}
	}
}

template<class T>
BOOL DoublyCircular_LinkedList<T>::InsertFirst(T no)
{
	node<T>* newn = new node<T>;
	if(newn == NULL){
		return FALSE;
	}

	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if((first == NULL)&&(last == NULL))
	{
		first = newn;
		last = newn;
	}
	else{
		newn->next = first;
		first->prev = newn;
		first = newn;
	}

	last->next = first;
	first->prev = last;

	size++;

	return TRUE;
}

template<class T>
BOOL DoublyCircular_LinkedList<T>::InsertLast(T no)
{
	node<T>* newn = new node<T>;
	if(newn == NULL){
		return FALSE;
	}

	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if((first == NULL)&&(last == NULL))
	{
		first = newn;
		last = newn;
	}
	else{
		last->next = newn;
		newn->prev = last;
		last = newn;
	}

	last->next = first;
	first->prev = last;

	size++;

	return TRUE;
}

template<class T>
BOOL DoublyCircular_LinkedList<T>::InsertAtPos(int iPos, T no)
{
	if((iPos < 1)||(iPos > size+1)||(first == NULL))
	{
		return FALSE;
	}

	if(iPos == 1)
	{
		return(InsertFirst(no));
	}
	else if(iPos == size)
	{
		return(InsertLast(no));
	}
	else{
		node<T>* newn =new node<T>;

		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;

		node<T>* temp = first;

		for(int i = 1; i < iPos-1; i++)
		{
			temp = temp->next;
		}

		newn->next = temp->next;
		newn->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;

		size++;

		return TRUE;
	}
}

template<class T>
BOOL DoublyCircular_LinkedList<T>::DeleteFirst()
{
	if((first == NULL) && (last == NULL))
	{
		return FALSE;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else{
		first = first->next;
		delete last->next;
		first->prev = last;
		last->next = first;
	}
	size--;

	return TRUE;
}

template<class T>
BOOL DoublyCircular_LinkedList<T>::DeleteLast()
{
	if((first == NULL) && (last == NULL))
	{
		return FALSE;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else{
		last = last->prev;
		delete last->next;
		first->prev = last;
		last->next = first;
	}
	size--;

	return TRUE;
}

template<class T>
BOOL DoublyCircular_LinkedList<T>::DeleteAtPos(int iPos)
{
	if((iPos < 1)||(iPos > size+1)||(first == NULL))
	{
		return FALSE;
	}

	if(iPos == 1)
	{
		return(DeleteFirst());
	}
	else if(iPos == size)
	{
		return(DeleteLast());
	}
	else{
		node<T>* temp = first;

		for(int i = 1; i < iPos-1; i++)
		{
			temp = temp->next;
		}

		temp->next = temp->next->next;
		delete temp->next->prev;
		temp->next->prev = temp;

		size--;
	}
	return TRUE;
}

template<class T>
void DoublyCircular_LinkedList<T>::Display()
{
	node<T>* temp = first;

	for(int i = 1; i <= size; i++)
	{
		cout<<"|"<<temp->data<<"|-> ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

template<class T>
int DoublyCircular_LinkedList<T>::Count()
{
	return size;
}

/*--------------------------------------------------------------------------------*/

//////////////////////////////////////////////////////////
//
//	Doubly Circular Linear LinkedList using C++
//	Auther :- Saurabh Rama Nale
//	Date :- 21/11/2021
//	Input :- User define
//	Output : Last in First OUT...........
//	Descrition :- User use the class to create STACK 
//
/////////////////////////////////////////////////////////

template<class T>
Stack<T>::Stack()
{
	first = NULL;
	size = 0;
}

template<class T>
Stack<T>::~Stack()
{
	node<T>* temp = NULL;
	node<T>* Navigate = NULL;

	if(first != NULL){
		Navigate = first;
		while(Navigate != NULL)
		{
			temp = Navigate->next;
			delete Navigate;
			Navigate = temp;
		}
	}
}

template<class T>
BOOL Stack<T>::Stack_Push(int no)
{
	node<T>* newn = new node<T>;
	if(newn == NULL){
		return false;
	}

	newn->data = no;
	newn->next = NULL;

	if(first == NULL){
		first = newn;
	}
	else{
		newn->next = first;
		first = newn;
	}
	size++;

	return true;
}

template<class T>
int Stack<T>::Stack_Pop()
{
	int no = 0;

	node<T>* temp = first;

	if(size == 0){
		cout<<"Stack is Empty : "<<endl;
		return -1;
	}

	if(size == 1){
		no = first->data;
		delete first;
		first = NULL;
	}
	else{
		no = first->data;
		first = first->next;
		delete temp;
	}
	size--;

	return no;
}

template<class T>
void Stack<T>::Display()
{
	node<T>* temp = first;

	while(temp != NULL)
	{
		cout<<"|"<<temp->data<<"|"<<endl;
		temp = temp->next;
	}
	cout<<endl;
}

template<class T>
int Stack<T>::Count()
{
	return size;
}

/*-----------------------------------------------------------------------------------------------*/
//////////////////////////////////////////////////////////
//
//	----------------QUEUE--------------------------------
//	Auther :- Saurabh Rama Nale
//	Date :- 19/11/2021
//	Input :- User define
//	Output : Last In First Out to use queue
//	Descrition :- User use the class to Queue 
//
/////////////////////////////////////////////////////////
template<class T>
Queue<T>::Queue()
{
	first = NULL;
	size = 0;
}

template<class T>
Queue<T>::~Queue()
{
	node<T>* temp = NULL;
	node<T>* Navigate = NULL;

	if(first != NULL){
		Navigate = first;
		while(Navigate != NULL)
		{
			temp = Navigate->next;
			delete Navigate;
			Navigate = temp;
		}
	}
}

template<class T>
BOOL Queue<T>::Enqueue(int no)
{
	node<T>* newn = new node<T>;

	if(newn == NULL){
		return false;
	}

	newn->data = no;
	newn->next = NULL;

	if(first == NULL){
		first = newn;
	}
	else{
		node<T>* temp = first;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
	}
	size++;

	return true;
}

template<class T>
int Queue<T>::Dequeue()
{
	int no = 0;
	node<T>* temp = first;

	if(first == NULL){
		cout<<"Queue is empty"<<endl;
		return -1;
	}

	if(first == NULL)
	{
		no = first->data;
		delete first;
		first = NULL;
	}
	else{
		no = first->data;
		first = first->next;
		delete temp;
	}
	size--;

	return no;
}

template<class T>
void Queue<T>::Display()
{
	node<T>* temp = first;

	for(int i = 1; i <= size; i++, temp = temp->next)
	{
		cout<<"|"<<temp->data<<"|-> ";
	}
	cout<<endl;
}

template<class T>
int Queue<T>::Count()
{
	return size;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-*/
int main()
{
	cout<<endl<<"----------------------------------------------------------------";
	cout<<endl<<"            || ----------O U T P U T---------- ||               ";
	cout<<endl<<"----------------------------------------------------------------"<<endl;
//////////////////////////////////////////////////////////
//
//	Singly Linear LinkedList using C++
//
/////////////////////////////////////////////////////////
	Singly_LinkedList <int>obj1;

	cout<<endl<<"----------------------------------------------------------------";
	cout<<endl<<"            || Singly Linear Linked List ||                     ";
	cout<<endl<<"----------------------------------------------------------------"<<endl;


	cout<<"InsertFirst the Elements in Linked List :"<<endl;
	obj1.InsertFirst(51);
	obj1.InsertFirst(21);
	obj1.InsertFirst(11);

	obj1.Display();
	int iRet = obj1.Count();
	cout<<"Count in Number of node : "<<iRet<<endl<<endl;

	obj1.InsertLast(101);
	obj1.InsertLast(111);
	cout<<"InsertLast the Elements in Linked List :"<<endl;
	obj1.Display();
	iRet = obj1.Count();
	cout<<"After the InsertLast Number of node : "<<iRet<<endl<<endl;
	
	obj1.InsertAtPos(4,75);
	cout<<"Insert At Position Elements in Linked List :"<<endl;
	obj1.Display();
	iRet = obj1.Count();
	cout<<"After the InsertAtPos Number of nodes : "<<iRet<<endl<<endl;

	obj1.DeleteFirst();
	cout<<"Delete first Elements in Linked List :"<<endl;
	obj1.Display();
	iRet = obj1.Count();
	cout<<"Delete first node after number of node : "<<iRet<<endl<<endl;

	obj1.DeleteLast();
	cout<<"Delete last node after Linked List :"<<endl;
	obj1.Display();
	iRet = obj1.Count();
	cout<<"Delete last node After number of node : "<<iRet<<endl<<endl;
	
	obj1.DeleteAtPos(3);
	cout<<"Delete At Pos node after Linked List :"<<endl;
	obj1.Display();
	iRet = obj1.Count();
	cout<<"Delete At Pos After number of node : "<<iRet<<endl<<endl;
/*--------------------------------------------------------------------------------------------*/	

//////////////////////////////////////////////////////////
//
//	Doubly Linear LinkedList using C++
//
/////////////////////////////////////////////////////////
	cout<<endl<<"----------------------------------------------------------------";
	cout<<endl<<"            || Doubly Linear Linked List] ||                    ";
	cout<<endl<<"----------------------------------------------------------------";
	/*
	cout<<endl<<"----------------------------------------------------------------"<<endl;
	cout<<endl<<"            * Integer Value Linked List *                   "<<endl;
	cout<<endl<<"----------------------------------------------------------------"<<endl;
	Doubly_LinkedList <int>obj2;

	cout<<"InsertFirst the Elements in Linked List :"<<endl;
	obj2.InsertFirst(51);
	obj2.InsertFirst(21);
	obj2.InsertFirst(11);

	obj2.Display();
	int iRet = obj2.Count();
	cout<<"Count in Number of node : "<<iRet<<endl<<endl;

	obj2.InsertLast(101);
	obj2.InsertLast(111);
	cout<<"InsertLast the Elements in Linked List :"<<endl;
	obj2.Display();
	iRet = obj2.Count();
	cout<<"After the InsertLast Number of node : "<<iRet<<endl<<endl;

	obj.InsertAtPos(4,75);
	cout<<"Insert At Position Elements in Linked List :"<<endl;
	obj2.Display();
	iRet = obj2.Count();
	cout<<"After the InsertAtPos Number of nodes : "<<iRet<<endl<<endl;

	obj2.DeleteFirst();
	cout<<"Delete first Elements in Linked List :"<<endl;
	obj2.Display();
	iRet = obj.Count();
	cout<<"Delete first node after number of node : "<<iRet<<endl<<endl;

	obj2.DeleteLast();
	cout<<"Delete last node after Linked List :"<<endl;
	obj2.Display();
	iRet = obj2.Count();
	cout<<"Delete last node After number of node : "<<iRet<<endl<<endl;

	obj2.DeleteAtPos(3);
	cout<<"Delete At Pos node after Linked List :"<<endl;
	obj2.Display();
	iRet = obj2.Count();
	cout<<"Delete At Pos After number of node : "<<iRet<<endl<<endl;
	
*/
	
	cout<<endl<<"----------------------------------------------------------------";
	cout<<endl<<"               * Float Value Linked List *                      ";
	cout<<endl<<"----------------------------------------------------------------"<<endl;
	Doubly_LinkedList <float>fobj;

	cout<<"InsertFirst the Elements in Linked List :"<<endl;
	fobj.InsertFirst(51.4);
	fobj.InsertFirst(21.6);
	fobj.InsertFirst(11.7);

	fobj.Display();
	float fRet = fobj.Count();
	cout<<"Count in Number of node : "<<fRet<<endl<<endl;

	fobj.InsertLast(101.9);
	fobj.InsertLast(111.7);
	cout<<"InsertLast the Elements in Linked List :"<<endl;
	fobj.Display();
	fRet = fobj.Count();
	cout<<"After the InsertLast Number of node : "<<fRet<<endl<<endl;

	fobj.InsertAtPos(4,75.8);
	cout<<"Insert At Position Elements in Linked List :"<<endl;
	fobj.Display();
	fRet = fobj.Count();
	cout<<"After the InsertAtPos Number of nodes : "<<fRet<<endl<<endl;

	fobj.DeleteFirst();
	cout<<"Delete first Elements in Linked List :"<<endl;
	fobj.Display();
	fRet = fobj.Count();
	cout<<"Delete first node after number of node : "<<fRet<<endl<<endl;

	fobj.DeleteLast();
	cout<<"Delete last node after Linked List :"<<endl;
	fobj.Display();
	fRet = fobj.Count();
	cout<<"Delete last node After number of node : "<<fRet<<endl<<endl;

	fobj.DeleteAtPos(3);
	cout<<"Delete At Pos node after Linked List :"<<endl;
	fobj.Display();
	fRet = fobj.Count();
	cout<<"Delete At Pos After number of node : "<<fRet<<endl<<endl;
	
/*------------------------------------------------------------------------------------*/
//////////////////////////////////////////////////////////
//
//	Singly Circular Linear LinkedList using C++
//
/////////////////////////////////////////////////////////
	
	SinglyCircular_LinkedList <int>obj3;

	cout<<endl<<"----------------------------------------------------------------";
	cout<<endl<<"            || Singly Circular Linear Linked List ||             ";
	cout<<endl<<"----------------------------------------------------------------"<<endl;
	
	cout<<"InsertFirst the Elements in Linked List :"<<endl;
	obj3.InsertFirst(51);
	obj3.InsertFirst(21);
	obj3.InsertFirst(11);

	obj3.Display();
	iRet = obj3.Count();
	cout<<"Count in Number of node : "<<iRet<<endl<<endl;

	obj3.InsertLast(101);
	obj3.InsertLast(111);
	cout<<"InsertLast the Elements in Linked List :"<<endl;
	obj3.Display();
	iRet = obj3.Count();
	cout<<"After the InsertLast Number of node : "<<iRet<<endl<<endl;

	obj3.InsertAtPos(4,75);
	cout<<"Insert At Position Elements in Linked List :"<<endl;
	obj3.Display();
	iRet = obj3.Count();
	cout<<"After the InsertAtPos Number of nodes : "<<iRet<<endl<<endl;

	obj3.DeleteFirst();
	cout<<"Delete first Elements in Linked List :"<<endl;
	obj3.Display();
	iRet = obj3.Count();
	cout<<"Delete first node after number of node : "<<iRet<<endl<<endl;

	obj3.DeleteLast();
	cout<<"Delete last node after Linked List :"<<endl;
	obj3.Display();
	iRet = obj3.Count();
	cout<<"Delete last node After number of node : "<<iRet<<endl<<endl;

	obj3.DeleteAtPos(3);
	cout<<"Delete At Pos node after Linked List :"<<endl;
	obj3.Display();
	iRet = obj3.Count();
	cout<<"Delete At Pos After number of node : "<<iRet<<endl<<endl;
	
/*------------------------------------------------------------------------------------------------*/

//////////////////////////////////////////////////////////
//
//	Doubly Circular Linear LinkedList using C++
//
/////////////////////////////////////////////////////////

	DoublyCircular_LinkedList <int>obj4;
	
	cout<<endl<<"----------------------------------------------------------------";
	cout<<endl<<"            || Doubly Circular Linear Linked List ||             ";
	cout<<endl<<"----------------------------------------------------------------"<<endl;
	
	cout<<"InsertFirst the Elements in Linked List :"<<endl;
	obj4.InsertFirst(51);
	obj4.InsertFirst(21);
	obj4.InsertFirst(11);

	obj4.Display();
	iRet = obj4.Count();
	cout<<"Count in Number of node : "<<iRet<<endl<<endl;

	obj4.InsertLast(101);
	obj4.InsertLast(111);
	cout<<"InsertLast the Elements in Linked List :"<<endl;
	obj4.Display();
	iRet = obj4.Count();
	cout<<"After the InsertLast Number of node : "<<iRet<<endl<<endl;

	obj4.InsertAtPos(4,75);
	cout<<"Insert At Position Elements in Linked List :"<<endl;
	obj4.Display();
	iRet = obj4.Count();
	cout<<"After the InsertAtPos Number of nodes : "<<iRet<<endl<<endl;

	obj4.DeleteFirst();
	cout<<"Delete first Elements in Linked List :"<<endl;
	obj4.Display();
	iRet = obj4.Count();
	cout<<"Delete first node after number of node : "<<iRet<<endl<<endl;

	obj4.DeleteLast();
	cout<<"Delete last node after Linked List :"<<endl;
	obj4.Display();
	iRet = obj4.Count();
	cout<<"Delete last node After number of node : "<<iRet<<endl<<endl;

	obj4.DeleteAtPos(3);
	cout<<"Delete At Pos node after Linked List :"<<endl;
	obj4.Display();
	iRet = obj4.Count();
	cout<<"Delete At Pos After number of node : "<<iRet<<endl<<endl;

/*-------------------------------------------------------------------------------------------*/

//////////////////////////////////////////////////////////
//
//	Cheack Whether to Stack function working or not
//
/////////////////////////////////////////////////////////
	Stack <int>obj5;
    
    cout<<endl<<"----------------------------------------------------------------";
	cout<<endl<<"            || -------S T A C K------ ||                         ";
	cout<<endl<<"----------------------------------------------------------------"<<endl;

    obj5.Stack_Push(11);
    obj5.Stack_Push(21);
    obj5.Stack_Push(51);
    obj5.Stack_Push(101);
    
    cout<<"Elements of Stack : "<<endl;
    obj5.Display();

    iRet = obj5.Stack_Pop();     
    cout<<"Poped Elements is : "<<iRet<<endl;                    
    

    cout<<"Elements of stack : "<<endl;
    obj5.Display();          
    iRet = obj5.Count();
    
    cout<<"Size of stack is : "<<iRet<<endl;
    
/*------------------------------------------------------------------------------------------*/
	
/////////////////////////////////////////////////////////
//
//	Cheack whether to Queue function working or not
//
/////////////////////////////////////////////////////////
	Queue <int>obj6;
    
    cout<<endl<<"----------------------------------------------------------------";
	cout<<endl<<"            || -------Q U E U E------ ||                        ";
	cout<<endl<<"----------------------------------------------------------------"<<endl;
    obj6.Enqueue(11);
    obj6.Enqueue(21);
    obj6.Enqueue(51);
    obj6.Enqueue(101);
    
    cout<<"Elements of Queue :"<<endl;
    
    obj6.Display();
    iRet = obj6.Dequeue();       
    cout<<"Removed first element from queue : "<<iRet<<endl<<endl;                     // 11
    
    cout<<"Elements from queue : "<<endl;
    obj6.Display();          
    iRet = obj6.Count();     
    
    cout<<"Size of queue is : "<<iRet<<endl;

/*-----------------------------------------------------------------------------------------*/
	
	return 0;
}