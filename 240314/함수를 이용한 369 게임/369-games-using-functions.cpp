#include <iostream>
#include <string>
using namespace std;

int a, b;
int cnt;

int counter3(int a, int b) {
	for (int i = a; i <= b; i++) {
		if (i % 3 == 0) {
			cnt++;
			continue;
		}

		string tmp = to_string(i);
		int len = tmp.length();

		for (int i = 0; i < len; i++) {
			if (tmp[i] == '3' || tmp[i] == '6' || tmp[i] == '9') {
				cnt++;
				break;
			}
		}
	}

	return cnt;
}

int main() {
	cin >> a >> b;
	cout << counter3(a, b) << endl;
	return 0;
}