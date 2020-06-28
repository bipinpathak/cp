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
        long long int n, k, i, temp, mf = 0, f = 1, mfe = 0, ans = 0;
        cin >> n >> k;
        vector<long long int> a(n, 0);
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            temp %= k;
            a.at(i) = temp;
        }
        sort(a.begin(), a.end());
        for (i = n - 1; i >= 0 && a.at(i) != 0; i--)
        {
            if (i == 0 || a.at(i) != a.at(i - 1))
            {
                if (f >= mf)
                {
                    mf = f;
                    mfe = a.at(i);
                }
                f = 1;
            }
            else
            {
                f++;
            }
        }
        if (mfe && mf)
        {
            ans = 1 - mfe + k * mf;
        }
        cout << ans << endl;
    }
    return 0;
}
