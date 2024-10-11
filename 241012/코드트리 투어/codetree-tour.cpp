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

vector<int> costs; // 정점에 대한 최단 거리 저장

struct Product {
	int id;
	int revenue;
	int dest;
	int cost;

	Product(int id, int r, int d, int c) : id(id), revenue(r), dest(d), cost(c) {}
/*
	bool operator<(const Product& comp) const {
		if (revenue - cost == comp.revenue - comp.cost)
			return id > comp.id;
		return revenue - cost < comp.revenue - comp.cost;
	}
*/
};

// Product Comp
struct comp {
	bool operator() (Product* a, Product* b) const {
		// costs로 우선순위 설정할 수 있나? -> 갱신 안됨
		if (a->revenue - a->cost == b->revenue - b->cost) {
			return a->id < b->id;
		}
		return a->revenue - a->cost > b->revenue - b->cost;
	}
};

struct cmp {
	bool operator() (pair<int, int> a, pair<int, int> b) const {
		// 도착 정점이 같은 경우, 비용이 작은게 앞에 오도록 한다.
		if (a.first == b.first)
			return a.second > b.second;
		// 도착 정점이 다른 경우, 정점 번호가 작은게 앞에 오도록 한다.
		else return a.first < b.first;
	}
};

vector<set<pair<int, int>, cmp>> graph; // 그래프. 간선을 인덱스로 접근하는 경우가 없기 때문에 set 사용 가능
set<Product*, comp> prodQ; // 상품 우선순위에 기반해 저장한 큐
Product* info[30001]; // 상품 정보 저장 (set find에서 사용할 거임)

// 다익스트라로 시작점 s로부터 최단 거리 구하기
// 다익스트라가 잘못됐나? O(ElogV)
void dijikstra(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
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
			Product* newProd = new Product(id, rev, des, costs[des]);
			prodQ.insert(newProd); // O(logn) -> 3만 logn
			info[id] = newProd;
			// isDeleted[id] = false; // 여행 상품 삭제 시도를 먼저 한 경우가 있을 수 있음
		}
		else if (op == 300) {
			cin >> id;
			// isDeleted[id] = true;
			// 여기를 set.find로 찾아야 함
			Product* tmp = info[id];
			
			if (tmp != nullptr) {
				// 비용 갱신 안 되어 있을 수 있음
				tmp->cost = costs[tmp->dest];

				auto it = prodQ.find(tmp);
				if (it != prodQ.end()) {
					prodQ.erase(it);
				}

				info[id] = nullptr;
			}
		}
		else if (op == 400) {
			while (true) {
				if (prodQ.size() == 0) {
					cout << -1 << '\n';
					break;
				}
				
				Product* curProd = *(prodQ.begin());

				if ((curProd->revenue) - costs[curProd->dest] < 0 || costs[curProd->dest] == INF) {
					cout << -1 << '\n';
					break;
				}
				else {
					cout << curProd->id << '\n';
					prodQ.erase(prodQ.begin());
					break;
				}
			}
		}
		else if (op == 500) {
			cin >> start;

			costs.clear();

			costs.resize(n, INF);
			
			dijikstra(start);

			// set에서 erase를 해서 빼야함
			// 안 빼고 cost 갱신하면, set 우선순위 바뀜
			vector<Product*> tmp;
			while (!prodQ.empty()) {
				Product* p = *prodQ.begin();
				prodQ.erase(prodQ.begin());
				p->cost = costs[p->dest];
				tmp.push_back(p);
			}

			for (auto p : tmp) {
				prodQ.insert(p);
			}
		}
	}

	return 0;
}