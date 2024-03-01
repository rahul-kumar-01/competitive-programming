#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

int knapsack1(int * value,int * weigth,int ** output,int count,int maxWeight,int n){
    
    if(count == n || maxWeight ==0) return 0;
    if(output[count][maxWeight] != -1){
        return output[count][maxWeight];
    }
    
    if(maxWeight < weigth[count]){
        output[count][maxWeight] = knapsack1(value,weigth+1,output,count+1,maxWeight,n);
    }
    else{
        output[count][maxWeight] = max
        (knapsack1(value,weigth+1,output,count+1,maxWeight,n),knapsack1(value,weigth+1,output,count+1,maxWeight-weigth[0],n)+value[count]);
    }
    return output[count][maxWeight];
}

int knapsack_2(int * value,int *weigth,int n,int maxWeight){
    int ** output = new int*[n+1];
    for(int i=0;i<=n;++i){
        output[i] = new int[maxWeight+1];
        for(int j=0;j<=maxWeight;++j){
            output[i][j] = -1;
        }
    }
    return knapsack1(value,weigth,output,0,maxWeight,n);
}

int knapsack(int * value,int * weight,int n,int maxWeight){
    if(n==0 || maxWeight==0) return 0;
    if(weight[0] > maxWeight){
        return knapsack(value+1,weight+1,n-1,maxWeight);
    }
    int value1=knapsack(value+1,weight+1,n-1,maxWeight-weight[0])+value[0];
    int value2=knapsack(value+1,weight+1,n-1,maxWeight);
    
    return max(value1,value2);
}


int editDistance_3(string s1,string s2){
    long s1L = s1.length(),s2L = s2.length();
    int ** output = new int*[s1L+1];
    for(int i=0;i<=s2L;++i){
        output[i] = new int[s2L+1];
    }
    output[0][0] = 0;
    for(int i=1;i<=s1L;++i){
        output[i][0] = i;
    }
    for(int j=1;j<=s2L;++j){
        output[0][j] = j;
    }
    for(int i=1;i<=s1L;++i){
        for(int j=1;j<=s2L;++j){
            if(s1.substr(s1L-i)[0] == s2.substr(s2L-j)[0]){
                output[i][j] = output[i-1][j-1];
            }
            else{
                output[i][j] = 1 + min(output[i-1][j],min(output[i-1][j-1],output[i][j-1]));
            }
        }
    }
    return output[s1L][s2L];
}



int editDistanceH(string s1,string s2,int ** output){
    long s1L = s1.length(), s2L = s2.length();
    
    if(s1.length() == 0 && s2.length() ==0){
        return 0;
    }
    
    if(output[s1L][s2L] != -1){
        return output[s1L][s2L];
    }
    if(s1[0] == s2[0]) return editDistanceH(s1.substr(1), s2.substr(1),output);
    int a = INT_MAX,b= INT_MAX,c=INT_MAX;
    if(s1.length()!=0){
        a = editDistanceH(s1.substr(1),s2,output);
    }
    if(s1.length()!=0 && s2.length()!=0){
        b = editDistanceH(s1.substr(1),s2.substr(1),output);
    }
    if(s2.length()!=0){
        c = editDistanceH(s1,s2.substr(1),output);
    }
    return min(a,min(b,c)) + 1;
}

int editDistance_2(string s1,string s2){
    long s1L = s1.length(), s2L = s2.length();
    int ** output = new int* [s1L];
    for(int i=0;i<=s1L;++i){
        output[i] = new int[s2L];
        for(int j=0;j<=s2L;++j){
            output[i][j] = -1;
        }
    }
    return editDistanceH(s1, s2,output);

}

int editDistance(string s1,string s2){
    if(s1.length() == 0 && s2.length() ==0){
        return 0;
    }
    if(s1[0] == s2[0]) return editDistance(s1.substr(1), s2.substr(1));
    int a = INT_MAX,b= INT_MAX,c=INT_MAX;
    if(s1.length()!=0){
        a = editDistance(s1.substr(1),s2);
    }
    if(s1.length()!=0 && s2.length()!=0){
        b = editDistance(s1.substr(1),s2.substr(1));
    }
    if(s2.length()!=0){
        c = editDistance(s1,s2.substr(1));
    }
    return min(a,min(b,c)) + 1;
}

int lcs3(string m,string n){
    long ml = m.length();
    long nl = n.length();
    int ** output = new int*[ml+1];
    for(int i=0;i<=ml;++i){
        output[i] = new int[nl+1];
    }
    for(int i=0;i<=ml;++i){
        output[i][0] = 0;
    }
    for(int j=0;j<=nl;++j){
        output[0][j] = 0;
    }
    for(int i=1;i<=ml;++i){
        for(int j=1;j<=nl;++j){
            if(m.substr(ml-i)[0] == n.substr(nl-j)[0]){
                output[i][j] = 1 + output[i-1][j-1];
            }
            else{
                output[i][j] = max(output[i-1][j],max(output[i-1][j-1],output[i][j-1]));
            }
        }
    }
    return output[ml][nl];
}


