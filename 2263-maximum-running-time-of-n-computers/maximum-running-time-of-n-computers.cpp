class Solution {
public:
 bool solve(long long n,vector<int>&bat,long long mid)
 {
    long long cnt=0;
long long devices=n;
    long long j=bat.size()-1;
    while(j>=0)
    {
        if(bat[j]>=mid)
        {
            cnt++;
            devices--;
            j--;
        }
        else
        {
            if(devices==0) break;
            long long sum=0;
            for(long long idx=j;idx>=0;--idx) sum+=bat[idx];
            long long avg=sum/devices;
            if(avg>=(long long)mid)
            {
                cnt+=devices;
                break;
            }
            else{
                break;
            }
        }

    }

    return cnt>=n;
 }
    long long maxRunTime(int n, vector<int>& bat) {
        // logic : jab remaining device ka avg runtime se estimate krna padey ki remaning device 
        // operate ho payga ya ni 
        // NOTE: we can take out the batteries from them
        // if req is higher than capacity, may use them in rotation
        sort(bat.begin(),bat.end());
        long long ts=0;
        for(long long i : bat) ts+=i;
        long long ans=0;
        long long low=0;
        long long high=ts;
        while(low<=high)
        {
            long long mid=(low+high)>>1;
            if(solve(n,bat,mid))
            {
                  ans=mid;
                 low=mid+1;
            }
            else high=mid-1;
        }

        return ans;


        
    }
};