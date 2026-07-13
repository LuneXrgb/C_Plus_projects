#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;
int a[N][N];
int b[N][N];
int n,m;
//在x1 y1和x2 y2围成的矩阵内加上k这个数
void insert(int x1,int y1,int x2,int y2,int k){
    b[x1][y1]+=k;
    b[x1][y2+1]-=k;
    b[x2+1][y1]-=k;
    b[x2+1][y2+1]+=k;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            insert(i,j,i,j,a[i][j]);
        }
    }
    
    int x1,y1,x2,y2,c;
    cin>>x1>>y1>>x2>>y2>>c;
    insert(x1,y1,x2,y2,c);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[i][j]+=b[i-1][j]+b[i][j-1]-b[i-1][j-1];
            cout<<b[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}