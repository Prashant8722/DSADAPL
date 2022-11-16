#include <fstream>
#include <iostream>
using namespace std;
 
int main () {
   char in[100];
   char pre[100];
   // open a file in read mode.
   ifstream infile; 
   infile.open("afile.txt"); 
 
   cout << "Reading from the file" << endl; 
   infile >> in; 

   // write the data at the screen.
   cout << in << endl;
   
   // again read the data from the file and display it.
   infile >> pre; 
   cout << pre << endl; 

   // close the opened file.
   infile.close();
   return 0;
}