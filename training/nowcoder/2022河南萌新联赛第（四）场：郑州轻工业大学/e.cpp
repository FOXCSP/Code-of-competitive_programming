#include <bits/stdc++.h>
#define fi first
#define se second
#define sf scanf
#define pf printf
//#define int long long
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
//
LL gcd(LL x,LL y) {return !y ? x:gcd(y, x%y);}
LL qmi(LL a,LL b) {LL res=1; while(b) {if(b&1)res=res*a;a=a*a,b>>=1;}return res;}

/*--code --*/
struct node{
    int hh, mm, ss;
};
int year, month, day;
int p[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
node st = {0, 0, 0};
bool check(node a, node b) {
    if(a.hh < b.hh) return true;
    else if(a.hh == b.hh && a.mm < b.mm) return true;
    else if(a.hh == b.hh && a.mm == b.mm && a.ss <= b.ss) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, cnt = 0, idx = 0;
    sf("%d-%d-%d", &year, &month, &day);
    sf("%d", &t);
    while(t --) {
        int hh, mm, ss;
        sf("%d:%d:%d", &hh, &mm, &ss);
        node tmp = {hh, mm, ss};
        if(check(tmp, st)) {
            day ++;
            if((year%4 == 0 && year%100 != 0) || year%400 == 0) p[2] = 29;
            else p[2] = 28;
            if(day > p[month]) month ++, day = 1;
            if(month > 12) year ++, month = 1, day = 1;
        }
        st = {hh, mm, ss};
        if(month%2 == day%2) cnt ++;
    }
    pf("%d\n", cnt);
    return 0;
}
