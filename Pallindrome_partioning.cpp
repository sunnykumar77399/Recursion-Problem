class Solution {
public:
    // Function to check if a given string 'part' is a palindrome
    bool check(string part){
        int r = part.size() - 1;
        int l = 0;
        while(l < r){
            if(part[l] != part[r]) return false; // Not a palindrome if characters don't match
            l++, r--; // Move pointers inward
        }
        return true; // All characters matched => it's a palindrome
    }

    vector<vector<string>> res; // To store the final result of all palindrome partitions
    vector<string> list; // To store the current partition path

    // Recursive function to generate all palindrome partitions starting from index 'idx'
    void func(string s, int idx){
        if(idx == s.size()){ // If we've reached the end of the string
            res.push_back(list); // Add the current partition path to the result
            return;
        }

        string part = "";
        // Try every substring starting from index 'idx'
        for(int i = idx; i < s.size(); i++){
            part += s[i]; // Extend the substring
            if(check(part)){ // If the substring is a palindrome
                list.push_back(part); // Choose this substring
                func(s, i + 1); // Recurse for the remaining string
                list.pop_back(); // Backtrack: remove the last added substring
            }
        }
    }

    // Main function to be called with the full string
    vector<vector<string>> partition(string s) { 
        func(s, 0); // Start recursion from index 0
        return res; // Return the result list of all partitions
    }
};
