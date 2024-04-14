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
node*evenafterodd(node*head){
    if(head==nullptr||head->next==nullptr){
        return head; 
    }
    node*oddhead=nullptr;
    node*oddtail=nullptr;
    node*evenhead=nullptr;
    node*eventail=nullptr;
    node*temp=head;
    while(temp!=nullptr){
        if(temp->data%2!=0){
            if(oddhead==nullptr){
              oddhead=temp;
              oddtail=temp;
          }
            else{
              oddtail->next=temp;
              oddtail=temp;

            }
        }
        else{
            if(evenhead==nullptr){
                evenhead=temp;
                eventail=temp;
            }
            else{
                eventail->next=temp;
                eventail=temp;
            }
        }
        temp=temp->next;
       
    }
    if(oddhead==nullptr){
        eventail->next=nullptr;
        return evenhead;
    }
    else if(evenhead==nullptr){
        oddtail->next=nullptr;
        return oddhead; 
    }
    oddtail->next=evenhead;
    eventail->next=nullptr;
    return oddhead;
}
int main(){
    cout<<"enter linkedlist"<<endl;
    node*head=takeinput_better();
    node*eao=evenafterodd(head);
    cout<<"the even after odd list is "<<endl;
    print(eao);
}