
#include<iostream>
#include<array>
#include<deque>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int main(){
    
//    int basic[3] = {1,2,3};
    array<int,4>a = {1,2,3,4};
    
    int size = a.size();
    for(int i=0;i<size;++i){
        cout<<a[i]<<endl;
    }
    
    //O(1)
    cout<<a.at(2)<<endl;
    cout<<a.empty()<<endl;
    cout<<a.front()<<endl;
    cout<<a.back()<<endl;
    
    cout<<endl;
    cout<<"--------     VECTOR    --------"<<endl;
    
    vector<int>v;
    vector<int> v1(5,1);         // itialize by 1 by defualt it's zero
    
    vector<int> v2(v1);         // print all the element of v1;
    
    
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    
    v.push_back(1);
    v.push_back(2);
    v.pop_back();
    
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    v.clear();              //capacity remains same just size become 0
    vector<int>::iterator it = v.begin();
    cout<<*it<<endl;
    
    
    cout<<endl;
    cout<<"--------   Deque/Doubel ended deque    --------"<<endl;
    cout<<endl;
    
    cout<<"vector & array have contigous memeory to store that not the case of Deque"<<endl;
    cout<<"Multiple fixed static array used to implement"<<endl;
    
    cout<<endl;
    
    
    deque<int>d;
    d.push_back(1);
    d.push_front(2);
    d.pop_back();
    d.pop_front();
    cout<<d.at(1)<<endl;
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    cout<<d.empty()<<endl;
    d.erase(d.begin(),d.begin()+1); // erase 1 st element
    cout<<d.max_size()<<endl;         //reamins same
    
    
    
    
    cout<<endl;
    cout<<"--------   List    --------"<<endl;
    cout<<endl;
    cout<<"double LL index direct access not possibel"<<endl;
    
    list<int>l1;
    list<int>l2(l1);
    list<int>n(5,100);      //size 5 value is 100
    
    
    
    l1.push_back(10);
    l1.push_front(20);
    
    cout<<l1.front()<<endl;
    cout<<l1.back()<<endl;
    l1.erase(l1.begin());
    cout<<l1.size()<<endl;
    
    
    cout<<endl;
    cout<<"--------   Set   --------"<<endl;
    cout<<endl;
    cout<<"store unique element implement using BST"<<endl;
    cout<<"sorted order if you pop"<<endl;
    
    set<int>s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(1);
    
    //insert O(longn)
    
    set<int>::iterator it1 = s1.begin();
    it1++;
    
    s1.erase(it1);
    
    
    
    for(auto i:s1){
        cout<<i<<endl;
    }
    
    cout<<s1.count(5)<<endl;    //check element is present on not bool
    cout<<s1.count(-5)<<endl;
    
    set<int>::iterator it3 = s1.find(5);      //return iteraotr
    cout<<*it3<<endl;
    
    for(auto it = it3;it!=s1.end();++it){
        cout<<*it<<endl;
    }
    
    //insert,find,count,erase O(longn)
    //size begin,end,empth 0(1);
    
    
    cout<<endl;
    cout<<"--------   Map   --------"<<endl;
    cout<<endl;
    
    map<int,string>m1;
    
    m1[1] = "babbar";
    m1[5] = "love";
    
    for(auto i:m1){
        cout<<i.first<<endl;
    }
    //come is sorted order
    
    m1.insert({5,"bheem"});
    
    for(auto i:m1){
        cout<<i.first<<" "<<i.second<<endl;
    }
    
    //finding
    cout<<m1.count(-12)<<endl;
    m1.erase(1);
    
    auto it4 = m1.find(5);
//    for(auto i = it4;i!=m1.end();++i){
//        cout<<(*i)<<endl;
//    }
    
    
    
    cout<<endl;
    cout<<"--------   Map   --------"<<endl;
    cout<<endl;
    
    
    
    //binarySearch
    
    vector<int> v10;
    v10.push_back(12);
    v10.push_back(15);
    
    cout<<binary_search(v10.begin(),v10.end(),6)<<endl;
    
    
    string s2 = "abcd";
    reverse(s2.begin(), s2.end());
    cout<<s2<<endl;
    
    rotate(v.begin(),v.begin()+1,v.end());
    
    
    
    
}
