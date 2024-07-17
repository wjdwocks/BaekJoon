#include <iostream>
#include <vector>

// tomato를 받는 vector배열을 만듦.
// tomato의 (x,y)는 좌측 위를 원점 으로 좌표. 
// value는 -1, 0, 1을 가짐.


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);


	int M, N, H;
	std::cin >> M >> N >> H;

    std::vector<std::vector<std::vector<int>>> tomato(H+2, std::vector<std::vector<int>>(N+2, std::vector<int>(M+2)));

    // tomato[0] -> 높이
    // tomato[0][0] -> 0높이의 행번호
    // tomato[0][0][0] -> 0높이의 0행 0열

    for (int i = 0; i < H+2; ++i)
    {
        for (int j = 0; j < N+2; ++j)
        {
            for (int k = 0; k < M+2; ++k)
            {
                tomato[i][j][k] = -1;
            }
        }
    }

    int total(H * M * N) , now = 0, prev_now = -1, day = 0;

    for (int i = 1; i <= H; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            for (int k = 1; k <= M; ++k)
            {
                std::cin >> tomato[i][j][k]; // (1,1)은 원점. (4,2)는 오른쪽, 아레로 이동.
                if (tomato[i][j][k] == -1) // 빈 공간 -> 전체 토마토 개수에서 제거
                    total--;
                else if (tomato[i][j][k] == 1)
                    now++;
            }
        }
    }
	
    std::vector<std::vector<std::vector<int>>> next_tomato(H+2, std::vector<std::vector<int>>(N+2, std::vector<int>(M+2)));

    next_tomato = tomato;

    while (now != total && prev_now != now) // 현재 토마토 개수 vs 이전 토마토 개수
    {
        for (int i = 1; i <= H; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                for (int k = 1; k <= M; ++k)
                {
                    if (tomato[i][j][k] == 1)
                    {
                        next_tomato[i - 1][j][k] = tomato[i - 1][j][k] == -1 ? -1 : 1; // 그 자리가 비어있었다면 그대로 비어놔. 아니면 익혀져.
                        next_tomato[i + 1][j][k] = tomato[i + 1][j][k] == -1 ? -1 : 1;
                        next_tomato[i][j - 1][k] = tomato[i][j - 1][k] == -1 ? -1 : 1;
                        next_tomato[i][j + 1][k] = tomato[i][j + 1][k] == -1 ? -1 : 1;
                        next_tomato[i][j][k - 1] = tomato[i][j][k - 1] == -1 ? -1 : 1;
                        next_tomato[i][j][k + 1] = tomato[i][j][k + 1] == -1 ? -1 : 1;
                    }
                }
            }
        }
        prev_now = 0;
        now = 0;
        for (int i = 1; i <= H; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                for (int k = 1; k <= M; ++k)
                {
                    if (tomato[i][j][k] == 1) // 빈 공간 -> 전체 토마토 개수에서 제거
                        prev_now++;
                }
            }
        }
        for (int i = 1; i <= H; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                for (int k = 1; k <= M; ++k)
                {
                    if (next_tomato[i][j][k] == 1) // 빈 공간 -> 전체 토마토 개수에서 제거
                        now++;
                }
            }
        }
        tomato = next_tomato;
        day++;
    }
    if (now == total)
        std::cout << day;
    else
        std::cout << -1;
}