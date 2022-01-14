#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll arr[2000][2000] = { 0 };
vector<ll> segTree(5000000);
ll fx = 0, fy = 0, lx = 0, ly = 0;
ll beginX = 0;
ll beginY = 0;
ll lastX = 0;
ll lastY = 0;

ll init(vector<ll>&tree, ll node, ll startX, ll startY, ll endX, ll endY)
{
	if(startX > endX || startY > endY)
	{
		return 0;
	}

	if(startX == endX && startY == endY)
	{
		return tree[node] = arr[startX][startY];
	}

	auto midX = (startX + endX) / 2;
	auto midY = (startY + endY) / 2;
	return tree[node] = init(tree, node * 4, startX, startY, midX, midY) +
		init(tree, node * 4 + 1, startX, midY + 1, midX, endY) +
		init(tree, node * 4 + 2, midX + 1, startY, endX, midY) +
		init(tree, node * 4 + 3, midX + 1, midY + 1, endX, endY);
}

ll query(ll node, ll startX, ll startY, ll endX, ll endY)
{
	if(endX<fx || startX>lx || endY<fy || startY>ly)
	{
		return 0;
	}
	if((startX >= fx && endX <= lx) && (startY >= fy && endY <= ly))
	{
		return segTree[node];
	}
	auto midX = (startX + endX) / 2;
	auto midY = (startY + endY) / 2;
	return query(node * 4, startX, startY, midX, midY) +
		query(node * 4 + 1, startX, midY + 1, midX, endY) +
		query(node * 4 + 2, midX + 1, startY, endX, midY) +
		query(node * 4 + 3, midX + 1, midY + 1, endX, endY);
}

ll update(ll node, ll startX, ll startY, ll endX, ll endY, ll X, ll Y, ll data)
{
	if(endX<X || startX>X || endY<Y || startY>Y)
	{
		return 0;
	}
	if((startX == X && endX == X) && (startY == Y && endY == Y))
	{
		segTree[node] = data;
		return data - arr[X][Y];

	}
	auto midX = (startX + endX) / 2;
	auto midY = (startY + endY) / 2;
	auto origin = segTree[node];
	segTree[node] += update(node * 4, startX, startY, midX, midY, X, Y, data) +
		update(node * 4 + 1, startX, midY + 1, midX, endY, X, Y, data) +
		update(node * 4 + 2, midX + 1, startY, endX, midY, X, Y, data) +
		update(node * 4 + 3, midX + 1, midY + 1, endX, endY, X, Y, data);
	return segTree[node] -= origin;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	lastX = n - 1;
	lastY = n - 1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	init(segTree, 1, 0, 0, n - 1, n - 1);

	for(int i = 0; i < q; i++)
	{
		int w;
		cin >> w;
		if(w == 1)
		{
			cin >> fx >> fy >> lx >> ly;
			if(fx > lx)
			{
				swap(fx, lx);
			}
			if(fy > ly)
			{
				swap(fy, ly);
			}
			fx--, fy--, lx--, ly--;
			cout << query(1, 0, 0, n - 1, n - 1) << "\n";
		}
		if(w == 0)
		{
			int dx, dy, data;
			cin >> dx >> dy >> data;
			update(1, 0, 0, n - 1, n - 1, dx - 1, dy - 1, data);
		}
	}
}