#include <iostream>
#include <vector>
using namespace std;

int n;
bool arr[9];
vector<int> ans;

void per() {
    if (ans.size() < n) {
        for (int i = 1; i <= n; i++) {
            if (!arr[i]) {
                ans.push_back(i);
                arr[i] = true;
                per();
                ans.pop_back();
                arr[i] = false;
            }
        }
    }
    else {
        for (auto &num : ans) {
            cout << num << ' ';
        }
        cout << endl;
    }
}

int main() {
    cin >> n;
    per();
    return 0;
}