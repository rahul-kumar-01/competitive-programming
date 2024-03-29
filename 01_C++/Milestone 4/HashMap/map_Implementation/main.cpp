#include<iostream>
#include<string>
using namespace std;

template <typename V>
class MapNode{
public:
    string key;
    V value;
    MapNode* next;
    
    MapNode(string key,V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    
    ~MapNode(){
        delete next;
    }
};

template <typename V>
class ourmap{
    MapNode<V>** buckets;
    int count;
    int numBuckets;
    
public:
    ourmap(){
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V>* [numBuckets];
        for(int i=0;i<numBuckets;++i){
            buckets[i] = NULL;
        }
    }
    ~ourmap(){
        for(int i=0;i<numBuckets;++i){
            delete buckets[i];
        }
        delete buckets;
    }
    
    //HashFunction
    
    int getBucketIndex(string key){
        int hasCode = 0;
        int currentCoeff = 1;
        for(int i=key.length()-1;i>=0;--i){
            hasCode += key[i]*currentCoeff;
            hasCode = hasCode % numBuckets;
            currentCoeff *= 37;
            currentCoeff = currentCoeff % numBuckets;
        }
        return hasCode % numBuckets;
    }
    
    double getLoadFactor(){
        return (1.0* count) / numBuckets;
    }
    
    void rehash(){
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[2*numBuckets];
        for(int i=0;i<2*numBuckets;++i){
            buckets[i] = NULL;
        }
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;
        for(int i=0;i<oldBucketCount;++i){
            MapNode<V>* head = temp[i];
            while(head != NULL){
                insert(head->key,head->value);
                head = head->next;
            }
        }
        
        for(int i=0;i<oldBucketCount;++i){
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete [] temp;
    }
    
    
    
    void insert(string key,V value){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head!=NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V>* node = new MapNode<V>(key,value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        double loadFactor = getLoadFactor();
        if(loadFactor > 0.7){
            rehash();
        }
    }
    
    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = NULL;
        
        while(head!=NULL){
            if(head->key == key){
                if(prev == NULL){
                    buckets[bucketIndex] = head->next;
                }
                else{
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                --count;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
    
   
    V getVaule(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    
    
    int size(){
        return count;
    }
    
};




int main(){
    ourmap<int> map;
    for(int i=0;i<10;i++){
        char c = '0' + i;
        string key = "abc";
        key = key+c;
        int value = i+1;
        map.insert(key, value);
//        cout<<map.getLoadFactor()<<endl;
    }
    
    cout<<map.size()<<endl;
    map.remove("abc2");
    map.remove("abc3");
    
    
    
    for(int i=0;i<10;++i){
        char c = '0' + i;
        string key = "abc";
        key = key+c;;
        cout<<key<<" "<<map.getVaule(key)<<endl;
    }
   
    cout<<map.size()<<endl;
    
}
