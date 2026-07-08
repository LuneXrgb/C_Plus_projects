// 快速排序模版 (Quicksort Template)
#include <bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int q[N]={0};
void quick_sort(int l,int r){
    if(l>=r)return;
    int i=l-1;int j=r+1;
    int mid=q[l+(r-l)/2];
    do{
        do i++ ;while(q[i]<mid);
        do j-- ;while(q[j]>mid);
        if(i<j){
            swap(q[i],q[j]);
        }
    }while(i<j);
    quick_sort(l,j);
    quick_sort(j+1,r);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&q[i]);
    quick_sort(0,n-1);
    for(int i=0;i<n;i++)cout<<q[i]<<' ';
    return 0;
}
