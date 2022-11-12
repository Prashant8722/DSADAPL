//Hash Header File.......hash.h//
#include<iostream>
using namespace std;
#include<string>

template <typename v>
class mapNode{
public:
string key;
v value;
mapNode* next;
mapNode(string key,v value){
this->key=key;
this->value=value;
next = NULL;
}
~mapNode(){
delete next;
}
};

template <typename v>
class ourmap{
mapNode<v>** buckets;
int count;
int numbucket;
public:
ourmap(){
count=0;
numbucket=5;
buckets=new mapNode<v>*[numbucket];
for(int i=0;i<numbucket;i++){
buckets[i]=NULL;
}
}
~ourmap(){
for(int i=0;i<numbucket;i++){
delete buckets[i];
}
delete []buckets;
}
private:
int getBucketIndex(string key){
int hashcode=0;
int curr_co=1;
for(int i=key.length()-1;i>=0;i--){
hashcode+=key[i]*curr_co;
hashcode=hashcode%numbucket;
curr_co*=37;
curr_co=curr_co%numbucket;
}
return hashcode%numbucket;
}
public:
void insert(string key,v value){
int bucketindex=getBucketIndex(key);
mapNode<v>* head=buckets[bucketindex];
while(head!=NULL){
if(head->key==key){
head->value=value;
return;
}
head=head->next;
}
head=buckets[bucketindex];
mapNode<v>* node=new mapNode<v>(key,value);
node->next=head;
buckets[bucketindex]=node;
count++;
}

int size(){
return count;
}
v getValue(string key) {
int bucketIndex = getBucketIndex(key);
mapNode<v>* head = buckets[bucketIndex];
while (head != NULL) {
if (head->key == key) {
return head->value;
}
head = head->next;
}
return 0;
}
v remove (string key){
int bucketindex=getBucketIndex(key);
mapNode<int>* prev=NULL;
mapNode<int>* head=buckets[bucketindex];
while(head!=NULL){
if(head->key==key){
if(prev==NULL){
buckets[bucketindex]=head-
>next;
}
else{
prev->next=head->next;
}
v value=head->value;
head->next=NULL;
delete head;
count--;
return value;
}
prev = head;
head = head->next;
}
return 0;

}
};
