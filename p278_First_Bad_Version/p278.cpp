bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        int mid;
        while((r-1)>l) {    
            mid = l + (r-l)/2;  
            if(isBadVersion(mid)) r = mid;
            else l = mid;
        }
        if(isBadVersion(l)) return l;
        if(isBadVersion(r)) return r;
        return -1;
    }
};