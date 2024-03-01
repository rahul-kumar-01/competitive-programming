//#include<iostream>
//using namespace std;
//
//void swap(int &a,int &b){
//    int temp = b;
//    b = a;
//    a = temp;
//}
//
//
//void bubbleSort(int arr[],int n){
//    for(int j=n-1;j>=1;--j){
//        for(int i=0;i<j;++i){
//            if(arr[i] > arr[i+1]){
//                swap(arr[i],arr[i+1]);
//            }
//        }
//    }
//    return;
//}
//
//void insertionSort(int arr[],int n){
//    for(int i=1;i<n;++i){
//        int count = 0;
//        for(int j=i-1;j>=0;--j){
//            if(arr[i] < arr[j]){
//                ++count;
//            }
//        }
//        if(count != 0){
//            swap(arr[i-count],arr[i]);
//            --i;
//        }
//    }
//}
//
//
//
//int partition(int arr[],int si,int ei){
//    int pivot = arr[si];
//    int pivotIndex = si;
//    for(int i=si+1;i<=ei;++i){
//        if(pivot >= arr[i]) ++pivotIndex;
//    }
//
//    //swap
//    arr[si] = arr[pivotIndex];
//    arr[pivotIndex] = pivot;
//
//    int i = si;
//    int j = pivotIndex+1;
//    while(i<pivotIndex && j<=ei){
//        if(arr[i] <= pivot){
//            ++i;
//        }
//        else if(arr[j] > pivot){
//            ++j;
//        }
//        else{
//            int temp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = temp;
//            ++i;
//            ++j;
//        }
//    }
//    return pivotIndex;
//}
//
//
//void quickSort(int arr[],int si,int ei){
//    if(si>=ei) return;
//    int pivot = partition(arr,si,ei);
//    quickSort(arr, si, pivot-1);
//    quickSort(arr, pivot+1 ,ei);
//}
//
//
//void mergeTwoSortedArray(int arr[],int si,int ei){
//    int output[100];
//    int mid = (si+ei)/2;
//    int i = si;
//    int j = mid+1;
//
//    int k=si;
//    while(i<=mid && j<=ei){
//        if(arr[i] < arr[j]){
//            output[k++] = arr[i++];
//        }
//        else{
//            output[k++] = arr[j++];
//        }
//    }
//
//    while(i<=mid){
//        output[k++] = arr[i++];
//    }
//    while(j<=ei){
//        output[k++] = arr[j++];
//    }
//
//    for(int i=si;i<k;++i){
//        arr[i] = output[i];
//    }
//    return;
//}
//
//void helper(int arr[],int si,int ei){
//    if(si>=ei) return;
//    int mid = (si+ei)/2;
//    helper(arr,si,mid);
//    helper(arr,mid+1,ei);
//    mergeTwoSortedArray(arr,si,ei);
//}
//
//
//void mergeSort(int arr[],int n){
//    if(n==0) return ;
//    helper(arr,0,n-1);
//}
//
//
//void selectionSort(int arr[],int n){
//    int i=0,j=0;
//    for(i=0;i<n;++i){
//        int min = i;
//        for(j=i+1;j<n;++j){
//            if(arr[min] > arr[j]){
//                min = j;
//                int temp = arr[i];
//                arr[i] = arr[j];
//                arr[j] = temp;
//            }
//        }
//    }
//    return;
//}
//
//int main(){
//    int arr[10] = {-1,-6,10,0,87,454,756,003,2340,3};
////    selectionSort(arr,10);
////    mergeSort(arr,10);
////    quickSort(arr,0,9);
////    bubbleSort(arr, 10);
////    insertionSort(arr,10);
//    for(int i=0;i<10;++i){
//        cout<<arr[i]<<" ";
//    }
//    cout<<endl;
//    return 0;
//}

//#include<iostream>
//using namespace std;
//void swap (char *x, char *y)
//{
//  char *t = x;
//  x = y;
//  y = t;
//}
//
//int main()
//{
//   char *x = "ninjasquiz";
//   char *y = "codingninjas";
//   char *t;
//   swap(x, y);
//   cout<<x << " "<<y;
//   t = x;
//   x = y;
//   y = t;
//   cout<<" "<<x<< " "<<y;
//   return 0;
//}
