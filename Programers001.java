class Programers001 {
    int []arr = new int[50001];
    int answer = 0;
    public int solve(int[] nums,int sum,int idx, int cnt)
    {
        
        if(cnt==3)
        {
            if(arr[sum]==0) answer++;
            return 0; 
        }
        for(int i = idx+1; i < nums.length; i++)
        {
            solve(nums,sum+nums[i],i,cnt+1);   
        }
        return 0;
    }
    public int Programers001(int[] nums) {
        int sum = 0;
        for(int i = 0; i < nums.length; i++)
        {
            sum = sum + nums[i];
        }
        for(int i = 2; i < sum; i++)
        {
            if(i*i>sum) break;
            for(int j = 2; j < sum; j++)
            {
                if(i*j>sum) break;
                if(arr[i*j]==0) arr[i*j] = 1;
            }
        }
        for(int i = 0; i < nums.length; i++)
        {
            solve(nums,nums[i],i,1);   
        }
        return answer;
    }
}