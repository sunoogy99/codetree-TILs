#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> vec;

void perm() {
    if (vec.size() == k) {
        for (auto &e : vec) {
            cout << e << ' ';
        }
        cout << endl;
        return;
    }
    else {
        for (int i = 1; i <= n; i++) {
            vec.push_back(i);
            perm();
            vec.pop_back();
        }
    }
}

int main() {
    cin >> n >> k;
    perm();
    return 0;
}