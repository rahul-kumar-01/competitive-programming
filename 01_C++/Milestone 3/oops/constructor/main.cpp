#include<iostream>
using namespace std;
class Student {
public:
    int rollNumber;
private:
    int age;
    
public:
    void display(){
        cout<<age<<" "<<rollNumber<<endl;
    }
    
    int getage(){
        return age;
    }
    
    void setage(int a,int passoword){
        if(passoword!=123){
            if(a<0) return;
            age=a;
        }
    }
    
    //constructor
    Student (){
        cout<<"1 construtor"<<endl;
    }
    Student(int rollNumber){
        cout<<"2 constructor"<<endl;
        //rollNumber=rollNumber; error;
        this->rollNumber=rollNumber;
        //(*this).rollNumber=rollNumber; both are same
    }
    Student(int a,int r){
        cout<<"3 constructor"<<endl;
        rollNumber=r;
        this->age=a; //optional
        
    }
};
int main(){
    
    /*Student s1;
    s1.display();
    
    Student s2;
    
    Student *s3= new Student;
    s3->display();
    
    cout<<"parametrized constructor"<<endl;
    Student s4(10);
    
    Student s5(20,1002);
    s5.display() ;
    */
    Student s1(100);
    s1.display();
    
    
}
