#include <iostream>
#include <cstdlib>
using namespace std;

int n;
int** arr;
int maxS;

int main() {
	cin >> n;

	// 메모리 동적 할당
	arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[2];
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				// 평행 조건 체크 : 모든 경우 체크 방식
				if ((arr[i][0] - arr[j][0] == 0 || arr[i][0] - arr[k][0] == 0 || arr[j][0] - arr[k][0] == 0) &&
					(arr[i][1] - arr[j][1] == 0 || arr[i][1] - arr[k][1] == 0 || arr[j][1] - arr[k][1] == 0)) {
					int s1 = arr[i][0] * arr[j][1] + arr[j][0] * arr[k][1] + arr[k][0] * arr[i][1];
					int s2 = arr[j][0] * arr[i][1] + arr[k][0] * arr[j][1] + arr[i][0] * arr[k][1];
					int s = abs(s1 - s2);

					if (s > maxS) maxS = s;
				}
			}
		}
	}

	// 메모리 해제
	for (int i = 0; i < n; i++)
		delete arr[i];
	delete[] arr;

	cout << maxS << '\n';
	return 0;
}