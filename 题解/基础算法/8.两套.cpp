#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;cin >> n;
    ll total = (ll)(n + 1) * n / 2;
    // 总和为奇数 → 无解
    if (total & 1) {
        cout << "NO";
        return 0;
    }
    cout<<"YES"<<endl;
    ll target = total / 2;
    vector<int> a, b;
 
    // 从大到小贪心：能放进第一组就放
    for (int i = n; i >= 1; i--) {
        if (target >= i) {
            a.push_back(i);
            target -= i;
        } else {
            b.push_back(i);
        }
    }

    
    cout << a.size() << "\n";
    for (int x : a) cout << x << " ";
    cout << "\n";
    cout << b.size() << "\n";
    for (int x : b) cout << x << " ";
    return 0;
}