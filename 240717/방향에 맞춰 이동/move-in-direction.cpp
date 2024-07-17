#include <iostream>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
    int n;
    cin >> n;

    char dir;
    int cnt;
    pair<int, int> pos = { 0, 0 };
    for (int i = 0; i < n; i++) {
        cin >> dir >> cnt;

        int dirIdx;
        switch (dir) {
            case 'N':
                dirIdx = 0;
                break;
            case 'E':
                dirIdx = 1;
                break;
            case 'S':
                dirIdx = 2;
                break;
            case 'W':
                dirIdx = 3;
                break;
            default:
                dirIdx = -1;
                break;
        }

        if (dirIdx != -1) {
            for (int j = 0; j < cnt; j++) {
                pos.first += dx[dirIdx];
                pos.second += dy[dirIdx];
            }
        }
    }

    cout << pos.first << ' ' << pos.second << '\n';
    return 0;
}