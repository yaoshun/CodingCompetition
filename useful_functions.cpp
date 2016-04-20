typedef long long ll;

// Calculate the greatest common divisor.
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }

// Calculate the modular inverse of a regards to b.
// Solve ax == 1 mod b, requires gcd(a,b) = 1 to work.
ll mul_inv(ll a, ll b) {
    ll b0 = b, t, q;
    ll x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }   
    if (x1 < 0) x1 += b0; 
    return x1; 
}

// Generate the primes under a certain number.
// Notice if there is result arr to push back, we need the commented part.
const int MAX = 1000000;
vector<bool> primes(MAX + 1, true);
void sieve() {
    primes[0] = false;
    primes[1] = false;
    int i;
    for (i = 2; i * i <= MAX; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= MAX; j += i) {
                primes[j] = false;
            }   
        }   
    }   
/*
    for (; i <= MAX; i++) {
        if (primes[i]) {
        }
    }
*/
}
