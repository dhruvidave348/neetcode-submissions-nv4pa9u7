class Solution {
public:
    
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26,0);
        for(char task: tasks){
            count[task-'A']++;
        }
        //adding freq to pq
        priority_queue<int> pq;
        for(int freq:count){
            if(freq>0) pq.push(freq);
        }
        //initialising queue for cooldown
        queue<pair<int,int>> cooldown;//we dont care abt char,only freq

        int time=0;
        while(!pq.empty()||!cooldown.empty()){
            time++;

            if(!pq.empty()){
                int freq=pq.top();
                pq.pop();
                freq--;
                if(freq>0){
                    cooldown.push({freq,time+n});
                }
            }
            if(!cooldown.empty()&&cooldown.front().second==time){
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        return time;


        
    }
};
