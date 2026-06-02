class TimeMap {
public:
    
    unordered_map<string,vector<pair<string,int>>> store;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({value,timestamp});
        
    }
    
    string get(string key, int timestamp) {
        
        if(store.find(key)==store.end()){
            return "";
        }
        auto &vec = store[key];
        
        int left=0;
        int right=vec.size()-1;
        int ans=-1;
        while(left<=right){
                int mid=left+(right-left)/2;
                if(vec[mid].second<=timestamp){
                    ans=mid;
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            if(ans==-1) return "";
            return vec[ans].first;

        }

        
    
};
