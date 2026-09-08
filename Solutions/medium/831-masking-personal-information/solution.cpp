class Solution {
public:
    string maskPII(string s) {
        string masked;
        if(s.find("@") != string::npos){
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            int pos = s.find("@");
            

            masked += s[0];
            masked += "*****";
            masked += s[pos-1];
            
            masked.append(s, pos, s.size());
        }
        else {
            string sanitized;

            for (char c : s) {
                if(c >= '0' && c <= '9')
                    sanitized += c;
            }
            
            const int size = sanitized.size();
            if(size == 10){
                masked += "***-***-";
                masked.append(sanitized, size-4, size);
            }
            else if(size == 11){
                masked += "+*-***-***-";
                masked.append(sanitized, size-4, size);
            }
            else if(size == 12){
                masked += "+**-***-***-";
                masked.append(sanitized, size-4, size);
            }
            else if(size == 13){
                masked += "+***-***-***-";
                masked.append(sanitized, size-4, size);
            }
        }

        return masked;
    }
};