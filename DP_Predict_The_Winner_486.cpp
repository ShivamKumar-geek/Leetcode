class Solution {
public:
  /*  
  //Recursive Approach just to understand the recurrence relation
  
  int check(vector <int> &nums , int i , int j, int turn)
    {
        int sum=0;
        if(i==j)
            return nums[i];
        int x= nums[i]+check(nums,i+1,j,(!turn));
        int y= nums[j]+check(nums,i,j-1,(!turn));
        if(turn==1)
            sum+=max(x,y);
        if(turn==0)
            sum+=min(x,y);
        return sum;
    }*/
    bool PredictTheWinner(vector<int>& nums) {
        int n= nums.size();
        if(n==1)                          // Edge Cases Need to be taken care of seperately
            return true;
        if(n==2 && nums[0]==nums[1])
            return true;
            
        int i=0;
        int prefix[n];
        prefix[0]=nums[0];
        for(i=1;i<n;i++)
            prefix[i]=prefix[i-1]+nums[i];
      vector <vector <pair <int,int>>> dp(n,vector< pair<int,int> >(n,make_pair(0,0)));
      int j=0;
        for(i=0;i<n;i++){
            dp[i][i].first=nums[i];
            dp[i][i].second=0;
        }
        int x=0;
        for(i=1;i<n;i++)
        {
            for(j=0;j<n-i;j++)
            {
                dp[j][j+i].first=max(nums[j+i]+dp[j][j+i-1].second,nums[j]+dp[j+1][j+i].second);
                if(j!=0)
                    dp[j][j+i].second=prefix[j+i]-prefix[j-1]-dp[j][j+i].first;
                else
                    dp[j][j+i].second=prefix[j+i]-dp[j][j+i].first;
                    
            }
        }
        i=0;
        if(n%2==0 && dp[0][n-1].first==prefix[n-1]/2)      // Edge Cases Need to be taken care of seperately
            return true;
        if(dp[0][n-1].first>prefix[n-1]/2)
            return true;
        else
            return false;
    }
};