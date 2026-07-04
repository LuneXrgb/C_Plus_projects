// https://www.luogu.com.cn/problem/P2036
#include <bits/stdc++.h>
using namespace std;
int denk(int arr[][2],int size){
    int res=abs(arr[0][0]-arr[0][1]);
//每次枚举对应一个二进制数，用for枚举所有的二进制数
    for(int s=1;s<(1<<size);s++){
        int i=s;
        int acid=1,bitter=0;
// 判断第0,1,2到最后一位是否有1，这里再用for循环，如果有，就取
        for(int j=0;j<size;j++){
//这是判断s的第j位是否为1的标准语句
            if(s & (1<<j) ){
                acid*=arr[j][0];
                bitter+=arr[j][1];
            }
        }
        res=min(res,abs(acid-bitter));
    }
    return res;
}
int main(){
    int arr[11][2]={0};
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>arr[i][j];
        }
    }
    cout<<denk(arr,n)<<endl;
    return 0;
}