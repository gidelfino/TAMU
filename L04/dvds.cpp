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
const int N = 1000006;

int main() {
	for_tests(t, tt) {
		int n; scanf("%d", &n);
		int cur = 1;
		for (int i = 0; i < n; i++) {
			int v; scanf("%d", &v);
			if (v == cur) cur++;

		}
		printf("%d\n", n - cur + 1);
	}
	return 0;	
}
