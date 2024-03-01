#include <iostream>
using namespace std;
#include <string>
int subsequence(string input,string output[]){
    if(input.empty()){
        output[0] = " ";
        return 1;
    }
    int smalloutput = subsequence(input.substr(1),output);
    for(int i =0 ;i<smalloutput;i++){
        output[i+smalloutput] = input[0] + output[i];
        
    } return 2*smalloutput;
    
}
int main() {
    string input = "Ishan";
    string * output = new string[1000];
    int n = subsequence(input,output);
    for(int i =0;i<n;i++){
        cout<<output[i]<<endl;
        
    }
    return 0; }





//#include<iostream>
//using namespace std;
//class Fraction{
//private:
//    int numerator ;
//    int denominator;
//    // parameter constructor
//    // means constructor not put default value in num & denominator
//    //forces user for give num & deno
//public:
//    Fraction(int numerator,int denominator){
//        this -> numerator=numerator;
//        this -> denominator=denominator;
//    }
//
//
//    //want to print fraction
//    //when we call object.funciton means (address of object)(this) goes to that function
//
//
//    void print(){
//        cout<<this -> numerator<<" / "<< denominator <<endl;
//       //no need to mention (this) because there is no numerator & denominator in argument when we called object.name of function print ke this keyword me address of object is saved so talk about same object numerator and denominator
//    }
//
//    // we have to put fraction in simplify (70/8) = (35/2)
//    // find gcd (greatest common divisor) or HCF are both same
//    // divide numerator and denominator by gcd
//    //it become simplify
//
//    void simplify(){
//        int gcd = 1;
//        int j=min(this ->numerator,this -> denominator);
//        // not neccesaty to use this
//        for(int i=1;i<=j;++i){
//            if(this -> numerator % i ==0 && this -> denominator % i==0){
//                gcd = i;
//            }
//        }
//        this -> numerator = this -> numerator / gcd;
//        this ->denominator = this -> denominator / gcd;
//    }
//
//    //add two fraction
//    //no need two give two paramenter or argument f1 and f2
//    //because when we called object.fuction (f1.add)
//    //add function ke this keyword me &f1 goes
//    //we can access f1 properties using this keyword
//    // f1.add(f2)
//    // we have to pass f2 only one argumernt
//    //we want when we add f1+f2 it will updated in f1
//    //f2 unchanged
//    //so void is used f1=f1+f2;
//
//
//
//
//    // 2 nd part
//    // what happens here Fraction f2 = main of f2 (copy)
//    // here copy of f2 created & new constructor called
//    // to avoid to make another copy of f2 we use referance variable
//    // but later any change in f2 in fuction can affect main f2
//    // so to avoid this we use const keyword
//    // after use const referance f2 has only access for read not write
//    void add(const Fraction &f2){
//        // to access denominator of f1 we use this keyword
//        // this->denominator * f2.denominator
//        //there is no use to use this keyword because
//        //when we type denominator only we implicit talkin about f1 deno or clearly we are taking about this denominator
//        int lcm = denominator * f2.denominator;
//        int x = lcm/denominator;
//        int y = lcm/f2.denominator;
//
//        int num = x * numerator + (y*f2.numerator);
//        // this numerator me num ko dalo
//        // this denominator me lcm dalo
//        numerator = num;
//        denominator = lcm;
//
//
//        //direct call function don't write object dot function implicit means this ke uper simplify call kar do , this kon tha f1 to f1 ke call ho gayega
//        simplify();
//    }
//
//    //f1.multiply(f2)
//    // multiply updated in f1 , f2 remians same
//    void mutiply (Fraction const &f2){
//        numerator = numerator  * f2.numerator ;
//        denominator =  denominator * f2. denominator;
//
//        simplify();
//    }
//
//};
//int main(){
//
//    Fraction f1(10,2);
//    Fraction f2(15,3);
//
//    f1.add(f2);
//
//    f1.print();
//    f2.print();
//
//    f1.mutiply(f2);
//    f1.print();
//    f2.print();
//}
