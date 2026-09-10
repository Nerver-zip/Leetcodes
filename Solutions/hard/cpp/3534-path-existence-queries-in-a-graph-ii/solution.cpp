class Solution {
public:
    vector<int> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {
        vector<pair<int, int>> nodes;
        nodes.reserve(n);

        for (int originalIndex = 0; originalIndex < n; ++originalIndex) {
            nodes.emplace_back(nums[originalIndex], originalIndex);
        }

        sort(nodes.begin(), nodes.end());

        // rank[originalIndex] = posição do nó depois da ordenação.
        vector<int> rank(n);

        for (int sortedIndex = 0; sortedIndex < n; ++sortedIndex) {
            rank[nodes[sortedIndex].second] = sortedIndex;
        }

        /*
         * component[i] identifica o componente conexo da posição
         * ordenada i.
         *
         * Se existe um gap consecutivo maior que maxDiff, nenhuma
         * aresta pode atravessá-lo.
         */
        vector<int> component(n);

        for (int i = 1; i < n; ++i) {
            component[i] = component[i - 1];

            if (nodes[i].first - nodes[i - 1].first > maxDiff) {
                ++component[i];
            }
        }

        /*
         * jump[0][i] = posição mais distante à direita alcançável
         * com exatamente um salto a partir de i.
         */
        constexpr int LOG = 18; // 2^17 < 1e5 <= 2^18
        vector<array<int, LOG>> jump(n);

        int right = 0;

        for (int left = 0; left < n; ++left) {
            right = max(right, left);

            while (
                right + 1 < n &&
                nodes[right + 1].first - nodes[left].first <= maxDiff
            ) {
                ++right;
            }

            jump[left][0] = right;
        }

        /*
         * jump[i][k] = posição mais distante alcançável a partir
         * de i usando 2^k saltos gulosos.
         */
        for (int k = 1; k < LOG; ++k) {
            for (int i = 0; i < n; ++i) {
                jump[i][k] = jump[jump[i][k - 1]][k - 1];
            }
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& query : queries) {
            int left = rank[query[0]];
            int target = rank[query[1]];

            if (left > target) {
                swap(left, target);
            }

            if (left == target) {
                answer.push_back(0);
                continue;
            }

            if (component[left] != component[target]) {
                answer.push_back(-1);
                continue;
            }

            int distance = 0;
            int current = left;

            /*
             * Aplicamos o maior número possível de saltos sem
             * alcançar o target.
             */
            for (int k = LOG - 1; k >= 0; --k) {
                if (jump[current][k] < target) {
                    current = jump[current][k];
                    distance += 1 << k;
                }
            }

            // Falta exatamente o último salto que alcança target.
            answer.push_back(distance + 1);
        }

        return answer;
    }
};