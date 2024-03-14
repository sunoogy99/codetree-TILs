#include <iostream>
using namespace std;

int r, c, cnt;
char arr[16][16];

void bf(int cur_r, int cur_c, char cur, int jmp_cnt) {
	if (cur_r == r - 1 || cur_c == c - 1) {
		// 도착 지점까지 카운팅하면 3칸 
		if (jmp_cnt == 3 && cur_r == r - 1 && cur_c == c - 1) {
			cnt++;
		}
		return;
	}

	for (int i = cur_r + 1; i < r; i++) {
		for (int j = cur_c + 1; j < c; j++) {
			if (cur_r == 0 && cur_c == 0 && i == r - 1 && j == c - 1) continue;
			if (arr[i][j] != cur) {
				bf(i, j, arr[i][j], jmp_cnt + 1);
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

	bf(0, 0, arr[0][0], 0);
	
	cout << cnt << endl;

	return 0;
}