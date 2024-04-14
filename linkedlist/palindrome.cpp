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
node* reverseLL_rec_3(node*head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    node*recursive=reverseLL_rec_3(head-> next);
  
    node*tail= head->next;
    tail->next=head;
    head->next=nullptr;
    return recursive;

}
bool ispalindrome(node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    // Reverse the second half of the linked list
    node* slow = head;
    node* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 'slow' is now pointing to the middle (or middle-left for odd length) node
    node* reversed =reverseLL_rec_3(slow->next);

    // Compare original and reversed halves
    while (reversed != nullptr) {
        if (head->data != reversed->data) {
            return false;
        }
        head = head->next;
        reversed = reversed->next;
    }

    return true;
}

int main(){
    cout<<"enter the new linkedlist "<<endl;
    node*head=takeinput_better();
    bool ispal=ispalindrome(head);
    cout<<"the linkedlist is a plaindrome?(true/false) "<<ispal<<endl;


}
