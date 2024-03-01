#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

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
    
   // cout<<ourmap.at("ghi")<<endl;       // gives exception
    
    cout<<ourmap["ghi"] <<endl;         //automatically create a pair "ghi" = 0
                                        //because "ghi" pair does't exits
    cout<<"size: "<<ourmap.size()<<endl;
    
    //check presence
    if(ourmap.count ("ghi") > 0) {          //count function return 1 or 0
        cout<<"ghi is present"<<endl;
    }
    int pairCount = 0;
    if (ourmap. find("abc") != ourmap.end()) {
        pairCount += ourmap [ "abc" ] ;
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
    
    
    if(ourmap["abc"]>0){                // if you find like this ourmap["abc"] = 0;
        cout<<"rahul"<<endl;            //  this   will happens "abc" inserted in map;
    }else{
        cout<<"rahul2"<<endl;
    }
    cout<<ourmap.size()<<endl;
}

