#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--)
    {
        string s, ans = "cyan";
        cin >> s;
        int sum = 0, zero = 0, even = 0, num, i;
        for (i = 0; i < s.length(); i++)
        {
            num = s[i] - '0';
            sum += num;
            sum %= 3;
            if (zero < 2 && num == 0)
            {
                zero++;
            }
            if (num && even == 0 && num % 2 == 0)
            {
                even++;
            }
        }
        //cout << zero << " " << even << " " << sum << endl;
        if (sum % 3 == 0 && zero && (even || zero > 1))
        {
            ans = "red";
        }
        cout << ans << endl;
    }
    return 0;
}
