#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct H {
	int index, height;
	H(int i, int h) :index(i), height(h) {}
	bool operator <(const H& h) const{
		return height < h.height;
	}
};

struct Edge {
	int index, x, height;
	bool left;
	Edge(int i, int xx, int h, bool l) :index(i), x(xx), height(h), left(l) {}
	bool operator <(Edge& edge) {
		if (x == edge.x) {
			if (left != edge.left) {
				return left;
			}
			if (left)
				return height > edge.height;
			else
				return height < edge.height;
		}
		return x < edge.x;
	}
};
 

class Solution {
public:	
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> ans;
		if (!buildings.size())
			return ans;
		vector<Edge> edges;
		for (int i = 0; i < buildings.size(); i++) {
			edges.push_back(Edge(i, buildings[i][0], buildings[i][2], true));
			edges.push_back(Edge(i, buildings[i][1], buildings[i][2], false));
		}
		sort(edges.begin(), edges.end());
		int cur = 0;
		int curx = -1;
		priority_queue<H> heap;
		vector<bool> f(buildings.size(), false);
		for (int i = 0; i < edges.size(); i++) {
			if (edges[i].left) {
				if (edges[i].height > cur) {
					ans.push_back(pair<int, int>(edges[i].x, edges[i].height));
					cur = edges[i].height;
				}
				heap.push(H(edges[i].index, edges[i].height));
			} else {
				f[edges[i].index] = true;
				while (f[heap.top().index]) {
					heap.pop();
					if (heap.empty()) {
						cur = 0;
						break;
					}
					cur = heap.top().height;
				}
				if (cur < edges[i].height)
					ans.push_back(pair<int, int>(edges[i].x, cur));
			}
		}
		return ans;
	}
};

int main() {
	vector<vector<int>> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> temp(3);
		cin >> temp[0] >> temp[1] >> temp[2];
		v.push_back(temp);
	}
	Solution sol;
	vector<pair<int, int>> ans = sol.getSkyline(v);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}