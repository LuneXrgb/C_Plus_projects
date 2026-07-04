#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int standard=1e9+7;
int arr[N]={0};
int n;
vector <int> temp;
long long res=0;
bool judge_triangle(int a,int b,int c,int d){
    int k[4]={a,b,c,d};
    sort(k,k+4);
    if((k[0]+k[1])==k[2] && k[2]==k[3]){
        return true;
    }
    return false;
}
void dfs(int pos,int begin){
    if(pos==4){
        if(judge_triangle(arr[temp[0]],arr[temp[1]],arr[temp[2]],arr[temp[3]])){
            res++;
            res%=standard;
        }
        return;
    }
    for(int i=begin;i<n;i++){
        temp.push_back(i);
        dfs(pos+1,i+1);
        temp.pop_back();
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dfs(0,0);
    cout<<res;
    return 0;
}