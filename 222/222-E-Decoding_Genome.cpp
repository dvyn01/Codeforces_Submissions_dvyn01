#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define mod 1000000007
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

template <class T>
ostream &operator<<(ostream &os, vector<T> V)
{
    os << "[ ";
    for (auto v : V)
        os << v << " ";
    os << "]";
    return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> S)
{
    os << "{ ";
    for (auto s : S)
        os << s << " ";
    return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P)
{
    return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M)
{
    os << "{ ";
    for (auto m : M)
        os << "(" << m.first << ":" << m.second << ") ";
    return os << "}";
}

struct Matrix
{
    vector<vector<ll>> mat; // the contents of matrix as a 2D-vector
    ll n_rows, n_cols;      // number of rows and columns

    Matrix(vector<vector<ll>> values) : mat(values), n_rows(values.size()),
                                         n_cols(values[0].size()) {}

    static Matrix identity_matrix(ll n)
    {
        // Return I_n - the identity matrix of size n.
        // This function is static, because it creates a new Matrix instance
        vector<vector<ll>> values(n, vector<ll>(n, 0));
        for (ll i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const
    {
        ll n = n_rows, m = other.n_cols;
        vector<vector<ll>> result(n_rows, vector<ll>(m, 0));
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < m; j++)
            {
                for (ll k = 0; k < n_cols; k++)
                {
                    result[i][j] = (result[i][j] + mat[i][k] * 1ll * other.mat[k][j]) % mod;
                }
            }
        // Multiply matrices as usual, then return the result as the new Matrix
        return Matrix(result);
    }

    inline bool is_square() const
    {
        return n_rows == n_cols;
    }
};

Matrix fast_exponentiation(Matrix m, ll power)
{
    assert(m.is_square());
    Matrix result = Matrix::identity_matrix(m.n_rows);

    while (power)
    {
        if (power & 1)
            result = result * m;
        m = m * m;
        power >>= 1;
    }

    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> v;
    v.resize(m);
    f(0, m) v[i].resize(m);
    f(0, m) fi(0, m) v[i][j] = 1;
    f(0, k)
    {
        string s;
        cin >> s;
        char a = s[0], b = s[1];
        ll ii, jj;
        if (a >= 'a' && a <= 'z')
            ii = a - 'a';
        else
            ii = a - 'A' + 26;
        if (b >= 'a' && b <= 'z')
            jj = b - 'a';
        else
            jj = b - 'A' + 26;
        v[ii][jj] = 0;
    }
    Matrix M(v);
    Matrix M1 = fast_exponentiation(M, n - 1);
    ll ans = 0;
    f(0, m)
        fi(0, m) ans = (ans + M1.mat[i][j]) % mod;
    cout << ans;

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}