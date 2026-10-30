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
#include <cstdint>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ld PI  = acosl(-1.0L);
const ld EPS = 1e-9L;                 // "close enough to zero" for real numbers
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
const ll INF = (ll)1e18;
const ll MOD = 1'000'000'007;

struct P { ld x, y; };
 
P operator+(P a, P b)  { return {a.x + b.x, a.y + b.y}; }
P operator-(P a, P b)  { return {a.x - b.x, a.y - b.y}; }
P operator*(P a, ld k) { return {a.x * k, a.y * k}; }
 
// DOT product = |a| * |b| * cos(theta)
//   == 0  -> the vectors are perpendicular (a right angle!)
//   >  0  -> angle between them is acute
//   <  0  -> angle between them is obtuse
ld dot(P a, P b) { return a.x * b.x + a.y * b.y; }

// CROSS product (2D) = |a| * |b| * sin(theta), signed
//   == 0  -> the vectors are parallel (points are collinear)
//   >  0  -> b is counter-clockwise (left turn) from a,   < 0 -> clockwise
//   |cross| = area of the parallelogram spanned by a and b (triangle area = |cross| / 2)
ld cross(P a, P b) { return a.x * b.y - a.y * b.x; }

ld len2(P a)      { return dot(a, a); }        // squared length: no sqrt, exact for integers
ld len(P a)       { return sqrtl(len2(a)); }
ld dist(P a, P b) { return len(a - b); }

// Angle between two vectors in [0, pi].
// Because tan(theta) = sin/cos = cross/dot, atan2(|cross|, dot) gives the angle without
// dividing (so no problem when dot == 0, i.e. when tan would be "infinite").
ld angleBetween(P a, P b) { return atan2l(fabsl(cross(a, b)), dot(a, b)); }

// Is the angle at vertex v (between rays v->a and v->b) a right angle?
bool rightAt(P v, P a, P b) { return fabsl(dot(a - v, b - v)) < EPS; }
 
// Are the three points on one line?
bool collinear(P a, P b, P c) { return fabsl(cross(b - a, c - a)) < EPS; }

ll my_gcd(ll a, ll b) { return b ? my_gcd(b, a % b) : a; } // Euclidean algorithm

template <class T> void print(const vector<T> &v) {   // print a vector on one line
    for (int i = 0; i < sz(v); i++) cout << v[i] << (i + 1 < sz(v) ? ' ' : '\n');
}

ll power_mod(ll a, ll e, ll m) {
    ll r = 1; // a^0

    while (e > 0) {
        if (e & 1) r = r * a % m; // odd
        a = a*a % m; // (b^2)^e/2
        e >>= 1; // e/=2
    }    

    return r;
}

const int MAXN = 1'000'001;
ll fact[MAXN], inv_fact[MAXN];

void precompute(size_t n, ll m) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;

    inv_fact[n] = power_mod(fact[n], MOD - 2, MOD); // x^(p-2) = x^(-1) mod p
    for (int i = n; i >= 1; i--) inv_fact[i - 1] = inv_fact[i] * i % MOD; // 1/(i-1)! = i * (1/i!)
}
 
// O(1) per query
ll nCr(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

struct DSU {
    vector<int> p, sz_;
    DSU(int n) : p(n), sz_(n, 1) { iota(all(p), 0); }
    int find(int x) {
        while (p[x] != x) {
            p[x] = p[p[x]]; // optimisation line
            x = p[x];
        }
        return x;
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz_[a] < sz_[b]) swap(a, b);
        p[b] = a;
        sz_[a] += sz_[b];
        return true;
    }
};

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
