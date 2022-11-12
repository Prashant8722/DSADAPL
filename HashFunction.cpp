//HashFunction.cpp
#include<iostream>
#include "hash.h"
using namespace std;
#include<string>
int main(){
ourmap<int> map;
for(int i=0;i<10;i++){
char c='0'+i;
string key="abc";
key=key+c;
int value=i+1;
map.insert(key,value);
cout<<"{"<<key<<":"<<value<<"}"<<endl;
}
cout<<map.size()<<endl;
map.insert("abcaa",1);
map.insert("Roman",12);
cout<<"CURRENT SIZE OF MAP IS"<<":"<<map.size()<<endl;
//cout<<map.size()<<endl;
cout<<"GETVALUE AT A GIVEN KEY"<<":"<<map.getValue("abc7")<<endl;
cout<<"REMOVED VALUE :"<<map.remove("abc7")<<endl;
cout<<"AFTER REMOVE abc7 size is"<<":"<<map.size()<<endl;
}
