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


void solve(){
	int n;
	cin >> n;
	vi p(n), idx(n + 2);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		idx[p[i]] = i;
	}
	string s;
	cin >> s;
	vi ones;
	for (int i = 0; i < n; i++) {
		if(s[i] == '1')
			ones.push_back(i);
	}
	if (s[idx[1]] == '1' || s[idx[n]] == '1') {
		cout << -1 << endl;
		return;
	}
	if(s[0] == '1' || s.back() == '1') {
		cout << -1 << endl;
		return;
	}
	vector<pii> ans;
	ans.emplace_back(idx[1],idx[n]);
	int mx = 0, mn = n;
	for (int i = 0; i < n; i++) {
		if (p[i] != 1 && p[i] != n) {
			mx = max(mx, p[i]);
			mn = min(mn, p[i]);			
		}
		if(!ones.empty() && ones[0] == i+1){
			ans.emplace_back(idx[mx], idx[1]);
			ans.emplace_back(idx[mn], idx[n]);
		}
	}
	mx = 0;
	mn = n;
	for (int i = n - 1; i >= 0; --i) {
		if (p[i] != 1 && p[i] != n) {
			mx = max(mx, p[i]);
			mn = min(mn, p[i]);			
		}
		if(!ones.empty() && ones.back() == i-1){
			ans.emplace_back(idx[mx], idx[1]);
			ans.emplace_back(idx[mn], idx[n]);
		}
	}
	cout << ans.size() << '\n';
	for (auto [l, r] : ans){
		cout << min(l,r)+1 << ' ' << max(l,r) + 1 << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}