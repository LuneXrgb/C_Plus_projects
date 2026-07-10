#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int n,q,num;
int a[N];

int left_search(int l,int r,int k){
    if(l>=r)return l;
    int mid=(l+r)/2;
    if(a[mid]>=k)return left_search(l,mid,k);
    else return left_search(mid+1,r,k);
}

int right_search(int l,int r,int k){
    if(l>=r)return r;
    int mid=(l+r+1)/2;
    if(a[mid]<=k)return right_search(mid,r,k);
    else return right_search(l,mid-1,k);
}

int main(){
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>a[i];
    while(q--){
        int k;
        cin>>k;
        int L=left_search(0,n-1,k);
        int R=right_search(0,n-1,k);
        if(a[L]!=k)cout<<-1<<' '<<-1<<endl;
        else cout<<L<<' '<<R<<endl;
    }
    return 0;
}