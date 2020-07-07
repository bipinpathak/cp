#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, k, ans;
        cin >> n >> m >> k;
        ans = m;
        if (m > n / k)
        {
            n /= k;
            ans = n - ((m - n + k - 2) / (k - 1));
        }
        cout << ans << endl;
    }
    return 0;
}
