#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
ll qmi(ll a,ll b) {ll res=1;while(b){if(b&1)res=(ll)res*a;a=a*a;b>>=1;}return res;}

int n, k;

void sovle() {
    cin >> n >> k;
    if(k == 0) cout << "NO\n";
    else {
        if(k % 4 == 0) cout << "NO\n";
        else {
            cout << "YES\n";
            if(k & 1) {
                for(int i = 1;i <= n;i += 2) {
                    cout << i << " " << i + 1 << "\n";
                }
            }
            else {
                int num = n / 2;
                int t = 4, j = 1;
                
                num /= 2;
                if(num == 0) {
                    cout << 2 << " " << 1 << endl;
                }else {
                    for(int i = 1;i <= num; i ++) {
                        cout << t - 1 << " " << t << "\n";
                        t += 4;
                    }
                    t = 2;
                    num = (n/2) - num;
                    for(int i = 1;i <= num; i ++) {
                        cout << t << " " << t - 1 << "\n";
                        t += 4;
                    }
                }
            }   
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) {
        sovle();
    }
    return 0;
}