//we can do this better
int lcsHelper(string m,string n,int ** output,long i,long j){
    long ml = m.length();
    long nl = n.length();
    if(ml == 0 || nl == 0) return 0;
    if(output[i][j] != -1){
        return output[i][j];
    }
         
    if(m[0] == n[0]){
        return 1 + lcsHelper(m.substr(1),n.substr(1),output,i-1,j-1);
    }
    
    int a = lcsHelper(m.substr(1),n,output,i-1,j);
    int b = lcsHelper(m,n.substr(1),output,i,j-1);
    int c = lcsHelper(m.substr(1),n.substr(1),output,i-1,j-1);
    output[i][j]  = max(a,max(b,c));
    return output[i][j];
}


int lcs2(string m,string n){
    long ml = m.length();
    long nl = n.length();
    int ** output = new int*[ml];
    for(int i=0;i<ml;++i){
        output[i] = new int[nl];
        for(int j=0;j<nl;++j){
            output[i][j] = -1;
        }
    }
    return lcsHelper(m,n,output,ml-1,nl-1);
    
}


int lcs(string m,string n){
    if(m.length() ==0 || n.length()==0) return 0;
    
    if(m[0] == n[0]){
        return 1 + lcs(m.substr(1),n.substr(1));
    }
    
    int a = lcs(m.substr(1),n);
    int b = lcs(m,n.substr(1));
    int c = lcs(m.substr(1),n.substr(1));
    return max(a,max(b,c));
    
}





int minCost_3(int ** path,int m,int n){
    int ** output = new int*[m];
    for(int i=0;i<m;++i){
        output[i] = new int[n];
    }
    output[m-1][n-1] = path[m-1][n-1];
    for(int j=n-2;j>=0;--j){
        output[m-1][j] = output[m-1][j+1] + path[m-1][j];
    }
    for(int i=m-2;i>=0;--i){
        output[i][n-1] = path[i][n-1] + output[i+1][n-1];
    }
    for(int i=m-2;i>=0;--i){
        for(int j=n-2;j>=0;--j){
            output[i][j] = path[i][j] + min(output[i+1][j],min(output[i+1][j+1],output[i][j+1]));
        }
    }
    return output[0][0];
}



int helperMin(int ** path,int **output,int m,int n,int i,int j){
    if(i==m-1 && j==n-1){
        return path[i][j];
    }
    if(i>=m || j>=n ) return INT_MAX;
    if(output[i][j] != -1){
        return output[i][j];
    }
    
    int a = helperMin(path,output,m,n,i+1,j);
    int b = helperMin(path,output,m,n,i+1,j+1);
    int c = helperMin(path,output,m,n,i,j+1);
    output[i][j] =  min(a,min(b,c)) + path[i][j];
    return output[i][j];
}


int minCost_2(int ** path,int m,int n){
    int ** output = new int*[m];
    for(int i=0;i<m;++i){
        output[i] = new int[n];
        for(int j=0;j<n;++j){
            output[i][j] = -1;
        }
    }
    return helperMin(path,output,m,n,0,0);
}

int minCost(int ** path,int m,int n,int i,int j){
    if(i==m-1 && j==n-1){
        return path[i][j];
    }
    if(i>=m || j>=n ) return INT_MAX;
    
    int a = minCost(path,m,n,i+1,j);
    int b = minCost(path,m,n,i+1,j+1);
    int c = minCost(path,m,n,i,j+1);
    return min(a,min(b,c)) + path[i][j];
}


int minCount_3(int n){
    int * output = new int[n+1];
    output[0] = 0;
    output[1] = 1;
    for(int i=2;i<=n;++i){
        int min= INT_MAX;
        int limit = (int)(sqrt(i));
        for(int j=1;j<=limit;++j){
            int temp = output[i-(j*j)];
            if(min > temp) min = temp;
        }
        output[i] = min + 1;
    }
    return output[n];
}



int helperMin(int n,int* output,int min){
    if(n<=0) return 0;
    if(n==1) return 1;
    if(output[n] != -1){
        return output[n];
    }
    int limit = (int)(sqrt(n));
    
    for(int i=1;i<=limit;++i){
        int temp = helperMin(n-(i*i),output,min);
        if(min>temp){
            min = temp;
        }
    }
    output[n] = min+1;
    return output[n];
}


int minCount_2(int n){
    int * output = new int[n+1];
    for(int i=0;i<=n;++i){
        output[i] = -1;
    }
    return helperMin(n,output,INT_MAX);
}



int minHelper(int n,int min){
    if(n==1) return 1;
    if(n<=0) return 0;
    int limit = (int)(sqrt(n));
    for(int i=1;i<=limit;++i){
        int temp = minHelper(n-(i*i),min);
        if(min>temp){
            min = temp;
        }
    }
    return min+1;
}

int minCount(int n){
    return minHelper(n,INT_MAX);
}





int staircase_3(int n){
    int * output = new int[n+1];
    output[0] = 1;
    output[1] = 1;
    output[2] = 2;
    for(int i=3;i<=n;++i){
        output[i] = output[i-1] + output[i-2]+output[i-3];
    }
    return output[n];
}


