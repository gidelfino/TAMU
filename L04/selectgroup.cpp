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


void show(vector<string> s) {
	for (string w : s) cout << w << " ";
}

bool is_command(string s) { return s == "union" || s == "intersection" || s == "difference"; }

vector<string> do_union(vector<string> s1, vector<string> s2) {
	unordered_set<string> st;
	vector<string> ret;
	for (string s : s1) st.insert(s), ret.pb(s);
	for (string s : s2) 
		if (!st.count(s)) ret.pb(s);
	return ret;
}

vector<string> do_intersection(vector<string> s1, vector<string> s2) {
	unordered_set<string> st;
	vector<string> ret;
	for (string s : s1) st.insert(s);
	for (string s : s2) 
		if (st.count(s)) ret.pb(s);
	return ret;
}



vector<string> do_difference(vector<string> s1, vector<string> s2) {
	unordered_set<string> st;
	vector<string> ret;
	for (string s : s2) st.insert(s);
	for (string s : s1) 
		if (!st.count(s)) ret.pb(s);
	return ret;
}

vector<string> do_operation(string op, vector<string> s1, vector<string> s2) {
	if (op == "union") return do_union(s1, s2);
	else if (op == "intersection") return do_intersection(s1, s2);
	else return do_difference(s1, s2);
}

void sort_and_show(vector<string> s) {
	sort(s.begin(), s.end());
	for (string w : s) cout << w << " ";
	putchar('\n');
}

vector<string> tokenize(string line) {
	int i = 0;
	vector<string> ret;
	for (int j = 1; j < line.size(); j++) 
		if (line[j] == ' ') ret.pb(string(line.begin() + i, line.begin() + j)), i = j + 1, j++;
	ret.pb(string(line.begin() + i, line.begin() + line.size()));
	return ret;
}

int main() {
	string line;
	unordered_map<string, vector<string> > mp;
	while (getline(cin, line)) {
		vector<string> exp;
		vector<vector<string> > gr;
		exp = tokenize(line);
		if (exp[0] == "group") {
			string name = exp[1];
			int n = stoi(exp[2]); 
			vector<string> cur;
			mp[name] = vector<string>(exp.begin() + 3, exp.end());
		}
		else {
			for (string s : exp) 
				if (is_command(s)) gr.pb(vector<string>{s});
				else gr.pb(mp[s]);
			for (int i = gr.size() - 1; i >= 0; i--) {
				if (gr[i].size() == 1 && is_command(gr[i].front())) { 
					vector<string> fset = do_operation(gr[i].front(), gr[i + 1], gr[i + 2]);
					gr[i] = fset;
					gr.erase(gr.begin() + i + 1, gr.begin() + i + 3);
				}
			}
			sort_and_show(gr[0]);
		}
	}
	return 0;
}
