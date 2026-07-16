#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

vector<int> a;
vector<int> tree;

int n; //kich thuoc mang

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        int tm = (tl + tr)/2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1 , tr);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, new_val);
        else
            update(2 * v + 1, tm + 1, tr, pos, new_val);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }
}


int main(){
    if (cin >> n) {
        a.resize(n);
        tree.resize(4 * n);
        for (int i = 0; i < n; i++ ){
            cin >> a[i];
        }
        build(1, 0, n - 1);
        // Printing the tree or array for verification
        cout << "Tree root sum: " << tree[1] << "\n";
    }
    
    for (int i = 0; i < 4 * n; i++) {
        cout << tree[i] << " ";
    }
    
    return 0;
}