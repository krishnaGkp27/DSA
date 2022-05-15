// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int n;
    vector<vector<int>> ans;
    vector<int> pos;
    
public:
    bool checkMajorDiagonal(int row,int col)
    {
        col--;
        row--;
        while(col>=0 && row>=0)
        {
            if(pos[row] == col+1)
                return false;
            col--;
            row--;    
        }
        return true;
    }
    
    bool checkMinorDiagonal(int row,int col)
    {
        row--;col++;
        while(col<n && row>=0)
        {
            if(pos[row] == col+1)
                return false;
            col++;
            row--;    
        }
        return true;
    }
    
    bool checkCol(int row,int col)
    {
        for(int i = 0; i<n; i++)
            if(pos[i] == col+1)
                return false;
        
        return true;        
    }
    
    bool isAllowed(int row,int col)
    {
        return checkCol(row,col) && checkMajorDiagonal(row,col) && checkMinorDiagonal(row,col);
    }
    
    void NQueens(int row)
    {
        if(row == n)
            ans.push_back(pos);
        
        for(int col =0; col<n; col++)
        {
            if(isAllowed(row,col))
            {
                pos[row] = col+1;
                NQueens(row+1);
                pos[row] = -1;
            }
            
        }
    }
    vector<vector<int>> nQueen(int n) {
        if(n == 2 || n ==3)
            return {} ;
        this->n = n;
        pos.resize(n, -1);
        NQueens(0);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends