#include <bits/stdc++.h>
using namespace std;

inline void add(int x, int &bal, vector<int> &pend, int &tcnt) {
    bal += x; pend.push_back(+x); ++tcnt;
}
inline void subt(int x, int &bal, vector<int> &pend, int &tcnt) {
    bal -= x; pend.push_back(-x); ++tcnt;
}
inline void kill(int k, int &bal, vector<int> &pend, int committed) {
    int j = k - committed;
    if (j >= 1 && j <= (int)pend.size() && pend[j-1] != 0) {
        bal -= pend[j-1];
        pend[j-1] = 0;
    }
}
inline void save(int bal, vector<int> &snaps, vector<int> &pend, int &committed, int tcnt) {
    snaps.push_back(bal);
    committed = tcnt;
    pend.clear();
}
inline void backto(int k, int &bal, vector<int> &pend, const vector<int> &snaps) {
    if (k >= 1 && k <= (int)snaps.size()) {
        bal = snaps[k-1];
        pend.clear();
    }
}

int main() {
 
    int bal, q;
    if (!(cin >> bal)) return 0;
    cin >> q;

    vector<int> pend;    pend.reserve(q);
    vector<int> snaps;   snaps.reserve(q);
    vector<int> outv;    outv.reserve(q);

    int tcnt = 0, committed = 0;

    for (int i = 0; i < q; ++i) {
        string op; cin >> op;
        if (op == "read") {
            outv.push_back(bal);
        } else if (op == "credit") {
            int x; cin >> x;
            add(x, bal, pend, tcnt);
        } else if (op == "debit") {
            int x; cin >> x;
            subt(x, bal, pend, tcnt);
        } else if (op == "abort") {
            int k; cin >> k;
            kill(k, bal, pend, committed);
        } else if (op == "rollback") {
            int k; cin >> k;
            backto(k, bal, pend, snaps);
        } else if (op == "commit") {
            save(bal, snaps, pend, committed, tcnt);
        }
    }

    for (size_t i = 0; i < outv.size(); ++i) {
        if (i) cout << '\n';
        cout << outv[i];
    }
    return 0;
}
