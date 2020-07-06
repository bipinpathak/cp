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
        long long n, ans = 0, power = 1;
        cin >> n;
        while (n)
        {
            if (n & 1)
            {
                ans += power;
            }
            n /= 2;
            power *= 2;
            power++;
        }
        cout << ans << endl;
    }
    return 0;
}
