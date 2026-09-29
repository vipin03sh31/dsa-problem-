class Info{
    public:
        int data;
        int rIndex;
        int cIndex;

        Info(int x,int y, int z){
            data = x;
            rIndex = y;
            cIndex = z;
        }
};

class campare{
    public:
        bool operator()(Info*a,Info*b){
            return a->data > b->data;
        }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int totalrow = nums.size();
        priority_queue<Info*,vector<Info*>,campare>pq;
        vector<int>ans;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i = 0;i <totalrow;i++){
            int element = nums[i][0];
            Info*temp = new Info(element,i,0);
            pq.push(temp);
            maxi = max(maxi,element);
            mini = min(mini,element);

        }

        int ans_start = mini;
        int ans_end = maxi;

        while(!pq.empty()){
            Info* front = pq.top();
            pq.pop();
            int frontdata = front->data;
            int front_rIndex = front->rIndex;
            int front_cIndex = front->cIndex;

            mini = frontdata;

            if((maxi-mini) < (ans_end-ans_start)){
                ans_start = mini;
                ans_end = maxi;
            }

            int currentcolumn = nums[front_rIndex].size();

            if(front_cIndex+1 < currentcolumn){
                int element = nums[front_rIndex][front_cIndex+1];
                Info*temp = new Info(element,front_rIndex,front_cIndex+1);
                 maxi = max(maxi,element);
                pq.push(temp);
               
            }
            else{
                break;
            }


        }
        ans.push_back(ans_start);
        ans.push_back(ans_end);

        return ans;
    }
};