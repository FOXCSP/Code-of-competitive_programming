#include <bits/stdc++.h>

using namespace std;

const int N = 10010;
int n, m;
int f[N];
struct stone {
    int s, l, e;
    bool operator < (const stone & E) const {
        return l * E.s >= s * E.l;
    }
};

vector<stone> st;
void solve() {
    cin >> n;
    st.resize(0);
    for(int i = 1;i <= n;i ++) {
        int s, l, e;
        cin >> s >> e >> l;
        st.push_back({s, l, e});
    }
    sort(st.begin(), st.end());
    memset(f, 0xcf ,sizeof f);
    f[0] = 0;
    for(int i = 0;i < n;i ++) {
        int s = st[i].s, e = st[i].e, l = st[i].l;
        for(int j = N;j >= s; j --) {
            f[j] = max(f[j], f[j - s] + max(0, e - (j - s) * l));
        }
    }
    int ans = 0;
    for(int i = 0;i <= N;i ++) ans = max(ans, f[i]);
    cout << ans << '\n';
}

int main () {
    int T; cin >> T;
    for(int i = 1;i <= T; i ++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}