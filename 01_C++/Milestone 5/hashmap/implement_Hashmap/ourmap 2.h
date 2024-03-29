#include<string>
using namespace std;
template <typename V>
class mapNode{
public:
    string key;
    V value;
    mapNode* next;
    
    mapNode(string key,V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~mapNode(){
        delete next;
    }
};

template <typename V>
class ourmap{
//    mapNode<V>* pointer of node
    mapNode<V> ** buckets;
    int count;
    int numBuckets;
public:
    ourmap(){
        count = 0;
        numBuckets = 5;
        buckets = new mapNode<V>* [numBuckets];
        for(int i=0;i<numBuckets;++i){
            buckets[i] = NULL;
        }
    }
    ~ourmap(){
        for(int i=0;i<numBuckets;++i){
            delete buckets[i];
        }
        delete [] buckets;
    }
    
    int size(){
        return count;
    }
    
private:
    int getBucketIndex(string key){
        int hashCode = 0;
        int currentCoeff = 1;
        for(int i=key.length()-1;i>=0;i--){
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets;
            currentCoeff *= 37;
            currentCoeff = currentCoeff %  numBuckets;
        }
        return hashCode % numBuckets;
    }
     
    void rehash(){
        mapNode<V>** temp = buckets;
        buckets = new  mapNode<V>* [2*numBuckets];
        for(int i=0;i<2*numBuckets;++i){
            buckets[i] = NULL;
        }
        int oldBucketsCount = numBuckets;
        numBuckets *= 2;
        count = 0;
        for(int i=0;i<oldBucketsCount;++i){
            mapNode<V>* head = temp[i];
            while(head != NULL){
                string key = head->key;
                V value = head ->value;
                insert(key,value);
                head = head->next;
            }
        }
        for(int i=0;i<oldBucketsCount;++i){
            mapNode<V>* head = temp[i];
            delete head;
        }
        delete []temp;
    }
public:
    double getLoadFactor(){
        return (1.0*count) / numBuckets;
    }
    void insert(string key,V value){
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];
        while(head!= NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        mapNode<V> * node = new mapNode<V>(key,value);
        node->next = head;
        buckets[bucketIndex] = node;
        ++count;
        double loadFactor = (1.0)*count / numBuckets;
        if(loadFactor > 0.7){
            rehash();
        }
    }
    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* root = buckets[bucketIndex];
        while(root != NULL){
            if(root->key == key){
                return root->value;
            }
            root = root->next;
        }
        return 0;
    }
    V remove(string key){
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* root = buckets[bucketIndex];
        mapNode<V>* prev = NULL;
        while(root != NULL){
            if(root->key == key){
                if(prev == NULL){
                    buckets[bucketIndex] = root->next;
                }
                else{
                    prev->next = root->next;
                }
                
                V value = root->value;
                root->next = NULL;
                delete root;
                count--;
                return value;
            }
            prev = root;
            root = root->next;
        }
        return 0;
    }
};
