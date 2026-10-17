#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using str = string;

static int intMin = numeric_limits<int>::min();
static int intMax = numeric_limits<int>::max();
static long long longMin = numeric_limits<long long>::min();
static long long longMax = numeric_limits<long long>::max();
const ll INF = 1e9 + 7;
static ll mod = 998244353;
static long long di[] = { -1, 0, 1, 0, -1, -1, 1, 1};
static long long dj[] = { 0, 1, 0, -1, -1, 1, -1, 1};

class ReadArray { public:
    vector<int> in() { string s; getline(cin >> ws, s); istringstream is(s); return vector<int>(istream_iterator<int>(is), {}); }
    vector<long long> ll() { string s; getline(cin >> ws, s); istringstream is(s); return vector<long long>(istream_iterator<long long>(is), {}); }
    vector<float> fl() { string s; getline(cin >> ws, s); istringstream is(s); return vector<float>(istream_iterator<float>(is), {}); }
    vector<double> dbl() { string s; getline(cin >> ws, s); istringstream is(s); return vector<double>(istream_iterator<double>(is), {}); }
    vector<string> str() { string s; getline(cin >> ws, s); istringstream is(s); return vector<string>(istream_iterator<string>(is), {}); }
    vector<char> ch() { string s; getline(cin >> ws, s); istringstream is(s); vector<char> v; for (char c; is >> c;) v.push_back(c); return v; }
}; ReadArray readArray;
class ReadMap { public:
    vector<vector<int>> in(int h, int w) { vector<vector<int>> r(h,vector<int>(w)); for(int i=0;i<h;i++){auto s = readArray.in(); for(int j=0;j<w;j++) r.at(i).at(j)=s.at(j);} return r; }
    vector<vector<long long>> ll(int h, int w) { vector<vector<long long>> r(h,vector<long long>(w)); for(int i=0;i<h;i++){auto s = readArray.ll(); for(int j=0;j<w;j++) r.at(i).at(j)=s.at(j);} return r; }
    vector<vector<char>> ch(int h, int w) { vector<vector<char>> r(h,vector<char>(w)); for(int i=0;i<h;i++){string s; cin >> s; for(int j=0;j<w;j++) r.at(i).at(j)=s.at(j);} return r; }
    vector<vector<bool>> bo(int h, int w, char c = '.') { vector<vector<bool>> r(h,vector<bool>(w)); for(int i=0;i<h;i++){string s; cin >> s; for(int j=0;j<w;j++) r.at(i).at(j)=(s.at(j)==c);} return r;}
};
class ReadFunctions { public:
    int in() { int x; scanf("%d", &x); return x; }
    auto in2() { int x, y; scanf("%d %d", &x, &y); return make_tuple(x, y); }
    auto in3() { int x, y, z; scanf("%d %d %d", &x, &y, &z); return make_tuple(x, y, z); }
    auto in4() { int x, y, z, w; scanf("%d %d %d %d", &x, &y, &z, &w); return make_tuple(x, y, z, w); }
    auto in5() { int x, y, z, w, u; scanf("%d %d %d %d %d", &x, &y, &z, &w, &u); return make_tuple(x, y, z, w, u); }
    auto in6() { int x, y, z, w, u, v; scanf("%d %d %d %d %d %d", &x, &y, &z, &w, &u, &v); return make_tuple(x, y, z, w, u, v); }
    long long ll() { long long x; scanf("%lld", &x); return x; }
    auto ll2() { long long x, y; scanf("%lld %lld", &x, &y); return make_tuple(x, y); }
    auto ll3() { long long x, y, z; scanf("%lld %lld %lld", &x, &y, &z); return make_tuple(x, y, z); }
    auto ll4() { long long x, y, z, w; scanf("%lld %lld %lld %lld", &x, &y, &z, &w); return make_tuple(x, y, z, w); }
    auto ll5() { long long x, y, z, w, u; scanf("%lld %lld %lld %lld %lld", &x, &y, &z, &w, &u); return make_tuple(x, y, z, w, u); }
    auto ll6() { long long x, y, z, w, u, v; scanf("%lld %lld %lld %lld %lld %lld", &x, &y, &z, &w, &u, &v); return make_tuple(x, y, z, w, u, v); }
    float fl() { float x; scanf("%f", &x); return x; }
    double dbl() { double x; scanf("%lf", &x); return x; }
    string str() { string x; cin >> x; return x; }
    char cha() { char x; scanf(" %c", &x); return x; }

