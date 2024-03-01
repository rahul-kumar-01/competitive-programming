#include<iostream>
using namespace std;
int main(){
    char * ch = new char('a');
    cout<<ch<<endl;
    cout<<*ch<<endl;
    cout << static_cast<void*>(ch) << endl;


}
