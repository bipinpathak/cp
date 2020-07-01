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
        long long n, r, temp, ans = 0;
        cin >> n >> r;
        temp = min(n - 1, r);
        if (temp % 2 == 0)
        {
            ans = 1;
            ans *= temp / 2;
            ans *= (temp + 1);
        }
        else
        {
            ans = 1;
            ans *= (temp + 1) / 2;
            ans *= temp;
        }
        if (temp < r)
        {
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
