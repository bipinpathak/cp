#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        long long n, m, x, y, i, j, temp = 0, two = 0, one = 0;
        char tile;
        cin >> n >> m >> x >> y;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> tile;
                if (tile == '.') {
                    grid[i][j] = 1;
                }
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (grid[i][j]) {
                    temp++;
                } else if (temp) {
                    one += temp % 2;
                    two += temp / 2;
                    temp = 0;
                }
            }
            if (temp) {
                one += temp % 2;
                two += temp / 2;
                temp = 0;
            }
        }
        if (2 * x <= y) {
            temp = (one + 2 * two) * x;
        } else {
            temp = (one * x) + (two * y);
        }
        cout << temp << endl;
    }
    return 0;
}
