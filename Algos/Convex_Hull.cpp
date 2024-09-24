

int findeq(pair<int,int> &p1, pair<int,int> &p2, pair<int,int> p3){
            int y3 = p3.second;
            int y2 = p2.second;
            int y1 = p1.second;
            int x3 = p3.first;
            int x2 = p2.first;
            int x1 = p1.first;
            int val = (y3-y2)*(x2-x1) - (y2-y1)*(x3-x2) ;
            return val;
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());
        vector<vector<int>> ans;
        deque<pair<int,int>> lower, upper;

        for(auto &pts:trees){
            int l = lower.size();
            int r = upper.size();
            pair<int,int> point = {pts[0],pts[1]};
            while(l>=2 && findeq(lower[l-1], lower[l-2],point)>0 ){
                l--;
                lower.pop_back();
            }
            while(r>=2 && findeq( upper[r-1], upper[r-2],point)<0 ){
                r--;
                upper.pop_back();
            }
            lower.push_back(point);
            upper.push_back(point);
        }
        set<pair<int,int>> st;
        for(auto it:lower){
            st.insert(it);
        }
        for(auto it:upper){
            st.insert(it);
        }
        for(auto it:st){
            ans.push_back({it.first, it.second});
        }
        return ans;

    }