#include <bits/stdc++.h>

using namespace std;

stack<int> a, b;
int main() {
	string s;
	map<string, int> mp;
	mp["true"] = 1;
	mp["false"] = 0;
	mp["or"] = 2;
	mp["and"] = 3;
	mp["not"] = 4;
	while (cin >> s) {
		if (mp[s] <= 1) a.push(mp[s]);
		else {
			if (mp[s] == 4) {
				cin >> s;
				if (s == "" || mp[s] > 1) {
					cout << "error\n";
					return 0;
				} else {
					a.push(!mp[s]);
				}
			} else {
				a.push(mp[s]);
			}
		}
	}

	while (a.size()) {
		auto t1 = a.top(); a.pop();
		if (a.size()) {
			auto t2 = a.top(); a.pop();
			if (t1 == 3) {
				if (t2 > 1 || b.size() == 0 || b.top() > 1) {
					printf("error\n");
					return 0;
				} else {
					auto x = b.top(); b.pop();
					b.push(t2 & x);
				}
			} else {
				b.push(t1);
				a.push(t2);
			}
		} else {
			b.push(t1);
		}
	}

	while (b.size()) {
		auto t1 = b.top(); b.pop();
		if (t1 > 1) {
			if (a.size() == 0 || b.size() == 0) {
				printf("error\n");
				return 0;
			} else {
				int at = a.top(); a.pop();
				int bt = b.top(); b.pop();
				a.push(at | bt);
			}
		} else {
			a.push(t1);
		}
	}
	if (a.size() > 1) {
		puts(a.top() ? "true" : "false");
	} else {
		printf("error\n");
		return 0;
	}
	return 0;
}