#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int n, m, q;
vector<int> v[N];
int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        v[x].push_back(i);
    }
    for (int i = 1; i <= q; i++) {
        int x;
        scanf("%d", &x);
        printf("%d\n", n-v[x].size());
    }
    return 0;
}