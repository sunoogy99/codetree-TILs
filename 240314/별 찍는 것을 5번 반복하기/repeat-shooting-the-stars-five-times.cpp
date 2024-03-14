#include <iostream>
using namespace std;

void print_star() {
    for (int i = 0; i < 5; i++) {
        cout << "**********" << endl;
    }
}

int main() {
    print_star();
    return 0;
}