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
    int n, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n % 4 == 0)
            cout << n / 4 << endl;
        else if (n % 4 == 2)
        {
            if (n / 4 >= 1)
                cout << n / 4 << endl;
            else
                cout << -1 << endl;
        }
        else if (n % 4 == 1)
        {
            if (n / 4 >= 2)
                cout << n / 4 - 1 << endl;
            else
                cout << -1 << endl;
        }
        else
        {
            if (n / 4 >= 3)
                cout << n / 4 - 1 << endl;
            else
                cout << -1 << endl;
        }
    }
    return 0;
}
