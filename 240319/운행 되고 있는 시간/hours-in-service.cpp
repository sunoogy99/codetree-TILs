#include <iostream>
#include <climits>
#include <memory.h>
using namespace std;

int n;
int** arr;
int max_oper = INT_MIN;

int main() {
	cin >> n;
	arr = new int* [n];

	for (int i = 0; i < n; i++) {
		arr[i] = new int[2];
		cin >> arr[i][0] >> arr[i][1];
	}

	// timeline 동적 배열로 구현해보려 했으나, 메모리 해제 부분 에러 발생
	// 원인 파악 후 이유 기록하기
	// bool* timeline = new bool[n];
	bool timeline[1001];
	for (int i = 0; i < n; i++) {
		int oper = 0;
		
		for (int j = 1; j < 1001; j++) {
			timeline[j] = false;
		}

		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			
			int start = arr[j][0], end = arr[j][1];
			for (int k = start; k < end; k++) {
				timeline[k] = true;
			}
		}

		for (int j = 1; j < 1001; j++)
			if (timeline[j]) oper++;

		if (oper > max_oper) max_oper = oper;
	}
	
	/*delete[] timeline;*/

	for (int i = 0; i < n; i++)
		delete arr[i];
	delete[] arr;

	cout << max_oper << '\n';
	return 0;
}