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

void counterA(char c) {
	if (c == 'R') printf("S");
	else if (c == 'B') printf("K");
	else printf("H");
}

int main() {
	char s[N];
	scanf("%s", s);
	int n = strlen(s);
	deque<char> q;
	for (int i = 0; i < n; i++) {
		q.pb(s[i]);
		if (q.size() == 3) {
			bool rs, bs, ls; rs = bs = ls = false;
			for (char c : q) rs = rs || (c == 'R'), bs = bs || (c == 'B'), ls = ls || (c == 'L');
			if (rs && bs && ls) printf("C"), q.clear();
			else counterA(q[0]), q.pop_front();
		}	
	}
	for (char c : q) counterA(c);
	printf("\n");
	return 0;
}
