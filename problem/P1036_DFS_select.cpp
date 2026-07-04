// https://www.luogu.com.cn/problem/P1036
#include <bits/stdc++.h>
using namespace std;
bool isprime(int a) {
    if (a == 1) return false;
    if (a == 2) return true;
    if (a % 2 == 0) return false;  
    for (int i = 3; i * i <= a; i += 2) {  
        if (a % i == 0) return false;
    }
    return true;
}
int n,k;
int a[30];
int sum=0,cnt=0;
vector <int> arr;
void dfs(int pos,int begin){
    if(pos==k){
        if(isprime(sum)){
            cnt++;
        }
        return;
    }
    for(int i=begin;i<n;i++){
        sum+=a[i];
//这个地方是从i+1开始，因为第一个是i，之后只能选i后面的，不能与i相同
        dfs(pos+1,i+1);
        sum-=a[i];
    }
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    dfs(0,0);
    cout<<cnt<<endl;
    return 0;
}