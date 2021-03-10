#include <string>
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>


using namespace std;

uint64_t get_fib(uint64_t& req){
		int i;
		vector<uint64_t> vec;
		vec.resize(req+1);
		if (req < 2){
			return req;
		}
		vec[0] = 0;
		vec[1] = 1;
		for (i=2; i <= req; i++){
			vec[i] = vec[i-1] + vec[i-2];
		}
		return vec[vec.size()-1];
}

vector<long> get_pisano_period(long m) {
    std::vector<long> v{1, 1};
    while (true) {
        auto t = (v[v.size() - 1] + v[v.size() - 2]) % m;
        v.push_back(t);
        if (t == 0 && v.size() % 2 == 0 &&
            std::equal(v.begin(), v.begin() + v.size() / 2,
                       v.begin() + v.size() / 2, v.end())) {
//            return v.size() / 2;
        	vector<long> tmp (v.begin(), v.begin() + v.size()/2);
        	return tmp;
        }
    }
//    return v.size() / 2;
    return v;
}

int gcd(int one, int two){
	if (two == 0) return one;
	return gcd(two, one%two);
}

int64_t lcd(int64_t one, int64_t two){
	if (one == 0 || two == 0) return 0;
	int64_t res = one * two / gcd(one, two);
	return res;
}

int main() {
	int one, two;
	cin >> one >> two;
	cout << lcd(one, two) << endl;

  return 0;
}
