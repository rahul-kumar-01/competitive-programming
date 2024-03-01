#include<iostream>
using namespace std;
class Student{
    
    //char * name = new char[100];
    //here we dont know the length of name if we take more
    //more space is taken so just intialize it use it after
    
public:
    int age;
    char * name;
    
   
    
    Student(int age,char *name){
        this -> age =age;
        //this -> name = name;
        
        // ideal we dont do , we have a make a new array
        // full name is copy in a new array
        // if we change in a new array nothing is change in name s1 reamins sam// deep copy - copy every entity of array
        
        this -> name = new char[strlen(name)+1];
        // this ka name is chracter pointer so it points to any charcter  array address
        // 1 for null charcter
        strcpy( this -> name , name);
        //for more clearnace open shallow copy senond part cpp
        
    }
  
    void display(){
        cout<< name <<" "<< age <<endl;
    }
};
int main(){
    // Student s1;  // ERROR  //because we use parametrized constructor default constructor vanished &  it show error
    
    char name[]="abcd";
    
    Student s1(20,name);
    
    // this shallow coping ( copy only address of first index of array(name) and pass location (name) as  referance
    //paramatrized constructor get input as int age and a char pointer which takes address and in this case it point to name int main)
    //here s1.name is refering to main char array
    //so s1.name get int value 780 as address of name main
    
    
    s1.display();
    name [3]='e';
    Student s2 (24, name);
    s2.display();
    
    s1.display();
    
}
