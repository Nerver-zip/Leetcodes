class Solution {
public:
    string addBinary(string a, string b) {
        const int n = a.size() > b.size() ? a.size() : b.size();
        
        // Normalize by adding leading zeros + extra zeros
        // e.g.: a = 1111, b = 111 -> a = 01111, b = 00111 
        a = string(n - a.size() + 1, '0') + a;
        b = string(n - b.size() + 1, '0') + b;
         
        string s(n+1, '0');
        
        bool carry = false;
        for(int i = n; i >= 0; --i){
            if(a[i] == '1' && b[i] == '1' && !carry){
                s[i] = '0';
                carry = true;
            }
            else if(a[i] == '1' && b[i] == '1' && carry)
                s[i] = '1';
            else if((a[i] == '1' || b[i] == '1') && !carry)
                s[i] = '1';
            else if ((a[i] == '1' || b[i] == '1') && carry)
                s[i] = '0';
            else if(carry){
                s[i] = '1';
                carry = false;
            }
            else
                s[i] = '0';
        }
        

        // Remove leading 0 if any
        return s[0] == '0' ? string(s.begin() + 1, s.end()) : s;
    }
};