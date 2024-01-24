#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
typedef long long ll;
typedef long double lbd;
// head

const int N = 500010;
char str[N];
int len[N], n, m, fail[N], son[N][26], idx = 1;
int ans[N];
int get_fail(int x, int i) {
	// 跳到 奇根 或者找到了  插入str[i]的位置 
//	printf(" fail step path: %d ", x);
	while (i - len[x] - 1 < 1 || str[i] != str[i - len[x] - 1]) {
		x = fail[x];
//		printf("%d ", x);
	}
//	printf("\n");
	return x;
}

void insert() {
	int cur = 1; // 初始在奇根
	len[1] = -1;
	len[0] = 0;
	fail[0] = 1;
	fail[1] = 0;
	int n = strlen(str + 1);
	int last = 0;
	for (int i = 1; i <= n; i++) {
		str[i] = (str[i] - 97 + last) % 26 + 97;
		int u = get_fail(cur, i); 
//		printf(" insert str[%d] = %c to [%d]: \n", i, str[i], u); 
		// 确定str[i]插入在u的子树中 
		if (!son[u][str[i] - 'a']) {
			// 没有这个儿子
			// 先计算fail, 再建儿子
//			printf("father %d no son %c\n", u, str[i]);
			fail[++idx] = son[get_fail(fail[u], i)][str[i] - 'a'];
			son[u][str[i] - 'a'] = idx;
			len[idx] = len[u] + 2;
			ans[idx] = ans[fail[idx]] + 1;
//			printf("son[%d][%c] = %d, len[%d] = %d\n", u, str[i], idx,  idx, len[idx]);
		}
		cur = son[u][str[i] - 'a'];
//		printf(" now cur point: %d\n", cur);
		last = ans[cur];
		printf("%d ", last);
	}
	return ;
}

int main() {
	scanf("%s", str + 1);
	insert(); 
  return 0;
}
