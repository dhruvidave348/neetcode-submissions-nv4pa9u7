class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*so find the index at m+n/2 and m+n/2-1 and we do that by using count so when count 
        is equal to m+n/2 store that as first ele and m+n/2-1 will we second ele
        so then check if its odd or even if its odd just take m+n/2 but how do we find the value
        we use while loop and iterate thru the arrays using i and j and count
        so compare i and j using two pointer until u find the value associated with the ele1
        and ele2*/
        int m=nums1.size();
        int n=nums2.size();
        int index1=(m+n)/2;
        int index2=index1-1;
        int count=0;
        int ele1=-1;
        int ele2=-1;
        int i=0;
        int j=0;
        int median=0;
        while( i<m &&  j<n){
            if(nums1[i]<nums2[j]){
                if(index1==count){
                    ele1=nums1[i];
                }
                if(index2==count){
                    ele2=nums1[i];
                }
                
                count++;
                i++;
            }
            else{
                if(index1==count){
                    ele1=nums2[j];
                }
                if(index2==count){
                    ele2=nums2[j];
                }
                count++;
                j++;
               

            }

     
        }
        /*for any left over elements on either arrays*/
        while(i<m){
            if(count==index1) ele1=nums1[i];
            if(count==index2) ele2=nums1[i];
            i++;
            count++;
        }
        while(j<n){
            if(count==index1) ele1=nums2[j];
            if(count==index2) ele2=nums2[j];
            j++;
            count++;
        }
        if((m+n)%2==1){
            return ele1;

        }
        else{
            return (double)((double)(ele1+ele2))/2.0;
        }

        
    }
};
