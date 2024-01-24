#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define lp (p<<1)
#define rp (p<<1|1)
#define pb push_back
#define P(T) pair<T,T>
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define setdb cout<<fixed<<setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--

const int N = 100010;
vec<int> e[N];
int n, m, indig[N], outdig[N];

int p[30];
vec<string> str;
int find(int x) {
    return x != p[x] ? p[x] = find(p[x]) : x;
}

int tot;
void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
        p[px] = py;
        tot--;
    }
}

void solve(int CaseT) {
    cin >> n;
    string s;
    for (int i = 0; i < 26; i++) 
        p[i] = i;
    map<char, int> mp;
    
    for (int i = 1; i <= n; i++) {
        cin >> s;
        str.pb(s);
        mp[s[0]]++;
        mp[s.back()]++;
        outdig[s[0]-'a']++;
        indig[s.back() - 'a']++;
    }

    tot = SZ(mp);

    for (int i = 0; i < SZ(str); i++) {
        merge(str[i][0] - 'a', str[i].back() - 'a');
    }

    int a = 0, b = 0, c = 0;
    for (auto [t, y] : mp) {
        int x = t - 'a';
        // cout << t << " " << indig[x] << " " << outdig[x] << '\n';
        if (indig[x] - outdig[x] == 1) a++;
        if (outdig[x] - indig[x] == 1) b++;
        if (indig[x] == outdig[x]) c++;
    }
    // cout << a << " " << b << " " << c << '\n';
    if (tot != 1 || a != 1 || b != 1 || c != SZ(mp) - 2)  cout << "No\n";
    else cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    _ = 1;
    // cin >> _;
    for (int i = 1; i <= _; i++) {
        solve(i);
    }
    return 0;
}