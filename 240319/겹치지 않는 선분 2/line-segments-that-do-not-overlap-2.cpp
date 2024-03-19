// 모든 방법을 분류해서 문제를 풀어본다.
#include <iostream>
using namespace std;

int n;
int** arr;
bool* dup_check;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	arr = new int* [n];

	for (int i = 0; i < n; i++) {
		arr[i] = new int[2];
		cin >> arr[i][0] >> arr[i][1];
	}
	
	dup_check = new bool[n];
	fill_n(dup_check, n, false);

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i][0] < arr[i][1] && arr[j][0] < arr[j][1]) {
				if (arr[j][0] > arr[i][0] && arr[j][1] < arr[i][1]) {
					dup_check[i] = true;
					dup_check[j] = true;
				}
				else if (arr[j][0] < arr[i][0] && arr[j][1] > arr[i][1]) {
					dup_check[i] = true;
					dup_check[j] = true;
				}
			}
			else if (arr[i][0] > arr[i][1] && arr[j][0] > arr[j][1]) {
				if (arr[j][0] < arr[i][0] && arr[j][1] > arr[i][1]) {
					dup_check[i] = true;
					dup_check[j] = true;
				}
				else if (arr[j][0] > arr[i][0] && arr[j][1] < arr[i][1]) {
					dup_check[i] = true;
					dup_check[j] = true;
				}
			}
			else if (arr[i][0] < arr[i][1] && arr[j][0] > arr[j][1]) {
				if (arr[j][0] > arr[i][0] && arr[j][1] < arr[i][1]) {
					dup_check[i] = true;
					dup_check[j] = true;
				}
			}
			else if (arr[i][0] > arr[i][1] && arr[j][0] < arr[j][1]) {
				if (arr[j][0] < arr[i][0] && arr[j][1] > arr[i][1]) {
					dup_check[i] = true;
					dup_check[j] = true;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
		delete arr[i];
	delete[] arr;


	int dup = 0;
	for (int i = 0; i < n; i++) {
		if (!dup_check[i]) dup++;
	}

	delete[] dup_check;
	cout << dup << '\n';
	return 0;
}