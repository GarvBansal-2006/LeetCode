class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s="";
        for(int i=0;i<n;i++)
        s+='.';
        vector<string> a(n,s);
        func(ans,a,n,0);
        return ans;

    }
    void func(vector<vector<string>> & ans,vector<string>& a,int n,int index){
        if(index==n){
            ans.push_back(a);
            return;
        }
        for(int i=0;i<n;i++){
            if(checkPosition(a,index,i,n)){
                a[index][i]='Q';
                func(ans,a,n,index+1);
                a[index][i]='.';
            }
        }
    }
    
    bool checkPosition(vector<string>& a,int i,int j,int n){
        for(int k=i;k>=0;k--){
            if(a[k][j]=='Q')
            return false;
        }

        int idx=i,jdx=j;
        while(idx>=0 && jdx<n){
            if(a[idx][jdx]=='Q')
            return false;
            idx--;
            jdx++;
        }
        while(i>=0 && j>=0){
            if(a[i][j]=='Q')
            return false;
            i--;
            j--;
        }
        return true;
    }
};