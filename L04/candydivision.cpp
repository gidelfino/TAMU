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

bool seen[1000006];

int main() {
	ll n; cin >> n;

	unordered_set<ll> st;
	for (ll d = 1; d * d <= n; d++) {
		if (n % d != 0) continue;
		st.insert(d);
		st.insert(n / d);
	}
	vector<ll> ans;
	for (ll x : st) ans.pb(x);
	sort(ans.begin(), ans.end());
	for (ll x : ans) cout << x - 1 << " ";
	putchar('\n');
	return 0;
}
