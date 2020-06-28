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
        long long int x, y, n, ans;
        cin >> x >> y >> n;
        ans = y + x * ((n - y) / x);
        cout << ans << endl;
    }
    return 0;
}