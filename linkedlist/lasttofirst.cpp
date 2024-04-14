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
node*appendlasttofirst(node*head,int n ){
    //base case
    if(head==nullptr||n==0){
        return head;
    }
    int l=length_recursive(head);
    if(n>l){
        return head;
    }
    node*temp=head;
    for(int i =0;i<l-n-1;i++){
       temp=temp->next;
    }
    node*newhead=temp->next;
    temp->next=nullptr;
    node*tail=newhead;
    while(tail->next!=nullptr){
       tail=tail->next;
    }
    tail->next=head;
    return newhead;
    
    
}
void print(node*head){
    node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main(){
    node*head=takeinput_better();
    int n; 
    cout<<"enter the number from where you want the linkedlist to go at first"<<endl;
    cin>>n;
    head=appendlasttofirst(head,n );
    print(head);

}