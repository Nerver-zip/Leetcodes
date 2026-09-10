class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        const int n = s.size();
        queue<int> q;
        q.push(0);

        for(int i = 1; i < n; ++i){
            if(s[i] == '1')
                continue;
            
            // Eliminar quem não pode atingir i
            while (!q.empty() && q.front() + maxJump < i) {
                q.pop();
            }
            
            // Adicionar quem pode atingir i
            // A fila é feita de moda que se algúem pode,
            // todos podem, só precisamos adicionar uma vez
            if(!q.empty() && q.front() + minJump <= i)
                q.push(i);
        }
            
        return !q.empty() && q.back() == n-1; 
    }
};