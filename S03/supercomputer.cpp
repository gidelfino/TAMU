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

int bit[N];

void update(int x, int v) {
	for (int i = x; i < N; i += (i & -i)) 
		bit[i] += v;
}

int get(int x) {
	int ret = 0;
	for (int i = x; i > 0; i -= (i & -i))
		ret += bit[i];
	return ret;
}

int pos[N];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	while (k--) {
		char op; scanf(" %c", &op);
		if (op == 'F') {
			int b; scanf("%d", &b);
			if (pos[b] == 1) update(b, -1), pos[b] = 0;
			else update(b, 1), pos[b] = 1;
		}
		else {
			int i, j; scanf("%d %d", &i, &j);
			int ans = get(j) - get(i - 1);
			printf("%d\n", ans);
		}
	}
	return 0;
}
