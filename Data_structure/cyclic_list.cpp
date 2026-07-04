#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int nex[N],ele[N],id,h;
int mp[N];
void push_front(int x){
    id++;
    ele[id]=x;
    mp[x]=id;
    nex[id]=nex[h];
    nex[h]=id;
}
void print(){
    for(int i=nex[h];i!=h;i=nex[i]){
        cout<<ele[i]<<' ';
    }
    cout<<endl<<endl;
}
void insert(int p,int x){
    id++;
    ele[id]=x;
    mp[x]=id;
    nex[id]=nex[p];
    nex[p]=id;
}
//删除p之后的一个元素
void erase(int p){
    if(nex[p]!=h){
        mp[ele[nex[p]]]=0;
        nex[p]=nex[nex[p]];
    }
}
int find(int x){
    return mp[x];
}
int main(){
    
    return 0;
}