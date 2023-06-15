int subarrayXOR(vector<int> a, int N, int K) {
        // code here
        int xr = 0;
        map<int, int> mp; //declaring the map.
        mp[xr]++; //setting the value of 0.
        int cnt = 0;
    
        for (int i = 0; i < N; i++) {
            // prefix XOR till index i:
            xr = xr ^ a[i];
    
            //By formula: x = xr^k:
            int x = xr ^ K;
    
            // add the occurrence of xr^k
            // to the count:
            cnt += mp[x];
    
            // Insert the prefix xor till index i
            // into the map:
            mp[xr]++;
        }
        return cnt;
    }