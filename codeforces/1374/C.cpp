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
        int n, open = 0, ans = 0;
        string s;
        cin >> n >> s;
        for (char c : s)
        {
            if (c == '(')
            {
                open++;
            }
            else
            {
                open--;
            }
            if (open < 0)
            {
                ans++;
                open = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}