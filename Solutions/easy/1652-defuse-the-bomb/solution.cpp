class Solution {
private:

    std::vector<int> answer;

    int sumNextK(vector<int>& code, int index, int k){
        int sum = 0;
        if (k > 0)
        {
            for (int i = 0; i < k; i++)
            {
                if (index+1 == code.size())
                {
                    index = -1;
                }
                sum += code[index+1];
                index++;
            }
        }
        else
        {
            k = k*-1;
            for (int i = 0; i < k; i++)
            {
                if (index-1 < 0)
                {
                    index = code.size();
                }
                sum += code[index-1];
                index--;
            }
        }
        return sum;
    }

public:
    vector<int> decrypt(vector<int>& code, int k) {
        if (k == 0)
        {
            for (int i = 0; i < code.size(); i++)
            {
                answer.push_back(0);
            }
            return answer;
        }
        int index = 0;
        while (index < code.size())
        {
            answer.push_back(sumNextK(code,index,k));
            index++;          
        }
        return answer;
    }
};