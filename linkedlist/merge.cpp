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
node*mergesortedLL(node*head1,node*head2){
    node*finalhead=nullptr;
    node*finaltail=nullptr;
    if(head1==nullptr){
        return head1;
    }
    if(head2==nullptr){
        return head2;
    }
    if(head1->data<head2->data){
        finalhead=head1;
        finaltail=head1;
        head1=head1->next;
    }
    else if (head1->data<head2->data){
        finalhead=head2;
        finaltail=head2;
        head2=head2->next;
    }
    while(head1!=nullptr&&head2!=nullptr){
        if(head1->data<head2->data){
            finaltail->next=head1;
            finaltail=head1;
            head1=head1->next;
        }else{
            finaltail->next=head2;
            finaltail=head2;
            head2=head2->next;
        }
       
    }
     if(head1!=nullptr){
            finaltail->next=head1;
        }else if(head2!=nullptr){
            finaltail->next=head2;
        }
    return finalhead;
}
void print(node*head){
    node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main(){
    node*head1=takeinput_better();
    node*head2=takeinput_better();
    node*newhead=mergesortedLL(head1,head2);
    print(newhead);
}