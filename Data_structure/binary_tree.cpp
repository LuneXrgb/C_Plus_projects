#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int val[N],l[N],r[N];
int n, root, id;

void preorder(int u){
    if(!u) return;
    cout << val[u] << ' ';
    preorder(l[u]);
    preorder(r[u]);
}

void inorder(int u){
    if(!u) return;
    inorder(l[u]);
    cout << val[u] << ' ';
    inorder(r[u]);
}

void postorder(int u){
    if(!u) return;
    postorder(l[u]);
    postorder(r[u]);
    cout << val[u] << ' ';
}

void sequenceorder(){
    for(int i = 1; i <= n; i++)
        cout << val[i] << ' ';
}

void sequence_get(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> val[i];
        if(2 * i <= n) l[i] = 2 * i;
        if(2 * i + 1 <= n) r[i] = 2 * i + 1;
    }
    root = 1;
}

int pre_get(){
    int x;
    cin >> x;
    if(x == -1) return 0;
    int u = ++id;
    val[u] = x;
    l[u] = pre_get();
    r[u] = pre_get();
    return u;
}

int main(){
    id = 0;
    root = pre_get();
    preorder(root);   cout << endl;
    inorder(root);    cout << endl;
    postorder(root);  cout << endl;
    return 0;
}