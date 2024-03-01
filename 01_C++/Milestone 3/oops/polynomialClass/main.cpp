#include<iostream>
using namespace std;
class Polynomial{
public:
    int * degreeCoffiecent;
    int capacity;
    
    
    Polynomial(){
        capacity = 6;
        degreeCoffiecent = new int[capacity-1];
    }
    
    void setCapacity(int index,int cofficient){
        
        if(index<capacity){
            degreeCoffiecent[index] = cofficient;
        }
        while(index >= capacity){
            int * newArray = new int[2*capacity];
            for(int i=0;i<capacity;++i){
                newArray[i] = degreeCoffiecent[i];
            }
            degreeCoffiecent = newArray;
            capacity = 2 * capacity;
        }
        degreeCoffiecent [index] = cofficient;
}
    
    void print(){
        for(int i=0;i<capacity;++i){
            if(degreeCoffiecent[i] != 0){
                cout<<degreeCoffiecent[i]<<"x"<<i<<endl;
            }
        }
        
    }
    Polynomial operator+(const Polynomial &p){
        int size = max(capacity , p.capacity);
        int * output = new int [size];
        for(int i=0;i<size;++i){
            if(degreeCoffiecent[i] ==0 && p.degreeCoffiecent ==0){
                continue;
            }
            else{
                output[i] =degreeCoffiecent[i]+p.degreeCoffiecent[i];
            }
        }
        Polynomial p3;
        p3.capacity = size;
        p3.degreeCoffiecent = output;
        return p3;
    }
    
    Polynomial operator-(Polynomial const &p){
        int size;
        if(capacity > p.capacity){
            size = capacity;
        }
        else {
            size = p.capacity;
        }
        int * output = new int [size];
        for(int i=0;i<size;++i){
            if(degreeCoffiecent[i] ==0 && p.degreeCoffiecent ==0){
                continue;
            }
            else{
                output[i] =degreeCoffiecent[i]-p.degreeCoffiecent[i];
            }
        }
        Polynomial p3;
        p3.capacity = size;
        p3.degreeCoffiecent = output;
        return p3;
    }
};
int main(){
    Polynomial p1;
    p1.setCapacity(2, 3);
    p1.setCapacity(5, 1);
    p1.setCapacity(6, 2);
    p1.print();
    Polynomial p2;
    p2.setCapacity(1, 3);
    p2.setCapacity(10, 1);
    p2.setCapacity(3, 2);
    p2.print();
    Polynomial p3 = p1+p2;
    p3.print();
    Polynomial p4 = p1-p2;
    p4.print();
    
}
