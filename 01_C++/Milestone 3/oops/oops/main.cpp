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
};


int main(){
//    Student s1;
//    Student * s4=new Student;
//    s1.rollNumber=24;
//    //s1.age=18;
//    cout<<s1.rollNumber<<endl;
//    s1.display();
//    s1.setage(100,123);
//
//    (*s4).rollNumber=25;
//    //(*s4).age=19;
//    s4->rollNumber=20;
//    cout<<s4->rollNumber<<endl;
//    (*s4).display();
//    s4->display();
//
//    return 0;

    
       int n = 5;
       vector<int> adj[n+1];
       for(int i=0;i<5;++i){
           int v,u;
           cin>>v>>u;
           
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       
        

    }
}
