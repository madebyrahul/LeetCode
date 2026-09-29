class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = 0;
        queue<pair<int,int>> month; // {day,cost}
        queue<pair<int,int>> week;

        for(int day : days){
            while(!month.empty() && month.front().first + 30 <= day){
                month.pop();
            }
            while(!week.empty() && week.front().first + 7 <= day){
                week.pop();
            }
            month.push({day,ans+costs[2]});
            week.push({day,ans+costs[1]});
            ans = min(ans+costs[0], min(month.front().second,week.front().second));
        }

        return ans;

    }
};