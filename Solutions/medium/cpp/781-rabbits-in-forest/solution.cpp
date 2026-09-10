class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            //agrupar chaves iguais, normalmente vamos somar chave + 1, a nao ser quando temos ocorrencias maior que chave nesse caso soma-se as ocorrencias
            unordered_map<int,int> frequecyMap;
    
            for (const auto& n : answers)
                frequecyMap[n]++;
            
            int minAmount = 0;
    
            for (const auto& [amount, freq] : frequecyMap)
            {   //amount + 1 can be seen as the group size xd
                if (freq > amount)
                {
                    int group = freq/(amount+1);
                    minAmount += group * (amount+1);
                    int rest = freq % (amount+1);
                    if(rest > 0){
                        minAmount += amount+1;
                    }
                }
                else
                    minAmount += amount + 1;
            }
            return minAmount;
        }
    };