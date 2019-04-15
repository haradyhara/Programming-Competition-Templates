#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int n_num = 6;
const ll inf = 1e9+7;
int start,fin;

typedef struct {
	int I;
	int from;
	int cost;
	vector<pair<int,int>> to;
} _node;

bool operator > (const _node& a,const _node& b) {
	return a.cost > b.cost;
}
class Dijkstra {
public:
	vector<_node> node;
	string ans;
	priority_queue<_node,vector<_node>,greater<_node>> pque;
	void ds_init(int n) {
		node = vector<_node>(n);
		for (int i = 0;i < n;i++) {
			node[i].I = i;
			node[i].from = i;
			node[i].cost = INF;
		}
	}
	void dijkstra(int s) {
		node[s].cost = 0;
		for (int i = 0;i < node[s].to.size();i++) {
			node[node[s].to[i].first].cost = node[s].to[i].second + node[s].cost;
			node[node[s].to[i].first].from = s;
			pque.push(node[node[s].to[i].first]);
		}
		while (!pque.empty()) {
			_node next = pque.top();
			pque.pop();
			if (next.cost > node[next.I].cost) continue;
			for (int i = 0;i < next.to.size();i++) {
				if (node[next.to[i].first].cost > next.cost + next.to[i].second) {
					node[next.to[i].first].cost = next.cost + next.to[i].second;
					node[next.to[i].first].from = next.I;
					pque.push(node[next.to[i].first]);
				}
			}
		}
	}
	void searchpath(int now) {
		if (node[now].from != now) {
			ans = to_string(node[now].from) + " " + ans;
			searchpath(node[now].from);
		} else {
			return;
		}
	}
};
Dijkstra dj;
int main() {	
	for (int i = 0;i < 10;i++) {
		int a,b,c;
		cin >> a >> b >> c;
		dj.node[a].to.push_back({b,c});
		dj.node[b].to.push_back({a,c});
	}
	dj.ds_init();
	start = 0;fin = 5;
	dj.dijkstra();
	dj.searchpath(fin);
	cout << dj.ans << endl;
}