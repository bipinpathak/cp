#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length(), count = 0, i;
        long long int ans = 0;
        vector<int> value(n), checked(n, -1);
        for (i = 0; i < n; i++)
        {
            if (s.at(i) == '-')
            {
                count--;
            }
            else
            {
                count++;
            }
            value.at(i) = count;
        }
        for (i = 0; i < n; i++)
        {
            if (value.at(i) < 0 && checked.at(-1 * value.at(i) - 1) == -1)
            {
                checked.at(-1 * value.at(i) - 1) = i;
            }
        }
        for (i = 0; i < n; i++)
        {
            if (checked.at(i) == -1)
            {
                break;
            }
            ans += checked.at(i) + 1;
        }
        ans += n;
        cout << ans << endl;
    }
    return 0;
}