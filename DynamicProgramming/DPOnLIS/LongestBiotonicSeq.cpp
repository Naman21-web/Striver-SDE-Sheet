#include <bits/stdc++.h> 
int longestBitonicSequence(vector<int>& arr, int n) {
	  // Write your code here.	
	  vector<int> forward(n,1),backward(n,1);  
	  for(int i=1;i<n;i++){
		  for(int j=0;j<i;j++){
			  if(arr[i]>arr[j]){
				  forward[i] = max(forward[i],1+forward[j]);
			  }
		  }
	  }
	  for(int i=n-2;i>=0;i--){
		  for(int j=n-1;j>i;j--){
			  if(arr[i]>arr[j]){
				  backward[i] = max(backward[i],1+backward[j]);
			  }
		  }
	  } 
	  int maxi=0;
	  for(int i=0;i<n;i++){
		  maxi = max(maxi,forward[i]+backward[i]-1);
	  }
	  return maxi;
} 
