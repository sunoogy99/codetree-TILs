#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> arr;

void comb() {
    if (arr.size() < k) {
        for (int i = 1; i <= n; i++) {
            arr.push_back(i);
            comb();
            arr.pop_back();
        }
    }
    else {
        for (auto &num : arr) {
            cout << num << ' ';
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> k;
    comb();
    return 0;
}