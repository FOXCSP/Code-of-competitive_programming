#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int N = 1e5 + 10, inf = 0x3f3f3f3f;

int ne[N], e[N], idx, h[N], w[N];
int dist[N], n, m;
bool st[N];
void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

int spfa()
{
    memset(dist, 0xcf, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while(q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;

        for(int i = h[t]; i != -1;i = ne[i])
        {
            int j = e[i];
            if(dist[j] < dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    if(dist[n] < (-inf)/2) return -1;
    else return dist[n];
}


int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d",&n, &m);
    for(int i = 1;i <= m;i ++)
    {
        int a, b, c;
        scanf("%d%d%d",&a, &b, &c);
        add(a, b, c);
    }

    cout << spfa() << "\n";

    return 0;
}