#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> nv, mv;
vector<pair<int, int>> h;
int result;

void BS(int l,int r,int v)
{
	if(l > r)
	{
		cout << 0 << " ";
		return;
	}

	int mid = (l + r) / 2;

	if(h[mid].first == v)
	{
		cout << h[mid].second<<" ";
	}
	else if(h[mid].first < v)
	{
		BS(mid + 1, r, v);
	}
	else
	{
		BS(l, mid - 1, v);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		nv.push_back(num);
	}

	sort(nv.begin(), nv.end());

	

	for(int e:nv)
	{
		if(h.empty() || h.back().first != e)
		{
			h.push_back({ e, 1 });
		}
		else
			h.back().second += 1;
	}

	cin >> m;

	for(int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		mv.push_back(num);
	}

	for(int i = 0; i < m; i++)
	{
		BS(0, h.size()-1, mv[i]);
	}

}