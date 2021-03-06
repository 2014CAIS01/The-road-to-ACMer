#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

const int mod = 119 << 23 | 1;

int main()
{
    int n;
    long long ans = 0, tmp = 1;
    scanf("%d", &n);
    for (int i = 0, a; i < n; i++)
    {
        scanf("%d", &a);
        tmp = tmp * (a + 1) % mod;
        ans = (ans + 1LL * (1 + a) * a / 2) % mod;
    }
    printf("%lld\n", (ans + tmp) % mod);
    return 0;
}