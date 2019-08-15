273_Integer_to_English_Words.cpp

constexpr char * kUnder20[] = {"","One", "Two", "Three", "Four", "Five", 
                               "Six", "Seven", "Eight", "Nine","Ten",
                               "Eleven", "Twelve", "Thirteen", "Fourteen",
                               "Fifteen", "Sixteen", "Seventeen", "Eighteen", 
                               "Nineteen"};
constexpr char * kUnder100[] = {"","","Twenty", "Thirty", "Forty", "Fifty", 
                                "Sixty", "Seventy", "Eighty", "Ninety"};
constexpr char * kHTMB[] = {"Hundred", "Thousand", "Million", "Billion"};
constexpr long kP[] = {100, 1000, 1000*1000, 1000*1000*1000};

class Solution {
    
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        return convert(num).substr(1);
    }
    
    string convert(int num)
    {
        // base case
        // digital
        if (num == 0) return "";
        if(num < 20) return string(" ") + kUnder20[num];
        if (num < 100) return string(" ") + kUnder100[num/10] + convert(num%10);
        for(int i = 3; i >= 0; i--)
        {
            if (num>=kP[i])
                return convert(num / kP[i]) + " "+ kHTMB[i] + convert(num%kP[i]);
        }
        return "";
    }
};



 
