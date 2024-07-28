#include<iostream>
#include<vector>
using namespace std ; 
template <typename V>
class MapNode{
    public:
    V value;
    string key;
    MapNode*next;
    //Constructor
    MapNode(string key ,V value){
        this->key=key;
        this->value=value;
        next=NULL;
    }
    //Destructor
    ~MapNode(){
        delete next;
    }

};
class ourmap{
    MapNode<V>**bucket;
    int count;
    int numbuckets;
  
        
    
    public:
    ourmap(){
       count=0;
       numbuckets=5;
       bucket=new MapNode<V>*(numbuckets);
       for(int i=0;i<numbuckets;i++ ){
        bucket[i]=NULL;

       }
    }
    ~ourmap(){
        for(int i=0;i<numbuckets;i++ ){
            delete bucket[i];
        }
        delete [] bucket;
    }
    private:
    int getBucketIndex(string key){
        int hashcode=0;
        int currentcoeff=1;
        for(int i=0;i<key.length()-1;i++){
            hashcode+=key[i]*currentcoeff;
            hashcode=hashcode%numbuckets;
            currentcoeff*=37;
            currentcoeff=currentcoeff%numbuckets;
        }
        return hashcode%numbuckets;
    }

    public:

    int size(){
        return count;
    }
    
    V getvalue(string key){
        int bucketindex=getBucketIndex(key);
        MapNode<V>*head=bucket[bucketindex];
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return 0;

          
    }
     int  remove(string key){
        int bucketindex=getBucketIndex(key);
        MapNode<V>*head=bucket[bucketindex];
        MapNode<V>*prev=NULL;
        while(head!=NULL){
            if(head->key==key){
                if(prev==NULL){
                    bucket[bucketindex]=head->next;
                }
                else{
                    prev->next=head->next;
                }
                V value=head->value;
                head->next=NULL;
                delete head;
                size--;
                return value
            }
            prev=head;
            head-head->next;
        }
        return 0;


    }
    void insert(string key ,V value){
        int bucketindex=getBucketIndex(key);
        MapNode<V>*head=bucket[bucketindex];
        while(head!=NULL){
            if(head->key==key){
                head->value=value;
                return ;
            }
            head=head->next;
        }
        head=bucket[bucketindex];
        MapNode<V>*node=new MapNode<V>(key,value);
        node->next=head;
        bucket[bucketindex]=head;
        count++;
        double loadfactor=(1.0*count)/numbuckets;
        if(loadfactor>0.7){
            rehash();
        }
    }
    void rehash(){
        MapNode<V>**temp=bucket;
        bucket=new MapNode*<V>(2*numbuckets);
        for(int i =0;i<2*numbuckets;i++){
            bucket[i]=NULL;
        }
        int oldbucketcount=numbucket;
        numbucket*=2;
        count=0;
        for(int i=0;i<oldbucketcount;i++){
            MapNode<V>*head=temp[i];
            while(head!=NULL){
                string key=head->key;
                V value=head->value;
                insert(key,value);
                head=head->next;
            }

        }
        for(int i=0;i<oldbucketsize;i++){
            MapNode<V>*head=temp[i];
            delete head;
        }
        delete[]temp;

    }
};