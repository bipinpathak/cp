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
        int n, x, i, count = 0, u, v;
        cin >> n >> x;
        string ans = "Ayush";
        for (i = 1; i < n; i++)
        {
            cin >> u >> v;
            if (u == x || v == x)
            {
                count++;
            }
        }
        if (count > 1 && n % 2)
        {
            ans = "Ashish";
        }
        cout << ans << endl;
    }
    return 0;
}
