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

	//가장 긴 통나무 길이의 기준은 mid
	//자를 수 있는 위치 사이중 어느 하나라도 mid보다 크다면 기준값은 커져야 한다.
	for(int i = 1; i <= K; i++)
	{
		if(D[i] - D[i - 1] > mid)
		{
			cnt = -1;
			break;
		}
	}

	//통나무를 잘라야할 경우는 구간의 길이가 mid보다 커졌을때이다.
	for(int i = 0; i < K; i++)
	{
		if(D[i + 1] - temp > mid)
		{
			temp = D[i];
			cnt--;
		}
		if(cnt < 0)break;
	}

	//통나무를 자를 수 있는 횟수를 초과하였다면 기준값은 작아져야한다.
	if(cnt >= 0)
	{
		return BS(left, mid);
	}
	//통나무를 C번안에 모두 잘랐다면 기준의 범위를 조금 더 줄여나간다.
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
	//답을 구하고 나서는 끝점부터 통나무를 자른다.

	for(int i = K - 1; i >= 0; i--)
	{
		if(temp - D[i] > ans)
		{
			//		cout << "자를 통나무 위치: " << D[i+1] << endl;
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