struct Rect {
    int minr, maxr, minc, maxc;
    bool ok;
    Rect(): minr(INT_MAX), maxr(INT_MIN), minc(INT_MAX), maxc(INT_MIN), ok(false) {}
    void add(int r, int c){
        ok = true;
        minr = min(minr, r);
        maxr = max(maxr, r);
        minc = min(minc, c);
        maxc = max(maxc, c);
    }
    long long area() const {
        if(!ok) return 0;
        return 1LL * (maxr - minr + 1) * (maxc - minc + 1);
    }
};

class Solution {
public:
    long long minimumSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int,int>> ones;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1) ones.push_back({i,j});
        if(ones.empty()) return 0;

        long long ans = LLONG_MAX;

        auto eval = [&](auto getGroup){
            Rect A,B,C;
            for(auto [r,c] : ones){
                int g = getGroup(r,c);
                if(g==0) A.add(r,c);
                if(g==1) B.add(r,c);
                if(g==2) C.add(r,c);
            }
            if(!A.ok || !B.ok || !C.ok) return; // precisa ter pelo menos um em cada
            ans = min(ans, A.area()+B.area()+C.area());
        };

        // 1) 3 horizontais
        for(int r1=0; r1<n-2; r1++){
            for(int r2=r1+1; r2<n-1; r2++){
                eval([&](int r,int c){
                    if(r<=r1) return 0;
                    if(r<=r2) return 1;
                    return 2;
                });
            }
        }

        // 2) 3 verticais
        for(int c1=0; c1<m-2; c1++){
            for(int c2=c1+1; c2<m-1; c2++){
                eval([&](int r,int c){
                    if(c<=c1) return 0;
                    if(c<=c2) return 1;
                    return 2;
                });
            }
        }

        // 3) T para baixo (top dividido em 2, bottom inteiro)
        for(int r=0; r<n-1; r++){
            for(int c=0; c<m-1; c++){
                eval([&](int rr,int cc){
                    if(rr<=r && cc<=c) return 0;
                    if(rr<=r && cc>c) return 1;
                    return 2; // rr>r
                });
            }
        }

        // 4) T para cima (bottom dividido em 2, top inteiro)
        for(int r=0; r<n-1; r++){
            for(int c=0; c<m-1; c++){
                eval([&](int rr,int cc){
                    if(rr<=r) return 0;
                    if(rr>r && cc<=c) return 1;
                    return 2;
                });
            }
        }

        // 5) ⊣ (left inteiro, right dividido)
        for(int r=0; r<n-1; r++){
            for(int c=0; c<m-1; c++){
                eval([&](int rr,int cc){
                    if(cc<=c) return 0;
                    if(cc>c && rr<=r) return 1;
                    return 2;
                });
            }
        }

        // 6) ⊢ (right inteiro, left dividido)
        for(int r=0; r<n-1; r++){
            for(int c=0; c<m-1; c++){
                eval([&](int rr,int cc){
                    if(cc>c) return 0;
                    if(cc<=c && rr<=r) return 1;
                    return 2;
                });
            }
        }

        return ans;
    }
};
