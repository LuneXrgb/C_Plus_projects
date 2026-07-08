#include <bits/stdc++.h>
using namespace std;

vector <int> a,b;

vector <int> add(vector<int>&a,vector<int>&b){
    vector <int> c;
    int t=0;
    for(int i=0;i<a.size() || i<b.size();i++){
        if(i<a.size())t+=a[i];
        if(i<b.size())t+=b[i];
        c.push_back(t%10);
        t=t/10;
    }
    if(t)c.push_back(1);
    return c;
}

vector <int> sub(vector <int> &a,vector <int> &b){
    vector <int> c;
    int t=0;
    for(int i=0;i<a.size() || i<b.size();i++){
        if(i<a.size())t+=a[i];
        if(i<b.size()) t-=b[i];
        c.push_back((t+10)%10);
        t=(t-9)/10;
    }
    if(t>0)c.push_back(t);
    while(c[c.size()-1]==0 && c.size()>1)c.pop_back();
    return c;
}

vector <int> mul(vector <int> &a,int b){
    if(b==0)return vector <int> (1,0);
    vector <int> c;
    int t=0;
    for(int i=0;i<a.size();i++){
        t+=a[i]*b;
        c.push_back(t%10);
        t/=10;
    }
    while(t>0){
        c.push_back(t%10);
        t/=10;
    }
    return c;
}

vector <int> div(vector<int>&a,int b,int &r){
    vector<int> c;
    for(int i=a.size()-1;i>=0;i--){
        c.push_back((r*10+a[i])/b);
        r=(r*10+a[i])%b;
    }
    reverse(c.begin(),c.end());
    while(c.back()==0 && c.size()>1)c.pop_back();
    return c;
}


int main(){
    string A;
    cin>>A;
    for(int i=A.size()-1;i>=0;i--)a.push_back(A[i]-'0');
    int num;
    cin>>num;
    int r=0;
    auto c=div(a,num,r);
    for(int i=c.size()-1;i>=0;i--)cout<<c[i];
    return 0;
}