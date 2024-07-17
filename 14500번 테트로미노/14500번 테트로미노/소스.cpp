#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	int** arr = new int* [N];
	for (int i = 0; i < N; ++i)
		arr[i] = new int[M];
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			cin >> arr[i][j];
	}

	// i블록에 대한 브루트 포스로 최대 점수 확인
	int max_i = -1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j <= M - 4; ++j)
		{
			int temp_i = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
			max_i = max(max_i, temp_i);
		}
	}
	for (int i = 0; i <= N - 4; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int temp_i = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];
			max_i = max(max_i, temp_i);
		}
	}
	// 네모 블록에 대한 최대 점수를 브루트 포스로 확인.
	int max_nemo = -1;
	for (int i = 0; i <= N - 2; ++i)
	{
		for (int j = 0; j <= M - 2; ++j)
		{
			int temp_nemo = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
			max_nemo = max(max_nemo, temp_nemo);
		}
	}
	// L블록 (4가지 위상) 위로 볼록, 아레로 볼록
	int L_max = -1;
	for (int i = 0; i <= N - 2; ++i)
	{
		for (int j = 0; j <= M - 3; ++j)
		{
			int temp_L = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			L_max = max(L_max, temp_L);
			temp_L = arr[i][j + 2] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			L_max = max(L_max, temp_L);
			temp_L = arr[i + 1][j + 2] + arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
			L_max = max(L_max, temp_L);
			temp_L = arr[i + 1][j] + arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
			L_max = max(L_max, temp_L);
		}
	}
	for (int i = 0; i <= N - 3; ++i)
	{
		for (int j = 0; j <= M - 2; ++j)
		{
			int temp_L = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i][j + 1];
			L_max = max(L_max, temp_L);
			temp_L = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];
			L_max = max(L_max, temp_L);
			temp_L = arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1] + arr[i + 2][j];
			L_max = max(L_max, temp_L);
			temp_L = arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1] + arr[i][j];
			L_max = max(L_max, temp_L);
		}
	}
	// z자 블록 위로 3x2 인 경우와 2x3인 경우
	int max_z = -1;
	for (int i = 0; i <= N - 3; ++i)
	{
		for (int j = 0; j <= M - 2; ++j)
		{
			int temp_z = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			max_z = max(max_z, temp_z);
			temp_z = arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j];
			max_z = max(max_z, temp_z);
		}
	}
	for (int i = 0; i <= N - 2; ++i)
	{
		for (int j = 0; j <= M - 3; ++j)
		{
			int temp_z = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			max_z = max(max_z, temp_z);
			temp_z = arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i ][j + 2];
			max_z = max(max_z, temp_z);
		}
	}
	// ㅗ형 블록 2 x 3 ㅗㅜ, 3 x 2 ㅓㅏ
	int max_h = -1;
	for (int i = 0; i <= N - 2; ++i)
	{
		for (int j = 0; j <= M - 3; ++j)
		{
			int temp_h = arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			max_h = max(max_h, temp_h);
			temp_h = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
			max_h = max(max_h, temp_h);
		}
	}
	for (int i = 0; i <= N - 3; ++i)
	{
		for (int j = 0; j <= M - 2; ++j)
		{
			int temp_h = arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			max_h = max(max_h, temp_h);
			temp_h = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j];
			max_h = max(max_h, temp_h);
		}
	}
	vector<int> v;
	v.emplace_back(max_h);
	v.emplace_back(max_i);
	v.emplace_back(max_z);
	v.emplace_back(max_nemo);
	v.emplace_back(L_max);
	sort(v.begin(), v.end(), [](int a, int b) {return a > b; });
	std::cout << v[0];
	
}