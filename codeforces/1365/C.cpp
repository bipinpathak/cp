#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i, temp, ans = 0;
    cin >> n;
    vector<int> a(n + 1), difference(n, 0);
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        a[temp] = i;
    }
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        difference[(a[temp] - i + n) % n]++;
    }
    for (i = 0; i < n; i++)
    {
        ans = max(ans, difference[i]);
    }
    cout << ans << endl;
    return 0;
}
