// https://www.luogu.com.cn/problem/P1157
#include <bits/stdc++.h>
using namespace std;
int n,r;
vector <int> arr;
void dfs(int pos,int begin){
    if(pos==r){
        for(int i=0;i<r;i++){
            cout<<setw(3)<<arr[i];
        }
        cout<<endl;
        return;
    }
    for(int i=begin;i<=n;i++){
        arr.push_back(i);
        dfs(pos+1,i+1);
        arr.pop_back();
    }
}
int main(){
    cin>>n>>r;
    dfs(0,1);
    return 0;
}