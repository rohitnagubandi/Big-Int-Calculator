//-----------------------------------------------------------------------------
//	Rohit Venkat Abhiram Nagubandi
//	CruzID: rnaguban
//	pa6
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ListTest.cpp
// A test client for List ADT
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<stdexcept>
#include"List.h"

using namespace std;

int main(){

   	List A, B, C;
    A.insertAfter(1);
    A.insertAfter(2);
    A.insertAfter(3);
    B.insertAfter(4);
    B.insertAfter(5);
    B.insertAfter(6);
    C = A.concat(B);
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
   cout << "C = " << C << endl;
   cout << "C.position() = " << C.position() << endl;    
    A.insertBefore(1);
    A.insertBefore(2);
    A.insertBefore(2);
    A.insertBefore(1);
    A.insertBefore(2);
    A.insertBefore(3);
    A.insertBefore(1);
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   A.findPrev(3);
   A.cleanup();
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
	A.moveFront();
	A.insertAfter(3214);
    A.insertAfter(176);
    A.insertAfter(16);
    A.insertAfter(5);
    A.insertAfter(1);
    A.moveNext();
    A.moveNext();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    A.moveFront();
    A.insertAfter(200);
    A.insertAfter(176);
    A.insertAfter(15);
    A.insertAfter(10);
    A.insertAfter(5);
    A.findNext(15);
    A.eraseAfter();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    List D;
    
    D = A;
    
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    
    cout << "D = " << D << endl;
    cout << "D.position() = " << D.position() << endl;
    
    A.clear();
    B.clear();
    C.clear();
    D.clear();
    
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
   cout << "C = " << C << endl;
   cout << "C.position() = " << C.position() << endl;  
   cout << "D = " << D << endl;
   cout << "D.position() = " << D.position() << endl;
}

/*
Output of Test:
A = (3, 2, 1)
A.position() = 0
B = (6, 5, 4)
B.position() = 0
C = (3, 2, 1, 6, 5, 4)
C.position() = 0
A = (1, 2, 2, 1, 2, 3, 1, 3, 2, 1)
A.position() = 7
A = (1, 2, 3)
A.position() = 1
A = (1, 5, 16, 176, 3214, 1, 2, 3)
A.position() = 2
A = (5, 10, 15, 200, 1, 5, 16, 176, 3214, 1, 2, 3)
A.position() = 3
A = (5, 10, 15, 200, 1, 5, 16, 176, 3214, 1, 2, 3)
A.position() = 3
D = (5, 10, 15, 200, 1, 5, 16, 176, 3214, 1, 2, 3)
D.position() = 3
A = ()
A.position() = 0
B = ()
B.position() = 0
C = ()
C.position() = 0
D = ()
D.position() = 0
*/



//-------------------------------------------------------------------------------------    


/*
//Concat_size    
   	List A, B, C;
    A.insertAfter(1);
    A.insertAfter(2);
    A.insertAfter(3);
    B.insertAfter(4);
    B.insertAfter(5);
    B.insertAfter(6);
    C = A.concat(B);
   cout << "C = " << C << endl;
   cout << "C.position() = " << C.position() << endl;
*/

//-------------------------------------------------------------------------------------

/*
//Cleanup_size
   List A;
	A.insertBefore(1);
    A.insertBefore(2);
    A.insertBefore(2);
    A.insertBefore(1);
    A.insertBefore(2);
    A.insertBefore(3);
    A.insertBefore(1);
    A.findPrev(3);
    A.cleanup();
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
*/

//-------------------------------------------------------------------------------------

/*
//EmptyList_position
	List A;
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;

*/

//-------------------------------------------------------------------------------------

/*
//MoveFront_position:
	List A;
    A.insertBefore(1);
    A.insertBefore(5);
    A.insertBefore(16);
    A.insertBefore(176);
    A.insertBefore(3214);
    A.moveFront();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
*/

//-------------------------------------------------------------------------------------

/*
//MoveBack_position
	List A;
    A.insertAfter(1);
    A.insertAfter(5);
    A.insertAfter(16);
    A.insertAfter(176);
    A.insertAfter(3214);
    A.moveBack();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
*/

//-------------------------------------------------------------------------------------

