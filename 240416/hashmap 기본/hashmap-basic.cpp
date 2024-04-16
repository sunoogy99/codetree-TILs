#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int n;
string oper;
unordered_map<int, int> m;

int main() {
	cin >> n;

	while (n--) {
		cin >> oper;

		int a, b;
		if (oper == "add") {
			cin >> a >> b;
			m[a] = b;
		}
		else if (oper == "remove") {
			cin >> a;
			m.erase(a);
		}
		else if (oper == "find") {
			cin >> a;

			if (m.find(a) == m.end()) {
				cout << "None" << '\n';
			}
			else {
				cout << (m.find(a))->second << "\n";
			}
		}
	}

	return 0;
}