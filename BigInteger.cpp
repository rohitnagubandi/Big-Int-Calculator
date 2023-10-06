#include<iostream>
#include<string>
#include<sstream>
#include<stdexcept>
#include <ctype.h>
#include "BigInteger.h"

/****************************************************************************************
*  Rohit Venkat Abhiram Nagubandi
*  rnaguban
*  pa6
*****************************************************************************************/
static const long base = 1000000000;
static const long power = 9;
//-----------------------------------------------------------------------------
// Biginterger.cpp
// Implementation file for BigTnteger ADT
//-----------------------------------------------------------------------------

/*
Possible Preconditions:
	if (s.length()==0){
		throw std::invalid_argument("BigInteger: Constructor: empty string");
	}
	if (s[0] != '+' || s[0]!= '-'){
		if (!isdigit(s[0])){
			throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
		}
	}
	for (unsigned long i = 0; i <= s.length()-1;i++){
		if (!isdigit(s[i])){
			throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
		}
	}
*/

// Class Constructors & Destructors ----------------------------------------

// BigInteger()
// Constructor that creates a new BigInteger in the zero state: 
// signum=0, digits=().

BigInteger::BigInteger(){
		signum = 0;
		digits = List();
}

// BigInteger()
// Constructor that creates a new BigInteger from the string s.
// Pre: s is a non-empty string consisting of (at least one) base 10 digit
// {0,1,2,3,4,5,6,7,8,9}, and an optional sign {+,-} prefix.
BigInteger::BigInteger(std::string s){
	if (s=="0"){
		signum = 0;
		return;
	}
	if (s.length()==0){
		throw std::invalid_argument("BigInteger: Constructor: empty string");
	}
	
	if (s[0] != '+' && s[0]!= '-'){
		if (!isdigit(s[0])){
			//printf("here\n");
			throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
		}
	}
	
	
	for (unsigned long i = 1; i <= s.length()-1;i++){
		if (!isdigit(s[i])){
			//printf("here123\n");
			throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
		}
	}

	//The string s will begin with an
	// optional sign ('+' or '-'), followed by decimal digit characters {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
	if (s[0]=='-' || s[0]=='+'){
		if (s[0]=='-'){
			signum = -1;
		} else {
			signum = 1;
		}
		s = s.substr(1);
	} else {
		signum = 1;
	}
	
	// get rid of leading zeros in the string. 
	unsigned long i = 0; 
	while(true){
		if (s[i]=='0'){
			i++;
		}
		else {
			break;
		}
	}
	s = s.substr(i);

	for (unsigned long y = s.length() ; y > 0 ;){
		std::string strnum;
		if (y<power){
			unsigned long x = y;
			y = 0;
			//printf("here\n");
			strnum = s.substr(y,x);
			//printf("%s\n",strnum.c_str());
			long num = std::stol(strnum);
			digits.insertAfter(num);

		}else{
			y -= power;
			strnum = s.substr(y,power);
			//printf("%s\n",strnum.c_str());
			long num = std::stol(strnum);
			digits.insertAfter(num);
		}
	} 
	//std::cout << "digits = " << digits << std::endl;
}
	

// BigInteger()
// Constructor that creates a copy of N.
BigInteger::BigInteger(const BigInteger& N){
	signum = N.signum;
	digits = List(N.digits);
}


   // Access functions --------------------------------------------------------

   // sign()
   // Returns -1, 1 or 0 according to whether this BigInteger is negative, 
   // positive or 0, respectively.
int BigInteger::sign() const{
	return signum;
}

   // compare()
   // Returns -1, 1 or 0 according to whether this BigInteger is less than N,
   // greater than N or equal to N, respectively.
