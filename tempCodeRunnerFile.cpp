vector<int> recamanSequence(int n){
        // code here
        unordered_map<int,int>mp;
        vector<int>v;
        v.push_back(0);
        int i=1;
        while(n--){
            auto itr=mp.find(v[i-1]-i);
            if((v[i-1]-i)>0 && itr==mp.end()){
                v[i]=v[i-1]-i;
                mp.insert({v[i],1});
            }
            else{
                v[i]=v[i-1]+i;
                mp.insert({v[i],1});
            }
            i++;
        }
        return v;
        
    }