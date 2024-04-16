// https://www.codetree.ai/missions/8/problems/number-frequency/description
// 숫자 등장 횟수
#include <iostream>
#include <unordered_map>
using namespace std;

int n, m;
int arr[100001];
unordered_map<int, int> num_to_index;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (num_to_index.find(arr[i]) == num_to_index.end()) {
			num_to_index[arr[i]] = 1;
		}
		else {
			num_to_index[arr[i]]++;
		}
	}

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		if (num_to_index.find(num) != num_to_index.end()) {
			cout << num_to_index[num] << ' ';
		}
		else
			cout << 0 << ' ';
	}

	return 0;
}