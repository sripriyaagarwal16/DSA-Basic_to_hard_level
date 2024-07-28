#include<iostream>
#include<fstream>
using namespace std; 
int main(){
   ofstream of; 
   of.open("sri.text");
   of<<"Hi everyone i am sripriya";
   of<<"I am very excited to meet you all";
   of.close();
   char buff[80];
   ifstream inf; 
   inf.open("sri.text");
   while(inf){
    inf.getline(buff,80);
    cout<<buff<<endl;
   }
   inf.close();
   return 0;

   


}