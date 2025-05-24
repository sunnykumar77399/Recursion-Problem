double power(double x, long long n) {

        if (n == 0) {
            return 1;
        }
        if (n % 2 == 0)                                               // it reduce no of recursion call 
            return myPow(x * x, n / 2);
        else
            return x * myPow(x, n - 1);
    }
    double myPow(double x, int n) {
        if (n >= 0)
            return power(x, n);
        else {
            long long num = -(long long)n;
            return 1.0 / power(x, num);
        }
    }
