#include <iostream>
#include <string>
using namespace std;

int n;
char tree[30];
char aIdx[30];

// 전위 순회
void preOrder(int idx) {
	cout << tree[idx];
	if (tree[2 * idx] != '.') preOrder(2 * idx);
	if (tree[2 * idx + 1] != '.') preOrder(2 * idx + 1);
}

// 중위 순회
void inOrder(int idx) {
	if (tree[2 * idx] != '.') inOrder(2 * idx);
	cout << tree[idx];
	if (tree[2 * idx + 1] != '.') inOrder(2 * idx + 1);
}

// 후위 순회
void postOrder(int idx) {
	if (tree[2 * idx] != '.') postOrder(2 * idx);
	if (tree[2 * idx + 1] != '.') postOrder(2 * idx + 1);
	cout << tree[idx];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	char node, left, right;
	aIdx[0] = 1; // 'A' 인덱스를 1로 설정

	// 이진 탐색 트리 생성하기
	for (int i = 1; i <= n; i++) {
		cin >> node >> left >> right;
		
		int cur = aIdx[node - 'A'];

		tree[cur] = node;

		int lChild = 2 * cur;
		if (left != '.') aIdx[left - 'A'] = lChild;
		tree[lChild] = left;

		int rChild = 2 * cur + 1;
		if (right != '.') aIdx[right - 'A'] = rChild;
		tree[rChild] = right;
	}

	preOrder(1);
	cout << '\n';

	inOrder(1);
	cout << '\n';

	postOrder(1);
	cout << '\n';

	return 0;
}