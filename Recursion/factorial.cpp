#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0) return 1;
    return n*factorial(n-1);
}

int fibronacci(int n){
    if(n==0 || n==1) return n;
    return fibronacci(n-1)+fibronacci(n-2);
}

#include<cstring>
void removeConsecutiveDuplicates(char *input) {
    int n = strlen(input);
	if( n<= 1) return;
	removeConsecutiveDuplicates(input+1);
	if(input[0] == input[1]){
		int i = 1;
		for(;i<n;++i){
			input[i-1] = input[i];
		}
		input[i-1] = '\0';
	}
	return;
}

int main(){
    cout<<factorial(5)<<endl;
    cout<<fibronacci(5)<<endl;
    char input[] = {'a','a','b','c','d','d','a'};
    removeConsecutiveDuplicates(input);
    cout<<input<<endl;
}