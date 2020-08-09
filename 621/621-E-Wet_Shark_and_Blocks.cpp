#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

ll mod = 1000000007;

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

ll n, m, p, z, x;

struct Matrix
{
    vector<vector<ll>> mat;
    ll n_rows, n_cols;

    Matrix(vector<vector<ll>> values) : mat(values), n_rows(values.size()),
                                        n_cols(values[0].size()) {}

    static Matrix identity_matrix(ll n)
    {
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
                for (ll k = 0; k < m; k++)
                {
                    result[i][j] = (result[i][j] + (mat[i][k] * 1ll * other.mat[k][j]) % mod) % mod;
                }
            }
        return Matrix(result);
    }

    inline bool is_square() const
    {
        return n_rows == n_cols;
    }

    friend ostream &operator<<(ostream &os, const Matrix &M)
    {
        for (int i = 0; i < M.n_rows; ++i)
        {
            for (int j = 0; j < M.n_cols; ++j)
            {
                cout << M.mat[i][j] << " ";
            }
            cout << "\n";
        }
        return os;
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

    cin >> m >> n >> p >> z;
    ll a[100];
    memset(a, 0, sizeof(a));
    f(0, m) cin >> x, a[x % z]++;
    vector<vector<ll>> v;
    v.resize(z);
    f(0, z) v[i].resize(z);
    f(0, z)
        fi(0, z) v[i][(i * 10 + j) % z] = a[j];
    Matrix M(v);
    M = fast_exponentiation(M, n);
    ll ans = M.mat[0][p];
    cout << ans;

#ifndef ONLINE_JUDGE
    cout
        << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}