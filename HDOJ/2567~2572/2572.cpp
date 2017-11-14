#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        string a, b, c;
        string ans;
        cin >> a >> b >> c;
        int st = min(b.length(),c.length());
        int n = a.length();
        for (int i = 0; i < n; i++)
            for (int j = st; j < n - i; j++)
            {
                string t = a.substr(i, j);
                if (~t.find(b) && ~t.find(c))
                    if (ans.length() == 0 || t.length() < ans.length() || t.length() == ans.length() && t < ans)
                        ans = t;
            }
        if (ans == "")
            cout << "No" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}