    template <class T> T t() { T x; cin >> x; return x; }
    template <class... Ts> auto ts() { return make_tuple(t<Ts>()...); }
    
    ReadArray a;
    ReadMap map;
}; ReadFunctions re;

template <class T> void wr(T x) { cout << x;}
template <class T> void wrln(T x) { cout << x << endl;}
template <class T> void wrVecln(vector<T> v) { for(int i=0;i<v.size();i++) {cout << v[i] << " ";} cout << endl;}
void writeMinus1() {printf("%i\n", -1);}

/* keysにそってvalueをソート */
template <typename T> void Sort(std::vector<T>& keys, std::vector<T>& values) {
    std::vector<std::pair<T, T>> paired;
    for (size_t i = 0; i < keys.size(); ++i) {
        paired.emplace_back(keys[i], values[i]);
    }
    std::sort(paired.begin(), paired.end());
    for (size_t i = 0; i < keys.size(); ++i) {
        keys[i] = paired[i].first;
        values[i] = paired[i].second;
    }
}
template <typename T> void Sort(vector<T> &array) {sort(array.begin(), array.end());}
template <typename T> void Reverse(vector<T> &array) {reverse(array.begin(), array.end());}

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1); // XORとビットシフトを利用してハッシュを合成
    }
};
struct tuple_hash {
    template <typename... T>
    size_t operator()(const tuple<T...>& t) const {
        size_t seed = 0;
        apply([&seed](const auto&... args) {
            ((seed ^= 
                hash<decay_t<decltype(args)>>{}(args)
                + 0x9e3779b97f4a7c15ULL
                + (seed << 6)
                + (seed >> 2)
            ), ...);
        }, t);
        return seed;
    }
};

long long average(long long a, long long b) {return a + (b - a) / 2; }
long long kaijou(long long v) { long long r = 1; for (long long i = v; i > 0; i--) r *= i; return r; }
long long yojou(int v, int v2) { long long r = v % v2; return r < 0 ? r + v2 : r; }
long long yojou(ll v, ll v2) { long long r = v % v2; return r < 0 ? r + v2 : r; }
int digit_count(long long n) {if(n==0)return 1;n=llabs(n);int cnt=0;while(n>0){cnt++;n/=10;}return cnt;}
bool rangeCheck(int i, int j, int h, int w) { return (0 <= i && i < h && 0 <= j && j < w);}
long long power(long long base, long long exp) { long long result = 1; for (int i = 0; i < exp; ++i) result *= base; return result; }
long long modPow(long long r, long long n) {long long res = 1; r %= mod; while (n > 0) { if (n & 1) res *= r; res %= mod; r *= r; r %= mod; n >>= 1;} return res % mod;}
long long modinv(long long a) { ll b = mod, u = 1, v = 0; while (b) { ll t = a / b; a -= t * b; swap(a, b); u -= t * v; swap(u, v);	} u %= mod; if (u < 0) u += mod; return u; }
int popcount(ll num) {int count = 0;while(num){count+=num&1;num>>=1;}return count;}
long long GCD(long long a, long long b) {if(b==0)return a;return GCD(b,a%b);}
ll floorSqrt(ll n){ll ret = (ll)floor(sqrt(n));if(n-(ret+1)*(ret+1) >= 0) ret++;else if(n-ret*ret < 0) ret--;return ret;}

