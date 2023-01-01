#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int num[102];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for(int i = 0; i <= 101; i++)
	{
		num[i] = pow(i, 2);
	}


	int n;

	cin >> n;

	int minCnt = 9999999;
	
	for(int i = int(floor(sqrt(n))); i > 0; i--)
	{
		int start = n;
		int cnt = 0;
		int j = i;
		while(start != 0)
		{
			if(sqrt(start)*sqrt(start) == start)
			{
				cnt++; 
				break;
			}
			else
			{
				if(start >= num[j])
				{
					start -= num[j];
					cnt++;
				}
			}
			j--;
		}
		minCnt = min(minCnt, cnt);
	}
	
	
	cout << minCnt;

}