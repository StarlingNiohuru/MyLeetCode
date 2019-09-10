class Solution {
public:
    string numberToWords(int num) {
        string res;
        string wordsBelow20[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                                 "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                                 "Eighteen", "Nineteen"};
        string wordsMultipleOf10[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string wordsMultipleOf1000[] = {"Thousand", "Million", "Billion"};
        int thousands = 0;
        if (num == 0) res = "Zero";
        while (num > 0) {
            int num1 = num % 1000, hundreds = num1 / 100, tens = num1 % 100;
            if (thousands > 0 && num1 > 0) res = wordsMultipleOf1000[thousands - 1] + (res.empty() ? "" : " ") + res;
            if (tens > 0) {
                if (tens < 20) res = wordsBelow20[tens - 1] + (res.empty() ? "" : " ") + res;
                else {
                    res = wordsMultipleOf10[tens / 10 - 2] + (tens % 10 ? " " + wordsBelow20[tens % 10 - 1] : "") +
                          (res.empty() ? "" : " ") + res;
                }
            }
            if (hundreds > 0) res = wordsBelow20[hundreds - 1] + " Hundred" + (res.empty() ? "" : " ") + res;
            num /= 1000;
            thousands++;
        }
        return res;
    }
};