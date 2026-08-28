class Solution {
public:
    string isPossible(int n, vector<int> freq, string cur, char &mid, string& target){
        // this gives the max palindrome achievable with the current prefix 
        //(descending order)
        for(int i=25; i>=0; i--){
            while(freq[i]){
                cur += (char)('a'+i);
                freq[i]--;
            }
        }
        if(mid!='#'){
            // odd-length palindrome: left half + mid + reverse(left half)
            string temp = cur;
            cur += mid;
            reverse(temp.begin(), temp.end());
            cur.append(temp.begin(), temp.end());
        }
        else {
            // even-length palindrome: left half + reverse(left half)
            string temp = cur;
            reverse(temp.begin(), temp.end());
            cur.append(temp.begin(), temp.end());
        }
        // feasibility check: only valid if this (largest possible) candidate beats target
        return cur>target? cur : "";
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        if(n==1){
            // if size is 1 then direct compare
            if(s>target) return s;
            else return "";
        }
        for(char c : s) freq[c-'a']++; // freq Track

        char mid = '#';
        int oddCount = 0;

        for(int i=0; i<26; i++){
            if(freq[i]%2){
                // odd count -> this becomes the middle character
                mid = (char)('a'+i);
                freq[i]--;
                oddCount++;
            }

            freq[i] /= 2; // each char used freq[i]/2 times in the left half

            if(oddCount>=2) return ""; // more than one odd-frequency char -> can't form a palindrome
        }

        n /= 2; // we only need to construct the left half now
        string res = "", prefix = "";

        // greedily build the left half, position by position
        for(int i=0; i<n; i++){

            string cur = prefix;
            bool isThereAny = false;

            // try smallest character first ('a' -> 'z')
            for(int j=0; j<26; j++){
                if(freq[j]){
                    freq[j]--;
                    cur += (char)('a'+j);

                    // check if this prefix can still lead to a palindrome > target
                    string isPos = isPossible(n, freq, cur, mid, target);

                    if(isPos!=""){
                        prefix = cur;      // keep this character, lock in the prefix
                        isThereAny = true;

                        if(res=="") res = isPos;
                        else res = min(res, isPos); // track smallest valid candidate seen
                        break;
                    }

                    // this character doesn't work, undo and try the next one
                    freq[j]++;
                    cur.pop_back();
                }
            }

            if(!isThereAny)
                return ""; // no character works at this position -> impossible
        }

        return res; 
    }
};