/**
 * “Sometimes life is like this dark tunnel. 
 *  You can't always see the light at the end of the tunnel, 
 *  but if you just keep moving... 
 *  you will come to a better place.” - Uncle Iroh, ATLA
 */

#include <bits/stdc++.h>

using namespace std;

// utility macros
#define sz(c) int(size(c))
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define range(c, b, e) next(begin(c), b), next(begin(c), e)

// debug utilities
// #define ONLINE_JUDGE 1
#ifndef ONLINE_JUDGE
#define dbg(args...) { __dbg_print(__dbg_tokenize(#args), args); }
vector<string> __dbg_tokenize(const string& s) {
    const regex re("\\s*[,]\\s+");
    return vector<string>(sregex_token_iterator(s.begin(), s.end(), re, -1), sregex_token_iterator());
}
template <typename... Args>
void __dbg_print(const vector<string>& argsName, const Args&... args) {
    auto itr = argsName.begin();
    cerr << ">> ";
    ((cerr << *itr++ << " = " << args << (itr != argsName.end() ? ", " : "\n")), ...);
    cerr.flush();
}
#else
#define dbg(args...)
#endif

// type aliases
using ll = long long;

// globals
const ll MOD = 1'000'000'007;

// utility functions
template <typename T> inline T ceil(T x, T y);
template <typename T1, typename T2> istream& operator>>(istream& is, pair<T1, T2>& p);
template <typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p);
template <typename T> istream& operator>>(istream& is, vector<T>& v);
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v);
template <typename T, typename V> ostream& operator<<(ostream& os, const set<T, V>& st);
template <typename T, typename V> ostream& operator<<(ostream& os, const multiset<T, V>& mst);
template <typename T1, typename T2, typename V> ostream& operator<<(ostream& os, const map<T1, T2, V>& mp);
template <typename T1, typename T2, typename V> ostream& operator<<(ostream& os, const multimap<T1, T2, V>& mmp);


void precalc() {}

void solve() {
    
}


int main() { 
	// fast i/o
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// file i/o
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int tc = 1;
	// cin >> tc;

	precalc();

	for (int t = 1; t <= tc; ++t) {
		solve();
		// cout << endl;
	}
	cout << "All OK!" << endl;

	return 0;
}


template <typename T> 
inline T ceil(T x, T y) {
	return (x + y - 1) / y;
}

template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
    is >> p.first >> p.second;
    return is;
}

template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) {
        is >> x;
    }
    return is;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    int i = 0, n = sz(v);
    if (os.rdbuf() == cout.rdbuf()) {
        for (; i < sz(v); ++i) {
            os << v[i] << ((i != n-1) ? " " : "");
        }
    }
    else {
        os << "[";
        for (; i < n; ++i) {
            os << v[i] << ((i != n-1) ? ", " : "");
        }
        os << "]";
    }
    return os;
}

template <typename T, typename V>
ostream& operator<<(ostream& os, const set<T, V>& st) {
    int i = 0, n = sz(st);
    os << "{";
    for (auto& x : st) {
        os << x << ((i != n-1) ? ", " : "");
        ++i;
    }
    os << "}";
    return os;
}

template <typename T, typename V>
ostream& operator<<(ostream& os, const multiset<T, V>& mst) {
    int i = 0, n = sz(mst);
    os << "{";
    for (auto& x : mst) {
        os << x << ((i != n-1) ? ", " : "");
        ++i;
    }
    os << "}";
    return os;
}

template <typename T1, typename T2, typename V>
ostream& operator<<(ostream& os, const map<T1, T2, V>& mp) {
    int i = 0, n = sz(mp);
    os << "{";
    for (auto& [k,v] : mp) {
        os << "{" << k << "," << v << "}" << ((i != n-1) ? ", " : "");
        ++i;
    }
    os << "}";
    return os;
}

template <typename T1, typename T2, typename V>
ostream& operator<<(ostream& os, const multimap<T1, T2, V>& mmp) {
    int i = 0, n = sz(mmp);
    os << "{";
    for (auto& [k,v] : mmp) {
        os << "{" << k << "," << v << "}" << ((i != n-1) ? ", " : "");
        ++i;
    }
    os << "}";
    return os;
}
