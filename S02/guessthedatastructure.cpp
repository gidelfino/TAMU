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
const int N = 1005;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int op, x;
		bool queue, pqueue, stack;
		queue = pqueue = stack = true;
		deque<int> q, st;
		priority_queue<int> pq;

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &op, &x);
			if (op == 1) { 
				q.pb(x);
				pq.push(x);
				st.pb(x);
			}
			else {
				if (q.empty()) { queue = stack = pqueue = false; break; }
				if (x != q.front()) queue = false;
				if (x != st.back()) stack = false;
				if (x != pq.top()) pqueue = false;
				q.pop_front();
				st.pop_back();
				pq.pop();
			}
		}

		if (queue + pqueue + stack > 1) printf("not sure\n");
		else if (queue + pqueue + stack == 0) printf("impossible\n");
		else if (queue) printf("queue\n");
		else if (pqueue) printf("priority queue\n");
		else printf("stack\n");
	}
	return 0;
}
