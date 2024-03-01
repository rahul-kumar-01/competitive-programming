// * this return object of function type
#include<iostream>
using namespace std;
class Fraction{
public:
    int numerator;
    int denominator;
    
    Fraction(int numerator,int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
    } 
    void print() const {
        cout<<this->numerator<< " / "<<denominator<<endl;
    }
    void simplify(){
        int gcd = 1;
        int j=min(this ->numerator,this -> denominator);
        // not neccesaty to use this
        for(int i=1;i<=j;++i){
            if(this -> numerator % i ==0 && this -> denominator % i==0){
                gcd = i;
            }
        }
        this -> numerator = this -> numerator / gcd;
        this ->denominator = this -> denominator / gcd;
    }
    //pre increment
    //only one argument need which is passes through this so  need to pass argument
    
    //okay for ++ operator but not for ++(++f1) operator
//    because when we do ++ operator that value store in buffer at different memeory location  and again as we do ++ that memory location get ++ not f
//    Fraction operator++(){
//
//        numerator=numerator+denominator;
//        simplify();
//        Fraction f(numerator,denominator);
//        return f;
//    }
    Fraction& operator++(){
    
        numerator=numerator+denominator;
        simplify();
        return *this;
        
    }
    
};
int main(){
    Fraction f1 (10,2);
    Fraction f2 (5,4);
    f1.print();
    ++f1;
    f1.print();
    Fraction f3 = ++f1;
    f1.print();
    f3.print();
    Fraction f4=++(++f1);
    f1.print();
    f4.print();
    
    
    
    
}
