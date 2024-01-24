#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct BST {
	int lc, rc;
	int val;
} a[N];

int root, idx, INF = 1 << 30;

int New(int val) {
	a[++idx].val = val;
	return idx;
}

void build() {
	New(-INF), New(INF);
	root = 1, a[1].rc = 2;
}

// 搜索 val
int search(int p, int val) {
	if (p == 0) return 0;
	if (val == a[p].val) return p; // 检索成功
	return val < a[p].val ? search(a[p].lc, val) : search(a[p].rc, val);
}

// 插入
void insert(int &p, int val) {
	if (p == 0) {
		p = New(val);
		return ;
	}
	if (val == a[p].val) return ; // 
	if (val < a[p].val) insert(a[p].lc, val);
	else insert(a[p].rc, val);
}

// 找前/后驱
int findNext(int val) {
	int ans = 2; // a[2].val = INF // 当没有出现val值时, 则走过的路径便是ans
	int p = root;
	while (p) {
		if (val == a[p].val) {
			// 找到了val, 在右子树一直向左走
			if (a[p].rc > 0) {
				p = a[p].rc; 
				while (a[p].lc > 0) p = a[p].lc;
				ans = p;
			}
			break;
		}
		if (a[p].val > val && a[p].val < a[ans].val) ans = p;
		p = a[p].val > val ? a[p].lc : a[p].rc;
	}
	return ans;
}

int findPre(int val) {
	int ans = 1; // a[1].val = -INF // 当没有出现val值时, 则走过的路径便是ans
	int p = root;
	while (p) {
		if (val == a[p].val) {
			// 找到了val, 在左子树一直向右走
			if (a[p].lc > 0) {
				p = a[p].lc; 
				while (a[p].rc > 0) p = a[p].rc;
				ans = p;
			}
			break;
		}
		if (a[p].val < val && a[p].val > a[ans].val) ans = p;
		p = a[p].val > val ? a[p].lc : a[p].rc;
	}
	return ans;
}
// 删除键值val
// 做法是: 找到val的后继将用后继替换val, 
void Remove(int &p, int val) { // 注意p是引用
	if (p == 0) return ;
	if (val == a[p].val) { // 找到检索值为val的值
		if (a[p].lc == 0) { // 没有左子树, 则用右子树代替p
			p = a[p].rc;
		} else if (a[p].rc == 0) { // 没有右子树, 则用左子树代替p
			p = a[p].lc;
		} else { // 既有左子树又有右子树
			int nxt = a[p].rc;
			while (a[nxt].lc > 0) nxt = a[nxt].lc;
			Remove(a[p].r, a[nxt].val);
			a[nxt].lc = a[p].lc, a[nxt].rc = a[p].rc;
			p = nxt;
		}

	}
}
void solve() {

}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}