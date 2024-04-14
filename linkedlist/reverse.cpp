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
void print(node*head){
    node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
node*reverse(node*head){
    if(head==nullptr){
        return head;
    }
   node*prev= nullptr;
   node*current=head;
   node*next=nullptr;
   while(current!=nullptr){
     next=current->next;
     current->next=prev;
     prev=current;
     current =next;
   }
   head=prev;
   return head;
}
node*reverse_2(node*head){
    if(head==nullptr){
        return head;
    }
    node*tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;

    }
    head=tail;
    return ;
}