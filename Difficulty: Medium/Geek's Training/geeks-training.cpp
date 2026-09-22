class Solution {
public:
    int maximumPoints(vector<vector<int>>& mat) {

        int n = mat.size();

        vector<int> prev(4, 0);

        prev[0] = max(mat[0][1], mat[0][2]);
        prev[1] = max(mat[0][0], mat[0][2]);
        prev[2] = max(mat[0][0], mat[0][1]);
        prev[3] = max({
            mat[0][0],
            mat[0][1],
            mat[0][2]
        });

        for (int day = 1; day < n; day++) {

            vector<int> curr(4, 0);

            for (int last = 0; last < 4; last++) {

                for (int activity = 0; activity < 3; activity++) {

                    if (activity != last) {

                        curr[last] =
                            max(
                                curr[last],
                                mat[day][activity]
                                + prev[activity]
                            );
                    }
                }
            }

            prev = curr;
        }

        return prev[3];
    }
};