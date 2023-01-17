#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long x, y;
	int w, s;

	long long ans = 0;

	cin >> x >> y >> w >> s;

	if(2 * w <= s)
	{
		ans += (x + y)*w;
	}
	else
	{
		if(x <= y)
		{
			ans += x * s;
			if((y - x) % 2 == 0)
			{
				if(w <= s)
				{
					ans += (y - x)*w;
				}
				else
				{
					ans += (y - x)*s;
				}
			}
			else
			{
				int remainder = (y - x) % 2;
				if(w <= s)
				{
					ans += (y - x)*w;
				}
				else
				{
					ans += ((y - x) - remainder)*s + remainder * w;
				}
			}
			
		}
		else
		{
			ans += y * s;
			if((x - y) % 2 == 0)
			{
				if(w <= s)
				{
					ans += (x - y)*w;
				}
				else
				{
					ans += (x - y)*s;
				}
			}
			else
			{
				int remainder = (x - y) % 2;
				if(w <= s)
				{
					ans += (x - y)*w;
				}
				else
				{
					ans += ((x - y) - remainder)*s + remainder * w;
				}
			}
		}
	}
	cout << ans;
}