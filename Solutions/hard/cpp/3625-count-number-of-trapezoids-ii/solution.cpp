class Solution {
public:
    using ll = long long;

    // Normaliza o vetor (dx, dy) que representa o slope.
    // Regras:
    //   - Verticais viram (0, 1)
    //   - Horizontais viram (1, 0)
    //   - Mantemos dx > 0 sempre que possível para fixar o sinal
    //   - Reduz via gcd
    static pair<ll,ll> normSlope(ll dx, ll dy) {
        if (dx == 0) return {0, 1};       // linha vertical
        if (dy == 0) return {1, 0};       // linha horizontal

        // fixa o sinal: dx > 0
        if (dx < 0) dx = -dx, dy = -dy;

        ll g = std::gcd(std::llabs(dx), std::llabs(dy));
        dx /= g;
        dy /= g;

        return {dx, dy};
    }

    // Calcula o "intercepto" da reta usando o slope normalizado.
    // Para slope = (sx, sy) representando dy/dx:
    //
    //   - Se slope for vertical (sx == 0):
    //         intercepto é simplesmente x = constante
    //
    //   - Caso geral:
    //         b = y - kx = (y*sx - x*sy) / sx
    //
    // Retorna intercepto reduzido como par (num, den).
    static pair<ll,ll> intercept_from_slope_point(const pair<ll,ll>& slope,
                                                  ll x1, ll y1) {
        ll sx = slope.first, sy = slope.second;

        if (sx == 0) {
            // linha vertical: x = constante
            return {x1, 1};
        }

        // b = (y*sx - x*sy) / sx
        ll num = y1 * sx - x1 * sy;
        ll den = sx;

        // força den > 0
        if (den < 0) { num = -num; den = -den; }

        ll g = std::gcd(std::llabs(num), std::llabs(den));
        if (g != 0) { num /= g; den /= g; }

        return {num, den};
    }

    // Hash seguro para pair<ll,ll>
    struct PairHash {
        size_t operator()(pair<ll,ll> const& p) const noexcept {
            // combinação estilo boost
            auto h1 = std::hash<ll>{}(p.first);
            auto h2 = std::hash<ll>{}(p.second);
            return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1<<6) + (h1>>2));
        }
    };

    long long countTrapezoids(vector<vector<int>>& pts) {
        int n = pts.size();
        if (n < 4) return 0;

        // slope -> lista de interceptos das retas que aparecem nos segmentos
        unordered_map<pair<ll,ll>, vector<pair<ll,ll>>, PairHash> slope_to_b;

        // midpoint -> lista de slopes (para detectar paralelogramos)
        unordered_map<pair<ll,ll>, vector<pair<ll,ll>>, PairHash> mid_to_slopes;

        slope_to_b.reserve(n * n / 4 + 1);
        mid_to_slopes.reserve(n * n / 4 + 1);

        // Percorre todos os segmentos (i,j)
        for (int i = 0; i < n; ++i) {
            ll x1 = pts[i][0], y1 = pts[i][1];

            for (int j = i + 1; j < n; ++j) {
                ll x2 = pts[j][0], y2 = pts[j][1];
                ll dx = x2 - x1, dy = y2 - y1;

                auto slope = normSlope(dx, dy);
                auto b     = intercept_from_slope_point(slope, x1, y1);

                slope_to_b[slope].push_back(b);

                // Usamos midpoint como (x1+x2, y1+y2) sem dividir por 2
                // Dois segmentos têm o mesmo midpoint <=> formam um paralelogramo
                pair<ll,ll> mid = {x1 + x2, y1 + y2};
                mid_to_slopes[mid].push_back(slope);
            }
        }

        long long ans = 0;

        // 1) Conta pares de segmentos paralelos que NÃO são colineares
        //    = candidatos a bases do trapézio
        for (auto &it : slope_to_b) {
            const auto &vec = it.second;
            if (vec.size() <= 1) continue;

            unordered_map<pair<ll,ll>, int, PairHash> freq;
            freq.reserve(vec.size() * 2);

            // conta interceptos iguais
            for (auto &b : vec) freq[b]++;

            // conta pares de interceptos diferentes: sum_{a<b} (cnt[a] * cnt[b])
            long long prefix = 0;
            for (auto &p : freq) {
                int c = p.second;
                ans += prefix * c;
                prefix += c;
            }
        }

        // 2) Subtrai paralelogramos (casos onde as duas bases são "espelhadas")
        for (auto &it : mid_to_slopes) {
            const auto &vec = it.second;
            if (vec.size() <= 1) continue;

            unordered_map<pair<ll,ll>, int, PairHash> freq;
            freq.reserve(vec.size() * 2);

            // conta slopes iguais dentro do mesmo midpoint
            for (auto &s : vec) freq[s]++;

            // subtrai combinações internas
            long long prefix = 0;
            for (auto &p : freq) {
                int c = p.second;
                ans -= prefix * c;
                prefix += c;
            }
        }

        return ans;
    }
};