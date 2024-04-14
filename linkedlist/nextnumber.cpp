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

node *nextnumberhelper(node* head,node*tail){
    if(head==NULL){
        return NULL;
    }
    
    if(tail->data!=9){
        tail->data+=1;
    }
    else{
        tail->data=0;
        node*temp=head;
        while(temp!=tail){
            temp=temp->next;
        }
        nextnumberhelper(head,temp);
        if(temp==head){
          node*newhead=new node(1);
          newhead->next=head;
          head=newhead;
        }
    }
    return head;
    
}
node* nextnumber(node*head){
    node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    head=nextnumberhelper(head,tail);
    return head;

}
int main(){
    node*head=takeinput_better();
    head=nextnumber(head);
    print(head);
}