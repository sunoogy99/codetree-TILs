#include <iostream>
#include <string>
using namespace std;

int res;
string before, after;

string make_maximal(string bin_num) {
	int len = bin_num.length();

	for (int i = 0; i < len; i++) {
		if (bin_num[i] == '0') {
			bin_num[i] = '1';
			return bin_num;
		}
	}

	bin_num[len - 1] = '0';
	return bin_num;
}

int binary_to_decimal(string bin_num) {
	int len = bin_num.length();
	int two = 1;
	int sum = 0;

	for (int i = len - 1; i >= 0; i--) {
		sum += (bin_num[i] - '0') * two;
		two *= 2;
	}

	return sum;
}

int main() {
	cin >> before;
	after = make_maximal(before);
	res = binary_to_decimal(after);
	cout << res << endl;

	return 0;
}