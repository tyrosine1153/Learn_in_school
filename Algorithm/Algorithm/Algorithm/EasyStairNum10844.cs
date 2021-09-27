using System;

namespace Algorithm
{
    // 10844 : 쉬운 계단 수
    public class EasyStairNum10844
    {
        public static int Func()
        {
            // 입력
            var N = int.Parse(Console.ReadLine());

            var memo = new int[N + 1, 10];
            memo[1, 0] = 0;
            for (int i = 1; i < 10; i++) memo[1, i] = 1;
            
            for (int i = 2; i <= N; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    memo[i, j] = 0;
                    if (j > 0) memo[i, j] += memo[i - 1, j - 1];
                    memo[i, j] %= 1000000000;
                    if (j < 9) memo[i, j] += memo[i - 1, j + 1];
                    memo[i, j] %= 1000000000;
                }
            }

            var answer = 0;
            for (int i = 0; i < 10; i++)
            {
                answer += memo[N, i];
                answer %= 1000000000;
            }

            return answer;
        }
    }
}