#include <iostream>
using namespace std;

int r, c, cnt;
char arr[16][16];

void bf(int cur_r, int cur_c, char cur) {
	if (cur_r + 1 == r || cur_c + 1 == c) {
		if (cur_r + 1 == r && cur_c + 1 == c) {
			cnt++;
		}
		
		return;
	}

	for (int i = cur_r + 1; i < r; i++) {
		for (int j = cur_c + 1; j < c; j++) {
			// 시작 지점 -> 도착 지점 바로 가는 경우 제거
			if (cur_r == 0 && cur_c == 0 && i == r - 1 && j == c - 1) 
				return;
			if (arr[i][j] != cur) {
				bf(i, j, arr[i][j]);
			}
		}
	}
}

int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	bf(0, 0, arr[0][0]);
	cout << cnt << endl;
}