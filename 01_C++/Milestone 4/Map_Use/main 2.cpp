#include<iostream>
#include<string>
using namespace std;
#include<unordered_map>
int main(){
    unordered_map<string, int> ourmap;
    
    //insert through pair
    pair<string,int> p ("abc",1);       //calling constructor
    ourmap.insert(p);
    ourmap["def"] = 2;
    
    //find & access
    cout<<ourmap["abc"]<<endl;
    cout<<ourmap.at("abc")<<endl;
    
    cout<<"size: "<<ourmap.size()<<endl;
    
   // cout<<ourmap.at("ghi")<<endl;       // gives error
    
    cout<<ourmap["ghi"] <<endl;         //automatically create a pair "ghi" = 0
                                        //because "ghi" pair does't exits
    cout<<"size: "<<ourmap.size()<<endl;
    
    //check presence
    if(ourmap.count ("ghi") > 0) {          //count function return 1 or 0
        cout<<"ghi is present"<<endl;
    }
    
    //erase
    ourmap.erase("ghi");
    cout<<"size: "<<ourmap.size()<<endl;
    if(ourmap.count("ghi") > 0) {
        cout<<"ghi is present"<<endl;
    }
    else{
        cout<<"ghi is not present."<<endl;
    }
    
}
