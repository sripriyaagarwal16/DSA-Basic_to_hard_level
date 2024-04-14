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
node* skipMdeleteN(node* head, int M, int N) {
    if (N == 0) {
        return head; 
    }
    if (M == 0 || head == nullptr) {
        return nullptr;
    
    node* temp = head;
    while (temp != nullptr) {
        for (int i = 0; i < M - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            break; 
        }
        
     
        node* temp1 = temp->next; 
        node* prev = temp; 
        for (int i = 0; i < N && temp1 != nullptr; i++) {
            node* next = temp1->next; 
            delete temp1; 
            temp1 = next; 
        }
        prev->next = temp1;
        temp = temp1;
    }
    
    return head;
}
}

int main(){
    cout<<"enter the linkedilist"<<endl;
    node*head=takeinput_better();
    int M;
    cout<<"enter the no. of digits to be skipped:";
    cin>>M;
    int N; 
    cout<<"enter the number of digits to be deleted:";
    cin>>N;
    head=skipMdeleteN( head, M, N);
    cout<<"the linkedlist after updation is "<<endl;
    print(head);

}