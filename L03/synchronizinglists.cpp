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
const int N = 5005;

int main() {
	while (true) {
		unordered_map<int, int> mp;
		int n; scanf("%d", &n);
		int l1[N], l2[N];
		if (n == 0) return 0;
		for (int i = 0; i < n; i++) scanf("%d", &l1[i]), mp[l1[i]] = i;
		for (int i = 0; i < n; i++) scanf("%d", &l2[i]);
		sort(l1, l1 + n); sort(l2, l2 + n);
		int ans[N];
		for (int i = 0; i < n; i++) {
			ans[mp[l1[i]]] = l2[i];
		}
		for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
		putchar('\n');
	}
	return 0;
}
