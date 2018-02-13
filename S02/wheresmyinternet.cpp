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
const int N = 200005;

int id[N], sz[N];

int parent(int x) {
	if (id[x] == x) return x;
	return id[x] = parent(id[x]);
}

void join(int a, int b) {
	a = parent(a); b = parent(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	sz[b] = 0;
	id[b] = a;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) id[i] = i, sz[i] = 1;

	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		join(a - 1, b - 1);
	}

	bool connected = true;
	for (int i = 0; i < n; i++) {
		if (parent(i) != parent(0)) printf("%d\n", i + 1), connected = false;
	}
	if (connected) printf("Connected\n");
	
	return 0;
}