int BigInteger::compare(const BigInteger& N) const{
	int equal = 0;
	int greater = 1;
	int less_than = -1;
	
	BigInteger x(*this);
	BigInteger y(N);
	x.signum = signum;
	y.signum = N.signum;
	
	if (x.signum > y.signum){
		//printf("12343\n");
		return greater;
	}   

	if (x.signum < y.signum){
		//printf("here\n");
		return less_than;
	}
	
	if (x.digits.length() > y.digits.length()){
		//printf("-12343\n");
		return greater;
	}
	
	if (x.digits.length() < y.digits.length()){
		//printf("-12341231233\n");
		return less_than;
	}
	
	//printf("X length = %d\n", x.digits.length());
	//printf("Y length = %d\n", y.digits.length());
	//printf("X signum = %d\n", x.signum);
	//printf("Y signum = %d\n", y.signum);
	
	x.digits.moveFront();
	y.digits.moveFront();
	while(x.digits.position() < x.digits.length()){
		long x_val = x.digits.moveNext();
		long y_val = y.digits.moveNext();
		//printf("X_Val = %ld\n", x_val);
		//printf("Y_Val = %ld\n", y_val);
		if (x.signum * x_val > y.signum * y_val){
			return greater;
		}
		if (x.signum * x_val < y.signum * y_val){
			return less_than;
		}
		if (x.signum * x_val == y.signum * y_val){
			continue;
		}		
	}
	//std::cout << "digits = " << x.digits << std::endl;
	//std::cout << "digits = " << y.digits << std::endl;
	
	//printf("123\n");
	return equal;
}


   // Manipulation procedures -------------------------------------------------

   // makeZero()
   // Re-sets this BigInteger to the zero state.
void BigInteger::makeZero(){
	signum = 0;
	digits.clear();
}

   // negate()
   // If this BigInteger is zero, does nothing, otherwise reverses the sign of 
   // this BigInteger positive <--> negative. 
void BigInteger::negate(){
	signum *= -1;
}

   // Helper Functions --------------------------------------------------------

// negateList()
// Changes the sign of each integer in List L. Used by sub().
void negateList(List& L){
	L.moveBack();
	while (L.position() > 0){
		long L_val = L.movePrev() * -1;
		L.setAfter(L_val);
	}
}

// sumList()
// Overwrites the state of S with A + sgn*B (considered as vectors).
// Used by both sum() and sub().
void sumList(List& S, List A, List B, int sgn){
	S.clear();
	A.moveBack();
	B.moveBack();
	while (A.position() > 0 || B.position()>0){
		long A_val;
		long B_val;
		if (A.position() > 0 && B.position()>0){
			A_val = A.movePrev();
			B_val = B.movePrev();
			S.insertAfter(A_val+ (sgn * B_val));
		}
		else if (A.position() > 0){
			A_val = A.movePrev();
			S.insertAfter(A_val);
		} 
		else {
			B_val = B.movePrev();
			S.insertAfter(sgn * B_val);
		}
	}
}

// normalizeList()
// Performs carries from right to left (least to most significant
// digits), then returns the sign of the resulting integer. Used
// by add(), sub() and mult().
int normalizeList(List& L){
	long carry = 0;
	long value = 0;
	L.moveBack();
	while (L.position()>=0){
		value = L.movePrev();
		value += carry;
		carry = value/base;
		/*
		if (L.position()==0 && carry !=0){
			L.insertBefore(carry);
			if (carry>0){
				std::cout << "L1= " << L << std::endl;
				return 1;
			}
			else {
				std::cout << "L2 = " << L << std::endl;
				return -1;
			}
		}
		*/
		if (L.position()==0){
			if (value>=0){
				if (value > base){
					long updated_val3 = value % base;
					//printf("updated_val3 = %ld\n", updated_val3);
					L.setAfter(updated_val3);
					L.insertBefore(carry);
					//std::cout << "normalize3= " << L << std::endl;
					L.moveFront();
					while(L.position() < L.length()){
						long z = L.moveNext();
						if (z==0){
							L.eraseBefore();
						}
						else {
							break;
							}
					}
					if (L.length()==0){
							return 0;
					}
					return 1;				
				}else{
					L.setAfter(value);
					//std::cout << "normalize4= " << L << std::endl;
					L.moveFront();
					while(L.position() < L.length()){
						long z = L.moveNext();
						if (z==0){
							L.eraseBefore();
						}
						else {
							break;
							}
					}
					if (L.length()==0){
							return 0;
					}
					return 1;
				}
			}
			if (value<0){
				L.setAfter(value);
				//std::cout << "normalize5= " << L << std::endl;
				L.moveFront();
				while(L.position() < L.length()){
					long z = L.moveNext();
					if (z==0){
						L.eraseBefore();
					}
					else {
						break;
						}
				}
				if (L.length()==0){
						return 0;
				}
				return -1;
			}			
		}
		else {
			//printf("here123\n");
			//printf("Value = %ld\n", value);
			//value += carry;
			//printf("Value1 = %ld\n", value);
			//carry = value/base;
			//printf("Value2 = %ld\n", value);
			if (value < 0){
				carry-=1;
				long added_value = -1 * base * carry;
				long updated_val = value + added_value;
				L.setAfter(updated_val); 
			}
			else if (value > base){
				long updated_val2 = value % base;
				//printf("updated_Vasl2 = %ld\n", updated_val2);
				L.setAfter(updated_val2);
				//std::cout << "L= " << L << std::endl;
			}
			
			else{
				L.setAfter(value);
				continue;
			}
		}
	}
	//std::cout << "L4= " << L << std::endl;
	L.moveFront();
	while(L.position() < L.length()){
		long z = L.moveNext();
		if (z==0){
			L.eraseBefore();
		}
		else {
			break;
			}
		}
	if (L.length()==0){
		return 0;
	}
	return 1;
}

