int mod = 1e9 + 7; // Modulo value to keep the result within integer range

// Function to compute (x^y) % mod using binary exponentiation
long long powerof(long long x, long long y) {
    if (y == 0) return 1; // Base case: any number to the power 0 is 1
    
    long long ans = powerof(x, y / 2); // Recursively calculate power(x, y/2)
    ans *= ans; // Square the result
    ans %= mod; // Take modulo to prevent overflow

    if (y % 2) ans *= x; // If y is odd, multiply by x one more time
    ans %= mod; // Again take modulo

    return ans; // Return the final result
}

int countGoodNumbers(long long n) {
    long long odd = n / 2; // Number of positions where only odd primes (2,3,5,7) can go
    long long even = n / 2 + n % 2; // Number of even positions where digits (0,2,4,6,8) can go
    
    // Total combinations = 5^even * 4^odd (modulo mod)
    return (powerof(5, even) * powerof(4, odd)) % mod;
}
