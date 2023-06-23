pair<int, int> get(int a, int b){
        //complete the function here
        // return {b,a};
        a = a^b;
        b = b^a;
        a = a^b;
        return {a,b};
    }