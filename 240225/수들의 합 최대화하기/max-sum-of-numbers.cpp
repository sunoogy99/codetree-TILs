#include <iostream>
using namespace std;

int n;
int arr[11][11];
int max_val;
int cum;
bool check[11];

int max(int a, int b) {
    return a > b ? a : b;
}

void bf(int depth) {
    if (depth <= n) {
        for (int i = 1; i <= n; i++) {
            if (!check[i]) {
                check[i] = true;
                cum += arr[depth][i];
                bf(depth + 1);
                check[i] = false;
                cum -= arr[depth][i];
            }
        }
    }
    else {
        if (cum > max_val) max_val = cum;
    }
}

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    bf(1);
    cout << max_val;
    return 0;
}