class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int a=s1.size();
        int b=s2.size();
        if(a>b)
            return false;
        map<char, int> map_s1, map_s2;
        for(int i=0;i<a;i++)
        {
            map_s1[s1[i]]+=1;
            map_s2[s2[i]]+=1;
        }
        auto itr=map_s1.begin();
        for(int i=0;i<b-a+1;i++)
        {
            if(map_s1[s2[i]]==map_s2[s2[i]])
            {

            }
            else
            {
                map_s2[map_s2[i]]
            }

        }
        return false;
    }
};
