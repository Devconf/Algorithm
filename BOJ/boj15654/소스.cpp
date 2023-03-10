#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int arr[8];
vector<int> v;
bool visited[8];

void func(int idx)
{
	if(idx == m)
	{
		for(int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";

		return;
	}

	for(int i = 0; i < v.size(); i++)
	{
		if(visited[i])
		{
			continue;
		}

		visited[i] = true;
		arr[idx] = v[i];
		func(idx + 1);

		visited[i] = false;
	}
}

void solution()
{
	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		v.push_back(num);
	}

	sort(v.begin(), v.end());

	func(0);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;

	solution();
}