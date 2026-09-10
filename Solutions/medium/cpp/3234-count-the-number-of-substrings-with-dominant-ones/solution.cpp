class Solution {
public:
    int numberOfSubstrings(string s) {
        const int n = s.length();
        long long ans = 0;

        // zero = quantidade de '0' no substring
        // só faz sentido enquanto zero + zero^2 <= n (senão não cabe)
        for (int zero = 0; zero + zero * zero <= n; ++zero) {
            int lastInvalidPos = -1;   // última posição onde estouramos a condição
            int count0 = 0, count1 = 0;
            int l = 0;

            for (int r = 0; r < n; ++r) {
                // expandimos a janela para a direita
                if (s[r] == '0') ++count0;
                else ++count1;

                // tentamos mover l para direita, mantendo a janela "mínima"
                for (; l < r; ++l) {
                    if (s[l] == '0' && count0 > zero) {
                        // temos 0 demais, remover esse 0 é obrigatório
                        --count0;
                        lastInvalidPos = l;
                    } else if (s[l] == '1' && count1 - 1 >= zero * zero) {
                        // podemos remover esse 1 e ainda manter count1 >= zero^2
                        --count1;
                    } else {
                        // não dá pra remover mais nada sem quebrar as condições
                        break;
                    }
                }

                // se a janela atual tem exatamente "zero" zeros
                // e pelo menos zero^2 ones, então é válida
                if (count0 == zero && count1 >= zero * zero) {
                    // qualquer início entre (lastInvalidPos+1 .. l) gera substring válido
                    ans += (l - lastInvalidPos);
                }
            }
        }
        return (int)ans;
    }
};
