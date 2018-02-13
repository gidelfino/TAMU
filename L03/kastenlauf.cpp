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
const int N = 105;

int S[N], sz[N];

int find(int a) {
	if (S[a] == a) return a;
	return S[a] = find(S[a]);
}

void join(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	S[b] = a;
}

int dist(pii a, pii b) { return abs(a.fst - b.fst) + abs(a.snd - b.snd); }

int main() {
	for_tests(t, tt) {
		pii l[N];
		int n; scanf("%d", &n);
		n += 2;
		for (int i = 0; i < n; i++) S[i] = i, sz[i] = 1;
		for (int i = 0; i < n; i++) 
			scanf("%d %d", &l[i].fst, &l[i].snd);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (dist(l[i], l[j]) <= 20 * 50) join(i, j);
			}
		}
		if (find(0) == find(n - 1)) printf("happy\n");
		else printf("sad\n");
	}
	return 0;
}
