#include <bits/stdc++.h>

using namespace std;

// wrong 
int main() {
    
    long long n;
    
    cin>>n;
    
    unordered_map<int, long long> map;
    
    long long maxf1 = INT_MIN, maxNum, maxf2 = INT_MIN, ans = 0;
    
    for (int i=0; i<n; i++) {
        
        long long arg;
        cin>>arg;
        
        map[arg]++;
        
        if (maxf1 < map[arg]) {
            maxf1 = map[arg];
            maxNum = arg;
        }
    }
    
    // Contains only 1 type of elment
    if (map.size() == 1) {
        cout<<ans<<endl;
        return 0;
    }
    
    for (auto & it: map) {
        if (it.first != maxNum && it.second > maxf2) {
            maxf2 = it.second;
        }
    }
    
    if (maxf2 <= 0) {
        cout<<ans<<endl;
        return 0;
    }
    
    for (auto & it: map) {
        if ( maxf2 < it.second) {
            ans += maxf2;
        } else {
            ans += it.second;
        }
    }
    
    cout<<ans<<endl;
    
}
