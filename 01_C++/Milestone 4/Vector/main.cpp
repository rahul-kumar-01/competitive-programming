//vector is template
#include<iostream>
#include<vector>
using namespace std;
int main(){
    
    vector <int> v1;                             //static allocation - automatically delted
    //vector <int> * v2 = new vector<int>;      //dynamic allocation -we have to delete manually
    
    for(int i=0;i<50;++i){
        cout<<"Capacity is : "<<v1.capacity()<<endl;
        cout<<"Size is : "<<v1.size()<<endl;
        v1.push_back(i+1);
    }
    
    
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    
    v1.pop_back();  //delter last element
    
    v1[1] =100;    // for changing value
    v1[3] = 100;  //don't  use [] for insertion it ignore
    
    cout<<v1[0]<<endl;
    cout<<v1[1]<<endl;
    cout<<v1[2]<<endl;
    cout<<v1.at(1)<<endl;
    cout<<v1.size()<<endl;
    
    cout<<v1[6]<<endl;          //it don't show error print garbage value
    // cout<<v1.at(6)<endl;        //it show error so it is safe is use
    
    
    
    
}
