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

int bit[N + N];

void update(int x, int v) {
	for (int i = x; i < N + N; i += (i & -i))
		bit[i] += v;
}

int get(int x) {
	int ret = 0;
	for (int i = x; i > 0; i -= (i & -i))
		ret += bit[i];
	return ret;
}

int main() {
	for_tests(t, tt) {
		int m, r;
		int mv[N];
		memset(bit, 0, sizeof bit);
		scanf("%d %d", &m, &r);
		for (int i = 1; i <= m; i++) mv[i] = m - i + 1, update(i, 1);
		int top = m + 1;
		for (int i = 0; i < r; i++) {
			int ai; scanf("%d", &ai);
			printf("%d ", get(top - 1) - get(mv[ai]));
			update(mv[ai], -1);
			update(top, 1);
			mv[ai] = top++;
		}
		printf("\n");
	}
	
	return 0;
}
