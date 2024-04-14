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
//works only for sorted linkedlist
node*duplicate(node*head){
    if(head==nullptr||head->next==nullptr){
        return head; 
    }
    node*a= head->next;
    if(head->data==a->data){
        node*temp=head;
        head=temp->next;
        delete temp;
        head=duplicate(head);
    }
    else{
    head->next=duplicate(head->next);
    }
    return head;

}
int main(){
    node*head=takeinput_better();
    head=duplicate(head);
    print(head);
}