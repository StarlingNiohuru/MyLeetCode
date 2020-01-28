#include <vector>
#include <stack>

using namespace std;

// Maintain a stack and traverse heights(push a '0' at end). When heights[i] <= heights[stk[top]], we calculate the area
// corresponding with stk[top]. The area = (i−stack[top-1]−1) * heights[stack[top]] so we need to pop the top first then
// calculate. Repeat this process until heights[i] > heights[stk[top]] and push i into the stack. At last we use
// heights[-1]=0 to clear all the element in the stack. The answer is max(area[]). Time complexity is O(n),
// space complexity O(n).
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        stack<int> stk;
        heights.push_back(0);
        int res = 0, temp;
        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                temp = stk.top();
                stk.pop();
                res = max(res, heights[temp] * (stk.empty() ? i : (i - stk.top() - 1)));
            }
            stk.push(i);
        }
        return res;
    }
};