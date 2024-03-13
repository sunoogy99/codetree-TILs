#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
	cin >> str;

	int len = str.length();
	int cnt = 0;
	
	for (int i = 0; i < len - 1; i++) {
		if (str[i] == '(') {
			for (int j = i + 1; j < len; j++) {
				if (str[j] == ')') cnt++;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}