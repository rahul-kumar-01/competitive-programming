#include<iostream>
using namespace std;
class Fraction{
private:
    int numerator;
    int denominator;
public:
    Fraction(int numerator,int denominator){
        this-> numerator= numerator;
        this-> denominator= denominator;
    }
    void print()const {
        cout<<numerator<< " / "<<denominator<<endl;
    }
    void Simplyfy(){
        int gcd = 1;
        int j=min(numerator,denominator);
        for(int i=1;i<=j;++i){
            if(numerator% i ==0 && denominator % i ==0){
                gcd = i;
            }
        }
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }
    
    //int only for post increment symbol
    Fraction operator++(int){
        Fraction fNew(numerator,denominator);
        numerator = numerator + denominator;
        Simplyfy();
        fNew.Simplyfy();
        return fNew;
    }
    Fraction& operator+= (Fraction const &f2){
        int lcm = denominator * f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;
        
        int num = x * numerator +( y * f2.numerator);
        numerator = num;
        denominator = lcm;
        Simplyfy();
        return *this;
    }
    
    //(i++)++ is not valid post increment not use nesting  increment
    
};
int main(){
    
    Fraction f1(10,3);
    Fraction f2(5 ,2 );
    Fraction f3 = f1++;
    f1.print();
    f3.print();
    int i = 5, j=3;
    (i+=j)+=j;
    cout<<i<<" "<<j<<endl;
    
    (f1 += f2) += f2;
    f1.print();
    f2.print();
    
}
