#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 125009;

vector<int> adj[N];
int en, to[N], cp[N], fl[N];
int seen[N], tme;

//add direct and reverse edge side to side
void add_edge(int v, int w, int c) {
	adj[v].pb(en); to[en] = w; cp[en] = c; en++;
	adj[w].pb(en); to[en] = v; cp[en] = 0; en++;
}

//find a path from source to sink 
int dfs(int v, int t, int f) {
	if (v == t) return f;
	seen[v] = tme;
	for (int e : adj[v]) {
		if (seen[to[e]] < tme && cp[e] - fl[e]) 
			if (int g = dfs(to[e], t, min(cp[e] - fl[e], f))) {
				fl[e] += g;
				fl[e ^ 1] -= g;
				return g;
			}
	}
	return 0;
}

//main max flow function, while there is a path from source to sink increase the flow
int max_flow(int s, int t) {
	int flow = 0; tme = 1;
	while (int g = dfs(s, t, 1000000)) flow += g, tme++;
	return flow;
}

int main() {
	int n, m, v, w, ti;
	scanf("%d %d", &n, &m); //n nodes and m edjes
	for (int i = 0; i < m; i++) {
		//Edge from v to w with cost ti
		scanf("%d %d %d", &v, &w, &ti);
		add_edge(v, w, ti);
	}
	//Assuming that the source is node 0 and the sink is node n - 1
	printf("Max Flow %d\n", max_flow(0, n - 1));
	return 0;
}

// This a simple implementation of the max flow algorithm
// For a faster version just replace the dfs for a bfs

