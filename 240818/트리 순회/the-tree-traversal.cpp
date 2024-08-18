#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> tree;

void preOrder(char x) {
	cout << x;
	if (tree[x - 'A'][0] != '.') preOrder(tree[x - 'A'][0]);
	if (tree[x - 'A'][1] != '.') preOrder(tree[x - 'A'][1]);
}

void inOrder(char x) {
	if (tree[x - 'A'][0] != '.') inOrder(tree[x - 'A'][0]);
	cout << x;
	if (tree[x - 'A'][1] != '.') inOrder(tree[x - 'A'][1]);
}

void postOrder(char x) {
	if (tree[x - 'A'][0] != '.') postOrder(tree[x - 'A'][0]);
	if (tree[x - 'A'][1] != '.') postOrder(tree[x - 'A'][1]);
	cout << x;
}

int main() {
	tree.resize(26);

	cin >> n;

	// 트리 생성
	char cur, left, right;
	for (int i = 0; i < n; i++) {
		cin >> cur >> left >> right;

		tree[cur - 'A'].push_back(left);
		tree[cur - 'A'].push_back(right);
	}

	preOrder('A');
	cout << '\n';

	inOrder('A');
	cout << '\n';

	postOrder('A');
	
	return 0;
}