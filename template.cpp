#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
const ll INF = (ll)1e18;
const ll MOD = 1'000'000'007;

ll my_gcd(ll a, ll b) { return b ? my_gcd(b, a % b) : a; } // Euclidean algorithm

template <class T> void print(const vector<T> &v) {   // print a vector on one line
    for (int i = 0; i < sz(v); i++) cout << v[i] << (i + 1 < sz(v) ? ' ' : '\n');
}

ll power_mod(ll b, ll e, ll m) { // b^e mod m in O(log e)
    ll r = 1;  b %= m;
    while (e > 0) {
        if (e & 1) r = r * b % m; // if odd 
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int result;
 
    cout << result << '\n';
}
 
int main() {
    ios::sync_with_stdio(false); // faster cin/cout (don't mix with scanf/printf)
    cin.tie(nullptr);
 
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}