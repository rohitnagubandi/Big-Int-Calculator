/****************************************************************************************
*  Rohit Venkat Abhiram Nagubandi
*  rnaguban
*  pa6
*****************************************************************************************/

//-----------------------------------------------------------------------------
// List.cpp
// Implementation file for List ADT
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<stdexcept>
#include"List.h"

/*
Possible Preconditions:
	if( length()<=0 ){
		throw std::length_error("List: Function(): empty List");
	}
   	if (position()>=length()){
		throw std::range_error("List: peekNext(): At end of List");
	}
	if (position()<=0){
		throw std::range_error("List: peekPrev(): At beginning of List");
	}
*/

// Private Constructor --------------------------------------------------------

List::Node::Node(ListElement x){
	data = x;
	next = nullptr;
	prev = nullptr;
}


// Class Constructors & Destructors -------------------------------------------

// Creates new List in the empty state.
List::List(){
	frontDummy = new Node(-1000000000);
 	backDummy = new Node(-1000000000);
 	frontDummy->next = backDummy;
 	backDummy->prev = frontDummy;
 	beforeCursor = frontDummy;
 	afterCursor = backDummy;
 	pos_cursor = 0;
	num_elements = 0;
}

// Copy constructor.
List::List(const List& L){ 
	frontDummy = new Node(-1000000000);
	backDummy = new Node(-1000000000);
	frontDummy->next = backDummy;
	backDummy->prev = frontDummy;
	beforeCursor = frontDummy;
 	afterCursor = backDummy;
 	pos_cursor = 0;
	num_elements = 0;
	Node* N = L.frontDummy->next;
	while(N!=L.backDummy){
		insertBefore(N->data);
		N = N->next;
	}
	moveFront();
}

// Destructor
List::~List(){
    clear();
    delete frontDummy;
    delete backDummy;
}

// Access functions --------------------------------------------------------

// length()
// Returns the length of this List.
int List::length() const{
   return(num_elements);
}

// front()
// Returns the front element in this List.
// pre: length()>0
ListElement List::front() const{
   if( length()<=0 ){
		throw std::length_error("List: front(): empty List");
   }
   return(frontDummy->next->data);
}


// back()
// Returns the back element in this List.
// pre: length()>0
ListElement List::back() const{
   if( length()<=0 ){
		throw std::length_error("List: back(): empty List");
   }
   return(backDummy->prev->data);
}

// position()
// Returns the position of cursor in this List: 0 <= position() <= length().
int List::position() const{
	return(pos_cursor);
}

// peekNext()
// Returns the element after the cursor.
// pre: position()<length()
ListElement List::peekNext() const{
	if (position()>=length()){
		throw std::range_error("List: peekNext(): At end of List");
	}
	return afterCursor->data;
}

// peekPrev()
// Returns the element before the cursor.
// pre: position()>0
ListElement List::peekPrev() const{
	if (position()<=0){
		throw std::range_error("List: peekPrev(): At beginning of List");
	}
	return beforeCursor->data;
}

// Manipulation procedures -------------------------------------------------

// clear()
// Deletes all elements in this List, setting it to the empty state.
//Got Puesdocode from Norton Chuy and Sebastian Carbonero
void List::clear(){
    moveBack();
    while(length() > 0){
        eraseBefore();
    }
}

// moveFront()
// Moves cursor to position 0 in this List.
void List::moveFront(){
   beforeCursor = frontDummy;
   afterCursor = frontDummy->next;
   pos_cursor = 0;
}

// moveBack()
// Moves cursor to position length() in this List.
void List::moveBack(){
	afterCursor = backDummy;
	beforeCursor = backDummy->prev;
	pos_cursor = length();
}

// moveNext()
// Advances cursor to next higher position. Returns the List element that
// was passed over. 
// pre: position()<length() 
ListElement List::moveNext(){
	if (position()>=length()){
		throw std::range_error("List: moveNext(): At end of List");
	}
	beforeCursor = afterCursor;
	afterCursor = afterCursor->next;
	pos_cursor++;
	return beforeCursor->data;
}

