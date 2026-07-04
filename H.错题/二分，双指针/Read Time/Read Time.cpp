#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1000009;
const long long INF = 4e18;
int h[maxn], p[maxn], n, m;
bool check(long long x) {
    int r = 1;
    for (int i = 1; i <= n; i++) {
        int l = r;
        while (r <= m) {
            long long cost = abs(p[r] - p[l]) + min(abs(p[l] - h[i]), abs(p[r] - h[i]));
            if (cost <= x) r++;  
            else break;
        }
        if (r > m) return true;
    }
    return false;
}
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= m; i++) cin >> p[i];

    long long l = 0, r = INF, ans = INF;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}