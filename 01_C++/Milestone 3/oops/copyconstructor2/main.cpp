#include<iostream>
using namespace std;
class Student{
    
    int age;
public:
    char *name;
public:
    Student (int age,char *name){
        this->age=age;
        //shallow copy
        //this->name=name;
        
        //deep copy
        this->name= new char[strlen(name)+1];
        strcpy(this->name,name);
    }
    void diplay(){
        cout<<name<<" "<<age<<endl;
    }
    
    //copy constructor
    Student(Student const &s){
        // here to avoid the loop we use referance and not make though s we use const kryword
        this->age=s.age;
        //this->name=s.name;
        //shallow copy made by default or inbuilt copy constructor but we have to made own copy constructor deafult copy constructor pass by referance and also have const keyword only differance is deep copy not include
        
        //deep copy
        this->name=new char[strlen(s.name)+1];
        strcpy(this->name,s.name);
    }
};
int main(){
    
    char name[]="abcd";
    Student s1(20,name);
    s1.diplay();
    
    Student s2(s1);
    s2.name[0]='x';
    s1.diplay();
    s2.diplay();
     
}

