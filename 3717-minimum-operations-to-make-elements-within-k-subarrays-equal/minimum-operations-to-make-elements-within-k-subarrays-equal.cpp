class Solution {
public:

    vector<long long> slidingWindowMoves(vector<int>& nums, int X) {

    vector<long long> cost;

    multiset<int> left, right;
    long long sumLeft = 0, sumRight = 0;

    auto balance = [&]() {
        int target = (left.size() + right.size() + 1) / 2;

        while (left.size() > target) {
            int val = *left.rbegin();

            left.erase(prev(left.end()));
            sumLeft -= val;

            right.insert(val);
            sumRight += val;
        }

        while (left.size() < target) {
            int val = *right.begin();

            right.erase(right.begin());
            sumRight -= val;

            left.insert(val);
            sumLeft += val;
        }
    };

    auto add = [&](int val) {
        if (left.empty() || val <= *left.rbegin()) {
            left.insert(val);
            sumLeft += val;
        }
        else {
            right.insert(val);
            sumRight += val;
        }

        balance();
    };

    auto remove = [&](int val) {
        auto it = left.find(val);

        if (it != left.end()) {
            left.erase(it);
            sumLeft -= val;
        }
        else {
            it = right.find(val);
            right.erase(it);
            sumRight -= val;
        }

        balance();
    };

    int i = 0;

    for (int j = 0; j < nums.size(); j++) {

        add(nums[j]);

        if (j - i + 1 == X) {

            long long median = *left.rbegin();

            long long moves =
                median * left.size() - sumLeft +
                sumRight - median * right.size();

            cost.push_back(moves);

            remove(nums[i]);
            i++;
        }
    }

    return cost;
}

    long long solve(vector<long long>& cost, int index,
                    int x, int k,
                    vector<vector<long long>>& dp) {

        if (k == 0)
            return 0;

        if (index >= cost.size())
            return LLONG_MAX / 2;

        if (dp[index][k] != -1)
            return dp[index][k];

        // TAKE
        long long take = cost[index] +
            solve(cost, index + x, x, k - 1, dp);

        // NOT TAKE
        long long notTake =
            solve(cost, index + 1, x, k, dp);

        return dp[index][k] = min(take, notTake);
    }

    long long minOperations(vector<int>& nums, int x, int k) {

        vector<long long> cost = slidingWindowMoves(nums, x);

        int m = cost.size();

        vector<vector<long long>> dp(
            m + 1, vector<long long>(k + 1, -1)
        );

        return solve(cost, 0, x, k, dp);
    }
};