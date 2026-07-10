#include <bits/stdc++.h>
using namespace std;
int quick_pow(int base,int exp){   //定义三个变量，base为底数，exp为指数，res为结果
    int res=1;
    while(exp){                
        if(exp & 1){
            res*=base;          //如果exp的最低位为1，则将base乘到res上
        }
        base*=base;
        exp>>=1;
    }
    return res;
}
int main(){
    cout<<quick_pow(2,10)<<endl;
    return 0;
}