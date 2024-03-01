#include<iostream>
using namespace std;
class Student{

public:
    int age;
    int const rollnumber;
    int &x;     //age referance variable
    
    Student (int r,int age) : rollnumber(r),age(age), x(this->age){
        //here we can't use this age(age) it show error because it's clear that
        // outer age is this ka age & inner age is argument ka age
        // we have to declare & x at time of creation so we use intializationlist int &x=age; is wrong because age is argument
        //so we have to  use this age
        //int &x=this->age;
    }
};

int main(){
    Student s1(100,20); //error because
    
}
//when even const keyword used always  we have to used intitalization list 
