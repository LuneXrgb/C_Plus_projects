// https://www.luogu.com.cn/problem/P1255
#include <bits/stdc++.h>
using namespace std;
string addition(string a,string b){
    string res;
    int len1=a.size();
    int len2=b.size();
    int arr[2000]={0};
    int len=max(len1,len2);
    for(int i=0;i<len;i++){
        if(i<=len1-1)arr[i]+=a[len1-1-i]-'0';
        if(i<=len2-1)arr[i]+=b[len2-1-i]-'0';
        if(arr[i]>=10){
            arr[i+1]++;
            arr[i]-=10;
        }
    }
    while(arr[len]==0 && len>=0){
        len--;
    }
    for(int i=len;i>=0;i--){
        res.push_back(arr[i]+'0');
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    string a[5001];
    a[0]="1";
    a[1]="2";
    a[2]="3";
    for(int i=3;i<n;i++){
        a[i]=addition(a[i-1],a[i-2]);
    }
    cout<<a[n-1];
    return 0;
}