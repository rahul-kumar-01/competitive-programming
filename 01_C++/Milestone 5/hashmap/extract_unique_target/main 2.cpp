
//  Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.
//Sample Input 1 :
//ababacd
//Sample Output 1 :
//abcd
//Sample Input 2 :
//abcde
//Sample Output 2 :
//abcde

#include <iostream>
#include <string>
#include <unordered_map>

// we can use map or unordered_map we get same result 

using namespace std;
string extractUniqueTarget(string str){
    string output="";
    unordered_map<char,int> count;
    for(int i=0;i<str.length();++i){
        ++count[str[i]];
        if(count[str[i]] ==1){
            output.push_back(str[i]);
        }
    }
    return output;
}


int main(){
    string input;
    cout<<"Enter the string : ";
    cin>>input;
    string output = extractUniqueTarget(input);
    for(int i=0;i<output.length();++i){
        cout<<output[i]<<" ";
    }
    cout<<endl;
    
}
