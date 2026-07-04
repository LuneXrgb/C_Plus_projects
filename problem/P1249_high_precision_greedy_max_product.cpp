// https://www.luogu.com.cn/problem/P1249
#include <bits/stdc++.h>
using namespace std;
int n;
int a[200]={0};  //a为分解的各个元素
int f[200]={0};  //f为前缀和，为了快速找到分解的个数
// 定义高精度乘法
string multiply(string a,string b){
    string res;
    int result[500]={0};
    int len1=a.size(),len2=b.size(),len=max(len1,len2);
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            result[i+j]+=(a[len1-1-i]-'0')*(b[len2-1-j]-'0');
        }
    }
    for(int i=0;i<500;i++){
        while(result[i]>=10){
            result[i+1]+=result[i]/10;
            result[i]%=10;
        }
    }
    int i=499;
    while(i>=0 && result[i]==0) i--;
    while(i>=0){
        res.push_back(result[i]+'0');
        i--;
    }
    return res;
}
//实现对数组的前n项的乘积，用高精度的方法，返回字符串形式的结果
string factorial(int arr[],int n){
    string res="1";
    for(int i=0;i<n;i++){
        res=multiply(res,to_string(arr[i]));
    }
    return res;
}
/*  贪心策略，首先要求分解的除了1之外的数字尽可能多，因此
先从2开始，到3,4一直加到大于n的数，然后取恰好小于n的那个为
index，此时前index项的和小于n，剩下的数分配给前index项，
从index一直往前，一次分配1，分配完后如果还有剩余(这时最多为1)，
就直接分配给index项即可
*/
int main(void){
    cin>>n;
// 3或者4的时候不能分解，特例处理，到5才开始分解
    if(n==3){
        cout<<3<<endl;
        cout<<3<<endl;
        return 0;
    }
    else if(n==4){
        cout<<4<<endl;
        cout<<4<<endl;
        return 0;
    }
    else {
        f[0]=2;
        a[0]=2;
        for(int i=1;i<200;i++){
            a[i]=i+2;
            f[i]=f[i-1]+a[i];
        }
        int index;
        for(int i=0;i<200;i++){
            if(f[i]>n){
                index=i-1;
                break;
            }
        }
        int last =  (n - f[index]);
        for(int i=index;i>=0 && last>0;i--){
            a[i]++;
            last--;
        }
        if(last>0)a[index]++;
        string res=factorial(a,index+1);
        for(int i=0;i<=index;i++){
            cout<<a[i]<<' ';
        }
        cout<<endl;
        cout<<res<<endl;
    }
    return 0;
}