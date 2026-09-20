class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int left = 0;
        int right = n-1;
        while(left<right){
          int h = min(height[left],height[right]);
          int w = (right-left);
          ans = max(ans, h*w);
          if(height[left]<=height[right]){
            left++;
          }
          else{
            right--;
          }
        }
        return ans;
    }
};
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int n = height.size();
//         // vector<int> NGL(n);
//         // NGL[0] = 0;
//         // for (int i = 1; i < n; i++) {
//         //     if (height[NGL[i - 1]] >= height[i - 1]) {
//         //         NGL[i] = NGL[i - 1];
//         //     } else {
//         //         NGL[i] = i - 1;
//         //     }
//         //     cout << NGL[i] << " ";
//         // }
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             for(int j=i+1; j<n; j++){
//                 ans = max(ans, min(height[i],height[j])*(j-i));
//             }
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int left = 0;
//         int right = height.size() - 1;
//         int max_area = 0;

//         while (left < right) {
            
//             int current_width = right - left;
//             int current_height = min(height[left], height[right]);
//             int current_area = current_width * current_height;
            
         
//             max_area = max(max_area, current_area);

         
//             if (height[left] < height[right]) {
//                 left++;
//             } else {
//                 right--;
//             }
//         }

//         return max_area;
//     }
// };
