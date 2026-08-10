class Solution {
public:
void solve (int open,int close,int n,string &temp,vector<string>&res){
    if(open==n&&close==n){
        res.push_back(temp);
        return;
    }
    if(open<n){
        temp.push_back('(');
        solve(open+1,close,n,temp,res);
        temp.pop_back();
    }
    if(close<open){
        temp.push_back(')');
        solve(open,close+1,n,temp,res);
        temp.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string temp;
        solve(0,0,n,temp,res);
        return res;
    }
};