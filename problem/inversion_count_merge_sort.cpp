#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e6+10;
int a[N];
LL cnt=0;
int n;
void merge_sort(int l,int r){
    if(l>=r)return;
    int mid=(l+r)/2;
    vector<int> temp;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int i=l,j=mid+1;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            temp.push_back(a[i++]);
        }else{
            temp.push_back(a[j++]);
            cnt+=mid-i+1;
        }
    }
    while(i<=mid){
        temp.push_back(a[i++]);
    }
    while(j<=r)temp.push_back(a[j++]);
    for(int i=0;i<=r-l;i++){
        a[l+i]=temp[i];
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    merge_sort(0,n-1);
    cout<<cnt<<endl;
    return 0;
}
