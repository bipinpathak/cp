#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n, k, p = 998244353, i, count = 1, last, sum;
    cin >> n >> k;
    if (k % 2)
    {
        sum = k * (k - 1) / 2;
    }
    else
    {
        sum = (k - 1) * k / 2;
    }
    sum = n * k - sum;
    vector<int> a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a.at(i);
    }
    i = 0;
    while (a.at(i) <= n - k)
    {
        i++;
    }
    last = i;
    i++;
    while (i < n)
    {
        if (a.at(i) > n - k)
        {
            count *= (i - last);
            count %= p;
            last = i;
        }
        i++;
    }
    cout << sum << " " << count << endl;
    return 0;
}
