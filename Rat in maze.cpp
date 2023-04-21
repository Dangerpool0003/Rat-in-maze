
//For Input : 
//m[][] = {{1, 0, 0, 0},
//         {1, 1, 0, 1}, 
//         {1, 1, 0, 0},
//         {0, 1, 1, 1}}

//Output: 
// DDRDRR DRDDRR



#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
vector<string>ans;
void solve(int i,int j,vector<vector<int>> &m, int n,string s)
 {
        if(i<0 || i>=n || j<0 || j>=n || m[i][j]==0)
           return;
        if(i==n-1 && j==n-1)
        {
            ans.push_back(s);
            s="";
            return;
        }
        m[i][j]=0;
        solve(i,j+1,m,n,s+"R");
        solve(i,j-1,m,n,s+"L");
        solve(i+1,j,m,n,s+"D");
        solve(i-1,j,m,n,s+"U");
        m[i][j]=1; //backtrack
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        string s="";
        if(m[0][0]==0)
           return {};
        if(m[n-1][n-1]==0)
           return {};
        solve(0,0,m,n,s);
        return ans;
    }
};

int main(){
	int n;
	cin>>n;
	
	vector<vector<int>> m(n,vector<int> (n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>m[i][j];
		}
	}
	
	Solution obj;
	vector<string> res=obj.findPath(m,n);
	sort(res.begin(),res.end());
	
	if(res.size()==0){
		cout<<"-1"<<endl;
	}
	else{
		for(int i=0;i<res.size();i++){
			cout<<res[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}

