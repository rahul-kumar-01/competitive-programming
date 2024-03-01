#include<iostream>
using namespace std;
int main(){
    
    int no_of_rows;
    cout<<"enter the number of rows : ";
    cin>>no_of_rows;
    int*  *multi_array_address = new int* [no_of_rows];
    
    for(int i=0; i<no_of_rows; ++i){
        int no_of_elements;
        cout<<"Enter the no. of elements in "<<(i+1)<<" row : ";
        cin>> no_of_elements;
        int * new_array_for_sinle_line = new int[no_of_elements];
        multi_array_address[i] = new_array_for_sinle_line;
        
        new_array_for_sinle_line[0] = no_of_elements;
        
        for(int j=1;j<=no_of_elements;++j){
            cout<<"enter the "<<j<<" th input of " <<(i+1)<<" row of "<<(j) <<" elements ";
            cin>>new_array_for_sinle_line[j];
        }
        
    }
    
    int row_index;
    int column_index;
    cout<<"To find the data please answer the following question : "<<endl;
    cout<<"Enter the row index : ";
    cin>>row_index;
    cout<<"Enter the column index : ";
    cin>>column_index;
    
    int * p = multi_array_address[row_index];
    cout<<p[column_index+1]<<endl;
    
}

