#include<iostream>
#include<fstream>
#include<string>
#include "BigInteger.h"
using namespace std;

/****************************************************************************************
*  Rohit Venkat Abhiram Nagubandi
*  rnaguban
*  pa6
*****************************************************************************************/

int main(int argc, char * argv[]){

   ifstream in;
   ofstream out;

   // check command line for correct number of arguments
   if( argc != 3 ){
      cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
      return(EXIT_FAILURE);
   }

   // open files for reading and writing 
   in.open(argv[1]);
   if( !in.is_open() ){
      cerr << "Unable to open file " << argv[1] << " for reading" << endl;
      return(EXIT_FAILURE);
   }

   out.open(argv[2]);
   if( !out.is_open() ){
      cerr << "Unable to open file " << argv[2] << " for writing" << endl;
      return(EXIT_FAILURE);
   }

	string bigint;
	string blank;
	getline(in,bigint);
	BigInteger A(bigint);
	getline(in,blank);
	getline(in,bigint);
	BigInteger B(bigint);

	BigInteger C("9");
	BigInteger D("16");
	out << A << endl << endl;
	out << B << endl << endl;
	out << A+B << endl << endl;
	out << A-B << endl << endl;
	out << A-A << endl << endl;
	out << (A+A+A)-(B+B) << endl << endl;
	out << A*B << endl << endl;
	out << A*A << endl << endl;
	out << B*B << endl << endl;
	out << ((A*A*A*A).mult(C)+(B*B*B*B*B).mult(D)) << endl << endl;
	in.close();
	out.close();

   return(EXIT_SUCCESS);
}
