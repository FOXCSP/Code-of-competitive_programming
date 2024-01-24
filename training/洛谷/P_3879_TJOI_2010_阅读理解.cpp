#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

int son[N][26],idx;
char str[30];
vector<int> cnt[N];

void insert(char str[],int t)
{
    int p = 0;
    for(int i = 0; str[i] ;i ++) {
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p].push_back(t);
}

vector<int> query(char str[])
{
    int p = 0;
    for(int i = 0; str[i];i ++) {
        int u = str[i] - 'a';
        if(!son[p][u]) {
        	vector<int> ans;
        	return ans;
        }
        p = son[p][u];
    }
    return cnt[p];
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++) {
        int num = 0; cin >> num;
        while(num --) {
            cin >> str;
            insert(str, i);
        }
    }
    int k; cin >> k;
    while(k --) {
        cin >> str;
        unordered_map<int,int> mp;
        auto ans = query(str);
        if(ans.size() == 0) {
        	cout << "\n";
        }
        else {
            for(int i = 0;i < ans.size(); i ++) {
                if(mp.count(ans[i]) == 0) {
                	cout << ans[i]  << " "; 
                }
                mp[ans[i]] ++;
            }
            cout << '\n';
        }
    }
    return 0;
}