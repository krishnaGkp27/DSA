#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> image;
    int newColor;
    int sourceColor;
    int rows;
    int cols;
public:

   void fillColor(int sr,int sc)
    {
        if(sr == rows || sc == cols || sr < 0 || sc < 0)
            return;
            
        if(image[sr][sc] != sourceColor)    
            return;
            
        image[sr][sc] = newColor;
            
        fillColor(sr-1,sc);
        fillColor(sr,sc-1);
        fillColor(sr+1,sc);
        fillColor(sr,sc+1);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       
        this->rows = image.size();
        this->cols = image[0].size();
        this->image = image;    
        this->sourceColor = image[sr][sc];
        this->newColor = newColor;
        fillColor(sr,sc);
        return this->image;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  