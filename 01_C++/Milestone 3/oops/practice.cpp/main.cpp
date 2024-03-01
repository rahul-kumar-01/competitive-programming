#include<iostream>
using namespace std;
class Fraction{
private:
    int numerator;
    int  denominator;
public:
    Fraction(int numerator,int denominator){
        this->numerator= numerator;
        this->denominator=denominator;
    }
    void print()const{
        cout<<numerator<<" / "<<denominator<<endl;
    }
    Fraction operator+(const Fraction &f2) const{
        int lcm = denominator * f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;
        int num = x * numerator + (y*f2.numerator);
        Fraction f(num,lcm);
        return f;
    }
};
int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);
    Fraction f3= f1+f2;
    f3.print();
    
    
}
