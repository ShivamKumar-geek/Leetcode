/*  MEDIUM
983. Minimum Cost For Tickets

In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways:

a 1-day pass is sold for costs[0] dollars;
a 7-day pass is sold for costs[1] dollars;
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.
*/


class Solution {
public:
    bool check(vector<int> days,int nums)
    {
        for(int i=0;i<days.size();i++)
            if(nums==days[i])
                return true;
        return false;
    }
    
    /*
    int dp(vector <int > & days ,vector <int> & costs,int num)
    {
       if(num>365)
            return 0;
        if(check(days,num))
            return min(costs[0]+dp(days,costs,num+1),min(costs[1]+dp(days,costs,num+7),costs[2]+dp(days,costs,num+30)));
        else
            return dp(days,costs,num+1);
    }
    */
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size() ,i=0;
        int maxim=-1,minimum=1000001;
        for(i=0;i<n;i++)
        {
            maxim=max(maxim,days[i]);
            minimum=min(minimum,days[i]);
        }
        int x=0,y=0,z=0;
        vector <int> dp(400,0);
        for(i=1;i<=maxim;i++)
        {
            if(check(days,i))
            {
                x=costs[0]+dp[max(i-1,0)];
                y=costs[1]+dp[max(i-7,0)];
                z=costs[2]+dp[max(i-30,0)];
                dp[i]=min(x,min(y,z));
            }
            else
                dp[i]=dp[i-1];
        }
        return(dp[maxim]);
    }
};