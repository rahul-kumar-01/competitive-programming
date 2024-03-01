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
    
        this->rollNumber=rollNumber;
       
    }
    
    
    
    Student(int a,int r){
       
        rollNumber=r;
        this->age=a;
        
    }
    
    ~Student(){
        cout<<"Destructor called ! "<<endl;
    }
};
int main(){
    
    
    /*
    Student s1(10,100);
    cout<<"s1 : ";
    s1.display();
    Student s2(s1);   //here  no constructor called because we use copy consturctor and no construtor called made by my self its automatically created & there is no output
    s2.display();
    
    Student *s3= new Student (20,2001);
    cout<<"s3 : ";
    s3->display();
    
    Student s4(*s3);
    cout<<"s4 : ";
    
    
    Student *s5=new Student (*s3);
    Student *s6=new Student (s1);
    */

    Student s1(10,1001);
    Student s2(20,2001);
    
    Student *s3=new Student (30,3001);
    
    s2=s1;
    *s3=s1;
    s2=*s3;
    
       //no destructor called for s3 because  it s delete it's location not its value so we have to manually delete the value;
    delete s3;
    
}


