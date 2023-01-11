#include <iostream>
#include <algorithm>
using namespace std;
int L, K, C;
int D[10002];
int First;

int BS(int left, int right)
{
	if(left >= right)
	{
		return right;
	}
	int mid = (left + right) / 2;
	int temp = 0;
	int cnt = C;

	if(D[0] > mid)
	{
		cnt = -1;
	}

	//���� �� �볪�� ������ ������ mid
	//�ڸ� �� �ִ� ��ġ ������ ��� �ϳ��� mid���� ũ�ٸ� ���ذ��� Ŀ���� �Ѵ�.
	for(int i = 1; i <= K; i++)
	{
		if(D[i] - D[i - 1] > mid)
		{
			cnt = -1;
			break;
		}
	}

	//�볪���� �߶���� ���� ������ ���̰� mid���� Ŀ�������̴�.
	for(int i = 0; i < K; i++)
	{
		if(D[i + 1] - temp > mid)
		{
			temp = D[i];
			cnt--;
		}
		if(cnt < 0)break;
	}

	//�볪���� �ڸ� �� �ִ� Ƚ���� �ʰ��Ͽ��ٸ� ���ذ��� �۾������Ѵ�.
	if(cnt >= 0)
	{
		return BS(left, mid);
	}
	//�볪���� C���ȿ� ��� �߶��ٸ� ������ ������ ���� �� �ٿ�������.
	else
	{
		return BS(mid + 1, right);
	}
}


int main()
{
	cin >> L >> K >> C;

	if(C > K)
	{
		C = K;
	}
	int idx = 0;
	int tempK = K;
	while(tempK--)
	{
		cin >> D[idx];
		idx++;
	}
	D[idx] = L;

	sort(D, D + K + 1);

	int ans = BS(0, L);

	int cnt = C;
	int temp = L;
	//���� ���ϰ� ������ �������� �볪���� �ڸ���.

	for(int i = K - 1; i >= 0; i--)
	{
		if(temp - D[i] > ans)
		{
			//		cout << "�ڸ� �볪�� ��ġ: " << D[i+1] << endl;
			temp = D[i + 1];
			cnt--;
		}
	}
	//cout << cnt << endl;
	if(cnt > 0)
	{
		First = D[0];
	}
	else
	{
		First = temp;
	}

	cout << ans << ' ' << First << endl;

	return 0;
}