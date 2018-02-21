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
const int N = 5000006;

ll bit[N];

void update (int i, ll v) {
	for (; i < N; i += (i & -i)) 
		bit[i] += v;
}

ll get (int i) {
	ll ret = 0;
	for (; i; i -= (i & -i)) ret += bit[i];
	return ret;
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	while (q--) {
		char op; int pos; ll val;
		scanf(" %c %d", &op, &pos);
		if (op == '+') {
			scanf("%lld", &val);
			update(pos + 2, val);
		}
		else {
			printf("%lld\n", get(pos + 1));
		}
	}
	return 0;
}