/*
//MoveNext_position
	List A;
	A.insertAfter(3214);
    A.insertAfter(176);
    A.insertAfter(16);
    A.insertAfter(5);
    A.insertAfter(1);
    A.moveNext();
    A.moveNext();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    A.moveNext();
    A.moveNext();
    A.moveNext();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;

*/

//-------------------------------------------------------------------------------------

/*
//MovePrev_position
	List A;
    A.insertBefore(1);
    A.insertBefore(5);
    A.insertBefore(16);
    A.insertBefore(176);
    A.insertBefore(3214);
    A.movePrev();
    A.movePrev();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl; 
    A.movePrev();
    A.movePrev();
    A.movePrev();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
*/

//-------------------------------------------------------------------------------------

/*
//InsertAfter_position
	List A;
    A.insertAfter(200);
    A.insertAfter(176);
    A.insertAfter(16);
    A.insertAfter(5);
    A.insertAfter(1);
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    
    A.moveBack();
    A.insertAfter(225);
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    
    A.insertAfter(255);
    A.moveBack();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
*/

//-------------------------------------------------------------------------------------

/*
//InsertBefore_position
	List A;
    A.insertBefore(1);
    A.insertBefore(5);
    A.insertBefore(16);
    A.insertBefore(176);
    A.insertBefore(200);
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    
    A.moveFront();
    A.insertBefore(225);
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    
    A.insertBefore(255);
    A.moveFront();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
*/

//-------------------------------------------------------------------------------------

/*
	//FindNext_position
	List A;
    A.insertAfter(16);
    A.insertAfter(200);
    A.insertAfter(176);
    A.insertAfter(16);
    A.insertAfter(5);
    A.insertAfter(1);
    A.findNext(16);
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    A.movePrev();
    A.insertBefore(225);
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    A.moveNext();
    A.findNext(16);
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    A.moveFront();
    A.findNext(16);
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
*/  

//-------------------------------------------------------------------------------------

/*
	//FindPrev_position
	List A;
    A.insertBefore(1);
    A.insertBefore(5);
    A.insertBefore(16);
    A.insertBefore(176);
    A.insertBefore(200);
    A.insertBefore(16);
    A.findPrev(16);
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    A.moveNext();
    A.insertAfter(225);
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    A.movePrev();
    A.findPrev(16);
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    A.moveBack();
    A.findPrev(16);
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
*/ 

//-------------------------------------------------------------------------------------

/*
//EraseAfter_position:
	List A;
    A.insertAfter(200);
    A.insertAfter(176);
    A.insertAfter(15);
    A.insertAfter(10);
    A.insertAfter(5);
    A.findNext(15);
    A.eraseAfter();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    
    A.insertAfter(175);
    A.eraseAfter();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    
    A.insertBefore(50);
    A.insertBefore(15);
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    
    A.findPrev(15);
    A.eraseAfter();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    
    A.findPrev(15);
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    A.moveFront();
    A.eraseAfter();
    A.eraseAfter();
    A.eraseAfter();
    A.eraseAfter();
    A.eraseAfter();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
*/        
    
//-------------------------------------------------------------------------------------

/*
	//EraseBefore_position:
	List A;    
    A.insertBefore(5);
    A.insertBefore(10);
    A.insertBefore(15);
    A.insertBefore(176);
    A.insertBefore(200);
    A.findPrev(15);
    A.eraseBefore();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    
    A.insertAfter(175);
    A.eraseBefore();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;

    A.insertBefore(15);
    A.insertBefore(50);
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    
    A.findNext(15);
    A.eraseBefore();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    
    A.findPrev(15);
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    
    A.moveBack();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
    
    A.eraseBefore();
    A.eraseBefore();
    A.eraseBefore();
    A.eraseBefore();
    A.eraseBefore();
    cout << "A = " << A << endl;
    cout << "A.position() = " << A.position() << endl;
*/    

//-------------------------------------------------------------------------------------

/*

//Cleanup Position
   List A;
	A.insertBefore(1);
    A.insertBefore(2);
    A.insertBefore(2);
    A.insertBefore(1);
    A.insertBefore(2);
    A.insertBefore(3);
    A.insertBefore(1);
    A.findPrev(3);
    A.cleanup();

    List B;
    B.insertBefore(1);
    B.insertBefore(2);
    B.insertBefore(2);
    B.insertBefore(1);
    B.insertBefore(2);
    B.insertBefore(3);
    B.insertBefore(1);
    B.findPrev(3);
    B.movePrev();
    B.cleanup();
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
*/

