#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9;

int Q;
int n, m;
int u, v, w;
int start = 0; // 출발 지점

struct Product {
	int id;
	int revenue;
	int dest;
	int cost;

	Product(int id, int r, int d, int c) : id(id), revenue(r), dest(d), cost(c) {}

	bool operator<(const Product& comp) const {
		if (revenue - cost == comp.revenue - comp.cost)
			return id > comp.id;
		return revenue - cost < comp.revenue - comp.cost;
	}
};

struct cmp {
	bool operator() (pair<int, int> a, pair<int, int> b) const {
		// 도착 정점이 같은 경우, 비용이 작은게 앞에 오도록 한다.
		if (a.first == b.first)
			return a.second < b.second;
		// 도착 정점이 다른 경우, 정점 번호가 작은게 앞에 오도록 한다.
		else return a.first < b.first;
	}
};

bool isDeleted[30001]; // 여행 상품이 삭제되었는가
vector<set<pair<int, int>, cmp>> graph; // 그래프. 간선을 인덱스로 접근하는 경우가 없기 때문에 set 사용 가능
priority_queue<Product> prodQ; // 상품 우선순위에 기반해 저장한 큐
vector<int> costs; // 정점에 대한 최단 거리 저장

// 다익스트라로 시작점 s로부터 최단 거리 구하기
void dijikstra(int s) {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, s)); // 시작 정점에 대한 비용은 0
	costs[s] = 0;

	while (!pq.empty()) {
		int curCost = pq.top().first;
		int curX = pq.top().second;
		pq.pop();

		// 현재 방문한 지점이 costs보다 작은 경우, 방문할 필요 없음
		if (curCost > costs[curX]) continue;

		for (pair<int, int> e : graph[curX]) {
			int nextX = e.first;
			int weight = e.second;

			// 정점 방문 체크를 하는 것이 맞는 구현인가? -> 맞음
			if (costs[curX] + weight < costs[nextX]) {
				costs[nextX] = costs[curX] + weight;
				pq.push(make_pair(costs[nextX], nextX));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> Q;

	int op, id, rev, des;
	while (Q--) {
		cin >> op;

		if (op == 100) {
			cin >> n >> m;

			graph.resize(n);
			costs.resize(n, INF);

			// 그래프 구현
			for (int i = 0; i < m; ++i) {
				cin >> u >> v >> w;
				graph[u].insert(make_pair(v, w));
				graph[v].insert(make_pair(u, w));
			}

			// 다익스트라로 최단 거리 갱신
			dijikstra(start);
		}
		else if (op == 200) {
			cin >> id >> rev >> des;
			prodQ.push(Product(id, rev, des, costs[des]));
			isDeleted[id] = false; // 여행 상품 삭제 시도를 먼저 한 경우가 있을 수 있음
		}
		else if (op == 300) {
			cin >> id;
			isDeleted[id] = true;
		}
		else if (op == 400) {
			while (true) {
				if (prodQ.empty()) {
					cout << -1 << '\n';
					break;
				}
				
				Product curProd = prodQ.top();

				if (isDeleted[curProd.id]) {
					prodQ.pop();
				}
				else if (curProd.revenue - curProd.cost < 0 || curProd.cost == INF) {
					cout << -1 << '\n';
					break;
				}
				else {
					cout << curProd.id << '\n';
					prodQ.pop();
					break;
				}
			}
		}
		else if (op == 500) {
			cin >> start;

			costs.clear();

			costs.resize(n, INF);

			dijikstra(start);

			vector<Product> temp;
			while (!prodQ.empty()) {
				Product prod = prodQ.top();
				prodQ.pop();

				// 삭제된 게 아닌 경우에만 갱신해서 넣기
				if (!isDeleted[prod.id]) {
					prod.cost = costs[prod.dest];
					temp.push_back(prod);
				}
			}

			for (const Product p : temp) {
				prodQ.push(p);
			}
		}
	}

	return 0;
}