#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, ans = "";
        int n, m, i, j, k, temp;
        cin >> s >> m;
        vector<int> differences(m);
        vector<int> zero;
        for (i = 0; i < m; i++)
        {
            ans += "a";
            cin >> differences[i];
            if (differences[i] == 0)
            {
                zero.push_back(i);
            }
        }
        j = s.length() - 1;
        sort(s.begin(), s.end());
        while (zero.size())
        {
            temp = zero.size();
            while (s[j] != s[j - temp + 1])
            {
                j--;
            }
            for (i = 0; i < temp; i++)
            {
                ans[zero[i]] = s[j];
                j--;
            }
            while (j >= 0 && s[j] == s[j + 1])
            {
                j--;
            }
            for (i = 0; i < m; i++)
            {
                if (differences[i])
                {
                    for (k = 0; k < temp; k++)
                    {
                        differences[i] -= abs(i - zero[k]);
                    }
                    if (differences[i] == 0)
                    {
                        zero.push_back(i);
                    }
                }
            }
            zero.erase(zero.begin(), zero.begin() + temp);
        }
        cout << ans << endl;
    }
    return 0;
}