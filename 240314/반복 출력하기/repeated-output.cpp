#include <iostream>
using namespace std;

int n;
void print_strange(int num) {
    for (int i = 0; i < num; i++) {
        cout << "12345^&*()_" << endl;
    }
}

int main() {
    cin >> n;
    print_strange(n);
    return 0;
}