#include<iostream>
using namespace std;
int returnPermutation(string input,string output[]){
    if(input.length() == 0){
        output[0] = "";
        return 1;
    }
    int k=0;
    for(int i=0;i<input.length();++i){
        string sOutput[100];
        int temp= returnPermutation(input.substr(0,i)+input.substr(i+1,input.length()),sOutput);
        
        for(int j=0;j<temp;++j){
            output[k++] = input[i] + sOutput[j];
        }
    }
    return k;
}

void permutation(string input, string output) {
    if(input.length()==0){
        cout<<output<<endl;
        return;
    }
    for(int i=0;i<input.length();++i){
        permutation(input.substr(0,i) + input.substr(i+1,input.length()), output+input[i]);
    }
    return;
}




int main(){
    string s1;
    cout<<"enter the string : ";
    cin>>s1;
//    string output[100];
//    int temp = returnPermutation(s1, output);
//    for(int i=0;i<temp;++i){
//        for(int j=0;j<output[i].length();++j){
//            cout<<output[i][j];
//        }
//        cout<<endl;
//    }
    permutation(s1, "");
    
}

