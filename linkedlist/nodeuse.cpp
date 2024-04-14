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
//print at ith position
void print_i(node*head,int n ){
    node*temp=head;
   for(int i =0;i<n;i++){
      temp=temp->next;
   }
   cout<<temp->data<<endl;
}
//length of linkedlist
int length(node*head){
    node*temp=head;
    int n =0;
    while(temp!=nullptr){
        n++;
        temp=temp->next;
    }
    return n ;
}
//length of list recursively 
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
//inserting element in the linkedlist 
void insertnode(node*head,int n,int data ){
      node* newnode=new node(data);
      node*temp_next=head;
      node*temp_prev=head;
      if(n==0){
        newnode->next=head;
        head=newnode;
      }
      else{
      for(int i=0;i<n;i++){
         temp_next=temp_next->next;
       
      }
      for(int i =0;i<n-1;i++){
        temp_prev=temp_prev->next;
      }
      temp_prev->next=newnode;
      newnode->next=temp_next;
      }

}
//inserting node better
node* insertnode_better(node*head,int n,int data){
    node*newnode=new node(data);
    int count=0;
    node*temp=head;
    if(n==0){
        newnode->next=head;
        head=newnode;
        return head;
    }
    while(temp!=nullptr&&count<n-1){
          temp=temp->next;
          count++;
    }
    if(temp!=nullptr){
        node*a=temp->next;
        temp->next=newnode;
        newnode->next=a;
    }
    return head;
}
//inserting node recursively 
node*insert_recursive(node*head,int pos , node*newnode){
    //base case
    if(pos<0){
        return head;
    }
    if(pos==0||head==nullptr){
        newnode->next=head;
        head=newnode;
        return head;

    }
    //hypothesis case 
    head->next=insert_recursive(head->next, pos-1 , newnode);
    //induction step 
    return head; 

}
//deleting the node in a linkedlist
node* deleteNode(node* head, int pos) {
    if (head == NULL) {
        // The list is empty, nothing to delete
        return NULL;
    }

    if (pos == 0) {
        node* temp = head;
        head=head->next;
        delete temp;
        return head;
    }

    int count = 0;
    node* temp = head;

    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp != NULL && temp->next != NULL) {
        node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        free(nodeToDelete);
    }

    return head;
}
//delete node recursively
node * delete_recursive(node*head, int pos){
    //base case
    if(pos<0||head==nullptr){
        return head;
    }
    if(pos==0){
        node*temp=head;
        head=temp->next;
        delete temp; 
        return head;
    }
    //hypothesis case
    head->next=delete_recursive(head->next, pos-1);
    //induction step 
    return head; 

}
int main(){
    //Statically
    /*node n1(5);
    node*head=&n1;
    node n2(10);
    node n3(15);
    node n4(13);
    node n5(18);
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;

    print(head);    
    */
    //dynamically 
    /*
   node*n1=new node(5);
   node*head=n1;
   node*n2=new node(12);
   n1->next=n2;
   node*n3=new node (15);
   n2->next=n3;
   node*n4=new node(18);
   n3->next=n4;
   node*n5=new node(10);
   n4->next=n5;
   print(head);*/
   node*head=takeinput_better();
   //int l=length(head);
   //cout<<"the length of the linked list is "<<l<<endl;
   //print(head);
   //int n ;
   //cin>>n;
   /*cout<<"the linkedlist before inserting"<<endl;
   print(head);
   int n ;
   cout<<"the index where we have to insert"<<endl;
   cin>>n;
   int data;
   cout<<"data to be inserted"<<endl;
   cin>>data;
   node*newnode=new node(data);
   head=insert_recursive(head,n, newnode );
   cout<<"the linkedlist after inserting"<<endl;
   print(head);*/
   int pos;
   cout<<"the position you want to delete"<<endl;
   cin>>pos;
   head=delete_recursive(head, pos);
   cout<<"the linkedlist after deletion "<<endl;
   print(head);
   //int length =length_recursive(head);
   //cout<<"length of linkedlist is "<<length<<endl;*/

   


}