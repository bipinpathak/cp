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
        int n;
        cin >> n;
        string ans;
        if (n == 1)
        {
            ans = "-1";
        }
        else
        {
            for (int i = 0; i < n - 2; i++)
            {
                ans += "3";
            }
            ans += "23";
        }
        cout << ans << endl;
    }
    return 0;
}
