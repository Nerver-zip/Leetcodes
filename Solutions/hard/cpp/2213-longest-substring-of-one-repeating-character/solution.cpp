class Solution {
private:
    struct Node {
        int len = 0;
        int prefix = 0;
        int suffix = 0;
        int best = 0;

        char leftChar = 0;
        char rightChar = 0;
    };

    int n;
    string s;
    vector<Node> tree;

    Node mergeNodes(const Node& left, const Node& right) {
        if (left.len == 0) return right;
        if (right.len == 0) return left;

        Node res;

        res.len = left.len + right.len;
        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;

        // Inicialmente, prefixo e sufixo ficam dentro
        // dos respectivos lados.
        res.prefix = left.prefix;
        res.suffix = right.suffix;

        // Melhor resposta sem cruzar os intervalos.
        res.best = max(left.best, right.best);

        // Podemos conectar as sequências na fronteira?
        if (left.rightChar == right.leftChar) {
            int connected = left.suffix + right.prefix;

            res.best = max(res.best, connected);

            // Se todo o lado esquerdo é formado pelo mesmo
            // caractere, o prefixo pode continuar no lado direito.
            if (left.prefix == left.len) {
                res.prefix = left.len + right.prefix;
            }

            // Se todo o lado direito é formado pelo mesmo
            // caractere, o sufixo pode continuar no lado esquerdo.
            if (right.suffix == right.len) {
                res.suffix = right.len + left.suffix;
            }
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = {
                1,      // len
                1,      // prefix
                1,      // suffix
                1,      // best
                s[l],   // leftChar
                s[l]    // rightChar
            };
            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = mergeNodes(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    void update(int node, int l, int r, int index, char c) {
        if (l == r) {
            tree[node] = {
                1,
                1,
                1,
                1,
                c,
                c
            };
            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid) {
            update(node * 2, l, mid, index, c);
        } else {
            update(node * 2 + 1, mid + 1, r, index, c);
        }

        tree[node] = mergeNodes(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        this->s = s;
        n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> answer;

        for (int i = 0; i < queryIndices.size(); i++) {
            int index = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, index, c);

            answer.push_back(tree[1].best);
        }

        return answer;
    }
};