template <typename T> int FindEqual(vector<T> &vec, T target) {
    int l = 0; int r = vec.size()-1;
    int ret = -1;
    while(l <= r) {
        int mid = (l + r)/2;
        if(vec.at(mid) > target) {
            r = mid - 1;
        }
        else if(vec.at(mid) == target)
        {
            ret = mid;
            break;
        }
        else l = mid + 1;
    }
    return ret;
}
template <typename T> int FindFirstGreater(vector<T> &vec, T target) {
    int l = 0; int r = vec.size()-1;
    int ret = -1;
    while(l <= r) {
        int mid = (l + r)/2;
        if(vec.at(mid) >= target) {
            ret = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ret;
}
template <typename T> int FindFirstLess(vector<T> &vec, T target) {
    int l = 0; int r = vec.size()-1;
    int ret = -1;
    while(l <= r) {
        int mid = (l + r)/2;
        if(vec.at(mid) <= target) {
            ret = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ret;
}

vector<long long> fact, fact_inv, inv;
/*  init_nCk :二項係数のための前処理
    計算量:O(n)
*/
void init_nCk(ll SIZE) {
    fact.resize(SIZE + 5);
    fact_inv.resize(SIZE + 5);
    inv.resize(SIZE + 5);
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < SIZE + 5; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
    }
}
/*  nCk :modでの二項係数を求める(前処理 int_nCk が必要)
    計算量:O(1)
*/
long long nCk(ll n, ll k) {
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fact[n] * (fact_inv[k] * fact_inv[n - k] % mod) % mod;
}

std::vector<std::pair<char, int>> run_length_encoding(string v) {
    std::vector<std::pair<char, int>> ret;
    for (const char &x : v) {
        if (ret.empty() or ret.back().first != x) ret.emplace_back(x, 0);
        ++ret.back().second;
    }
    return ret;
}
vector<int> topo_sort(vector<vector<ll>> &G) {
    vector<int> ans;
    int n = (int)G.size();
    vector<int> ind(n);            // ind[i]: 頂点iに入る辺の数(次数)
    for (int i = 0; i < n; i++) {  // 次数を数えておく
        for (auto e : G[i]) {
            ind[e]++;
        }
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {  // 次数が0の点をキューに入れる
        if (ind[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {  // 幅優先探索
        int now = que.front();
        ans.push_back(now);
        que.pop();
        for (auto e : G[now]) {
            ind[e]--;
            if (ind[e] == 0) {
                que.push(e);
            }
        }
    }
    return ans;
}

mt19937 rng(123456);  // 固定seed（好きな数字でOK）
// [l, r] の整数乱数
int rand_int(int l, int r) {
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}
// [0, 1) の実数乱数
double rand_double() {
    uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(rng);
}

template <int MOD>
struct ModInt {
    long long v;

    ModInt(long long x = 0) {
        v = x % MOD;
        if (v < 0) v += MOD;
    }

    static constexpr int mod() {
        return MOD;
    }

    ModInt& operator+=(const ModInt& other) {
        v += other.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }

    ModInt& operator-=(const ModInt& other) {
        v -= other.v;
        if (v < 0) v += MOD;
        return *this;
    }

    ModInt& operator*=(const ModInt& other) {
        v = v * other.v % MOD;
        return *this;
    }

    ModInt pow(long long e) const {
        ModInt res = 1, x = *this;
        while (e > 0) {
            if (e & 1) res *= x;
            x *= x;
            e >>= 1;
        }
        return res;
    }

    ModInt inv() const {
        // MOD が素数の場合
        return pow(MOD - 2);
    }

    ModInt& operator/=(const ModInt& other) {
        return *this *= other.inv();
    }

    friend ModInt operator+(ModInt a, const ModInt& b) {
        return a += b;
    }

    friend ModInt operator-(ModInt a, const ModInt& b) {
        return a -= b;
    }

    friend ModInt operator*(ModInt a, const ModInt& b) {
        return a *= b;
    }

    friend ModInt operator/(ModInt a, const ModInt& b) {
        return a /= b;
    }

    friend bool operator==(const ModInt& a, const ModInt& b) {
        return a.v == b.v;
    }

    friend bool operator!=(const ModInt& a, const ModInt& b) {
        return a.v != b.v;
    }

    friend ostream& operator<<(ostream& os, const ModInt& x) {
        return os << x.v;
    }

    friend istream& operator>>(istream& is, ModInt& x) {
        long long t;
        is >> t;
        x = ModInt(t);
        return is;
    }
};
using mint = ModInt<998244353>;

template <class T>
struct NDPrefixSum {
    int n;                  // dimension
    vector<int> sz;         // size of each dimension
    vector<int> stride;     // flatten stride
    vector<T> data;         // original / prefix data

    NDPrefixSum(vector<int> size)
        : n(size.size()), sz(size) {

        stride.assign(n, 1);

        for (int i = n - 2; i >= 0; i--) {
            stride[i] = stride[i + 1] * sz[i + 1];
        }

        int total = 1;
        for (int x : sz) total *= x;

        data.assign(total, 0);
    }

    int id(const vector<int>& p) const {
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += p[i] * stride[i];
        }
        return res;
    }

    // set value
    void add(const vector<int>& p, T x) {
        data[id(p)] += x;
    }

    // build prefix sum
    void build() {
        vector<int> cur(n);

        for (int d = 0; d < n; d++) {
            int block = stride[d];
            int len = sz[d];

            int total = data.size();

            for (int base = 0; base < total; base += block * len) {
                for (int offset = 0; offset < block; offset++) {
                    for (int i = 1; i < len; i++) {
                        data[base + offset + i * block] +=
                            data[base + offset + (i - 1) * block];
                    }
                }
            }
        }
    }

    // sum over [l, r)
    T sum(vector<int> l, vector<int> r) const {
        T ans = 0;

        int lim = 1 << n;

        for (int mask = 0; mask < lim; mask++) {
            vector<int> p(n);
            bool ok = true;

            for (int i = 0; i < n; i++) {
                if (mask >> i & 1) {
                    p[i] = l[i] - 1;
                } else {
                    p[i] = r[i] - 1;
                }

                if (p[i] < 0) ok = false;
            }

            if (!ok) {
                if (__builtin_popcount(mask) % 2 == 0)
                    ans += data[id(p)];
                continue;
            }

            if (__builtin_popcount(mask) % 2 == 0)
                ans += data[id(p)];
            else
                ans -= data[id(p)];
        }

        return ans;
    }
};

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    // コンストラクタ: 要素数nの集合を作成
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1); // 初期ランクは1
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // 各要素は自分自身が親
        }
    }

    // Find: xが属する集合の代表を返す（経路圧縮付き）
    int find(int x) {
        if (parent[x] == x) {
            return x;
        } else {
            // 経路圧縮：再帰的に親を探して更新
            return parent[x] = find(parent[x]);
        }
    }

    // Union: xとyの集合を統合する（ランク付き）
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // ランクの高い方に統合
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                // ランクが同じ場合、どちらかに統合しランクを上げる
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    // 同じ集合に属しているかを判定する
    bool isSameSet(int x, int y) {
        return find(x) == find(y);
    }
};

template <typename T>
class SegmentTreeSum {
private:
    std::vector<T> tree; // セグメントツリー
    int size; // 配列のサイズ

    // セグメントツリーの構築
    void build(const std::vector<T>& arr, int node, int start, int end) {
        if (start == end) {
            // 葉ノードの場合
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            // 左右の子ノードを再帰的に構築
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            // 子ノードをマージ
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // 範囲クエリ
    T query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            // 範囲外の場合
            return 0;
        }
        if (l <= start && end <= r) {
            // 完全に範囲内の場合
            return tree[node];
        }
        // 範囲が部分的に重なる場合
        int mid = (start + end) / 2;
        T leftSum = query(2 * node + 1, start, mid, l, r);
        T rightSum = query(2 * node + 2, mid + 1, end, l, r);
        return leftSum + rightSum;
    }

    // 値の更新
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            // 葉ノードを更新
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                // 左部分木を更新
                update(2 * node + 1, start, mid, idx, val);
            } else {
                // 右部分木を更新
                update(2 * node + 2, mid + 1, end, idx, val);
            }
            // 子ノードの値を基に現在のノードを更新
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

public:
    // コンストラクタ: 配列を受け取り、セグメントツリーを構築
    SegmentTreeSum(const std::vector<T>& arr) {
        size = arr.size();
        tree.resize(4 * size);
        build(arr, 0, 0, size - 1);
    }

    // 範囲クエリの公開メソッド
    long long query(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    // 値の更新の公開メソッド
    void update(int idx,T val){update(0,0,size-1,idx,val);} 
    void add(int idx,T delta){update(idx, query(idx,idx)+delta);}
};
class SegmentTreeMax {
private:
    std::vector<long long> tree; // セグメントツリー（区間の最大値）
    int size; // 配列のサイズ

    // セグメントツリーの構築
    void build(const std::vector<long long>& arr, int node, int start, int end) {
        if (start == end) {
            // 葉ノードの場合
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            // 左右の子ノードを再帰的に構築
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            // 子ノードをマージ（最大値を保持）
            tree[node] = std::max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    // 範囲クエリ（最大値を取得）
    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            // 範囲外の場合（最小値を返す）
            return LLONG_MIN;
        }
        if (l <= start && end <= r) {
            // 完全に範囲内の場合
            return tree[node];
        }
        // 範囲が部分的に重なる場合
        int mid = (start + end) / 2;
        long long leftMax = query(2 * node + 1, start, mid, l, r);
        long long rightMax = query(2 * node + 2, mid + 1, end, l, r);
        return std::max(leftMax, rightMax); // 最大値を取得
    }

    // 値の更新
    void update(int node, int start, int end, int idx, long long val) {
        if (start == end) {
            // 葉ノードを更新
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                // 左部分木を更新
                update(2 * node + 1, start, mid, idx, val);
            } else {
                // 右部分木を更新
                update(2 * node + 2, mid + 1, end, idx, val);
            }
            // 親ノードの値を更新（最大値を保持）
            tree[node] = std::max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

public:
    // コンストラクタ: 配列を受け取り、セグメントツリーを構築
    SegmentTreeMax(const std::vector<long long>& arr) {
        size = arr.size();
        tree.resize(4 * size);
        build(arr, 0, 0, size - 1);
    }

    // 範囲クエリ（最大値）の公開メソッド
    long long query(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    // 値の更新の公開メソッド
    void update(int idx,long long val){update(0,0,size-1,idx,val);} 
    void add(int idx,long long delta){update(idx, query(idx,idx)+delta);}
};
class SegmentTreeMin {
private:
    std::vector<long long> tree; // セグメントツリー（区間の最小値）
    int size; // 配列のサイズ

    // セグメントツリーの構築
    void build(const std::vector<long long>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = std::min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    // 範囲クエリ（最小値を取得）
    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return LLONG_MAX; // 範囲外なら最大値を返す（最小値を取るため）
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        long long leftMin = query(2 * node + 1, start, mid, l, r);
        long long rightMin = query(2 * node + 2, mid + 1, end, l, r);
        return std::min(leftMin, rightMin); // 最小値を取得
    }

    // 値の更新
    void update(int node, int start, int end, int idx, long long val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, val);
            } else {
                update(2 * node + 2, mid + 1, end, idx, val);
            }
            tree[node] = std::min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

public:
    SegmentTreeMin(const std::vector<long long>& arr) {
        size = arr.size();
        tree.resize(4 * size);
        build(arr, 0, 0, size - 1);
    }

    long long query(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void update(int idx,long long val){update(0,0,size-1,idx,val);} 
    void add(int idx,long long delta){update(idx, query(idx,idx)+delta);}
};
class SegmentTreeRollingHash {
private:
    using ull = unsigned long long;

    struct Node {
        ull hash; // 区間ハッシュ
        int len;  // 区間長
    };

    std::vector<Node> tree;
    std::vector<ull> power; // BASE の累乗
    int size;

    static constexpr ull BASE = 1000003;

    // 2つのノードをマージ
    Node merge(const Node& left, const Node& right) {
        Node res;
        res.len = left.len + right.len;

        // 左 hash を桁シフトして右を連結
        res.hash = left.hash * power[right.len] + right.hash;

        return res;
    }

    // セグメントツリー構築
    void build(const std::string& s, int node, int start, int end) {
        if (start == end) {
            tree[node] = {static_cast<ull>(s[start]), 1};
        } else {
            int mid = (start + end) / 2;

            build(s, 2 * node + 1, start, mid);
            build(s, 2 * node + 2, mid + 1, end);

            tree[node] = merge(
                tree[2 * node + 1],
                tree[2 * node + 2]
            );
        }
    }

    // 範囲ハッシュ取得
    Node query(int node, int start, int end, int l, int r) {
        // 完全に範囲外
        if (r < start || end < l) {
            return {0, 0};
        }

        // 完全に範囲内
        if (l <= start && end <= r) {
            return tree[node];
        }

        int mid = (start + end) / 2;

        Node leftNode = query(2 * node + 1, start, mid, l, r);
        Node rightNode = query(2 * node + 2, mid + 1, end, l, r);

        return merge(leftNode, rightNode);
    }

    // 1文字更新
    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {static_cast<ull>(ch), 1};
        } else {
            int mid = (start + end) / 2;

            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, ch);
            } else {
                update(2 * node + 2, mid + 1, end, idx, ch);
            }

            tree[node] = merge(
                tree[2 * node + 1],
                tree[2 * node + 2]
            );
        }
    }

public:
    // コンストラクタ
    SegmentTreeRollingHash(const std::string& s) {
        size = s.size();

        tree.resize(4 * size);

        // BASE^i を前計算
        power.resize(size + 1);
        power[0] = 1;

        for (int i = 1; i <= size; ++i) {
            power[i] = power[i - 1] * BASE;
        }

        build(s, 0, 0, size - 1);
    }

    // 区間ハッシュ取得
    ull query(int l, int r) {
        return query(0, 0, size - 1, l, r).hash;
    }

    // 文字更新
    void update(int idx, char ch) {
        update(0, 0, size - 1, idx, ch);
    }
};

