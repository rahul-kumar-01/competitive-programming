// we can use operation (add,substract,multiply) on integer but we want to extent the limit of operation for the object

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
    
    void print() const {
        cout<<this->numerator<< " / "<<denominator<<endl;
    }
    void simplify()  {
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
    
    //this is for fraction f3=f1.add(f2);
    
    Fraction add(const Fraction &f2){
        int lcm = denominator * f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;
        int num = x * numerator + (y*f2.numerator);
        //numerator = num;
        //denominator = lcm;
        Fraction fnew(num,lcm);
        fnew.simplify();
        return fnew;
    }
     
    
    // for f4=f1+f2;
    // f1 pass through this & f2 pass through referance
    Fraction operator+(const Fraction &f2)const{
        int lcm = denominator * f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;
        int num = x * numerator + (y*f2.numerator);
        Fraction fnew(num,lcm);
        fnew.simplify();
        return fnew;
    }
    void mutiply (Fraction const &f2){
        numerator = numerator  * f2.numerator ;
        denominator =  denominator * f2. denominator;
        
        simplify();
    }
    
    //Fraction operator*(Fraction f2){  also use this give same ans but wrong practice
    Fraction operator*(Fraction const &f2) const {
        int n = numerator  * f2.numerator ;
        int d =  denominator * f2. denominator;
        Fraction fNew(n,d);
        fNew.simplify();
        return fNew;
    }
    bool operator==(Fraction fNew) const{
        return (numerator==fNew.numerator && denominator == fNew.denominator);
    }
    
  
    
};
int main(){
    
    Fraction f1(10,2);
    Fraction f2(15,4);
    
    Fraction f3=f1.add(f2);
    Fraction f4=f1+f2;
    f1.print();
    f2.print();
    f3.print();
    f4.print();
    Fraction f6;
    f6=f1*f2;
    f6.print();
    if(f1==f1) cout<<"equal"<<endl;
    else cout<<"not equal"<<endl;
    
}