// shiftList()
// Prepends p zero digits to L, multiplying L by base^p. Used by mult().
//Got Puesdocode from Mahyar
void shiftList(List& L, int p){
	L.moveBack();
	int i=0;
	while (i<p){
		L.insertAfter(0);
		i++;
	}
}

// scalarMultList()
// Multiplies L (considered as a vector) by m. Used by mult().
//Got Puesdocode from Mahyar
void scalarMultList(List& L, ListElement m){
	if (m!=1){
		L.moveBack();
		while (L.position()>0){
			long x = L.movePrev();
			if (x==0){
				continue;
			}else {
				L.setAfter(x*m);
			}
		}
	}
}

   // BigInteger Arithmetic operations ----------------------------------------

   // add()
   // Returns a BigInteger representing the sum of this and N.
BigInteger BigInteger::add(const BigInteger& N) const{
	BigInteger A(*this);
	BigInteger B(N);
	List SS;
	BigInteger S;
	
	long a_sign = A.signum;
	long b_sign = B.signum;
	if (a_sign != b_sign){
		if (a_sign<0){
			A.signum*=-1;
			return B.sub(A);
		}
		else {
			//printf("Look Here\n");
			return B.add(A);
		}
	}
	
	sumList(SS, A.digits, B.digits, 1);
	//std::cout << "SS = " << SS << std::endl;
	int x = normalizeList(SS);


	S.signum = A.signum;	
	if (x == -1){
		S.signum = x;
		negateList(SS);
		normalizeList(SS);
	} else if (x==0){
		S.signum = 0;
	}

	S.digits = SS;
	//std::cout << "S.digits = " << S.digits << std::endl;
	//std::cout << "S.signum = " << S.signum << std::endl;
	return S;
}

   // sub()
   // Returns a BigInteger representing the difference of this and N.
BigInteger BigInteger::sub(const BigInteger& N) const{
	BigInteger A(*this);
	BigInteger B(N);
	List SS;
	BigInteger S;
	
	if (B.signum == -1){
		B.signum*=-1;
		return A.add(B);
	}
	else if (A.signum == -1 && B.signum == 1){
		B.signum*=-1;
		return A.add(B);
	}
	
	sumList(SS, A.digits, B.digits, -1);
	int x = normalizeList(SS);
	if (SS.length()==0){
		S.signum = 0;
		return S;
	}

	if (x == -1){
		S.signum = x;
		negateList(SS);
		normalizeList(SS);
	} else{
		S.signum = x;
	}
	S.digits = SS;
	return S;
}

   // mult()
   // Returns a BigInteger representing the product of this and N. 
   //Got Puesdocode from Mahyar
