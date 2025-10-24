#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<string> g(n);
    for (int i = 0; i < n; ++i) cin >> g[i];

    auto inb = [&](int r,int c){ return r>=0 && r<n && c>=0 && c<n; };

    int crosses = 0, top1 = 0, top2 = 0;

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < n; ++c) {
            char t = g[r][c];
            if (t != '1' && t != '2') continue;
            char u = (t == '1') ? '2' : '1';

            bool Lt = inb(r,c-1) && g[r][c-1] == t;
            bool Rt = inb(r,c+1) && g[r][c+1] == t;
            bool Ut = inb(r-1,c) && g[r-1][c] == t;
            bool Dt = inb(r+1,c) && g[r+1][c] == t;

            bool Lu = inb(r,c-1) && g[r][c-1] == u;
            bool Ru = inb(r,c+1) && g[r][c+1] == u;
            bool Uu = inb(r-1,c) && g[r-1][c] == u;
            bool Du = inb(r+1,c) && g[r+1][c] == u;

            bool topH = (Lt && Rt && Uu && Du);
            bool topV = (Ut && Dt && Lu && Ru);

            if (topH || topV) {
                ++crosses;
                if (t == '1') ++top1; else ++top2;
            }
        }
    }

    if (crosses == 0) { cout << 0; return 0; }
    if (top1 > 0 && top2 > 0) { cout << "Impossible"; return 0; }
    cout << crosses;
    return 0;
}
