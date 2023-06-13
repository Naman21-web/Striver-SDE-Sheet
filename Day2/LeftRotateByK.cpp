void leftRotate(int arr[], int k, int n) 
	{ 
	   // Your code goes here
	   k = k%n;
	   queue<int> q;
	   for(int i=k;i<n+k;i++){
	       q.push(arr[i%n]);
	   }
	   int i=0;
	   while(!q.empty()){
	       arr[i]=q.front();
	       q.pop();
	       i++;
	   }
	} 