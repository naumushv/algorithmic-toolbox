#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, m, d, tmp, max_stop = 0, current = 0, k = 0, result = 0;
    vector<int> stops;
    cin >> d >> m >> n;
    for (int i=0; i < n; i++){
    	cin >> tmp;
    	stops.push_back(tmp);
    	if (tmp <= m){
    		k = i;
    	}
    }

	max_stop = stops[k];

	if (m >= d) {
		cout << result << endl;
		return 0;
	}

    while(current < d){
    	if (max_stop - current == 0) {
    		cout << -1 << endl;
    		return 0;
    	}
    	else if (d - max_stop <= m){
    		current = max_stop;
    		++result;
    		cout << result << endl;
    		return 0;
    	}
    	else{
    		current = max_stop;
    		result++;
    	}

    	for (; k < stops.size() && (stops[k] - current) <= m ; k++){
    		max_stop = stops[k];
    	}
    }


    return 0;
}
