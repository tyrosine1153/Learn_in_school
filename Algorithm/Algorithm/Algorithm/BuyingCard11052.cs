using System;

namespace Algorithm
{
    // 11052 : 카드 구매하기
    public class BuyingCard11052
    {
        public static int Func()
        {
            // 입력
            var N = int.Parse(Console.ReadLine() ?? string.Empty);

            var P = new int[N];
            var temp = (Console.ReadLine() ?? string.Empty).Split(' ');
            for (int i = 0; i < N; i++)
            {
                P[i] = int.Parse(temp[i]);
            }
            
            // 계산
            var memo = new int[N + 1];
            memo[0] = 0;
            for (int i = 1; i <= N; i++)
            {
                var max = int.MinValue;
                for (int j = 1; j <= i; j++)
                {
                    max = Math.Max(max, memo[i - j] + P[j - 1]);
                }

                memo[i] = max;
            }
            
            return memo[N];
        }
    }
}