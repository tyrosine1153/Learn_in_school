namespace Algorithm
{
    public class Fibonacci
    {
        private int[] _memoization = new int[100];

        public Fibonacci()
        {
            _memoization[0] = 0;
            _memoization[1] = 1;
            _memoization[2] = 2;
        }
        
        public int Fibonacci_(int n)
        {
            if (n <= 2)
            {
                return 1;
            }
            if (_memoization[n] > 0)
            {
                return _memoization[n];
            }
            _memoization[n] = Fibonacci_(n - 1) + Fibonacci_(n - 2);
            return _memoization[n];
        
        }
    }
}