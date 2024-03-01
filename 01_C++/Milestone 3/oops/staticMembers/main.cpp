#include<iostream>
using namespace std;
class Student{
    static int totalNumber;
public:
    int age;
    int rollNumber;
    
    Student(){
        ++totalNumber;
    }
    int getrollNumber(){
        return rollNumber;
    }
    int static gettotalNumber(){
        return totalNumber;
    }
    // static function access only static properties
    // cannot have this because static function not called by object
};

int Student :: totalNumber = 0;
int main(){
    
    Student s1,s2,s3;
    //cout<<s1.totalNumber<<endl;  we can do but it's wrong because it class properties not object;
    //s1.totalNumber=21;
    Student s4;
    //cout<<Student :: totalNumber<<endl; private
    cout<<Student :: gettotalNumber()<<endl;
    
}
