#include <iostream>
using namespace std;

int n;
int arr[3]; // a, b, c 저장
int cnt[3]; // 2 이내 숫자 개수 저장

int main() {
	cin >> n;
	cin >> arr[0] >> arr[1] >> arr[2];

	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < arr[i] - 2; j++) {
			cnt[i]++;
		}

		for (int j = arr[i] + 3; j <= n; j++) {
			cnt[i]++;
		}
	}

	int sub = cnt[0] * cnt[1] * cnt[2];
	int total = n * n * n - sub;
	cout << total << "\n";
	return 0;
}