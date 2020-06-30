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
        long long a, b;
        int count = 0, ans = -1;
        cin >> a >> b;
        while (a % 2 == 0)
        {
            count++;
            a /= 2;
        }
        while (b % 2 == 0)
        {
            count--;
            b /= 2;
        }
        if (a == b)
        {
            count = abs(count);
            ans = count / 3;
            if (count % 3)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
