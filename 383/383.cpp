/*
* Name: Jihwan Oh
* e-mail: jihwanoh315@gmail.com
*
* 383. Ransom Note
* https://leetcode.com/problems/ransom-note/?envType=study-plan-v2&envId=top-interview-150
*/


/*

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> currMap;
        for (auto val : magazine)
        {
            currMap[val]++;
        }

        for (auto val : ransomNote)
        {
            if (currMap.find(val) != currMap.end())
            {
                currMap[val]--;
                if (currMap[val] == 0)
                {
                    currMap.erase(val);
                }
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};