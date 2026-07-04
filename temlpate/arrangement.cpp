#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> arr;
vector <bool>  vis(10,false);
void dfs(int pos){
    if(pos==n){
        for(int i=0;i<n;i++)cout<<setw(5)<<arr[i];
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            arr.push_back(i);
            dfs(pos+1);
            arr.pop_back();
            vis[i]=false;
        }
    }
}
int main(){
    cin>>n;
    dfs(0);
    return 0;
}