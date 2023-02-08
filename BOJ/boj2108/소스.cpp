#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using  namespace std;

bool pre(pair<int, int> a, pair<int, int> b)
{
	if(a.first == b.first)
	{
		return a.second < b.second;
	}
	return a.first > b.first;
}

vector<int> v;
pair<int, int> arr[8002] = { {0,0 } };
int main()
{
	int n = 0;
	double sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		sum += num;
		v.push_back(num);
		arr[num + 4000].first += 1;
		arr[num + 4000].second = num;
	}
	sort(v.begin(), v.end());
	sort(&arr[0], &arr[8002], pre);

	if(sum == -1)
	{
		cout << 0 << "\n"; // »ê¼úÆò±Õ
	}
	else
	{
		cout << round(sum / n)<< "\n"; // »ê¼úÆò±Õ
	}
	
	cout << v[(n / 2)] << "\n"; // Áß¾Ó°ª

	if(arr[0].first == arr[1].first)
	{
		cout << arr[1].second << "\n";
	}
	else
	{
		cout << arr[0].second << "\n";
	}
	cout << v[n - 1] - v[0] << "\n";
	return 0;
}