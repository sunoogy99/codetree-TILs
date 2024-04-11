// https://www.codetree.ai/missions/2/problems/select-segments-without-overlap-2/description
// 겹치지 않게 선분 고르기
/* 
	내가 생각한 로직
	- 끝나는 지점을 기준으로 정렬한다. 
	- 끝나는 지점이 동일하다면, 시작지점이 가장 큰 것이 앞에 오도록 정렬한다.
		이유) 끝나는 지점이 동일할 때 막대 길이가 제일 작은 것이 앞에 오게 하기 위함
	- 이전 막대의 끝나는 지점보다 현재 막대의 시작 지점이 더 클 때 겹치지 않는 선분 개수를 증가시킨다.
	- DP 방식이 아닌 그리디 알고리즘으로 풀이하였음
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, total;
pair<int, int> arr[1001];
bool compare(pair<int, int>, pair<int, int>);	// pair 비교를 위한 비교 함수

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	
	sort(arr + 1, arr + n + 1, compare);

	// arr[0]: (0, 0)
	// picked는 이전에 선택된 막대의 인덱스를 저장하는 변수
	int picked = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i].first > arr[picked].second) {
			total++;
			picked = i;
		}
	}

	cout << total;
	return 0;
}

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first > b.first;
	return a.second < b.second;
}