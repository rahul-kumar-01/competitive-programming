#include<iostream>
using namespace std;
class Fraction{
private:
    int numerator;
    int denominator;
public:
    Fraction(){
        
    }
    Fraction(int numerator,int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
    }
    int getNumerator() const{
        return numerator;
    }
    int getDenominator() const {
        return denominator;
    }
    void setNumber(int n){
        numerator=n;
    }
    void setDenominator(int d){
        denominator=d;
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
    void add(const Fraction &f2){
        
        int lcm = denominator * f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;
        int num = x * numerator + (y*f2.numerator);
       
        numerator = num;
        denominator = lcm;
        simplify();
    }
    void mutiply (Fraction const &f2) {
        numerator = numerator  * f2.numerator ;
        denominator =  denominator * f2. denominator;
        simplify();
    }
};

int main(){
    
    Fraction f1(10,2);
    Fraction f2(15,4);
    
    
    const Fraction f3;
    // f3 in constant our compiler don't allow to call any function which involve f3 because it may change f3 value
    //we can call only constant function
    // constant function = which doesn't change any properties of current function
    //means cannot change any this proprties of object
    // so if fuction don't change value of object use const in function calling
    f3.print();
    f1.add(f3);
    cout<<f3.getNumerator()<<endl;
    cout<<f3.getDenominator() <<endl;
    f1.print();
    f3.print();
    
}
