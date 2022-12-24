#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	vector<int> arr,arr2;
	int n=0, k=0;
	int cnt=0,total=0;
	
	cin >> n >> k;

	arr.push_back(0);

	for(int i = 0;i < n; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}

	
	while(1)
	{
		int eat = 0;
		for(int i = k + 1; i <= n; i++)
		{
			if(arr[i] <= arr[i - k])
			{
				continue;
			}
			else
			{
				cnt++;
				eat += arr[i] - arr[i - k];
				arr[i] = arr[i - k];
				sort(arr.begin(), arr.end());
			}
		}
		if(eat != 0)
		{
			total+=eat;
			continue;
		}
		break;
	}
	
	
	cout << total << " "<<cnt;
}