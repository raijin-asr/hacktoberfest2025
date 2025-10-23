class Solution {
    public:
        double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) 
        {
            int n = arr1.size(),m = arr2.size();
            if(n > m)
            {
                return findMedianSortedArrays(arr2,arr1);
            }       
    
            int s=0,e=n;
            while(s <= e)
            {
                int mid1 = s + (e-s)/2;
                int mid2 = (n+m+1)/2 - mid1;
    
                int l1 = (mid1 == 0 ? INT_MIN: arr1[mid1-1]);
                int l2 = (mid2 == 0 ? INT_MIN: arr2[mid2-1]);
                int r1 = (mid1 == n ? INT_MAX: arr1[mid1]);
                int r2 = (mid2 == m ? INT_MAX: arr2[mid2]);
    
                if(l1 <= r2 && l2 <= r1)
                {
                    if((n+m) & 1)
                    {
                        return (double)max(l1,l2);
                    }
                    return (double)(max(l1,l2)+min(r1,r2))/2;
                }
                else if(l1 > l2)
                {
                    e = mid1-1;
                }
                else
                {
                    s = mid1+1;
                }
            }         
            return -1.0;
        }
    };