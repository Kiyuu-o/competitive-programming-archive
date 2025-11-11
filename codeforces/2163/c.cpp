// Author: Kexuan Miao
#include <bits/stdc++.h>
using namespace std;

#define cmax(u, v) u = max(u, v)
#define cmin(u, v) u = min(u, v)
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

typedef pair<ll, ll> pll;
const ll m = 1e9 + 7;

struct Tree {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return (a + b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void solve(){
	int n;
	cin >> n;
	vector<vi> a(2,vi(n));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	vi pmx(n), pmn(n), smx(n), smn(n);
	pmx[0] = a[0][0];
	pmn[0] = a[0][0];
	for (int i = 1; i < n; i++) {
		pmx[i] = max(pmx[i - 1], a[0][i]);
		pmn[i] = min(pmn[i - 1], a[0][i]);
	}
	smx[n-1] = a[1][n-1];
	smn[n-1] = a[1][n-1];
	for (int i = n - 2; i >= 0; --i) {
		smx[i] = max(smx[i + 1], a[1][i]);
		smn[i] = min(smn[i + 1], a[1][i]);
	}
	vector<pii> v;
	for (int i = 0; i < n; i++) {
		int mn = min(pmn[i], smn[i]);
		int mx = max(pmx[i], smx[i]);
		v.emplace_back(mn, mx);
	}
	Tree tree(4 * n + 1);
	sort(all(v));
	vi arr(2 * n + 1);
	for (auto [l, r] : v){
		// if (n == 6) cout << l << ' ' << r << endl;
		// tree.update(r, 1);
		arr[r]++;
	}
	for (int i = 0; i <= 2 * n; i++)
		tree.update(i, arr[i]);
	// cout << tree.query(0, 9) << endl;
	int ptr = 0;
	ll ans = 0;
	for (int l = 1; l <= 2 * n; l++) {
		int lo = l, hi = 2 * n + 1;
		while (lo < hi) {
			int mid = (lo + hi) >> 1;
			int s = tree.query(0, mid + 1);
			if (s > 0) hi = mid;
			else lo = mid + 1;
		}
		if (tree.query(0, hi + 1) > 0)
			ans += (2 * n - hi + 1);
		// if (n == 6) cout << hi << endl;
		while (ptr < n && l == v[ptr].first) {
			// tree.update(v[ptr].second, -1);
			int r = v[ptr].second;
			arr[r]--;
			tree.update(r, arr[r]);
			ptr++;
		}
		// cout << ans << endl;
	}
	cout << ans << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}