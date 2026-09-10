class Solution {
public:
    using ll = long long;
    using It = list<pair<ll,int>>::iterator;
    using T  = tuple<ll, int, It>; // {soma, id_esquerdo, iterador_esquerdo}

    struct Compare {
        // min-heap: menor soma primeiro, depois leftmost (menor id)
        bool operator()(const T& a, const T& b) const {
            if (get<0>(a) != get<0>(b))
                return get<0>(a) > get<0>(b);
            return get<1>(a) > get<1>(b);
        }
    };

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        list<pair<ll,int>> lst;  // {valor, id}
        priority_queue<T, vector<T>, Compare> pq;
        unordered_set<int> ids;

        int bad = 0;

        for (int i = 0; i < n; ++i) {
            lst.push_back({nums[i], i});
            ids.insert(i);
            auto it = prev(lst.end());
            
            if (it != lst.begin()) {
                auto L = prev(it);

                if (L->first > it->first)
                    ++bad;

                pq.push({L->first + it->first, L->second, L});
            }
        }

        int ops = 0;

        // loop principal
        while (bad > 0) {
            T cur;

                // lazy deletion: achar par ainda adjacente
            while (true) {
                cur = pq.top();
                pq.pop();

                auto [sum, id, it] = cur;

                // 1) O nó esquerdo já foi removido da lista
                //    → iterator está dangling ou o id não existe mais
                if (!ids.count(id))
                    continue;

                // 2) O iterator não aponta mais para um elemento válido da lista
                //    (normalmente coberto pelo ids, mas barato de checar)
                if (it == lst.end())
                    continue;

                // 3) O nó esquerdo não tem mais vizinho à direita
                //    -> não existe mais par adjacente
                if (next(it) == lst.end())
                    continue;

                // 4) O par ainda é adjacente, mas NÃO é o mesmo par
                //    -> o vizinho da direita mudou depois de merges
                //    -> a soma armazenada no heap está obsoleta
                if (it->first + next(it)->first != sum)
                    continue;

                // Se passou por tudo isso, o par é válido
                break;
            }

            auto it = get<2>(cur);
            auto jt = next(it);

            auto L = (it == lst.begin() ? lst.end() : prev(it));
            auto R = next(jt);

            // ---- remover violações antigas ----
            if (L != lst.end() && L->first > it->first) bad--;
            if (it->first > jt->first) bad--;
            if (R != lst.end() && jt->first > R->first) bad--;

            // ---- merge ----
            it->first += jt->first;
            ids.erase(jt->second);
            lst.erase(jt);

            // ---- adicionar novas violações ----
            if (L != lst.end() && L->first > it->first) bad++;
            if (R != lst.end() && it->first > R->first) bad++;

            // ---- adicionar novos pares ----
            if (L != lst.end())
                pq.push({L->first + it->first, L->second, L});
            if (R != lst.end())
                pq.push({it->first + R->first, it->second, it});

            ops++;
        }

        return ops;
    }
};