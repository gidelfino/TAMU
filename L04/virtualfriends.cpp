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
const int N = 100005;

int id[N], sz[N];

int find(int a) {
	if (a == id[a]) return a;
	return id[a] = find(id[a]);
}

void join(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	id[b] = a;
}

int main() {
	for_tests(t, tt) {
		int n; scanf("%d", &n);
		unordered_map<string, int> mp;
		int top = 0;
		string s1, s2;
		for (int i = 0; i < N; i++) id[i] = i, sz[i] = 1;
		for (int i = 0; i < n; i++) {
			cin >> s1 >> s2;
			if (!mp.count(s1)) mp[s1] = top++;
			if (!mp.count(s2)) mp[s2] = top++;
			join(mp[s1], mp[s2]);
			printf("%d\n", sz[find(mp[s1])]);
		}
	}
	return 0;
}
