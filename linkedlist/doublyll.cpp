#include<iostream>
using namespace std; 
class Node{
   public:
   int data; 
   Node*next;
   Node*prev;
//Constructor
   Node(int data){
    this->data=data;
    next=nullptr;
    prev=nullptr;
   }
};
Node *takeinput_better(){
     int data;
    cin>>data;
    Node*head=nullptr;
    Node*tail=nullptr;
    while(data!=-1){
        Node *newnode=new Node(data);
        if(head==nullptr){
            head=newnode;
            tail=newnode;
            head->prev=nullptr;
        }
        else{
           Node*temp=head;
           tail->next=newnode;
           tail=tail->next;
           tail->prev=temp;
           temp=temp->next;
        }
        cin>>data;
    }
    return head;
    
}
bool palindromeDLL(Node*head){
    if(head==nullptr||head->next==nullptr){
        return true;
    }
    Node*start=head;
    Node*end=head;
    while(start!=end&&start->prev!=end){
        if(start->data!=end->data){
            return false;
        }
        start=start->next;
        end=end->prev;
    }
    return true;
}

int main(){
    Node*head=takeinput_better();
    bool ispalindrome=palindromeDLL(head);
    cout<<"the double linked list is a "<<" "<<ispalindrome<<endl;
}