// https://www.codetree.ai/missions/8/problems/most-frequent-data/description
// 가장 많은 데이터
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int n;
string str;
unordered_map<string, int> m;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;

		if (m.find(str) == m.end()) {
			m[str] = 1;
		}
		else {
			m[str]++;
		}
	}

	int max_val = 0;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second > max_val) {
			max_val = iter->second;
		}
	}

	cout << max_val;
	return 0;
}