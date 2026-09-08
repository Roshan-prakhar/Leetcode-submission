class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int k=0;
    // we are modifying the vector in-place.
        while(i<chars.size())
        {
            char ch=chars[i];
            int cnt=1;
            int idx=i+1;

            while(idx<chars.size() && chars[idx]==ch)
            {
                cnt++;
                idx++;
            }

            chars[k]=ch;
            k++;

            if(cnt>1)
            {
                string hn=to_string(cnt);

                for(char x:hn)
                {
                    chars[k++]=x;
                }
            }

            i=idx;
        }

        return k;
    }
};