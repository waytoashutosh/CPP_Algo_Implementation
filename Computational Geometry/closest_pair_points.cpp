#include<bits/stdc++.h>
using namespace std;

//The usual approach is a divide-and-conquer algorithm  
//The complexity of this algorithm is O(nlog(n))
//but it is rather tricky to achieve this complexity.

//The alternative approach (based on the same algorithm), is to do sweep-line. 
//We sort the points based on the x-coordinate 
//and we keep a set of the points in the region x - d, x, sorted by y coordinate. 
//Here d is the smallest distance so far (we do that with the two-pointers technique). 
//Now, for each new point x, y, we query the whole range y - d, y + d in this set and possibly update our answer.

//Due to the proof of the Divide & Conquor algorithm
//at each time the quieried range should be of size O(1) on average, so total complexity would be O(nlog(n)).


long long ClosestPair(vector<pair<int, int>> pts) {
    int n = pts.size();
    sort(pts.begin(), pts.end());
    set<pair<int, int>> s;

    long long best_dist = 1e18;
    int j = 0;
    for (int i = 0; i < n; ++i) {


        //maintaining a range from current position to the left (elements which are greater than d are removed by moving the j pointer ahead)
        // j........i  -> this
        // |________|
        // is the range of values which are in set also.

        int d = ceil(sqrt(best_dist));
        while (pts[i].first - pts[j].first >= best_dist) {
            s.erase({pts[j].second, pts[j].first});
            j += 1;
        }

        //now since in the set, all the points are arranged by their y coordiantes -> {y, x}
        //finding the the points which are in range d
        // p1
        // p2  <- it1  -|
        // p3           | now these points in range totally since x is set by above while loop and y is set by below Lower_bounds, upper_bounds   
        // p4           |
        // p5   <-it2  -|
        // p6 
        auto it1 = s.lower_bound({pts[i].second - d, pts[i].first});
        auto it2 = s.upper_bound({pts[i].second + d, pts[i].first});
        
        for (auto it = it1; it != it2; ++it) {
            int dx = pts[i].first - it->second;
            int dy = pts[i].second - it->first;
            best_dist = min(best_dist, 1LL * dx * dx + 1LL * dy * dy);      
        } 
        s.insert({pts[i].second, pts[i].first}); 
    }
    return best_dist;
}


int main(){
    int n;
    
    cin>>n;
    vector<pair<int,int>> v(n);

    int x,y;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        v[i]={x,y};
    }

    cout<<ClosestPair(v);
    return 0;
}