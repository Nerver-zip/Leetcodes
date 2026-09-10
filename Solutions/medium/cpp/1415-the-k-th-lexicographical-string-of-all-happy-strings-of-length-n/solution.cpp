class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        backtrack(happyStrings, n, "");

        if(k > happyStrings.size())
            return "";

        sort(happyStrings.begin(), happyStrings.end());
        return happyStrings[k-1];
    }
private:
    void backtrack(vector<string>& happyStrings, int n, string s){
        if(s.size() == n){
            happyStrings.push_back(s);
            return;
        }
        
        if(s.empty()){
            s.push_back('a');
            backtrack(happyStrings, n, s);
            s.pop_back();

            s.push_back('b');
            backtrack(happyStrings, n, s);
            s.pop_back();
            
            s.push_back('c');
            backtrack(happyStrings, n, s);
            s.pop_back();
        }
        else if(s.back() == 'a'){
            s.push_back('b');
            backtrack(happyStrings, n, s);
            s.pop_back();
            

            s.push_back('c');
            backtrack(happyStrings, n, s);
            s.pop_back();
        }
        else if(s.back() == 'b'){
            s.push_back('a');
            backtrack(happyStrings, n, s);
            s.pop_back();
        
            s.push_back('c');
            backtrack(happyStrings, n, s);
            s.pop_back();
        }
        else{
            s.push_back('a');
            backtrack(happyStrings, n, s);
            s.pop_back();
        
            s.push_back('b');
            backtrack(happyStrings, n, s);
            s.pop_back();
        }
    }
};