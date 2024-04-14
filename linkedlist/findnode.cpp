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
int index(node*head,int data){
    //basecase
   
    if(head==nullptr){
        return -1;
    }
    if(head->data==data){
       int i=0;
       return i;
    }
    int i=index(head->next,data);
    if(i==-1){
        return -1;
    }
    return i+1;

}
node *takeinput_better(){
     int data;
    cin>>data;
    node*head=nullptr;
    node*tail=nullptr;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
           tail->next=newnode;
           tail=tail->next;
        }
        cin>>data;
    }

      return head;
    
}

int main(){
    node*head=takeinput_better();
    int data;
    cout<<"Enter the data you want to find index of "<<endl;
    cin>>data;
    int i =index(head,data);
    cout<<"The index of the this data is "<<i<<endl; 
   
}