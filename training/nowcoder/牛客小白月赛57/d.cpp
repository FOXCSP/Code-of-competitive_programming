#include <bits/stdc++.h>


using namespace std;

const int N = 1000100;

int st[N];
int n;

void solve () {
	cin >> n;
	int m = 0;
	for(int i = 1;i <= n; i ++) {
		int x; cin >> x;
		st[x] ++;
		m = max(m, x);
	}
	std::vector<int> ans;
    ans.push_back(1);
	for(int i = m; i; i --)
		if(st[i]) {
			if(st[i] > 1) {
				ans.push_back(i);
			}
			else {
				for(int a = 2; a <= i / a; a ++)
					if(i % a == 0)
						if(st[i/a]) {
							ans.push_back(i/a);
                            break;
                        }
			}
		}

	cout << *max_element(ans.begin(), ans.end()) << '\n';
}


int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}