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
        int n, ans;
        cin >> n;
        if (n % 2)
        {
            ans = 1 + ((n - 1) / 2);
        }
        else
        {
            ans = n / 2;
        }
        cout << ans << endl;
    }
    return 0;
}
