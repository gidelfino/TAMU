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

char toLower(char c) { return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c; }

string lowercase(string s) {
	string ans;
	for (int i = 0; i < s.size(); i++) 
		ans.pb(toLower(s[i]));
	return ans;
}

bool isLetter(char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); }

int main() {
	string word, line;
	unordered_set<string> st;
	while (getline(cin, line)) {
		for (int i = 0; i < line.size(); ) {
			int j;
			for (j = i; j < line.size() && isLetter(line[j]); j++);
			string word(line, i, j - i + (j == line.size()));
			string lower = lowercase(word);
			if (st.count(lower)) printf(".");
			else st.insert(lower), cout << word;
			while (!isLetter(line[j]) && j < line.size()) printf("%c", line[j++]);
			i = j;
		}
		cout << endl;
	}
	return 0;
}
