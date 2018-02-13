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

int main() {
	string command;
	map<string, int> mp;
	map<int, string> rev;

	while(cin >> command) {
		if (command == "def") {
			string x; int y;
			cin >> x >> y;
			if (mp.count(x)) rev.erase(mp[x]);
			mp[x] = y;
			rev[y] = x;
		}
		else if (command == "clear")
			mp.clear(), rev.clear();
		else {
			string x, op("+");
			int ans = 0; bool unknown = false;
			while (op != "=") {
				cin >> x;
				if (!mp.count(x)) unknown = true;
				else {
					if (op == "+") ans += mp[x];
					else if (op == "-") ans -= mp[x];
				}
				cin >> op;
				cout << x << " " << op << " ";
			}
			if (unknown || !rev.count(ans)) cout << "unknown" << endl;
			else cout << rev[ans] << endl;
		}
	}
	return 0;
}
