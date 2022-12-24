//구간 업데이트 쿼리
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
vector<ll> arr(100000);
vector<ll> tree(444444);
vector<ll> lazy(444444);

void propagate(ll node, ll start, ll end)
{
	if(lazy[node])
	{
		tree[node] += (end - start + 1)*lazy[node];
		if(start != end)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update(ll node, ll left, ll right, ll start, ll end, ll data)
{
	propagate(node, left, right);
	if(right <  start || left > end)
	{
		return;
	}
	
	if(left >= start && right <= end)
	{
		tree[node] += (right - left + 1)*data;
		if(left != right)
		{
			lazy[node * 2] += data;
			lazy[node * 2 + 1] += data;
		}
		return;
	}

	ll mid = (left + right) / 2;
	update(node * 2, left, mid, start, end, data);
	update(node * 2 + 1, mid + 1, right, start, end, data);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(ll node, ll left, ll right, ll start, ll end)
{
	propagate(node, left, right);
	if(right < start || left > end)
	{
		return 0;
	}
	if(start <= left && end >= right)
	{
		return tree[node];
	}
	auto mid = (left + right) / 2;
	return query(node * 2, left, mid, start, end) + query(node * 2 + 1, mid + 1, right, start, end);
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, q;
	cin >> n;

	for(ll i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cin >> q;

	
	for(ll i = 0; i < q; i++)
	{
		ll key, l, r, x;
		cin >> key;
		if(key == 1)
		{
			cin >> l >> r;
			update(1, 1, n, l, r, 1);
			update(1, 1, n, r + 1, r + 1, (l - r - 1));
		}
		if(key == 2)
		{
			cin >> x;
			cout << arr[x - 1] + query(1, 1, n, 1, x) << "\n";
		}
	}

}