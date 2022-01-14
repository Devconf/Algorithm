#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef long long ll;
vector<ll> arr(100000);
vector<pair<ll, ll>> tree(300000);

pair<ll,ll> init(vector<ll> &arr, vector<pair<ll,ll>> &tree, size_t node, size_t start, size_t end) {
	if (start == end) {
		return { tree[node].first = arr[start-1], tree[node].second = arr[start-1] };
	}
	auto mid = (start + end) / 2;
	auto left = init(arr, tree, node * 2, start, mid);
	auto right = init(arr, tree, node * 2 + 1, mid + 1, end);
	return tree[node]={ max(left.first,right.first),min(left.second,right.second) };

}

pair<ll, ll> query(size_t node, size_t left, size_t right, size_t start, size_t end) {
	if (right < start || left > end) {
		return { -1, 9999999999 };
	}
	if (start <= left && end >= right) {
		return tree[node];
	}
	auto mid = (left + right) / 2;
	auto l = query(node * 2, left, mid, start, end);
	auto r = query(node * 2 + 1, mid + 1, right, start, end);
	return { max(l.first,r.first),min(l.second,r.second) };
}

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);

	
	int a, b, n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	init(arr, tree, 1, 1, n);
	
	for (int i = 0; i < m; i++) {
		ll max, min;
		cin >> a >> b;
		
		auto p = query(1, 1, n, a, b);
		cout<<p.second <<" "<< p.first << "\n";
	}


}