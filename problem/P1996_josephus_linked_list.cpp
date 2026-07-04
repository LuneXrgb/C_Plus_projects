//https://www.luogu.com.cn/problem/P1996
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int ele[N],nex[N],head,id;
int n,k;
int siz;
//把k后面的那个位置删掉
void push_front(int x){
    id++;
    ele[id]=x;
    nex[id]=nex[head];
    nex[head]=id;
}
void del(int k){
    nex[k]=nex[nex[k]];
    siz--;
}
int main(){
    cin>>n>>k;
    siz=n;
    for(int i=n;i>=1;i--){
        push_front(i);
    }
    int j=head;
    while(siz>1){
        for(int i=1;i<k;i++){
            j=nex[j];
            if(j==head)j=nex[j];
        }
        if(nex[j]==head)j=nex[j];
        cout<<ele[nex[j]]<<' ';
        del(j);
    }
    cout<<ele[nex[head]];
    return 0;
}