#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define lp (p << 1)
#define rp (p << 1 | 1)
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
#define setdb cout << fixed << setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--

struct name {
    string str[8];
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n;
    name sta[n + 1];
    auto check = [&](name x, name y) -> bool {
        for (int i = 0; i < 8; i++) {
            if (x.str[i] != y.str[i])
                return false;
        }
        return true;
    };
    for (int i = 1; i <= n; i++) {
        name x;
        for (int j = 0; j < 8; j++) {
            cin >> x.str[j];
        }
        int cnt = 1;
        for (int j = 1; j < i; j++) {
            if (check(x, sta[j]))
                cnt++;            
        }
        for (int j = 0; j < 8; j++)
            sta[i].str[j] = x.str[j];
        cout << cnt << '\n';
    }

    return 0;
}