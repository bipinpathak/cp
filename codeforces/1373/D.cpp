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
        int n, i, j;
        long long ans = 0, temp, reverse = 0;
        cin >> n;
        vector<long long> a(n), even, odd;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i % 2 == 0)
            {
                ans += a[i];
            }
        }
        for (i = 0; i + 1 < n; i++)
        {
            if (i % 2)
            {
                odd.push_back(a[i] - a[i + 1]);
            }
            else
            {
                even.push_back(a[i + 1] - a[i]);
            }
        }
        for (i = 0; i < even.size(); i++)
        {
            temp = even[i];
            if (i)
            {
                temp += even[i - 1];
            }
            if (temp < 0)
            {
                temp = 0;
            }
            reverse = max(reverse, temp);
            even[i] = temp;
        }
        for (i = 0; i < odd.size(); i++)
        {
            temp = odd[i];
            if (i)
            {
                temp += odd[i - 1];
            }
            if (temp < 0)
            {
                temp = 0;
            }
            reverse = max(reverse, temp);
            odd[i] = temp;
        }
        ans += reverse;
        cout << ans << endl;
    }
    return 0;
}
