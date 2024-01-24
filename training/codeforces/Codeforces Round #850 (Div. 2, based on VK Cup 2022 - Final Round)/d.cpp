#include <bits/stdc++.h>
// #define int long long
#define P(T) pair<T, T>
#define pb push_back
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

void solve() {
    int n;
    cin >> n;
    vector<int> v[4][4][4];
    for (int x = 0; x <= 3; x++) 
        for (int y = 0; y <= 3; y++)
            for (int z = 0; z <= 3; z++)
                v[x][y][z].clear();
    
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int x = 0, y = 0, z = 0;
        for (auto c : s) {
            x += c == 'w';
            y += c == 'i';
            z += c == 'n';
        }
        v[x][y][z].pb(i);
    }
    int cnt = SZ(v[1][1][1]);
    vector<tuple<int, char, int, char>> ans;
    while (cnt < n) {
        // www
        while (SZ(v[3][0][0]) && SZ(v[0][3][0]) && SZ(v[0][0][3])) {
            int p1 = v[3][0][0].back(); v[3][0][0].pop_back();
            int p2 = v[0][3][0].back(); v[0][3][0].pop_back();
            int p3 = v[0][0][3].back(); v[0][0][3].pop_back();
            ans.pb({p1, 'w', p2, 'i'});
            ans.pb({p2, 'i', p3, 'n'});
            ans.pb({p1, 'w', p3, 'n'});
            cnt += 3;
        }
        // wii -> wnn -> nnn -> inn

        while (SZ(v[1][2][0]) && SZ(v[1][0][2])) {
            int a, c;
            char b, d;
            a = v[1][2][0].back(); v[1][2][0].pop_back();
            b = 'i';
            d = 'n';
            c = v[1][0][2].back(); v[1][0][2].pop_back();
            ans.pb({a, b, c, d});
            cnt += 2;
        }

        while (SZ(v[0][1][2]) && SZ(v[2][1][0])) {
            int a, c;
            char b, d;
            a = v[0][1][2].back(); v[0][1][2].pop_back();
            b = 'n';
            d = 'w';
            c = v[2][1][0].back(); v[2][1][0].pop_back();
            ans.pb({a, b, c, d});
            cnt += 2;
        }

        while (SZ(v[0][2][1]) && SZ(v[2][0][1])) {
            int a, c;
            char b, d;
            a = v[0][2][1].back(); v[0][2][1].pop_back();
            b = 'i';
            d = 'w';
            c = v[2][0][1].back(); v[2][0][1].pop_back();
            ans.pb({a, b, c, d});
            cnt += 2;
        }

        while (SZ(v[1][2][0])) {
            int a, c;
            char b, d;
            a = v[1][2][0].back();
            b = 'i';
            d = 'n';
            if (SZ(v[1][0][2])) {
                c = v[1][0][2].back(); v[1][0][2].pop_back();
                cnt += 2;
            } else if (SZ(v[0][0][3])) {
                c = v[0][0][3].back(); v[0][0][3].pop_back(); v[0][1][2].pb(c);
                cnt += 1;
            } else if (SZ(v[0][1][2])) {
                c = v[0][1][2].back(); v[0][1][2].pop_back(); v[0][2][1].pb(c);
                cnt += 1;
            } else {
                break;
            }
            v[1][2][0].pop_back();
            ans.pb({a, b, c, d});
        }
        // wnn -> wii -> iii -> iin
        while (SZ(v[1][0][2])) {
            int a, c;
            char b, d;
            a = v[1][0][2].back();
            b = 'n';
            d = 'i';
            if (SZ(v[1][2][0])) {
                c = v[1][2][0].back(); v[1][2][0].pop_back();
                cnt += 2;
            } else if (SZ(v[0][3][0])) {
                c = v[0][3][0].back(); v[0][3][0].pop_back(); v[0][2][1].pb(c);
                cnt += 1;
            } else if (SZ(v[0][2][1])) {
                c = v[0][2][1].back(); v[0][2][1].pop_back(); v[0][1][2].pb(c);
                cnt += 1;
            } else {break;}
            v[1][0][2].pop_back();
            ans.pb({a, b, c, d});
        }
        // inn -> wwi -> www -> wwn
        while (SZ(v[0][1][2])) {
            int a, c;
            char b, d;
            a = v[0][1][2].back(); 
            b = 'n';
            d = 'w';
            if (SZ(v[2][1][0])) {
                c = v[2][1][0].back(); v[2][1][0].pop_back();
                cnt += 2;
            } else if (SZ(v[3][0][0])) {
                c = v[3][0][0].back(); v[3][0][0].pop_back(); v[2][0][1].pb(c);
                cnt += 1;
            } else if (SZ(v[2][0][1])) {
                c = v[2][0][1].back(); v[2][0][1].pop_back(); v[1][0][2].pb(c);
                cnt += 1;
            } else {
                break;
            }
            ans.pb({a, b, c, d});
            v[0][1][2].pop_back();
        }
        // wwi -> inn -> nnn -> wnn
        while (SZ(v[2][1][0])) {
            int a, c;
            char b, d;
            a = v[2][1][0].back(); 
            b = 'w';
            d = 'n';
            if (SZ(v[0][1][2])) {
                c = v[0][1][2].back(); v[0][1][2].pop_back();
                cnt += 2;
            } else if (SZ(v[0][0][3])) {
                c = v[0][0][3].back(); v[0][0][3].pop_back(); v[1][0][2].pb(c);
                cnt += 1;
            } else if (SZ(v[1][0][2])) {
                c = v[1][0][2].back(); v[1][0][2].pop_back(); v[2][0][1].pb(c);
                cnt += 1;
            } else {break;}
            v[2][1][0].pop_back();
            ans.pb({a, b, c, d});
        }
        // iin -> wwn -> www -> wwi
        while (SZ(v[0][2][1])) {
            int a, c;
            char b, d;
            a = v[0][2][1].back(); 
            b = 'i';
            d = 'w';
            if (SZ(v[2][0][1])) {
                c = v[2][0][1].back(); v[2][0][1].pop_back();
                cnt += 2;
            } else if (SZ(v[3][0][0])) {
                c = v[3][0][0].back(); v[3][0][0].pop_back(); v[2][1][0].pb(c);
                cnt += 1;
            } else if (SZ(v[2][1][0])) {
                c = v[2][1][0].back(); v[2][1][0].pop_back(); v[1][2][0].pb(c);
                cnt += 1;
            } else {
                break;
            }
            v[0][2][1].pop_back();
            ans.pb({a, b, c, d});
        }
        // wwn -> iin -> iii -> wii
        while (SZ(v[2][0][1])) {
            int a, c;
            char b, d;
            a = v[2][0][1].back(); 
            b = 'w';
            d = 'i';
            if (SZ(v[0][2][1])) {
                c = v[0][2][1].back(); v[0][2][1].pop_back();
                cnt += 2;
            } else if (SZ(v[0][3][0])) {
                c = v[0][3][0].back(); v[0][3][0].pop_back(); v[1][2][0].pb(c);
                cnt += 1;
            } else if (SZ(v[1][2][0])) {
                c = v[1][2][0].back(); v[1][2][0].pop_back(); v[2][1][0].pb(c);
                cnt += 1;
            } else {
                break;
            }
            v[2][0][1].pop_back();
            ans.pb({a, b, c, d});
        }
    }
    cout << SZ(ans) << '\n';
    for (auto [a, b, c, d] : ans) {
        cout << a << " " << b << " " << c << " " << d << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
