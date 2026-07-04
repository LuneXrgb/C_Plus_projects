#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int que[N];
int head,tail;
void push(int x){
    que[tail++]=x;
}
void pop(){
    head++;
}
int front(){
    return que[head];
}
bool empty(){
    return head == tail;
}
int main(){
    push(1);
    push(2);
    push(3);
    while(!empty()){
        cout << front() << ' ';
        pop();
    }
    cout << endl;
    push(10);
    push(20);
    cout << front() << endl;
    pop();
    cout << front() << endl;
    return 0;
}