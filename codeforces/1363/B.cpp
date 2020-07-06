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
        string s;
        cin >> s;
        int i, n = s.length(), ans, totalOnes = 0, ones = 0;
        for (i = 0; i < n; i++)
        {
            totalOnes += s[i] - '0';
        }
        ans = min(totalOnes, n - totalOnes);
        for (i = 0; i < n - 1; i++)
        {
            ones += s[i] - '0';
            ans = min(ans, min(totalOnes + i + 1 - 2 * ones, n + 2 * ones - totalOnes - i - 1));
        }
        cout << ans << endl;
    }
    return 0;
}
