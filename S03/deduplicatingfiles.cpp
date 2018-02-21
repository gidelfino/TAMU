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

int hash_value(string line) {
	int ret = 0;
	for (int i = 0; i < line.size(); i++) 
		ret ^= line[i];
	return ret ^ '\n';
}

bool is_collision(string a, string b) {
	if (a.size() != b.size()) return true;
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i]) return true;
	return false;
}

int main() {
	while (42) {
		int n; scanf("%d", &n);
		if (!n) break;
		int tot = n, coll = 0;
		vector<string> s;
		vector<int> hv;
		getchar();
		for (int i = 0; i < n; i++) {
			string line;
			getline(cin, line);
			s.push_back(line);
			hv.pb(hash_value(line));
		}
		bool seen[505];
		memset(seen, 0, sizeof seen);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (hv[i] == hv[j]) {
					if (is_collision(s[i], s[j])) coll++;
					else { tot -= (!seen[i] || !seen[j]); seen[i] = seen[j] = true; } 
				}
			}
		}
		printf("%d %d\n", tot, coll);
	}
	return 0;
}
