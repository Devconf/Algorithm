#include<iostream>
#include<cstring>
using namespace std;

int arr[201];

int findParent(int x)
{
	if(arr[x]<0)
	{
		return x;
	}
	int parent = findParent(arr[x]);
	return parent;
}

void merge(int aParent, int bParent)
{
	//집합의 크기가 더 큰 쪽으로 합쳐진다
	if(abs(aParent) >= abs(bParent))
	{
		arr[aParent] += arr[bParent];
		arr[bParent] = aParent;
	}
	else
	{
		arr[bParent] += arr[aParent];
		arr[aParent] = bParent;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;

	memset(arr, -1, sizeof(arr));


	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int num = 0;
			cin >> num;

			if(num == 1)
			{
				int aParent = findParent(i);
				int bParent = findParent(j);

				if(aParent == bParent)
				{
					continue;
				}

				merge(aParent, bParent);
			}
		}
	}

	int root = 0;
	for(int i = 0; i < m; i++)
	{
		int node;
		cin >> node;
		if(i != 0)
		{
			if(root != findParent(node))
			{
				cout << "NO";
				return 0;
			}
		}
		else
		{
			root = findParent(node);
		}
		
	}

	cout << "YES";
}