#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int one = 0, zero = 0;
        cin >> s;
        for (char c : s)
        {
            if (c == '1')
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        if (min(one, zero) % 2)
        {
            cout << "DA" << endl;
        }
        else
        {
            cout << "NET" << endl;
        }
    }
    return 0;
}