// movePrev()
// Advances cursor to next lower position. Returns the List element that
// was passed over. 
// pre: position()>0
ListElement List::movePrev(){
	if (position()<=0){
		throw std::range_error("List: movePrev(): At beginning of List");
	}
	afterCursor = beforeCursor;
	beforeCursor = beforeCursor->prev;
	pos_cursor--;
	return afterCursor->data;	
}

// insertAfter()
// Inserts x after cursor.
void List::insertAfter(ListElement x){
	Node* X = new Node(x);
	X->next = afterCursor;
	X->prev = beforeCursor;
	afterCursor->prev = X;
	beforeCursor->next = X;
	afterCursor = X;
	num_elements++;
}

// insertBefore()
// Inserts x before cursor.
void List::insertBefore(ListElement x){
	Node* X = new Node(x);
	X->prev = beforeCursor;
	X->next = afterCursor;
	beforeCursor->next = X;
	afterCursor->prev = X;
	beforeCursor = X;
	num_elements++;
	pos_cursor++; 
}

// setAfter()
// Overwrites the List element after the cursor with x.
// pre: position()<length()
void List::setAfter(ListElement x){
	if (position()>=length()){
		throw std::range_error("List: setAfter(): At end of List");
	}
	afterCursor->data = x;
}

// setBefore()
// Overwrites the List element before the cursor with x.
// pre: position()>0
void List::setBefore(ListElement x){
	if (position()<=0){
		throw std::range_error("List: setBefore(): At beginning of List");
	}
	beforeCursor->data = x;
}

//Got Puesdocode from Norton Chuy and Sebastian Carbonero
//eraseAfter()
//Delete element after cursor.
//pre: position()<length()
void List::eraseAfter(){
	if (position()>=length()){
		throw std::range_error("List: eraseAfter(): At end of List");
	}
    Node* temp = afterCursor;
    afterCursor = afterCursor->next;
    beforeCursor->next = afterCursor;
    afterCursor->prev = beforeCursor;
    num_elements --;
    delete temp;
    temp = nullptr;
}

//Got Puesdocode from Norton Chuy and Sebastian Carbonero
//eraseBefore()
//Deletes element before cursor.
//pre: position()>0
void List::eraseBefore(){
	if (position()<=0){
		throw std::range_error("List: eraseBefore(): At beginning of List");
	}
	
	Node* temp = beforeCursor;
	afterCursor->prev = temp->prev;
	temp->prev->next = afterCursor;
	beforeCursor = temp->prev;
	num_elements--;
	pos_cursor--;
	delete temp;
	temp = nullptr;
}
   // Other Functions ---------------------------------------------------------

// findNext()
// Starting from the current cursor position, performs a linear search (in 
// the direction front-to-back) for the first occurrence of element x. If x
// is found, places the cursor immediately after the found element, then 
// returns the final cursor position. If x is not found, places the cursor 
// at position length(), and returns -1. 
int List::findNext(ListElement x){
	while (pos_cursor<length()){
		if (peekNext()==x){
			moveNext();
			return pos_cursor;
		} else{
			moveNext();
		}
	}
	return -1;
}

// findPrev()
// Starting from the current cursor position, performs a linear search (in 
// the direction back-to-front) for the first occurrence of element x. If x
// is found, places the cursor immediately before the found element, then
// returns the final cursor position. If x is not found, places the cursor 
// at position 0, and returns -1. 
int List::findPrev(ListElement x){
	while (pos_cursor>0){
		if (peekPrev()==x){
			movePrev();
			return pos_cursor;
		} else{
			movePrev();
		}
	}
	return -1;
}



// cleanup()
// Removes any repeated elements in this List, leaving only unique elements.
// The order of the remaining elements is obtained by retaining the frontmost 
// occurrance of each element, and removing all other occurances. The cursor 
// is not moved with respect to the retained elements, i.e. it lies between 
// the same two retained elements that it did before cleanup() was called.

