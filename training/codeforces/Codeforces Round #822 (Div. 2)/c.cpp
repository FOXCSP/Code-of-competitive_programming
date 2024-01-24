#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<map>
#include<queue>
#define int long long
using namespace std;
int n;
string s;
priority_queue<int, vector<int>, greater<int> > heap;
map<int, int> m1, m2;
int res;

void calc()
{
	for(int i = 1; i <= n; i ++)
	{
		if(s[i] == '1')
		{
			m1[i] = 1;
		}
		else	heap.push(i);
	}
}

void solve()
{
	m1.clear();
	m2.clear();
	res = 0;
	cin >> n;
	cin >> s;
	s = '_' + s;
	calc();
	while(heap.size())
	{
		int t = heap.top();
		heap.pop();
		if(m1[t] != 1 && m2[t] != 1)
		{
			res += t;
			m2[t] = 1;
		}
		for(int j = 2, i = t * j; i <= n; j ++, i = t * j)
		{
			if(m1[i])	break;
			if(m2[i] != 1)
			{
				res += t;
				m2[i] = 1;
			}	
		}
	}
	
	cout << res << '\n';
}

signed main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T --)
	{
		solve();
	}
	return 0;
}
