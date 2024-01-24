#include <bits/stdc++.h>

using namespace std;

struct node {
    int l, r, ty;
};
vector<node> seg;
char s[N];
int main() {
    scanf("%d%s", &n, s + 1);
    for (int i = 1; i < n; i++) {
        if (s[i] == '>') {
            int pos = i;
            seg.push_back({i, i, ty[s[i]]});
            while (pos <= n && s[pos] != '<') 
                if (s[i] == '>')
                    seg.back().r++;
            i = seg.back().r;
        } else if (s[i] == '<') {
            int pos = i;
            seg.push_back({i, i, ty[s[i]]});
            while (pos <= n && s[pos] != '>') 
                if (s[i] == '<')
                    seg.back().r++;
            i = seg.back().r;
        }
    }
    for (auto c : seg) {
        prinf("%d %d %d\n", c.l, c.r, c.ty);
    }
    return 0;
}