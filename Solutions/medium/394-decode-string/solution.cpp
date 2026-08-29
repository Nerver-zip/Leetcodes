class Solution {
public:
    string decodeString(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '[')
                st.push(i);
            else if(s[i] == ']'){
                closingIdx[st.top()] = i;
                st.pop();
            }
        }
        
        decode(s, 0, 1, s.size());
        return ans;
    }
private:
    string ans;
    unordered_map<int, int> closingIdx;

    void decode(string& s, int index, int amount, int size){
        while(amount){
            string num;
            for(int i = index; i < size; ++i){
                if(s[i] >= '0' && s[i] <= '9')
                    num += s[i];
                else if(s[i] == '['){
                    int close = closingIdx[i];
                    decode(s, i+1, stoi(num), close);
                    i = close;
                    num = "";
                }
                else
                    ans += s[i];
            }
            --amount;
        }
    }
};