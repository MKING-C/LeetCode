 #include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    // 计算前缀和
    vector<ll> pre(n+1,0);
    for (int i=0; i<n; i++) pre[i+1] = pre[i] + a[i];

    ll S = pre[n];
    ll avg = S / n;
    ll r = S % n;

    // 计算达到平衡所需操作数M
    ll M = 0;
    int pos1 = lower_bound(a.begin(), a.end(), avg) - a.begin();
    M += avg * pos1 - pre[pos1];
    int pos2 = upper_bound(a.begin(), a.end(), avg+1) - a.begin();
    M += pre[n] - pre[pos2] - (avg+1) * (n - pos2);

    // 判断是否可以通过m次操作达到平衡
    if (m >= M) {
        cout << (r?1:0) << endl;
    } else {
        // 二分最小值能增加到多少
        ll low_min = a[0], high_min = avg;
        while (low_min < high_min) {
            ll mid = (low_min + high_min + 1) >> 1;
            int p = lower_bound(a.begin(), a.end(), mid) - a.begin();
            ll need = mid * p - pre[p];
            if (need <= m) low_min = mid;
            else high_min = mid - 1;
        }

        // 二分最大值能减少到多少
        ll low_max = avg + (r>0), high_max = a.back();
        while (low_max < high_max) {
            ll mid = (low_max + high_max) >> 1;
            int p = upper_bound(a.begin(), a.end(), mid) - a.begin();
            ll need = pre[n] - pre[p] - mid * (n - p);
            if (need <= m) high_max = mid;
            else low_max = mid + 1;
        }

        // 输出最小值与最大值之间的差值
        cout << low_max - low_min << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}