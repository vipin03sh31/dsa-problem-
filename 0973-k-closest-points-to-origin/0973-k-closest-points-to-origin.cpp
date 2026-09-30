class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Placeholder logic for finding k closest points to the origin
        int totalrow = points.size();
        priority_queue<pair<int,int>>pq;
        vector<vector<int>>ans;
        for(int row = 0; row < totalrow;row++){
            int sum = points[row][0]*points[row][0] + points[row][1]*points[row][1];
            pq.push({sum,row});
        }
        while(!pq.empty() && pq.size()!=k){
            pq.pop();
        }
        while(!pq.empty()){
            vector<int>temp;
            temp.push_back(points[pq.top().second][0]);
            temp.push_back(points[pq.top().second][1]);
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
    }
};