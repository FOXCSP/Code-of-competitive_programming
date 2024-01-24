#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5+10;
int cnt[N];
int main () {
    int n; cin >> n;
    for(int i = 1;i <= n;i ++) {
        int x; cin >> x;
        cnt[x] ++;
    }
    int a[N];
    int pos = 0;
    for(int k = 10, c = 0; c < 10; k = (k + 1)%10, c ++) {
        for(int i = k; i <= n; i += 10) {
            if(cnt[pos] == 0) pos ++;
            a[i] = pos;
            cnt[pos] --;
        }
    }
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
    return 0;
}