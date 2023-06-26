vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        stack<int> st1,st2;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>=0){
                st1.push(asteroids[i]);
            }
            else{
                if(st1.empty()) st2.push(asteroids[i]);
                else{
                    while(!st1.empty() && st1.top()<abs(asteroids[i])){
                        st1.pop();
                    }
                    if(st1.empty()) st2.push(asteroids[i]);
                    else if(st1.top()==abs(asteroids[i])) st1.pop();
                }
            }
        }
        vector<int> ans;
        while(!st1.empty()){
            ans.push_back(st1.top());
            st1.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }