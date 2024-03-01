/*include<iostream>
using namespace std;
class Pair{
    int x;
    int y;
public:
    Pair(int x,int y){
        this->x = x;
        this->y = y;
    }
    void getX(){
        cout<<this->x<<endl;
    }
    void getY(){
        cout<<this->y<<endl;
    }
    void setX(int num){
        this->x = num;
    }
    void setY(int num){
        this->y = num;
    }
};
int main(){
    Pair p1(199,389);
    p1.getX();
    p1.getY();
}

*/
//if we want to make x & y  double or char we have to write class funciton multiple times.
//so here we use tempelate

#include<iostream>
using namespace std;


// we can use multiple tempalte

template <typename t,typename v>        //t & v is temporary datatype

class Pair{
    t x;
    v y;
public:
    
    void getX(){
        cout<<this->x<<endl;
    }
    void getY(){
        cout<<this->y<<endl;
    }
    void setX(t num){
        this->x = num;
    }
    void setY(v num){
        this->y = num;
    }
};
int main(){
    //Pair p1(199,389); here we have to declare which template we use
    Pair <int , double> p1;
    p1.setX(100);
    p1.setY(100.2);
}
