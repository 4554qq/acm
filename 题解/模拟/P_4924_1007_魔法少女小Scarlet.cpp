#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void xz(vector<vector<int>>& a, int x, int y, int r, int z) {
    auto b = a;
    for (int i = -r; i <= r; i++) {
        for (int j = -r; j <= r; j++) {
            if (z == 0) {
                // 顺时针 90°：(i, j) -> (j, -i)
                b[x + j][y - i] = a[x + i][y + j];
            } else {
                // 逆时针 90°：(i, j) -> (-j, i)
                b[x - j][y + i] = a[x + i][y + j];
            }
        }
    }
    a = move(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> num(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            num[i][j] = (i - 1) * n + j;
        }
    }

    int x, y, r, z;
    while (m--) {
        cin >> x >> y >> r >> z;
        xz(num, x, y, r, z);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << num[i][j] << " \n"[j == n];
        }
    }

    return 0;
}
