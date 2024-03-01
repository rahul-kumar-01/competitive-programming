#include<iostream>
using namespace std;
class student{

public:
    int rollNumber;
private:
    int age;
    
public:
    ~student (){
        cout<<"destructor called ! "<<endl;
    }
    
    //default constructor
    student(){
        cout<<"constructor 1 called ! "<<endl;
    }
    
    //parameterized constructor
    student (int rollNumber){
        cout<<"construction 2 called ! "<<endl;
        this -> rollNumber=rollNumber;
    }
    
    student (int a,int r){
        cout<<"construction 3 called ! "<<endl;
        this -> age=a;
        rollNumber=r;
    }
    
    
};
int main(){
    
    student s1;             //constructor 1 called
    student s2(101);        //constructor 2 called
    student s3(20,201);     //constructor 3 called
    student s4(s3);         //copy constructor called
    s1=s2;                  //no constructor called because s1 & s2 is already
                            //created and constructor created already
    student s5=s4;          //copy constructor
    //compiler enterprete like this student s5(s4);
}
