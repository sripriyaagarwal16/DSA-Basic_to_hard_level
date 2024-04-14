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
node *takeinput(){
    int data;
    cin>>data;
    node*head=nullptr;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==nullptr){
            head=newnode;
        }
        else{
            node*temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newnode;
        }
        cin>>data;
    }

      return head;
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
void print(node*head){
    node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
node* swapping(node* head, int m, int n) {
    if (head == nullptr || m <= 0 || n <= 0) {
        return head; 
    }
    if (m == n) {
        return head;
    }

    node* prev_i = head;
    node* j_current = head;
    for (int i = 0; i < m - 1 && prev_i != nullptr; i++) {
        prev_i = prev_i->next; 
    }
    if (prev_i == nullptr || prev_i->next == nullptr) {
        return head; 
    }

    for (int j = 0; j < n && j_current != nullptr; j++) {
        j_current = j_current->next;
    }
    if (j_current == nullptr) {
        return head; 
    }

    node* a = prev_i->next;
    node* b = j_current->next;
    prev_i->next = j_current;
    j_current->next = a->next;
    a->next = b;

    return head;
}
