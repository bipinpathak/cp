#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i, high, low, temp = 0;
        long long int ans = 0;
        cin >> n >> k;
        vector<int> a(n), w(k);
        for (i = 0; i < n; i++)
        {
            cin >> a.at(i);
        }
        for (i = 0; i < k; i++)
        {
            cin >> w.at(i);
        }
        sort(a.begin(), a.end());
        sort(w.begin(), w.end());
        high = n - 1;
        low = 0;
        while (temp < k && w.at(temp) == 1)
        {
            ans += 2 * a.at(high);
            temp++;
            high--;
        }
        for (i = k - 1; i >= temp; i--)
        {
            ans += a.at(high) + a.at(low);
            high--;
            low += w.at(i) - 1;
        }
        cout << ans << endl;
    }
    return 0;
}