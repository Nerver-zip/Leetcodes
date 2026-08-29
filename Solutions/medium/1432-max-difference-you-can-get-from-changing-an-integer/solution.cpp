class Solution {
public:
    int maxDiff(int num) {
        string maxNumber = to_string(num);
        string minNumber = maxNumber;

        char choice = ' ';

        for (auto& c : maxNumber)
        {
            if (choice == ' ' && c != '9')
                choice = c;
            if (c == choice)
                c = '9';
        }

        int maximum = atoi(maxNumber.c_str());

        char temp = minNumber[0];
        char specialChoice = ' ';

        if (temp == '1')
        {
            for (const auto& c : minNumber)
            {
                if(c != '1' && c != '0'){
                    specialChoice = c;
                    break;
                }
            }
            if(specialChoice == ' ')
                return maximum - atoi(minNumber.c_str());
        }
        
        choice = ' ';
        bool zero = specialChoice != ' ' ? true : false;

        for (int i = 0; i < minNumber.size(); ++i)
        {
            if (!zero && choice == ' ' && i >= 0 && minNumber[i] != '0')
                choice = minNumber[i];

            if (minNumber[i] == specialChoice && zero)
                minNumber[i] = '0';
            else if(minNumber[i] == choice && !zero)
                minNumber[i] = '1';
        }
        int minimum = atoi(minNumber.c_str());

        return maximum - minimum;
    }
};