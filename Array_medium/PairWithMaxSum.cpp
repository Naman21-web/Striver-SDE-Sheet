long long pairWithMaxSum(long long arr[], long long N)
    {
        // Your code goes here
        long long int ans=0;
        for(int i=1;i<N;i++){
            //KYUKI AGAR 3 SIZE KA SUBARRAY LE TO AGAR ABHI JO 2 ELEMENT H USSE 
            //BADHA AAYA TO WESE BHI WO SMALLEST SUM M KUCH CONTRIBUTE NHI KREGA
            //AUR USSE CHOTA AAYA TO SUM AUR KAM HO JAEGA AUR WO MAX SMALLEST SUM M
            //KUCH CONTRIBUTE NHI KREGA ISILIYE ADJACENT 2 ELEMENT KA HI SUM LIYA ISSE ANS MIL JAEGA
            ans = max(ans,arr[i-1]+arr[i]);
        }
        return ans;
    }