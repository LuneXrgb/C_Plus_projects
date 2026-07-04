//   https://www.luogu.com.cn/problem/P2089
#include <bits/stdc++.h>
using namespace std;
int n;
//sum用来记录当前时刻的配料总和，用于剪枝和结束搜索是判断搜索是否符合题意
//nums用来记录成功方法的数量，每一次搜索成功时自增
int sum=0,nums=0;  
//arr用来记录当前时刻的选择
vector <int> arr;
void dfs(int pos,bool flag){
//pos==10时搜索结束，用sum判断此次搜索是否合法，flag判断是否打印方案
    if(pos==10){
        if(sum==n){
            nums++;
            if(flag){
                for(int i=0;i<10;i++){
                    cout<<arr[i]<<' ';
                }
                cout<<endl;
            }
        }
        return ;
    }
//排列型枚举，前面的不影响后面的，每次都从1~3遍历
    for(int i=1;i<=3;i++){
//可行性剪枝：判断在当前i的情况下是否合法，如果不合法直接return
        if(sum+i>n)return;
        sum+=i;
        arr.push_back(i);
        dfs(pos+1,flag);
        arr.pop_back();
        sum-=i;
    }
}
int main(){
    cin>>n;
    dfs(0,false);
    cout<<nums<<endl;
    dfs(0,true);
    return 0;
}