//-------------------------------------------------------------------------------------

/*
//Concat_position   
   	List A, B, C;
    A.insertAfter(1);
    A.insertAfter(2);
    A.insertAfter(3);
    B.insertAfter(4);
    B.insertAfter(5);
    B.insertAfter(6);
    C = A.concat(B);
   cout << "C = " << C << endl;
   cout << "C.position() = " << C.position() << endl;
*/

//-------------------------------------------------------------------------------------

/*
//Assign_Equals  
   	List A, B;
    A.insertAfter(2);
    A.insertAfter(1);
    B = A;
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
    cout << endl;
*/   

//-------------------------------------------------------------------------------------

/*
//InsertAfter_Equals
	List A, B;
	A.insertAfter(2);
    A.insertAfter(1);
    B.insertAfter(2);
    if (A.equals(B)){
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
	}

    B.insertAfter(1);
   if (A.equals(B)){
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
   }
*/

//-------------------------------------------------------------------------------------

/*
//InsertBefore_equals: {
	List A, B;
    A.insertBefore(2);
    A.insertBefore(1);
    B.insertAfter(2);
	if (A.equals(B)){
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
	}

    B.moveBack();
    B.insertBefore(1);
	if (A.equals(B)){
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
	}
*/

//-------------------------------------------------------------------------------------
	
/*
	//EraseAfter_equals
	List A, B;
    A.insertBefore(1);
    A.insertAfter(2);
    B.insertBefore(1);
    B.insertBefore(2);
    A.eraseAfter();
	if (A.equals(B)){
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
	}

    B.movePrev();
    B.eraseAfter();
	if (A.equals(B)){
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
	}

    A.insertAfter(5);
    B.insertAfter(5);
    A.eraseAfter();
    B.eraseAfter();
	if (A.equals(B)){
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
	}
*/
//-------------------------------------------------------------------------------------

/*
	//EraseBefore_equals
	List A, B;
    A.insertBefore(1);
    A.insertAfter(2);
    B.insertBefore(1);
    B.insertBefore(2);
    A.eraseBefore();
	if (A.equals(B)){
	printf("Bad");
	}

    B.movePrev();
    B.eraseBefore();
	if (A.equals(B)){
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
	}

    A.insertBefore(5);
    B.insertBefore(5);
    A.eraseBefore();
    B.eraseBefore();
	if (A.equals(B)){
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
	}
*/
	
//-------------------------------------------------------------------------------------

/*
//Cleanup_equals
	List A, B;
    A.insertBefore(3);
    A.insertBefore(3);
    A.insertBefore(1);
    A.insertBefore(3);
    A.insertBefore(2);
    A.insertBefore(2);
    A.insertBefore(1);
    A.insertBefore(4);
    B.insertBefore(3);
    B.insertBefore(1);
    B.insertBefore(2);
	if (A.equals(B)){
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
	}
    A.cleanup();
	if (A.equals(B)){
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
	}

    A.moveBack();
    A.eraseBefore();
	if (A.equals(B)){
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
	}
*/

//-------------------------------------------------------------------------------------

/*
//Concat_Equals
    List A,B,C;
    A.insertBefore(1);
    A.insertAfter(3);
    A.insertAfter(2);
    B.insertBefore(3);
    B.insertBefore(2);
    B.insertBefore(1);
    C.insertAfter(1);
    C.insertAfter(2);
    C.insertAfter(3);
    C.insertAfter(3);
    C.insertAfter(2);
    C.insertAfter(1);
    if (C.equals(A.concat(B))){
   cout << "A = " << A << endl;
   cout << "A.position() = " << A.position() << endl;
   
   cout << "B = " << B << endl;
   cout << "B.position() = " << B.position() << endl;
   
   cout << "C = " << C << endl;
   cout << "C.position() = " << C.position() << endl;
}
*/

//-------------------------------------------------------------------------------------

/*
//Empty_Clear
	List A;
    A.clear();
    if (A.length() != 0 || A.position() != 0){
      printf("Bad\n");
    }
    printf("Good\n");
*/

//-------------------------------------------------------------------------------------

