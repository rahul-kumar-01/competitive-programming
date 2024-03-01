#include<vector>
class priorityQueue{
    vector<int> pq;
    
public:
    priorityQueue(){
        
    }
    
    bool isEmpty(){
        return pq.size() == 0;
    }
    unsigned long getSize(){
        return pq.size();
    }
    int getMin(){
        return pq[0];
    }
    
    void insert(int element){
        pq.push_back(element);
        size_t childIndex = pq.size()-1;
        pq[childIndex] = element;
        
        unsigned long parentIndex = (childIndex-1)/2;
        
        while(parentIndex >= 0){
            
            if(pq[parentIndex] > pq[childIndex]){
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
            parentIndex = (childIndex-1)/2;
        }
    }
    
    int removeMin(){
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        
        int parentIndex = 0;
        int lc = (2*parentIndex)+1;
        int rc = (2*parentIndex)+2;
        ;  //for storing swaping index with parentIndex
        
        
        while(lc < pq.size() ){
            int minIndex = parentIndex;
            if(pq[minIndex] > pq[lc]){
                minIndex = lc;
            }
            if(rc < pq.size() &&  pq[minIndex] > pq[rc]){
                minIndex = rc;
            }
            if(minIndex == parentIndex) break;
            
            //swap
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            
            parentIndex = minIndex;
            lc = (2*parentIndex)+1;
            rc = (2*parentIndex)+2;
        }
    
        return ans;
    
    }
    
};
