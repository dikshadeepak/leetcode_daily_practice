class Solution {
public:
unordered_map<char,string>mp;
void solve(string s,int n,int idx,string diary,vector<string>&res){
 if(idx==n){
    res.push_back(diary);
    return;

 }
 string choice =mp[s[idx]];
 for(int j=0;j<choice.size();j++){
    diary.push_back(choice[j]);
    solve(s,n,idx+1,diary,res);
    diary.pop_back();
 }
}
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        return {};

        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        vector<string>res;
        int n=digits.size();
        string diary={};
        solve(digits,n,0,diary,res);
        return res;


    }
};