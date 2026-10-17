// https://github.com/Oe0930/CP

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using str = string;

static int intMin = numeric_limits<int>::min();
static int intMax = numeric_limits<int>::max();
static long long longMin = numeric_limits<long long>::min();
static long long longMax = numeric_limits<long long>::max();
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
    
    ReadArray array;
    ReadMap map;
}; ReadFunctions re;

void write(string s) { printf("%s\n", s.c_str()); }
void write(char c) { printf("%c\n", c); }
void write(int n) { printf("%i\n", n); }
void write(long long n) { printf("%lld\n", n); }
void write(unsigned long long n) { printf("%llu\n", n); }
void write(double n) { printf("%.10f\n", n); }
void write(bool a) { printf("%s\n", a ? "yes" : "no"); }
void writeMinus1() {printf("%i\n", -1);}

/* keysにそってvalueをソート */
template <typename KEY, typename VALUE> void Sort(std::vector<KEY>& keys, std::vector<VALUE>& values) {
    std::vector<std::pair<KEY, VALUE>> paired;
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

int main()
{
    
}