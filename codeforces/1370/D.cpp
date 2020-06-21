#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &a, int k, int x)
{
    int evenLength = 0, oddLength = 0, i;
    for (i = 0; i < a.size(); i++)
    {
        if (evenLength < k && !(evenLength % 2 == 0 && a[i] > x))
        {
            evenLength++;
        }
        if (oddLength < k && !(oddLength % 2 == 1 && a[i] > x))
        {
            oddLength++;
        }
        if (oddLength == k || evenLength == k)
        {
            return true;
        }
    }
    return false;
}
void binSearch(vector<int> &a, int k)
{
    int ans = -1, low = 1, high = 1000000000, mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (check(a, k, mid))
        {
            high = mid;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}
int main()
{
    int n, k, i;
    cin >> n >> k;
    vector<int> a(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    binSearch(a, k);
    return 0;
}