class LazySegmentTreeSum {
private:
    int n;                           // 配列のサイズ
    vector<long long> tree;          // セグメントツリーのデータ
    vector<long long> lazy;          // 遅延評価用のデータ

    // 区間の合計を計算する (加算クエリに対応)
    void apply(int node, int start, int end, long long value) {
        tree[node] += value * (end - start + 1); // ノードの値を更新
        if (start != end) { // 子ノードが存在する場合
            lazy[node * 2] += value;     // 左の子ノードに遅延を追加
            lazy[node * 2 + 1] += value; // 右の子ノードに遅延を追加
        }
    }

    // 遅延を伝播する
    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) { // 遅延が存在する場合
            apply(node, start, end, lazy[node]);
            lazy[node] = 0; // 遅延をクリア
        }
    }

    // 区間更新 (内部)
    void updateRange(int node, int start, int end, int l, int r, long long value) {
        propagate(node, start, end); // 遅延を反映

        if (start > r || end < l) return; // 完全に範囲外
        if (start >= l && end <= r) {     // 完全に範囲内
            apply(node, start, end, value);
            return;
        }

        // 部分的に範囲内
        int mid = (start + end) / 2;
        updateRange(node * 2, start, mid, l, r, value);
        updateRange(node * 2 + 1, mid + 1, end, l, r, value);
        tree[node] = tree[node * 2] + tree[node * 2 + 1]; // 子ノードの結果を合成
    }

    // 区間クエリ (内部)
    long long queryRange(int node, int start, int end, int l, int r) {
        propagate(node, start, end); // 遅延を反映

        if (start > r || end < l) return 0; // 完全に範囲外
        if (start >= l && end <= r) return tree[node]; // 完全に範囲内

        // 部分的に範囲内
        int mid = (start + end) / 2;
        long long left = queryRange(node * 2, start, mid, l, r);
        long long right = queryRange(node * 2 + 1, mid + 1, end, l, r);
        return left + right; // 子ノードの結果を合成
    }

