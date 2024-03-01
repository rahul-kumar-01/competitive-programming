//copy constructor and copy assingment operator always do shallow copy

#include<iostream>
using namespace std;
class Student{
public:
    int age;
    char * name;
    
    Student(int age,char *name){
        this->age=age;
        this->name=name;        //shallow copy char*name is pointer it take the                         address of name char array from main and                              we changed main array in line 23  so it                               reflect in s1 also
        //in next section we do deep copy
    }
    void Display(){
        cout<<age<<" "<<name<<endl;
    }
};
int main(){
    
    char name[]="abcd";
    Student s1(10,name);
    s1.Display();
    
    name[2]='e';
    Student s2(20,name);
    s2.Display();
    s1.Display();
    
    
    //here s1 & s2 both are changed
    
    
}
/*
 #include<iostream>
 #include<cstring>
 using namespace std;
 int main(){
 char name[]="abcd";
 char *p=new char[5];
 
 
 strcpy(p,name);
 for(int i=0;i<4;++i){
 cout<<*(p+i)<<endl;
 }
 
 }
 */
