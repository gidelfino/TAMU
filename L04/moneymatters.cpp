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
const int N = 10005;

int id[N], sz[N];

int find(int a) {
	if (a == id[a]) return a;
	id[a] = find(id[a]);
	return id[a];
}

void join(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	id[b] = a;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	int o[N];
	for (int i = 0; i < n; i++) scanf("%d", &o[i]), id[i] = i, sz[i] = 1;
	
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		join(a, b);
	}
	
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int a = find(i);
		if (mp.count(a)) mp[a] += o[i];
		else mp[a] = o[i];
	}

	for (pii a : mp)
		if (a.snd != 0) { printf("IMPOSSIBLE\n"); return 0; }
	printf("POSSIBLE\n");
	return 0;
}
