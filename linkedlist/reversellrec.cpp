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
class Pair{
    public:
    node*head;
    node*tail;
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
//Time Complexity: O(n^2)
node* reverseLL_rec(node*head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    node*recursive=reverseLL_rec(head-> next);
    node*tail=recursive;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    tail->next=head;
    head->next=nullptr;
    return recursive;

}
//maintain both head and tail 
//time complexity is O(n)
Pair*reverseLL_rec_2(node*head){
    if(head==nullptr||head->next==nullptr){
        Pair *result;
        result->head=head;
        result->tail=head;
        return result;

    }
    Pair* smallresult =reverseLL_rec_2(head->next);
    smallresult->tail->next=head;
    head->next=nullptr;
    Pair*result=new Pair;
    result->head=smallresult->head;
    result->tail=head;
    return result;
}
//time complexity=O(n)
node* reverseLL_rec_3(node*head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    node*recursive=reverseLL_rec(head-> next);
  
    node*tail= head->next;
    tail->next=head;
    head->next=nullptr;
    return recursive;

}

int main(){
    cout<<"enter the linkedlist"<<endl;
    node*head=takeinput_better();
    node*result=reverseLL_rec_3(head);
    cout<<"the likedlist after reverseing the linkedlist"<<endl;
    print(result);
    delete result;
    return 0;
    

}
