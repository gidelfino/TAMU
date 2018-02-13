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

int n;
vector<pii> hole;
int ans[15][15];

pii rotateP(int i, int j) { return pii(j, n - i - 1); }

void rotate() {
	for (int i = 0; i < hole.size(); i++)
		hole[i] = rotateP(hole[i].fst, hole[i].snd);
	sort(hole.begin(), hole.end());
}

int main() {
	char c, word[110];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf(" %c", &c);
			if (c == '.') hole.pb(pii(i, j));
			ans[i][j] = '*';
		}

	scanf("%s", word);
	int sz = n * n;
	if (sz % 4 != 0 || sz / 4 != hole.size()) { printf("invalid grille\n"); return 0; }

	for (int i = 0; i < sz && !hole.empty();) {
		for (pii h : hole) ans[h.fst][h.snd] = word[i++];
		rotate();
	}
	string s;

	for (int i = 0; i < n; i++)  
		for (int j = 0; j < n; j++) 
			if (ans[i][j] == '*') { printf("invalid grille\n"); return 0; }
			else s.pb(ans[i][j]);
	cout << s << endl;
	return 0;	
}
