class Solution {
  public:
    int lastStoneWeight(vector<int> &stones) {
        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }
        int sum = 0;
        while (pq.size() != 1) {
            int element_1 = pq.top();
            pq.pop();
            int element_2 = pq.top();
            pq.pop();
            int a = element_1 - element_2;
            pq.push(a);
        }
        return pq.top();
    }
};