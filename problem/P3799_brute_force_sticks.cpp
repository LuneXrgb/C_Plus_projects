// https://www.luogu.com.cn/problem/P3799
/*本题ai的数据范围比数据个数n的范围小的多，因此可以考虑暴力枚
举结果的所有可能(即等边三角形的边长)，看有多少种组合能满足这个
结果，然后输出组合的个数，另一方面是确定了结果四条边也非常好确
定。
如果用普通的枚举四条边的话，那么用到四层for循环，对于1e5数据量
的四层for循环是必然超时的
*/
#include <bits/stdc++.h>
using namespace std;
const int N=5e3+10;
const int standard=1e9+7;
long long comb2(long long n) {
    if (n < 2) return 0;
    return n * (n - 1) / 2;
}
int main(){
    int a[N]={0};
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a[temp]++;
    }
    long long res=0;
    for(int i=2;i<N;i++){
        long long fl=0,la=0;
        for(int x=1;x<i-x;x++){
            fl+=a[x]*a[i-x];
            fl%=standard;
        }
        if(i%2==0){
            fl+=comb2(a[i/2]);
            fl%=standard;
        }
        la+=comb2(a[i]);
        la%=standard;
        res+=fl*la;
        res%=standard;
    }
    cout<<res<<endl;
    return 0;
}