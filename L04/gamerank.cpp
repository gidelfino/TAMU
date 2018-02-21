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

int level_stars(int lvl) {
	int req;
	if (lvl >= 21 && lvl <= 25) req = 2;
	else if (lvl >= 16 && lvl <= 20) req = 3;
	else if (lvl >= 11 && lvl <= 15) req = 4;
	else if (lvl >= 1 && lvl <= 10) req = 5;
	else req = INT_MAX;
	return req;

}

void update_level_stars(int &lvl, int &stars) {
	int req = level_stars(lvl);
	if (req < stars) lvl--, stars = stars - req; 
}

int main() {
	string game;
	cin >> game;
	int lvl = 25, stars = 0, lwins = 0;
	for (char c : game) {
		if (c == 'W') {
			lwins++; stars++;
			if (lvl >= 6 && lvl <= 25 && lwins >= 3) stars++;
			update_level_stars(lvl, stars);
		}
		else {
			lwins = 0;
			if (lvl >= 1 && lvl <= 20) 
				if (stars == 0 && lvl < 20) stars = level_stars(lvl + 1) - 1, lvl++; 
				else if (stars) stars--;
		}
	}
	if (lvl == 0) printf("Legend\n");
	else printf("%d\n", lvl);
	return 0;
}
