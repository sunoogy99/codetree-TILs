#include <iostream>
using namespace std;

int n, m;

// lcm = gcd * gcd로 나눈 몫들
int gcd(int a, int b) {
    if (a == 0 || b == 0) {
        return a == 0 ? b : a;
    }
    if (a > b) return gcd(b, a % b);
    else return gcd(a, b % a);
}

int main() {
    cin >> n >> m;
    int gcd_num = gcd(n, m);
    int a = n / gcd_num;
    int b = m / gcd_num;
    cout << gcd_num * a * b << endl;    
    return 0;
}