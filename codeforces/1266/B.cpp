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
        long long x;
        string ans = "NO";
        cin >> x;
        if (x > 14)
        {
            x %= 14;
            if (x > 0 && x < 7)
            {
                ans = "YES";
            }
        }
        cout << ans << endl;
    }
    return 0;
}
