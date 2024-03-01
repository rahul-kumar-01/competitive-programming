#include<vector>
#include<climits>
class PriorityQueue {
    // Declare the data members here
    vector<int> pq;

   public:
    PriorityQueue() {
        // Implement the constructor here
    }
    
    void insert(int element) {
        // Implement the insert() function here
        // if(pq.size() == 0) {
        //     pq.push_back(element);
        //     return;
        // }
         
        pq.push_back(element);
        long childIndex = pq.size()-1;
        pq[childIndex] = element;
        long parentIndex = (childIndex - 1) / 2;

        while(childIndex > 0){
        
          if (pq[childIndex] > pq[parentIndex]) {
            int temp = pq[childIndex];
            pq[childIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
          }
          else  break;

            childIndex = parentIndex;
            parentIndex = (childIndex-1)/2;
        }
        return;
    }

    int getMax() {
        // Implement the getMax() function here
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        
        int ans = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        int parentIndex = 0;
        int lc =2* parentIndex +1;
        int rc = 2* parentIndex +2;

        while(lc<pq.size()){
            int maxIndex = parentIndex;

            if(pq[maxIndex] < pq[lc]){
                maxIndex = lc;
            }
            if (rc<pq.size() && pq[maxIndex] < pq[rc]) {
                maxIndex = rc;
            }
            if (maxIndex == parentIndex) break;
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            

            parentIndex = maxIndex;
            lc = 2*parentIndex + 1;
            rc = 2*parentIndex + 2;
        }

        return ans;
    }

    long getSize() {
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }
};