/*
//Empty_Clear
	List A;
    A.insertAfter(1);
    A.insertAfter(2);
    A.insertAfter(3);
    A.insertBefore(5);
    A.insertBefore(12);
    A.clear();
    if (A.length() != 0 || A.position() != 0){
      printf("Bad\n");
    }
    printf("Good\n");
*/

//-------------------------------------------------------------------------------------

/*
//MoveNext_Value
	List A;
    A.insertAfter(3215);
    A.insertAfter(176);
    A.insertAfter(22);
    A.insertAfter(5);
    A.insertAfter(1);
    A.moveNext();
    if (A.moveNext() != 5){
      return 1;
	}
	
    A.eraseBefore();
    A.eraseBefore();
    A.moveNext();
    A.moveNext();
    if (A.moveNext() != 3215){
      return 2;
	}
	
    A.moveFront();
    if (A.moveNext() != 22){
      return 3;
    }
    printf("Good\n");
*/

//-------------------------------------------------------------------------------------

/*
//MovePrev_value
	List A;
    A.insertBefore(1);
    A.insertBefore(5);
    A.insertBefore(22);
    A.insertBefore(176);
    A.insertBefore(3215);
    A.movePrev();
    if (A.movePrev() != 176){
      return 1;
	}
    A.eraseAfter();
    A.eraseAfter();
    A.movePrev();
    A.movePrev();
    if (A.movePrev() != 1){
      return 2;
	}
    A.moveBack();
    if (A.movePrev() != 22){
      return 3;
    }
    printf("Good\n");
*/

//-------------------------------------------------------------------------------------

/*
//PeekNext_Value
	List A;
    A.insertAfter(60);
    A.insertAfter(50);
    A.insertAfter(40);
    A.insertBefore(10);
    A.insertBefore(20);
    A.insertBefore(30);
    if (A.peekNext() != 40){
      return 1;
	}
    A.eraseAfter();
    if (A.peekNext() != 50){
      return 2;
	}
    A.moveFront();
    if (A.peekNext() != 10){
      return 3;
    }
    printf("Good\n");
*/

//-------------------------------------------------------------------------------------

/*
//PeekPrev_Value
	List A;
    A.insertAfter(60);
    A.insertAfter(50);
    A.insertAfter(40);
    A.insertBefore(10);
    A.insertBefore(20);
    A.insertBefore(30);
    if (A.peekPrev() != 30){
      return 1;
	}
    A.eraseBefore();
    if (A.peekPrev() != 20){
      return 2;
	}
    A.moveBack();
    if (A.peekPrev() != 60){
      return 3;
    }
    printf("Good\n");
*/

//-------------------------------------------------------------------------------------

/*
//FindNext_value: {
	List A;
    A.insertAfter(77);
    A.insertAfter(55);
    A.insertAfter(1);
    A.insertAfter(34);
    A.insertAfter(1);
    A.insertAfter(77);
    A.insertAfter(77);
    A.insertAfter(34);
    if (A.findNext(99) != -1){
      return 1;
    }
    if (A.position() != A.length()){
      return 2;
	}
    A.moveFront();
    if (A.findNext(1) != 4){
      return 3;
    }
    if (A.findNext(1) != 6){
      return 4;}
    if (A.findNext(1) != -1){
      return 5;}

    A.moveFront();
    A.cleanup();
    if (A.findNext(1) != 3){
      return 6;}
    if (A.findNext(1) != -1){
      return 7;}
    printf("Good123\n");
*/
//-------------------------------------------------------------------------------------

/*
//FindPrev_Value
	List A;
    A.insertBefore(34);
    A.insertBefore(77);
    A.insertBefore(77);
    A.insertBefore(1);
    A.insertBefore(34);
    A.insertBefore(1);
    A.insertBefore(55);
    A.insertBefore(77);
    if (A.findPrev(99) != -1)
      return 1;
    if (A.position() != 0)
      return 2;

    A.moveBack();
    if (A.findPrev(1) != 5)
      return 3;
    if (A.findPrev(1) != 3)
      return 4;
    if (A.findPrev(1) != -1)
      return 5;

    A.moveBack();
    A.cleanup();
    if (A.findPrev(1) != 2)
      return 6;
    if (A.findPrev(1) != -1)
      return 7;
    printf("Good123\n");
    return 0;
*/

//-------------------------------------------------------------------------------------

