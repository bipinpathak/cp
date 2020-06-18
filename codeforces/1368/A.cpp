#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long int a, b, n, ans = 0;
        cin >> a >> b >> n;
        long int x, y;
        x = min(a, b);
        y = max(a, b);
        while (y <= n)
        {
            ans++;
            a = y;
            y += x;
            x = a;
        }
        cout << ans << endl;
    }
    return 0;
}
