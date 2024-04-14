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
int length(node*head){
    //base case
    if(head==nullptr){
        return 0 ;
    }
    //hypothesis case 
    node*temp =head;
     int l= length(temp->next);

    //induction step 
    return l+1;
}
node*rotate(node*head,int k ){
    if(head==nullptr||k==0){
        return head; 
    }
    node*temp=head;
    node*prev=head;
    int l= length(head);
    if(k%l==0){
        return head;
    }
    while(temp->next!=nullptr){
        prev=temp;
        temp=temp->next;
    }
    temp->next=head;
    for(int i =0;i<l-k-1;i++){
        head=head->next;
    }
    node*newhead=head->next;
    head->next=nullptr;
    return newhead;
}

int main(){
    cout<<"enter the new linkedlist "<<endl;
    node*head=takeinput_better();
    int k ;
    cout<<"enter the value of k :";
    cin>>k;
    node*rotatedhead=rotate(head, k );
    cout<<"the linkedlist after rotation is "<<endl;
    print(rotatedhead);

}