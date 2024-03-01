#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
int main(){
    
    unordered_map<string,int> ourmap;
    ourmap["abc"]  = 1;
    ourmap["abc2"] = 2;
    ourmap["abc3"] = 3;
    ourmap["abc4"] = 4;
    ourmap["abc5"] = 5;
    
    //iterator store adderess of first pair (key,value) it may be any abc,abc2,abc3,abc4,abc5 , it we do ++it we get next pair or next pair address
    

    //two function of iterator .begin() & .end() used to get first pointer & last
    
    unordered_map <string,int> :: iterator it = ourmap.begin();
    while(it != ourmap.end()){
        cout<<"Key : "<<it->first<<" Value : "<<it->second<<endl;
        ++it;
        
    }
    //iterator can be used in many function
    //find
    
    unordered_map<string,int> :: iterator it4 = ourmap.find("abc");
    // if we use at() we get value
    ourmap.erase(it4);
   
    vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(7);
    v.push_back(1);
    v.push_back(8);
    vector<int> :: iterator it2 = v.begin();
    while(it2 != v.end()){
        cout<< *it2 <<" ";
        ++it2;
    }
    cout<<endl;
    
        
}
