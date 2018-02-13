#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<string, string> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

void read(int i, unordered_map<string, ll> &mp) {
	int m;
	scanf("%d", &m);
	for (int j = 0; j < m; j++) {
		string ing;
		cin >> ing;
		mp[ing] |= (1ll << i);
	}
}

int main() {
	for_tests(t, tt) {
		unordered_map<string, ll> native, foreign;
		int n, m;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			char name[30];
			scanf("%s", name);
			read(i, native);
			read(i, foreign);
		}
		vector<pii> ans;
		for (auto it = native.begin(); it != native.end(); ++it) {
			for (auto itf = foreign.begin(); itf != foreign.end(); ++itf) {
				if (it->snd == itf->snd) 
					ans.pb(pii(it->fst, itf->fst));
			}
		}
		sort(ans.begin(), ans.end());
		for (pii x : ans) cout << "(" << x.fst << ", " << x.snd << ")" << endl;
		cout << endl;
	}
	return 0;
}
