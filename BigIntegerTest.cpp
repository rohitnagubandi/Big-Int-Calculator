/****************************************************************************************
*  Rohit Venkat Abhiram Nagubandi
*  rnaguban
*  pa6
*****************************************************************************************/

//-----------------------------------------------------------------------------
//  BigIntegerClient.cpp 
//  A test client for the BigInteger ADT
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<stdexcept>
#include"BigInteger.h"

using namespace std;

int main(){

//Tests for BigInteger Constructor

	try{
		string s1 = "";
		BigInteger A = BigInteger(s1);
	}catch( std::invalid_argument& e ){
		cout << e.what() << endl;
		cout << "continuing without interruption\n" << endl;
	}
	   
	try{
		string s1 = "1234324234asd1232";
		BigInteger A = BigInteger(s1);
	}catch( std::invalid_argument& e ){
		cout << e.what() << endl;
		cout << "continuing without interruption\n" << endl;
	}
   
//Tests For Compare
	printf("---------------------Equal Tests---------------------\n");
	string s1 = "2441583736913160704457829347598475938475934859374589739459345";
	BigInteger A = BigInteger(s1);
	cout << "A = " << A << endl;
	string s2 = "2441583736913160704457829347598475938475934859374589739459345";
	BigInteger B = BigInteger(s2);
	cout << "B = " << B << endl;	
	cout << "A==B : " << ((A==B)) << endl;
	cout << endl;
	
	string s3 = "-2441583736913160704457829347598475938475934859374589739459345";
	BigInteger C = BigInteger(s3);
	cout << "C = " << C << endl;	
	string s4 = "2441583736913160704457829347598475938475934859374589739459345";
	BigInteger D = BigInteger(s4);
	cout << "D = " << D << endl;
	cout << "C!=D : " << ((C==D)) << endl;
	cout << endl;


	string s5 = "2441583736913160704457829347598475938475934859374589739459346";
	BigInteger E = BigInteger(s5);
	cout << "E = " << E << endl;
	string s6 = "2441583736913160704457829347598475938475934859374589739459345";
	BigInteger F = BigInteger(s6);
	cout << "F = " << F << endl;
	cout << "E>F : " << ((E>F)) << endl;
	cout << endl;
	
	string s7 = "2441583736913160704457829347598475938475934859374589739459345";
	BigInteger G = BigInteger(s7);
	cout << "G = " << G << endl;
	string s8 = "2441583736913160704457829347598475938475934859374589739459346";
	BigInteger H = BigInteger(s8);
	cout << "H = " << H << endl;
	cout << "G<H : " << ((G<H)) << endl;
	cout << endl;

//Tests For Add and normalize
	printf("---------------------ADD TEST---------------------\n");
	string s9 = "+111122223333";
	BigInteger I = BigInteger(s9);
	cout << "I = " << I << endl;
	string s10 = "-111122223333";
	BigInteger J = BigInteger(s10);
	cout << "J = " << J << endl;
	BigInteger K = I+J;
	cout << "K =  : " << K << endl;
	cout << "K_Sign =  : " << K.sign() << endl;
	cout << endl;
	
	
//Tests For Sub and normalize
	printf("---------------------SUB TEST---------------------\n");
	string s11 = "-4883167473826321408915658695196951876951869718749179478918691";
	BigInteger L = BigInteger(s11);
	cout << "L = " << L << endl;
	string s12 = "2441583736913160704457829347598475938475934859374589739459345";
	BigInteger M = BigInteger(s12);
	cout << "M = " << M << endl;
	BigInteger N = L-M;
	cout << "N =  : " << N << endl;
	cout << endl;

//Tests For Mult and normalize
	printf("---------------------MULT TEST---------------------\n");
	string s13 = "123";
	BigInteger O = BigInteger(s13);
	cout << "O_string = " << O << endl;
	string s14 = "123";
	BigInteger P = BigInteger(s14);
	cout << "P_string = " << P << endl;
	BigInteger Q = O*P;
	cout << "Q =  : " << Q << endl;
	cout << endl;
	
	return 0;
}
