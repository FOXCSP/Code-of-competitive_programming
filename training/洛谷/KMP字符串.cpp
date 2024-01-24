#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
char a[N], b[N];
int n, m;
int ne[N], f[N];
int main () {
    cin >> n >> a + 1 >> m >> b + 1;
    ne[1] = 0;
    for(int i = 2, j = 0;i <= n;i ++) {
        while(j > 0 && a[i] != a[j+1]) j = ne[j];
        if(a[i] == a[j+1]) j ++;
        ne[i] = j; 
    }
    
    for(int i = 1, j = 0; i <= m; i ++) {
        while(j > 0 && (j == n || b[i] != a[j+1])) j = ne[j];
        if(b[i] == a[j+1]) j ++;
        f[i] = j;
        if(f[i] == n) {
            cout << i - n << " ";
            j = ne[j];
        }
    }

    return 0;
}