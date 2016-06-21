/*
Dinic
*/

#include <cstdio>
#include <list>
#include <queue>
using namespace std;

#define MAXV 410
#define MAXN 100
#define MAXE 50000

struct info {
	int p, num;
	info(int pp, int nnum) : p(pp), num(nnum) {}
};

int N, F, D;
list<info> map[MAXV];
int edges[MAXE];
int n, e;

void add_edge(int x, int y){
	edges[e] = 1;
	map[x].push_back(info(y, e));
	e++;
	edges[e] = 0;
	map[y].push_back(info(x, e));
	e++;
}

int dis[MAXV];

bool bfs() {
	for (int i = 0; i < n; i++) {
		dis[i] = -1;
	}
	queue<int> q;
	q.push(0);
	dis[0] = 0;
	while (!q.empty()) {
		int now = q.front();
		if (now == n - 1) {
			break;
		}
		q.pop();
		list<info>::iterator iter = map[now].begin();
		while (iter != map[now].end()) {
			int pnow = (*iter).p;
			int vnow = edges[(*iter).num];
			if (dis[pnow] == -1 && vnow != 0) {
				dis[pnow] = dis[now] + 1;
				q.push(pnow);
			}
			iter++;
		}
	}
	return dis[n - 1] > 0;
}

int min2(int x, int y) {
	if (x > y) return y;
	return x;
}

int dfs(int x, int min) {
	if (x == n - 1)
		return min;
	int remain;
	list<info>::iterator iter = map[x].begin();
	while (iter != map[x].end()) {
		int pnow = (*iter).p;
		int vnow = edges[(*iter).num];
		if (dis[pnow] == dis[x] + 1
			&& vnow != 0
			&& (remain = dfs(pnow, min2(min, vnow)))) {
			edges[(*iter).num] -= remain;
			edges[(*iter).num ^ 1] += remain;
			return remain;
		}
		iter++;
	}
	return 0;
}

int main() {
	int fn, dn;
	int temp;
	while (~scanf_s("%d%d%d", &N, &F, &D)){
		//0, 源点
		//1 - F，食物
		//F + 1 - F + N，牛
		//F + N + 1 - F + 2N，牛
		//F + 2N + 1 - F + 2N + D，饮料
		//F + 2N + D + 1，汇点
		e = 0;
		for (int i = 0; i < n; i++) {
			map[i].clear();
		}
		n = F + 2 * N + D + 2;
		for (int i = 1; i <= F; i++) {
			add_edge(0, i);
		}
		for (int i = N * 2 + F + 1; i <= N * 2 + F + D; i++) {
			add_edge(i, n - 1);
		}
		for (int i = 0; i < N; i++) {
			scanf_s("%d%d", &fn, &dn);
			for (int j = 0; j < fn; j++) {
				scanf_s("%d", &temp);
				add_edge(temp, F + i + 1);
			}
			add_edge(F + i + 1, F + N + i + 1);
			for (int j = 0; j < dn; j++) {
				scanf_s("%d", &temp);
				add_edge(N + F + i + 1, F + N * 2 + temp);
			}
		}
		int ans = 0;
		int path;
		while (bfs())
			while (path = dfs(0, 0x7fffffff))
				ans += path;
		printf("%d\n", ans);
	}
}