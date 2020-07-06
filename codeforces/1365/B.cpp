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
        int n, i, one = 0, zero = 0;
        string ans = "Yes";
        cin >> n;
        vector<int> a(n), b(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> b[i];
            if (zero == 0 && b[i] == 0)
            {
                zero++;
            }
            else if (one == 0 && b[i] == 1)
            {
                one++;
            }
        }
        for (i = 0; i < n - 1 && a[i] <= a[i + 1]; i++)
        {
        }
        if (i < n - 1 && one + zero < 2)
        {
            ans = "No";
        }
        cout << ans << endl;
    }
    return 0;
}
