#include <bits\stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long power(long long base, long long exp)
{
    long long res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInv(long long n)
{
    return power(n, MOD - 2);
}

const int MAXN_TOTAL = 200005;
vector<long long> fact(MAXN_TOTAL);
vector<long long> invFact(MAXN_TOTAL);

void pre_fact()
{
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN_TOTAL; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    invFact[MAXN_TOTAL - 1] = modInv(fact[MAXN_TOTAL - 1]);

    for (int i = MAXN_TOTAL - 2; i >= 1; --i)
    {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

void solve()
{
    int n_total;
    cin >> n_total;
    string a;
    cin >> a;

    int num_ones = 0;
    for (char c : a)
    {
        if (c == '1')
        {
            num_ones++;
        }
    }
    int num_zeros = n_total - num_ones;

    if (num_ones < 2 || num_zeros < 1)
    {
        cout << 0 << endl;
        return;
    }

    long long ans = fact[n_total];

    ans = (ans * invFact[3]) % MOD;

    ans = (ans * invFact[num_ones - 2]) % MOD;

    ans = (ans * invFact[num_zeros - 1]) % MOD;

    cout << ans << endl;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pre_fact();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}