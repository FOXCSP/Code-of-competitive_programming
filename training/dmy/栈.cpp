#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
template <class T> 
struct STK {
	T stk[N];
	int top;
	STK() {
		top = -1;
	}
	void push(T x) {
		stk[++ top] = x;
	}

	void pop() {
		top --;
	}

	T query() {
		return stk[top];
	}
};

void solve() {
	int n; cin >> n;
	STK<int> stk;

	while(n --) {
		string op; cin >> op;
		if(op == "push") {
			int x; cin >> x;
			stk.push(x);
		}
		else if(op == "top") {
			int t = stk.query();
			cout << t << '\n';
		}
		else stk.pop();
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}