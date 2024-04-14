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
int length_recursive(node*head){
    //base case
    if(head==nullptr){
        return 0 ;
    }
    //hypothesis case 
    node*temp =head;
     int length= length_recursive(temp->next);

    //induction step 
    return length+1;
}
node*midpoint(node*head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    node*slow=head;
    node*fast=head;
    while(fast->next==nullptr||fast->next->next==nullptr){
        slow=slow->next;
        fast=fast->next->next;

    }
    return slow;
}