BigInteger BigInteger::mult(const BigInteger& N) const{
	BigInteger A(*this);
	BigInteger B(N);
	int col = 0; // column number
	BigInteger Prod;
	List A_list = A.digits;
	List B_list = B.digits;
	List C;
   
   List& P = Prod.digits;
   	if (A.sign() != B.sign()){
		Prod.signum = -1;
	} else{
		Prod.signum = 1;
	}
	
	if (A.sign()==0 || B.sign()==0){
		Prod.signum = 0;
		return Prod;
	}
   
   // move to the front of "B"
	B_list.moveBack();
   // iterate thriugh "B":
	while (B_list.position()>0){
		C = A_list;
		long x = B_list.movePrev();
		scalarMultList(C, x);
		//std::cout << "Scalarmult C= " << C << std::endl;
		shiftList(C, col);
		//std::cout << "Shifted C= " << C << std::endl;
		sumList(P, P, C, 1);
		//std::cout << "P= " << P << std::endl;
		int y = normalizeList(P);
		if (y == -1){
			negateList(P);
			normalizeList(P);
		}
		col++;
   }
        // set C to A
        // set a variable "x" of type ListElement to get the data of the next element of B
        // multiply list C by "x"
        
        // normalize C by shifting the list by the number of columns "col"
        // reassign P by adding the Lists C and P 
        // normalize P
        //increment the column number

   return Prod;
		
}


   // Other Functions ---------------------------------------------------------

   // to_string()
   // Returns a string representation of this BigInteger consisting of its
   // base 10 digits. If this BigInteger is negative, the returned string 
   // will begin with a negative sign '-'. If this BigInteger is zero, the
   // returned string will consist of the character '0' only.
   //Puesdocode provided by Sebastian Carbonero
std::string BigInteger::to_string(){
	digits.moveFront();
	while(digits.position() < digits.length()){
		long z = digits.moveNext();
		if (z==0){
			digits.eraseBefore();
		}
		else {
			break;
		}
	}
	if (digits.length()==0){
		signum = 0;
		return "0";
	}
	
	std::string s;
	if (signum == -1){
		s += '-';
	}
	digits.moveFront();
	while(digits.position() < digits.length()){
		long elem = digits.moveNext();
		std::string elemstr = std::to_string(elem);
		
		while(digits.position()!=1 && elemstr.length() < power){
			elemstr = '0' + elemstr;
		}
		s += elemstr;
		unsigned long i = 0; 
		while(true){
			if (s[i]=='0'){
				i++;
			}
			else {
				break;
			}
		}
		s = s.substr(i);
	}
	return s;
	}


   // Overriden Operators -----------------------------------------------------
   
   
      // operator<<()
   // Inserts string representation of N into stream.
std::ostream& operator<<( std::ostream& stream, BigInteger N ){
	return stream << N.to_string();
}

   // operator==()
   // Returns true if and only if A equals B. 
bool operator==( const BigInteger& A, const BigInteger& B ){
	int x = A.compare(B);
	if ( x == 0){
		//printf("Rohit");
		return true;
	}	
	return false;
}

   // operator<()
   // Returns true if and only if A is less than B. 
bool operator<( const BigInteger& A, const BigInteger& B ){
	int x = A.compare(B);
	if ( x == -1){
		//printf("Rohit\n");
		return true;
	}	
	return false;
}

   // operator<=()
   // Returns true if and only if A is less than or equal to B. 
bool operator<=( const BigInteger& A, const BigInteger& B ){
	int x = A.compare(B);
	if ( x == -1 || x == 0){
		//printf("Rohit\n");
		return true;
	}	
	return false;
}

   // operator>()
   // Returns true if and only if A is greater than B. 
bool operator>( const BigInteger& A, const BigInteger& B ){
	int x = A.compare(B);
	//printf("A is less than: %d" , x);
	if ( x == 1){
		//printf("Rohit\n");
		return true;
	}	
	return false;
}

   // operator>=()
   // Returns true if and only if A is greater than or equal to B. 
bool operator>=( const BigInteger& A, const BigInteger& B ){
	int x = A.compare(B);
	if (x == 1 || x == 0){
		//printf("Rohit\n");
		return true;
	}	
	return false;
}

   // operator+()
   // Returns the sum A+B. 
BigInteger operator+( const BigInteger& A, const BigInteger& B ){
	return A.add(B);
}

   // operator+=()
   // Overwrites A with the sum A+B. 
BigInteger operator+=( BigInteger& A, const BigInteger& B ){
	return A = A.add(B);
}

   // operator-()
   // Returns the difference A-B. 
BigInteger operator-( const BigInteger& A, const BigInteger& B ){
	return A.sub(B);
}

   // operator-=()
   // Overwrites A with the difference A-B. 
BigInteger operator-=( BigInteger& A, const BigInteger& B ){
	return A = A.sub(B);
}

   // operator*()
   // Returns the product A*B. 
BigInteger operator*( const BigInteger& A, const BigInteger& B ){
	return A.mult(B);
}
   // operator*=()
   // Overwrites A with the product A*B. 
BigInteger operator*=( BigInteger& A, const BigInteger& B ){
	return A = A.mult(B);
}

