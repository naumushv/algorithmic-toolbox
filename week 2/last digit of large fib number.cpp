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

int last_fib(int64_t& fib){
	return fib%10;
}

ostream& operator<<(ostream& os, vector<long> vec){
	for (int i=0; i < static_cast<long>(vec.size()); i++){
		os << vec[i] << "  ";
		if (i%10 == 0) os << endl;
	}
	return os;
}

int main() {

/*
	for (int i = 0; i < 70; i++){
		cout << get_fib(i) % 10 << "  ";
		if (i % 10 == 0) cout << endl;
	}
*/
	int Modulo = 10;
	uint64_t input;
	cin >> input;
	vector<long> vv = get_pisano_period(Modulo);
	int index = (input%60)-1;
	if (index == -1) cout << 0;
	else{
	cout << vv[index] << endl;
	}
//	cout << vv.size() << endl;
//	cout << get_pisano_period(5) << endl;



  return 0;
}
