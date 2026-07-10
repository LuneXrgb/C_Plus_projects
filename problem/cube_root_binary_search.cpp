#include <bits/stdc++.h>

using namespace std;

double cube_root(double n){
    if(n<0)return -cube_root(-n);
    double l=0,r=50,mid=25;
    while(fabs(mid*mid*mid-n)>=1e-10){
        if(mid*mid*mid>n){
            r=mid;
            mid=(l+r)/2;
        }
        else{
            l=mid;
            mid=(l+r)/2;
        }
    }
    return mid;
}

int main(){
    double n;
    cin>>n;
    printf("%.6f\n",cube_root(n));
    return 0;
}