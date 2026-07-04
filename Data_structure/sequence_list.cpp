#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

class SeqList {
    int a[N];
    int n;
public:
    SeqList() : n(0) {}

    void init(int *arr, int sz) {
        n = 0;
        for (int i = 0; i < sz; i++) {
            a[++n] = arr[i];
        }
    }

    void clear() {
        n = 0;
    }

    void push_back(int x) {
        a[++n] = x;
    }

    void push_front(int x) {
        for (int i = n; i >= 1; i--) {
            a[i + 1] = a[i];
        }
        a[1] = x;
        n++;
    }

    void insert(int p, int x) {
        for (int i = n; i >= p; i--) {
            a[i + 1] = a[i];
        }
        a[p] = x;
        n++;
    }

    void pop_back() {
        n--;
    }

    void pop_front() {
        for (int i = 2; i <= n; i++) {
            a[i - 1] = a[i];
        }
        n--;
    }

    void erase(int p) {
        for (int i = p + 1; i <= n; i++) {
            a[i - 1] = a[i];
        }
        n--;
    }

    void change(int p, int x) {
        a[p] = x;
    }

    void print() {
        for (int i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }
};

SeqList sl;

int main() {
    sl.push_back(1);
    sl.print();
    sl.push_back(2);
    sl.print();
    sl.push_back(3);
    sl.print();
    sl.push_front(1);
    sl.print();
    sl.insert(2, 1145);
    sl.print();
    sl.pop_back();
    sl.print();
    sl.pop_front();
    sl.print();
    sl.push_back(3);
    sl.print();
    sl.erase(2);
    sl.print();

    int arr[] = {10, 20, 30, 40, 50};
    sl.init(arr, 5);
    sl.print();

    sl.clear();
    sl.push_back(100);
    sl.print();
    return 0;
}
