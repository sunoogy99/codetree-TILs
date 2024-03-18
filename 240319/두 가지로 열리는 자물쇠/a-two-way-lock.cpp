// a: 첫번째 조합에서의 가짓수 파악
// b: 두번째 조합에서의 가짓수 파악
// c: 첫번째와 두번째 조합에서 겹치는 가짓수 파악
// 답: a + b - c
#include <iostream>
#include <cstdlib>
using namespace std;

int n;
int arr1[3];
int arr2[3];
int atotal = 1, btotal = 1, difftotal = 1;
int diff[3];
// 비효율적 방법 사용
// 100 크기의 배열 생성하여 나온 값 범위 체크
bool acheck[101][3];
bool bcheck[101][3];

int main() {
	cin >> n;
	cin >> arr1[0] >> arr1[1] >> arr1[2];
	cin >> arr2[0] >> arr2[1] >> arr2[2];

	for (int i = 0; i < 3; i++) {
		// 범위 체크 먼저 하기
		for (int j = arr1[i] - 2; j <= arr1[i] + 2; j++) {
			if (j >= 1 && j <= n) {
				acheck[j][i] = true;
			}
			else {
				if (j == 0) acheck[n][i] = true;
				else acheck[(j + n) % n][i] = true;
			}
		}
		
		for (int j = arr2[i] - 2; j <= arr2[i] + 2; j++) {
			if (j >= 1 && j <= n) {
				bcheck[j][i] = true;
			}
			else {
				bcheck[(j + n) % n][i] = true;
			}
		}

		for (int j = 1; j <= 100; j++) {
			if (acheck[j][i] && bcheck[j][i])
				diff[i]++;
		}
	}

	for (int i = 0; i < 3; i++) {
		int a1 = 0;
		int b1 = 0;
		for (int j = 1; j <= 100; j++) {
			if (acheck[j][i]) a1++;
			if (bcheck[j][i]) b1++;
		}

		atotal *= a1;
		btotal *= b1;
		difftotal *= diff[i];
	}

	cout << atotal + btotal - difftotal << '\n';
	return 0;
}