public:
    LazySegmentTreeSum(int size) {
        n = size;
        tree.resize(4 * n, 0); // セグメントツリーのサイズ
        lazy.resize(4 * n, 0); // 遅延配列のサイズ
    }

    // 区間更新
    void update(int l, int r, long long value) {
        updateRange(1, 0, n - 1, l, r, value);
    }

    // 区間クエリ
    long long query(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};
class LazySegmentTreeMax {
private:
    int n;                            // 配列サイズ
    vector<long long> tree;           // 区間最大値
    vector<long long> lazy;           // 遅延加算

    // 遅延値をノードに適用
    void apply(int node, int start, int end, long long value) {
        tree[node] += value;          // 最大値に加算
        if (start != end) {           // 葉でなければ子へ遅延伝播
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
    }

    // 遅延伝播
    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            apply(node, start, end, lazy[node]);
            lazy[node] = 0;
        }
    }

    // 区間更新
    void updateRange(int node, int start, int end,
                     int l, int r, long long value) {
        propagate(node, start, end);

        if (start > r || end < l) return; // 範囲外

        if (start >= l && end <= r) {     // 完全包含
            apply(node, start, end, value);
            return;
        }

        int mid = (start + end) / 2;
        updateRange(node * 2, start, mid, l, r, value);
        updateRange(node * 2 + 1, mid + 1, end, l, r, value);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    // 区間クエリ
    long long queryRange(int node, int start, int end,
                         int l, int r) {
        propagate(node, start, end);

        if (start > r || end < l) return LLONG_MIN; // 単位元
        if (start >= l && end <= r) return tree[node];

        int mid = (start + end) / 2;
        long long left = queryRange(node * 2, start, mid, l, r);
        long long right = queryRange(node * 2 + 1, mid + 1, end, l, r);

        return max(left, right);
    }

public:
    LazySegmentTreeMax(int size) {
        n = size;
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    // 区間加算
    void update(int l, int r, long long value) {
        updateRange(1, 0, n - 1, l, r, value);
    }

    // 区間最大値取得
    long long query(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};
class LazySegmentTreeMin {
private:
    int n;                            // 配列のサイズ
    vector<long long> tree;           // 区間最小値を保持
    vector<long long> lazy;           // 遅延加算を保持

    // 遅延を適用
    void apply(int node, int start, int end, long long value) {
        tree[node] += value; // 区間の最小値を一括加算
        if (start != end) { // 葉でなければ子に遅延を伝える
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
    }

    // 遅延を伝播
    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            apply(node, start, end, lazy[node]);
            lazy[node] = 0;
        }
    }

    // 区間更新 (内部)
    void updateRange(int node, int start, int end, int l, int r, long long value) {
        propagate(node, start, end);

        if (start > r || end < l) return; // 範囲外
        if (start >= l && end <= r) {     // 完全に範囲内
            apply(node, start, end, value);
            return;
        }

        int mid = (start + end) / 2;
        updateRange(node * 2, start, mid, l, r, value);
        updateRange(node * 2 + 1, mid + 1, end, l, r, value);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    // 区間クエリ (内部)
    long long queryRange(int node, int start, int end, int l, int r) {
        propagate(node, start, end);

        if (start > r || end < l) return LLONG_MAX; // 範囲外は無限大
        if (start >= l && end <= r) return tree[node];

        int mid = (start + end) / 2;
        long long left = queryRange(node * 2, start, mid, l, r);
        long long right = queryRange(node * 2 + 1, mid + 1, end, l, r);
        return min(left, right);
    }

public:
    LazySegmentTreeMin(int size) {
        n = size;
        tree.resize(4 * n, 0);  // 区間最小値 (初期値は0で構築)
        lazy.resize(4 * n, 0);  // 遅延配列
    }

    // 区間更新
    void update(int l, int r, long long value) {
        updateRange(1, 0, n - 1, l, r, value);
    }

    // 区間クエリ
    long long query(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};
class LazySegmentTreeSumSquare {
private:
    int n;
    struct Node {
        long long sum;
        long long sumsq;
    };

    vector<Node> tree;
    vector<long long> lazy;

    void apply(int node, int start, int end, long long value) {
        long long len = end - start + 1;

        tree[node].sumsq += 2 * value * tree[node].sum + value * value * len;
        tree[node].sum += value * len;

        if (start != end) {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
    }

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            apply(node, start, end, lazy[node]);
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int start, int end, int l, int r, long long value) {
        propagate(node, start, end);

        if (start > r || end < l) return;

        if (start >= l && end <= r) {
            apply(node, start, end, value);
            return;
        }

        int mid = (start + end) / 2;
        updateRange(node * 2, start, mid, l, r, value);
        updateRange(node * 2 + 1, mid + 1, end, l, r, value);

        tree[node].sum = tree[node * 2].sum + tree[node * 2 + 1].sum;
        tree[node].sumsq = tree[node * 2].sumsq + tree[node * 2 + 1].sumsq;
    }

    Node queryRange(int node, int start, int end, int l, int r) {
        propagate(node, start, end);

        if (start > r || end < l) return {0, 0};

        if (start >= l && end <= r) return tree[node];

        int mid = (start + end) / 2;
        Node left = queryRange(node * 2, start, mid, l, r);
        Node right = queryRange(node * 2 + 1, mid + 1, end, l, r);

        return {
            left.sum + right.sum,
            left.sumsq + right.sumsq
        };
    }

public:
    LazySegmentTreeSumSquare(int size) {
        n = size;
        tree.resize(4 * n, {0, 0});
        lazy.resize(4 * n, 0);
    }

    void update(int l, int r, long long value) {
        updateRange(1, 0, n - 1, l, r, value);
    }

    long long query(int l, int r) {
        return queryRange(1, 0, n - 1, l, r).sumsq;
    }
};

int main()
{
    auto[n,q] = re.ll2();
    vector<vector<tuple<ll,ll>>> con(n);
    vector<ll> cntIn(n,0);
    
    while(q--)
    {
        auto[t,u,v] = re.ll3();
        u--; v--;

        con.at(u).push_back({v,t});
        cntIn.at(v)++;
    }

    vector<ll> ans(n,-1);

    for(int i = 0; i < n; i++)
    {
        queue<ll> que;
        vector<ll> memo(n,-1);
        set<ll> seen;
        if(ans.at(i) == -1)
        {
            memo.at(i) = 0;
            seen.insert(i);
            que.push(i);
        }
        else continue;

        ll delta = 0;

        while(que.size())
        {
            int v = que.front();
            que.pop();

            for(auto[u,t] : con.at(v))
            {
                memo.at(u) = max(memo.at(u), memo.at(v)+t);
                seen.insert(u);
                
                cntIn.at(u)--;
                if(cntIn.at(u) == 0)
                {
                    que.push(u);
                }

                if(ans.at(u) != -1)
                {
                    delta = min(delta, memo.at(u) - ans.at(u));
                }
            }
        }
    }
}