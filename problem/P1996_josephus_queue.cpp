//https://www.luogu.com.cn/problem/P1996
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,k;
queue <int> q;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(q.size()>1){
        for(int j=1;j<k;j++){
            q.push(q.front());
            q.pop();
        }
        cout<<q.front()<<' ';
        q.pop();
    }
    cout<<q.front()<<endl;
    return 0;
}