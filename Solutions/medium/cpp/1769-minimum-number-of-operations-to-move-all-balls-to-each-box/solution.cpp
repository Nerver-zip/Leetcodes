class Solution { 
public:
    vector<int> minOperations(string boxes) {
        
        vector<int> minOp;
        vector<int> prefix(boxes.size());


        int accum = 0;
        for (int i = 1; i < boxes.size(); i++)
        {
            if (boxes[i-1] == '1')
            {
                accum++;
            }
            prefix[i] = prefix[i-1] + accum;
        }

        vector<int> answer;
        answer.resize(boxes.size());

        answer[boxes.size()-1] = prefix[boxes.size()-1];

        accum = 0;
        int last = 0;
        for (int i = boxes.size()-2; i >= 0; i--)
        {
            if (boxes[i+1] == '1')
            {
                accum++;
            }
            last = last + accum;
            answer[i] = prefix[i] + last;
        }
        return answer;
    }
};