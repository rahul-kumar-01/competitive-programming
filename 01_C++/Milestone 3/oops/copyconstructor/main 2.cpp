
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
