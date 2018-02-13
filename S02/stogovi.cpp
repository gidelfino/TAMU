#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 300005;
const int MAXLOG = 30;

int pr[N], top[N], dist[N], P[N][MAXLOG];

int process(int i, int j) {
	if (j == 0) return P[i][j] = pr[i];
	int &anc = P[i][j];
	if (anc != -1) return anc;
	anc = process(process(i, j - 1), j - 1);
	return anc;
}

int lca(int v, int w) {
	int log;
	if (dist[v] < dist[w]) swap(v, w);
	for (log = 1; (1 << log) <= dist[v]; log++);
	log--;
	for (int i = log; i >= 0; i--)	
		if (dist[v] - (1 << i) >= dist[w])
			v = process(v, i);
	if (v == w) return v;
	for (int i = log; i >= 0; i--)
		if (process(v, i) != process(w, i))
			v = process(v, i), w = process(w, i);
	return pr[v];
}

int main() {
	int n; char c;

	scanf("%d", &n);
	pr[0] = 0; top[0] = 0;
	memset(P, -1, sizeof P);
	for (int i = 1; i <= n; i++) {
		scanf(" %c", &c);
		if (c == 'a') {
			int w; scanf("%d", &w);
			pr[i] = top[w];
			top[i] = i;
			dist[i] = dist[top[w]] + 1;
		}
		else if (c == 'b') {
			int w; scanf("%d", &w);
			top[i] = pr[top[w]];
			printf("%d\n", top[w]);
		}
		else {
			int w, v;
			scanf("%d %d", &v, &w);
			top[i] = top[v];
			int x = lca(top[v], top[w]);
			printf("%d\n", dist[x]);
		}
	}
	return 0;
}
