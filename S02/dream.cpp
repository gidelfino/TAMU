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
const int N = 50005;

int main() {
	int n; char op;
	vector<string> st;
	unordered_map<string, int> mp;
	scanf("%d", &n);

	while (n--) {
		scanf(" %c", &op);
		if (op == 'E') { 
			string event;
			cin >> event;
			mp[event] = st.size();
			st.pb(event);
		}
		else if (op == 'D') {
			int r; scanf("%d", &r);
			while (r--) { 
				mp.erase(st.back());
				st.pop_back();
			}
		}
		else {
			int k, mn = N, mx = -1; 
			string scene;
			bool plot = false;

			scanf("%d", &k);
			while (k--) {
				cin >> scene;
				if (scene.at(0) == '!') {
					string nsc = string(scene.begin() + 1, scene.end());
					if (mp.count(nsc)) mn = min(mn, mp[nsc]);
				}
				else {
					if (!mp.count(scene)) plot = true;
					else mx = max(mx, mp[scene]);
				}
			}
			if (plot) printf("Plot Error\n");
			else if (mn == N) printf("Yes\n");
			else if (mx < mn) printf("%d Just A Dream\n", st.size() - mn);
			else printf("Plot Error\n");
		}
	}
	return 0;
}
