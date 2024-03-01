#include<iostream>
using namespace std;
class ComplexNumber{
private:
    int real;
    int imaginary;
    
public:
    ComplexNumber(int real,int imaginary){
        this-> real = real;
        this-> imaginary = imaginary;
    }
    
    void plus(ComplexNumber const &c2){
        int sum_real = real + c2.real;
        int imaginary_sum = imaginary + c2.imaginary;
        
        real = sum_real;
        imaginary = imaginary_sum;
    }
    void print(){
        cout<<real<<" + "<<"i"<<imaginary<<endl;
    }
    void multiply(ComplexNumber const &c2){
        int first_real_product = real * c2.real;
                int second_real_product = -(imaginary*c2.imaginary);
                int first_imaginary_product = real * c2.imaginary;
                int second_imaginary_product = imaginary * c2.real;
                
                real = first_real_product + second_real_product;
                imaginary =  first_imaginary_product + second_imaginary_product;
    }
};
int main(){
    int real1 , imaginary1 , real2 , imaginary2;
    cin>> real1>> imaginary1 >> real2 >> imaginary2;
    
    ComplexNumber c1(real1 , imaginary1);
    ComplexNumber c2(real2 , imaginary2);
    
    int choice;
    cin>>choice;
    
    if(choice == 1){
        c1.plus(c2);
        c1.print();
    }
    else if (choice == 2){
        c1.multiply(c2);
        c1.print();
    }
    else
        return 0;
    
}
