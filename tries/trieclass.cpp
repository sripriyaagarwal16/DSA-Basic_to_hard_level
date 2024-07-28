#include<iostream>
using namespace std;
class node{
    public:
    char data;
    bool isterminal;
    node*child[26];
    int endcount;
    node(char data){
        this->data=data;
        isterminal=false;
        for(int i =0;i<26;i++){
            child[i]=NULL;
        }
        this->endcount=0;
    }
    //Insert function 
    void insert(node*root,string word){
        if(word.size()==0){
            return;
        }
        node *temp=root;
        for(int i =0;i,word.size();i++){
           int index=word[i]-'a';
           if(temp->child[index]==NULL){
            node*newnode=new node(word[index]);
            temp->child[index]=newnode;
           }
           temp=temp->child[index];
        }
        temp->isterminal=true;
        temp->endcount++;
        cout<<"Inserted the word"<<" "<<word<<endl;

    }

    //search in tries 
    bool find(node*root,string word){
        node*temp=root;
        for(int i =0;i<word.size();i++){
            int index=word[i]-'a';
            if(temp->child[index]==NULL){
                return false;
            }
            else{
                temp=temp->child[index];
            }
        }
        if(temp->isterminal==true){
            return true;
        }
        else{
            return false;
        }
    }

    //remove in tries 
    void remove(node*root,string word){
        node*temp=root;
        for(int i =0;i<word.size();i++){
            int index=word[i]-'a';
            if(temp->child[index]==NULL){
                return ;
            }
            temp=temp->child[index];

        }
        temp->endcount--;
    }




};
int main(){
    node*root=new node('$');
    int n ;
    cin>>n;
    string word;
    while(n--){
        cin>>word;
        root->insert(root,word);
    }

}