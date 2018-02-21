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
const int N = 20005;

int main() {
	while (42) {
		int n, m; scanf("%d %d", &n, &m);
		if (n + m == 0) break;
		int k[N], d[N];
		for (int i = 0; i < n; i++) scanf("%d", &d[i]);
		for (int i = 0; i < m; i++) scanf("%d", &k[i]);

		sort(d, d + n);
		sort(k, k + m);

		int i = 0, j = 0, ans = 0;
		while (i < n && j < m) {
			if (k[j] >= d[i]) ans += k[j], i++, j++;
			else j++;
		}
		if (i == n) printf("%d\n", ans);
		else printf("Loowater is doomed!\n");
	}
	return 0;
}