//Got Puesdocode from Norton Chuy and Sebastian Carbonero
void List::cleanup(){
	Node* A = frontDummy->next;
	int cursor_pos = pos_cursor;
	int cursor_pos1 = pos_cursor;
	int index = 1;
	while (A != backDummy){
		moveFront();
		while (pos_cursor<length()){
			//printf("outside loop: %d\n",A->data);
			//printf("index:%d\n",index);
			if (findNext(A->data)>index){
				//printf("inside loop: %d\n",A->data);
				if(pos_cursor < cursor_pos1){
					cursor_pos--;
				}
				eraseBefore();
			}
		}
		index+=1;
		A=A->next;
	}
	
	//printf("cursor_pos: %d\n", cursor_pos);
	//printf("pos_cursor: %d\n", pos_cursor);
	//
	if(pos_cursor>cursor_pos){
		while(pos_cursor!=cursor_pos && pos_cursor != 0){
			movePrev();
		}
	}
	
	if(pos_cursor<cursor_pos){
		while(pos_cursor!=cursor_pos && pos_cursor != length()){
			moveNext();
		}
	}
}



   // concat()
   // Returns a new List consisting of the elements of this List, followed by
   // the elements of L. The cursor in the returned List will be at postion 0.
List List::concat(const List& L) const{
   List J;
   Node* N = frontDummy->next;
   Node* M = L.frontDummy->next;
   while( N!=backDummy ){
	J.insertBefore(N->data);
	//printf("J.length = %d\n",J.length());
	N = N->next;
   }
   while( M!=L.backDummy ){
	J.insertBefore(M->data);
	//printf("J.length = %d\n",J.length());
	M = M->next;
   }
   J.moveFront();
   //printf("J.length before returning = %d\n",J.length());
   return J;
}

   // to_string()
   // Returns a string representation of this List consisting of a comma 
   // separated sequence of elements, surrounded by parentheses.
std::string List::to_string() const{
	Node* N = nullptr;
	std::string s = "(";
	for(N=frontDummy->next; N!=backDummy; N=N->next){
		if (N->next!=backDummy){
			s += std::to_string(N->data)+", ";
		} else{
			s += std::to_string(N->data);
			break;
		}
	}
	s+=")";
   return s;
}

   // equals()
   // Returns true if and only if this List is the same integer sequence as R.
   // The cursors in this List and in R are unchanged.
bool List::equals(const List& R) const{
   bool eq = false;
   Node* N = nullptr;
   Node* M = nullptr;

   eq = ( length() == R.length() );
   N = frontDummy->next;
   M = R.frontDummy->next;
   while( eq && N!=backDummy){
      eq = (N->data==M->data);
      N = N->next;
      M = M->next;
   }
   //printf("Equals Returns: %d\n",eq);
   return eq;
}

   // Overriden Operators -----------------------------------------------------
   
   // operator<<()
   // Inserts string representation of L into stream.
std::ostream& operator<<( std::ostream& stream, const List& L ){
	return stream << L.List::to_string();
}

   // operator==()
   // Returns true if and only if A is the same integer sequence as B. The 
   // cursors in both Lists are unchanged.
bool operator==( const List& A, const List& B ){
	return A.List::equals(B);
}

   // operator=()
   // Overwrites the state of this List with state of L.
List& List::operator=( const List& L ){
	if (this != &L){
		List temp = L;
		
		std::swap(frontDummy,temp.frontDummy);
		std::swap(backDummy,temp.backDummy);
		std::swap(beforeCursor,temp.beforeCursor);
		std::swap(afterCursor,temp.afterCursor);		
		std::swap(pos_cursor,temp.pos_cursor);
		std::swap(num_elements,temp.num_elements);
		moveFront();
		while(pos_cursor != L.pos_cursor){
		    moveNext();
		}
	}
	return *this;
}



