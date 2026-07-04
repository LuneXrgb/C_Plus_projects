#include <bits/stdc++.h>
using namespace std;

int main(){
    stack <int> st;
    st.push(1145);
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    cout<<st.empty()<<endl;
    st.pop();
    cout<<st.empty();
    return 0;
}