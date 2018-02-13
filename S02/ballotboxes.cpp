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
const int N = 500005;

struct compare {
	bool operator() (pii a, pii b) const{
		int c1 = a.fst / a.snd + (a.fst % a.snd != 0);
		int c2 = b.fst / b.snd + (b.fst % b.snd != 0);
		return c1 < c2;
	}
};

int main() {
	int n, b;
	
	while (42) {
		priority_queue<pii, vector<pii>, compare> pq;
		scanf("%d %d", &n, &b);
		if (n == -1) break;

		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			pq.push(pii(x, 1));
		}
		b -= pq.size();
		while (b--) {
			pii x = pq.top(); pq.pop();
			x.snd++;
			pq.push(x);
		}
		pii top = pq.top();
		printf("%d\n", top.fst / top.snd + (top.fst % top.snd != 0));
	}
	return 0;
}
