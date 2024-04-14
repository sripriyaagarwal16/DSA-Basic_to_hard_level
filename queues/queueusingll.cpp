#include<iostream>
using namespace std;
class node{
   public:
   int data; 
   node*next;
//Constructor
   node(int data){
    this->data=data;
    next=nullptr;
   }
};
class queueusingLL{
    node*head; 
    node*tail;
    int size;
   
    public:
    queueusingLL(){
        head=nullptr;
        tail=nullptr;
        size=0;
        
    }
    //enqueue function 
    void enqueue(int element){
        node*newnode=new node(element);
        if(head==nullptr&&tail==nullptr){
            head=newnode;
            tail=newnode;
            size++;
        }
        tail->next=newnode;
        tail=newnode;
        size++;

    }
    //size function
    int size(){
        return size;
    }    
    //isempty function 
    bool isempty(){
        return size==0;
    }
    //dequeue function 
    int dequeue(){
        if(isempty()){
            cout<<"queue is empty"<<endl;
            return -1; 
      }
      int ans= head->data;
      head=head->next;
      node*temp=head;
      delete temp;
      size--;
      return ans;
    }
    //front function 
    int front(){
      if(isempty()){
            cout<<"queue is empty"<<endl;
            return -1; 
      }
      int front=head->data;
      return front;
    }


};
