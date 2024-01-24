#include <iostream>
#define int long long
using namespace std;

const int N = 2e5+10;

signed main () {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    cout << c  <<  " " << (a + b)*c;
    return 0;
}