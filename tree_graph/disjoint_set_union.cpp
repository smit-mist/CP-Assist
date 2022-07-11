#include<bits/stdc++.h>
using namespace std;
struct DSU {
	int n;
	vector<int>par, siz;

	void init(int x) {
		n = x;
		par.assign(n + 5, 0);
		siz.assign(n + 5, 1);
		for (int i = 0; i < n + 5; i++) {
			par[i] = i;
		}
	}

	int find(int x) {
		if (x == par[x])
			return x;
		return par[x] = find(par[x]);
	}

	bool same(int a, int b) {
		return find(a) == find(b);
	}

	void unite(int a, int b) {
		a = find(a);
		b = find(b);

		if (siz[a] < siz[b])
			swap(a, b);

		par[b] = a;
		siz[a] += siz[b];
	}
};

int main() {
	return 0;
}