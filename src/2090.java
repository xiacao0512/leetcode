// by watercolor, 2023-06-20

class Solution {
    public int[] getAverages(int[] nums, int k) 
    {
        if(k == 0) {
            return nums;
        }

        int[] answer = new int[nums.length];
        for(int i = 0; i < answer.length; i++) {
            answer[i] = -1;
        }

        if(k*2+1 > nums.length) {
            return answer;
        }

        int left = 0, right = 0;
        long sum = 0;
        while(right < nums.length)
        {
            sum += nums[right];
            right++;

            if(right - left >= k*2+1) {
                answer[k+left] = (int)(sum / (k*2+1));
                sum -= nums[left];
                left++;
            }
        }

        return answer;
    }
}
