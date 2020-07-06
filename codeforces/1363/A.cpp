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
        int n, x, i, odd = 0, even = 0, temp;
        string ans = "Yes";
        cin >> n >> x;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp % 2)
            {
                odd++;
            }
            else
            {
                even++;
            }
        }
        if (odd == 0 || (x % 2 == 0 && (even == 0 || ((odd - 1) / 2 + (even - 1) / 2 < x / 2 - 1))) || (x % 2 == 1 && (max(0, (odd - 1) / 2) + max(0, (even) / 2) < x / 2)))
        {
            ans = "No";
        }
        cout << ans << endl;
    }
    return 0;
}