int staircaseHelper(int n,int * output){
    if(n<0) return 0;
    if(n==0)return 1;
    if(output[n] != -1){
        return output[n];
    }
    output[n] = staircaseHelper(n-1,output)+staircaseHelper(n-2,output)+
    staircaseHelper(n-3, output);
    return output[n];
}

int staircase_2(int n){
    int * output = new int[n+1];
    for(int i=0;i<=n;++i){
        output[i] = -1;
    }
    return staircaseHelper(n,output);
}

int staircase_1(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    return staircase_1(n-1) + staircase_1(n-2) + staircase_1(n-3);
}

int minStepTo1_3(int n){
    int * output = new int[n+1];
    output[0] = 0;
    output[1] = 0;
    for(int i=2;i<=n;++i){
        int a = INT_MAX,b= INT_MAX;
        if(i%2==0) a = output[i/2];
        if(i%3==0) b = output[i/3];
        int c = output[i-1];
        output[i] = min(a,min(b,c))+1;
    }
    return output[n];
}

int helper(int n,int * output){
    if(n<=1) return 0;
    if(output[n] != -1){
        return output[n];
    }
    int a = INT_MAX,b = INT_MAX;
    if(n%2==0){
        a = helper(n/2,output);
    }
    if(n%3==0){
        b = helper(n/3,output);
    }
    int c = helper(n-1,output);
    output[n] = min(a,min(b,c))+1;
    return output[n];
}


int minStepTo1_2(int n){
    int * output = new int[n+1];
    for(int i=0;i<=n;++i){
        output[i] = -1;
    }
    return helper(n,output);
}


int minStepTo1(int n){
    if(n<=1) return 0;
    int a = INT_MAX, b = INT_MAX;
    if(n%2==0) {
        a = minStepTo1(n/2);
    }
    if(n%3==0){
        b = minStepTo1(n/3);
    }
    int c = minStepTo1(n-1);
    return min(a,min(b,c))+1;
}

int fibronacci_3(int n){
    int * output = new int[n+1];
    output[0] = 0;
    output[1] = 1;
    for(int i = 2;i<=n;++i){
        output[i] = output[i-1] + output[i-2];
    }
    return output[n];
}



int fibHelper(int n,int * output){
    if(n==0) return 0;
    if(n==1) return 1;
    if(output[n] != -1){
        return output[n];
    }
    output[n] = fibHelper(n-1,output) + fibHelper(n-2,output);
    return output[n];
}



int fibronacci_2(int n){
    int* output = new int[n+1];
    for(int i=0;i<=n;++i){
        output[i] = -1;
    }
    return fibHelper(n,output);
}


int fibronacci_1(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fibronacci_1(n-1) + fibronacci_1(n-2);
}


int main(){
//    cout<<fibronacci_1(4)<<endl;
//    cout<<fibronacci_2(4)<<endl;
//    cout<<fibronacci_3(4)<<endl;
//    cout<<endl;
//    cout<<minStepTo1(110)<<endl;
//    cout<<minStepTo1_2(110)<<endl;
//    cout<<minStepTo1_3(110)<<endl;
//    cout<<endl;
//    cout<<staircase_1(49)<<endl;
//    cout<<staircase_2(49)<<endl;
//    cout<<staircase_3(49)<<endl;
//    cout<<minCount(59)<<endl;
//    cout<<minCount_2(59)<<endl;
//    cout<<minCount_3(59)<<endl;
//
//    int m,n;
//    cout<<"enter the size of path : ";
//    cin>>m;
//    cin>>n;
//    int ** path = new int*[m];
//    for(int i=0;i<m;++i){
//        path[i] = new int[n];
//        for(int j=0;j<n;++j){
//            cin>>path[i][j];
//        }
//    }
//    cout<<minCost(path,m,n,0,0)<<endl;
//    cout<<minCost_2(path,m,n)<<endl;
//    cout<<minCost_3(path,m,n)<<endl;
//
//    string a = "abcdefhji";
//    string b = "badeffdfiji";
////    cout<<lcs(a,b)<<endl;
//    cout<<lcs2(a,b)<<endl;
//    cout<<lcs3(a,b)<<endl;
//
//    cout<<endl;
//
//    cout<<editDistance(a,b)<<endl;
//    cout<<editDistance_2(a,b)<<endl;
//    cout<<editDistance_3(a,b)<<endl;
//
//    int value[5] = {3,1,2,1,4};
//    int weight [5] = {3,5,6,233,3};
//    cout<<knapsack(value, weight, 5, 15)<<endl;
//    cout<<knapsack_2(value, weight, 5, 15)<<endl;

    int ** output = new int*[5];
    for(int i=0;i<5;++i){
        output[i] = new int [10];
        for(int j=0;j<10;++j){
            output[i][j] = -1;
        }
        
    }
    for(int i=0;i<5;++i){
        for(int j=0;j<10;++j){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
   
    
    
}

