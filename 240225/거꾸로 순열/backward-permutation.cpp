#include <iostream>
#include <vector>
using namespace std;

int n;
bool arr[9];
vector<int> ans;

void per() {
    if (ans.size() < n) {
        for (int i = n; i > 0; i--) {
            if (!arr[i]) {
                arr[i] = true;
                ans.push_back(i);
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