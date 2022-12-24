#include <iostream>
using namespace std;

long long sum = 0;
long long XOR = 0;

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);

	int qcnt = 0;
	   
	cin>>qcnt;
	cin.ignore();
	for(int i = 0; i< qcnt; i++)
	{
		int q;
		cin >> q;


		if(q == 1)
		{
			int num;
			cin >> num;
			sum += num;
			XOR ^= num;
			continue;
		}
		if(q == 2)
		{
			int num;
			cin >> num;
			XOR ^= num;
			sum -= num;
			continue;
		}
		if(q == 3)
		{
			cout << sum<<"\n";
		}
		if(q == 4)
		{
			cout<<XOR<<"\n";
		}
	}
	return 0;
}