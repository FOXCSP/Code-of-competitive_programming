#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
int tot, n;
struct node {
	map<string, int> next;
} tr[N];

void insert(vector<string> s) {
	int p = 0;
	for (auto c : s) {
		if (!tr[p].next[c]) tr[p].next[c] = ++tot;
		p = tr[p].next[c];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		vector<string> v;
		string t;
		for (auto c : s) {
			if (c == '/') {
				if (t != "") v.push_back(t);
				t = "";
			}
			if (c != '/') t = t + c;
		}
		v.push_back(t);
		insert(v);
		cout << tot << '\n';
	}
	return 0;
}