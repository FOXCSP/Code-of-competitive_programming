#include <bits/stdc++.h>

using namespace std;

stack<int> stk;
char s[100];
int main() {
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	int t = 0;
	for (int i = 1; i <= len; i++) {
		if (s[i] >= '0' && s[i] <= '9') t = t * 10 + s[i] - '0';
		else {
			if (s[i] != '.' && s[i] != '@') {
				int b = stk.top(); stk.pop();
				int a = stk.top(); stk.pop();
				if (s[i] == '+') a += b;
				if (s[i] == '*') a *= b;
				if (s[i] == '/') a /= b;
				if (s[i] == '-') a -= b;
				stk.push(a);
			} else {
				if (t) stk.push(t);
			}
			t = 0;
		}
	}
	printf("%d\n", stk.top());
	return 0;
}