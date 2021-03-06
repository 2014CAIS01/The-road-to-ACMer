// Mayor's posters, POJ2528

/*Sample Input
1
5
1 4
2 6
8 10
3 4
7 10
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define clr(a,x) memset(a, x, sizeof(a))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

#define lson rt << 1
#define rson rt << 1 | 1
#define Lson l, m, lson
#define Rson m + 1, r, rson

const int maxn = 2e4 + 5;
PII a[maxn];
vector<int> v;
int val[maxn << 2];
bool vis[maxn];

void build(int l, int r, int rt)
{
    val[rt] = -1;
    if (l == r)
        return;
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
}

void PushDown(int rt)
{
    if (val[rt] == -1)
        return;
    val[lson] = val[rson] = val[rt];
    val[rt] = -1;
}

void Update(int L, int R, int setv, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        val[rt] = setv;
        return;
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    if (L <= m) Update(L, R, setv, Lson);
    if (m < R) Update(L, R, setv, Rson);
}

int query(int p, int l, int r, int rt)
{
    if (l == r) return val[rt];
    PushDown(rt);
    int m = (l + r) >> 1;
    if (p <= m) return query(p, Lson);
    else if (m < p) return query(p, Rson);
}

int main()
{
    int c;
    scanf("%d", &c);
    while (c--)
    {
        int n;
        clr(vis, 0);
        v.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &a[i].X, &a[i].Y);
            v.pb(a[i].X);
            v.pb(a[i].Y);
            v.pb(a[i].Y + 1);
        }
        sort(v.begin(), v.end());
        int N = unique(v.begin(), v.end()) - v.begin();
        for (int i = 0; i < n; i++)
        {
            a[i].X = lower_bound(v.begin(), v.begin() + N, a[i].X) - v.begin() + 1;
            a[i].Y = lower_bound(v.begin(), v.begin() + N, a[i].Y) - v.begin() + 1;
            //printf("%d %d\n", a[i].X, a[i].Y);
        }
        build(1, N, 1);
        for (int i = 0; i < n; i++)
            Update(a[i].X, a[i].Y, i, 1, N, 1);
        int ans = 0;
        for (int i = 1; i <= N; i++)
        {
            int col = query(i, 1, N, 1);
            if (col != -1 && vis[col] == 0)
            {
                vis[col] = 1;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

