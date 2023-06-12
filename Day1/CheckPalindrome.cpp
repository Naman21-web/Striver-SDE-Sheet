string is_palindrome(int n)
		{
		    // Code here.
		    int x=n;
		    int ans=0;
		    while(x){
		        ans = ans*10;
		        ans += x%10;
		        x = x/10;
		    }
		    if(ans==n) return "Yes";
		    return "No";
		}