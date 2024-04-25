/*
* Name: Jihwan Oh
* e-mail: jihwanoh315@gmail.com
*
* 17. Letter Combinations of a Phone Number
* https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=top-interview-150
*/


/*

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]

*/

#include <unordered_map>
#include <vector>

class Solution {
public:
    std::unordered_map<char, string> numMap =
    {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    vector<string> letterCombinations(string digits) {

        if(digits.length() == 0)
            return vector<string>();

        std::vector<string> currStrings;
        
        for(char mj : numMap[digits[0]])
        {
            currStrings.push_back({mj});
        }

        for(int i = 1; i < digits.length(); ++i)
        {
            std::vector<string> newStrings;

            for(string currStr : currStrings)
            {
                for(char mj : numMap[digits[i]])
                {
                    newStrings.push_back(currStr + mj);
                }
            }
            currStrings = newStrings;
        }

        return currStrings;
    }
};