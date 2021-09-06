using System.Collections.Generic;
using System.Linq;

namespace Algorithm
{
    // 1463 : 1로 만들기
    public class Make1
    { 
        public int Func(int n)
        {
            int[] _d = new int[n+3];

            _d[0] = 0; _d[1] = 0; _d[2] = 1;
            
            for (int i = 3; i <= n; i++)
            {
                int min = int.MaxValue;
                if (i % 3 == 0 && _d[i / 3] < min)
                    min = _d[i / 3];
                if (i % 2 == 0 && _d[i / 2] < min)
                    min = _d[i / 2];
                if (_d[i - 1] < min) 
                    min = _d[i - 1];

                _d[i] = min + 1;
            }

            return _d[n];
        }
    }
}