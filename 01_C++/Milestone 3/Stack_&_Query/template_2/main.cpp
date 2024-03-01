//make triplet without use three properties of class

#include<iostream>
using namespace std;

// we can use multiple tempalte

template <typename t,typename v>

class Pair{
    t x;
    v y;
public:
    
    t getX(){
        return x;
    }
    v getY(){
        return y;
    }
    void setX(t x){
        this->x = x;
    }
    void setY(v y){
        this->y = y;
    }
};
int main(){
    //Pair p1(199,389); here we have to declare which template we use
    
    
    Pair <Pair<int,double> , double> p1;
    p1.setY(23.3);
    
    Pair<int,double> p3;
    p3.setX(30);
    p3.setY(20.5);
    p1.setX(p3);
    
    cout<<p1.getX().getX()<<" "<<p1.getX().getY()<<" "<<p1.getY()<<endl;
    
}

