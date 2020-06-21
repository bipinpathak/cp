#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, product = 1, i = 0;
    vector<long long int> a(10, 1);
    string ans = "", temp = "codeforces";
    cin >> n;
    while (product < n)
    {
        product /= a[i];
        a[i]++;
        product *= a[i];
        i = (i + 1) % 10;
    }
    for (i = 0; i < 10; i++)
    {
        while (a[i]--)
        {
            ans += temp[i];
        }
    }
    cout << ans << endl;
    return 0;
}