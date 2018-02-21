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

vector<string> tokenize(string line) {
	int i = 0;
	vector<string> ret;
	for (int j = 1; j < line.size(); j++)
		if (line[j] == ' ') ret.pb(string(line.begin() + i, line.begin() + j)), i = j + 1, j++;
	ret.pb(string(line.begin() + i, line.begin() + line.size()));
	return ret;
}

int main() {
	unordered_map<string, string> dc;
	while (42) {
		string line;
		getline(cin, line);
		if (line.empty()) break;
		vector<string> s = tokenize(line);
		dc[s[1]] = s[0];
	}
	string w;
	while (cin >> w) {
		if (dc.count(w)) cout << dc[w] << endl;
		else cout << "eh" << endl;
	}
	return 0;
}
