class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>arr(26,0);
        for(int i=0;i<magazine.size();i++){
            arr[magazine[i]-'a']++;
        }
        for(int i=0;i<ransomNote.size();i++){
            if(arr[ransomNote[i]-'a']>0) arr[ransomNote[i]-'a']--;
            else return false;
        }
        return true;
    }
};