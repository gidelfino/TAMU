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
const int N = 100005;

int main() {
	int n; scanf("%d", &n);
	int t[N];
	for (int i = 0; i < n; i++) scanf("%d", &t[i]);
	sort(t, t + n);
	int ans = t[n - 1] + 1;
	int cday = 2;
	for (int i = n - 2; i >= 0; i--) { 
		ans = max(ans, cday + t[i]);
		cday++;
	}
	printf("%d\n", ans + 1);
	return 0;
}
