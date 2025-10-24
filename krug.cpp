#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define fast_io ios::sync_with_stdio(false); cin.tie(0);

static inline ll manh_dist(ll a, ll b, ll c, ll d){   // Krug (4-dir)
    return llabs(a - c) + llabs(b - d);
}
static inline ll D_ka_dist(ll a, ll b, ll c, ll d){   // Doran (8-dir)
    return max(llabs(a - c), llabs(b - d));
}

int main() {
    fast_io
    int t;
    cin >> t;
    while (t--) {
        ll n;                           // n can be up to 1e9
        cin >> n;
        ll rk, ck, rd, cd;
        cin >> rk >> ck >> rd >> cd;

        // ---- Infinite survival check: any corner with TK < TD (strict)?
        ll cx[4] = {0, 0, n, n};
        ll cy[4] = {0, n, 0, n};

        bool is_at_corner = ((rk==0 || rk==n) && (ck==0 || ck==n));
        bool cornerTrap = is_at_corner && (D_ka_dist(rk, ck, rd, cd) == 1);
        ll ans = (ll)4e18;
        bool infinite = false;
        if(!cornerTrap){
            for(int i=0;i<4;i++){
                ll TK = manh_dist(rk, ck, cx[i], cy[i]);     // Krug time (L1)
                ll TD = D_ka_dist(rd, cd, cx[i], cy[i]);     // Doran time (Linf)
                if(TK < TD){
                    ans = -1;
                    break;
                }
            }
        }

     
        

        for(int i=0;i<4;i++){
            ll TK = manh_dist(rk, ck, cx[i], cy[i]);
            ll TD = D_ka_dist(rd, cd, cx[i], cy[i]);
            if(TK >= TD) ans = min(ans, (ll)TK);
        }

        // 2) Sides from Krug's row/col (only the side "away from Doran" gives best chance)
        //    sides: (0,ck)=up, (n,ck)=down, (rk,0)=left, (rk,n)=right
        bool a = false;

        // up side if D is below
        if(rd > rk){
            a = true;
            ll x = 0, y = ck;
            ll TK = manh_dist(rk, ck, x, y);
            ll TD = D_ka_dist(rd, cd, x, y);
            ans = min(ans, (TK < TD) ? (TK + 1) : TK);
        }
        // down side if D is above
        if(rd < rk){
            a = true;
            ll x = n, y = ck;
            ll TK = manh_dist(rk, ck, x, y);
            ll TD = D_ka_dist(rd, cd, x, y);
            ans = min(ans, (TK < TD) ? (TK + 1) : TK);
        }
        // left side if D is right
        if(cd > ck){
            a = true;
            ll x = rk, y = 0;
            ll TK = manh_dist(rk, ck, x, y);
            ll TD = D_ka_dist(rd, cd, x, y);
            ans = min(ans, (TK < TD) ? (TK + 1) : TK);
        }
        // right side if D is left
        if(cd < ck){
            a = true;
            ll x = rk, y = n;
            ll TK = manh_dist(rk, ck, x, y);
            ll TD = D_ka_dist(rd, cd, x, y);
            ans = min(ans, (TK < TD) ? (TK + 1) : TK);
        }

        // 3) If no away-side applied (rare), consider all four sides as fallback
        if(!a){
            // up
            {
                ll x = 0, y = ck;
                ll TK = manh_dist(rk, ck, x, y);
                ll TD = D_ka_dist(rd, cd, x, y);
                ans = min(ans, (TK < TD) ? (TK + 1) : TK);
            }
            // down
            {
                ll x = n, y = ck;
                ll TK = manh_dist(rk, ck, x, y);
                ll TD = D_ka_dist(rd, cd, x, y);
                ans = min(ans, (TK < TD) ? (TK + 1) : TK);
            }
            // left
            {
                ll x = rk, y = 0;
                ll TK = manh_dist(rk, ck, x, y);
                ll TD = D_ka_dist(rd, cd, x, y);
                ans = min(ans, (TK < TD) ? (TK + 1) : TK);
            }
            // right
            {
                ll x = rk, y = n;
                ll TK = manh_dist(rk, ck, x, y);
                ll TD = D_ka_dist(rd, cd, x, y);
                ans = min(ans, (TK < TD) ? (TK + 1) : TK);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
