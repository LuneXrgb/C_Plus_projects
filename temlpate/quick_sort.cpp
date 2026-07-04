#include <bits/stdc++.h>
using namespace std;
void quicksort(int arr[],int left,int right){
    int mid=arr[(left+right)/2];
    int i=left,j=right;
    while(i<=j){
        while(arr[i]<mid)i++;
        while(arr[j]>mid)j--;
        if(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if(left<j)quicksort(arr,left,j);
    if(i<right)quicksort(arr,i,right);
}   
int main(){
    int arr[4]={5,2,9,1};
    quicksort(arr,0,3);
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}