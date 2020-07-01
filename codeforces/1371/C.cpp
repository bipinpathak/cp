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
        long long a, b, n, m;
        cin >> a >> b >> n >> m;
        string ans = "No";
        if (a - n >= m - b && m <= min(a, b))
        {
            ans = "Yes";
        }
        cout << ans << endl;
    }
    return 0;
}
