#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> arr(100001,0);

int binarySearch(int start, int end, int n)
{
	if(start == end)
	{
		if(arr[start] == n)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int mid = (start + end) / 2;
	if(n < arr[mid])
	{
		return binarySearch(start, mid, n);
	}
	else if(n > arr[mid])
	{
		return binarySearch(mid + 1, end, n);
	}
	else
	{
		return 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(),arr.begin()+n);

	cin >> m;

	vector<int> search(m,0);

	for(int i = 0; i < m; i++)
	{
		cin >> search[i];
	}

	for(int i = 0; i < m; i++)
	{
		cout << binarySearch(0, n - 1, search[i]) << "\n";
	}
}