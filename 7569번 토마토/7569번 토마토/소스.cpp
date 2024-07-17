#include <iostream>
#include <vector>

// tomato�� �޴� vector�迭�� ����.
// tomato�� (x,y)�� ���� ���� ���� ���� ��ǥ. 
// value�� -1, 0, 1�� ����.


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);


	int M, N, H;
	std::cin >> M >> N >> H;

    std::vector<std::vector<std::vector<int>>> tomato(H+2, std::vector<std::vector<int>>(N+2, std::vector<int>(M+2)));

    // tomato[0] -> ����
    // tomato[0][0] -> 0������ ���ȣ
    // tomato[0][0][0] -> 0������ 0�� 0��

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
                std::cin >> tomato[i][j][k]; // (1,1)�� ����. (4,2)�� ������, �Ʒ��� �̵�.
                if (tomato[i][j][k] == -1) // �� ���� -> ��ü �丶�� �������� ����
                    total--;
                else if (tomato[i][j][k] == 1)
                    now++;
            }
        }
    }
	
    std::vector<std::vector<std::vector<int>>> next_tomato(H+2, std::vector<std::vector<int>>(N+2, std::vector<int>(M+2)));

    next_tomato = tomato;

    while (now != total && prev_now != now) // ���� �丶�� ���� vs ���� �丶�� ����
    {
        for (int i = 1; i <= H; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                for (int k = 1; k <= M; ++k)
                {
                    if (tomato[i][j][k] == 1)
                    {
                        next_tomato[i - 1][j][k] = tomato[i - 1][j][k] == -1 ? -1 : 1; // �� �ڸ��� ����־��ٸ� �״�� ����. �ƴϸ� ������.
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
                    if (tomato[i][j][k] == 1) // �� ���� -> ��ü �丶�� �������� ����
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
                    if (next_tomato[i][j][k] == 1) // �� ���� -> ��ü �丶�� �������� ����
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