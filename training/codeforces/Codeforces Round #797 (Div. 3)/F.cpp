// Problem: F. Shifting String
// Contest: Codeforces - Codeforces Round #797 (Div. 3)
// URL: https://codeforces.com/contest/1690/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;

ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
ll qmi(ll a,ll b) {ll res=1;while(b){if(b&1)res=(ll)res*a;a=a*a;b>>=1;}return res;}


int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	return 0;
}