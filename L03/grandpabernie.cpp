#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<string, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int main() {
	int n; scanf("%d", &n);
	string name;
	vector<pii> all;
	int year, pos; 

	for (int i = 0; i < n; i++) {
		cin >> name >> year;
		all.pb(pii(name, year));
	}
	sort(all.begin(), all.end());

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> name >> pos;
		int l = 0, r = all.size() - 1;
		while (l < r) {
			int mid = (l + r) / 2;
			if (all[mid].fst < name) l = mid + 1;
			else r = mid;
		}
		printf("%d\n", all[l + pos - 1].snd);
	}
	return 0;
}
