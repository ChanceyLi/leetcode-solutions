class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> res;
        int sumcount = 0, minnum = INT_MAX, maxnum = 0, maxcount = 0, maxindex;
        double sum = 0;
        for(int i = 0; i < 256; ++i) 
            if(count[i]) {
                minnum = min(i,minnum);
                maxnum = max(i,maxnum);
                sumcount += count[i];
                if(maxcount < count[i]) {
                    maxcount = count[i];
                    maxindex = i;
                }
            }
        for(int i = 0; i < 256; ++i) 
            if(count[i]) sum += (double)count[i]*i/sumcount;
            
        double mid = 0;
        int counttmp = 0;
        if(sumcount%2) {
            for(int i = 0; i < 256; ++i) {
                if(count[i]) {
                    counttmp += count[i];
                    if(counttmp > sumcount/2) {
                        mid = i;
                        break;
                    }
                }
            }
        } else {
            for(int i = 0; i < 256; ++i) {
                if(count[i]) {
                    counttmp += count[i];
                    if(counttmp >= sumcount/2) {
                        if(counttmp > sumcount/2) {
                            mid = i;
                            break;
                        } else {
                            mid =(double)i/2;
                            for(int j = i+1; j < 256;++j)
                                if(count[j]){
                                    mid += (double)j/2;
                                    break;
                                }
                            break;
                            }
                    }
                }
            }
        }
        res.push_back(minnum);
        res.push_back(maxnum);
        res.push_back(sum);
        res.push_back(mid);
        res.push_back(maxindex);
        return res;
    }
};
