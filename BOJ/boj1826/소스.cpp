#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

priority_queue<int> pq;
vector<pair<int, int>> v;
int n;
int l, p;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());
	
	cin >> l >> p;

	int curP = 0, curL = p, ans = 0;
	while(curL < l)
	{
		while(curP < n && v[curP].first <= curL)
		{
			pq.push(v[curP++].second);
		}
		if(pq.empty())
		{ // L 에 도착도 못했고, 더 이상 갈 곳도 없음.
			ans = -1;
			break;
		}
		curL += pq.top();
		pq.pop();
		ans++;
	}
	cout << ans << '\n';
	return 0;
}