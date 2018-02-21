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
const int N = 1000005;

int seen[N], id[N], sz[N];
vector<int> prime, pf[N];

void generate_primes() {
	int n = N;
	for (int k = 2; k < N; k++) {
		if (seen[k]) continue;
		prime.pb(k);
		for (ll j = (ll)k * k; j < N; j += (ll)k) seen[j] = true;
	}
}

int find(int x) {
	if (id[x] == x) return x;
	return id[x] = find(id[x]);
}

void join(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	id[b] = a;
}

int main() {
	generate_primes();
	for_tests(t, tt) {
		ll a, b, p;
		scanf("%lld %lld %lld", &a, &b, &p);
		int n = b - a + 1;
		for (int i = 0; i < n; i++) id[i] = i, sz[i] = 1;
		int newp = (int)min(p, (ll)n);
		for (int pr : prime) {
			if (pr < newp) continue;
			if (pr > n) break;
			int st = 0;
			if (a % pr != 0) st = pr - a % pr;
			for (int i = st + pr; i < n; i += pr) join(st, i);
		}

		unordered_set<int> st;
		for (int i = 0; i < n; i++) 
			if (!st.count(find(i))) st.insert(find(i));

		printf("Case #%d: %d\n", tt, st.size());
	}
	return 0;
}
