#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>

using namespace std;


bool money(long one, long two){
	vector<long> v_one, v_two;
//	cout << one << "   " << two << endl;
	while (one > 9){
		v_one.push_back(one % 10);
		one /= 10;
	}
	while (two > 9){
		v_two.push_back(two % 10);
		two /= 10;
	}
	v_one.push_back(one);
	v_two.push_back(two);


	while (!v_one.empty() && !v_two.empty()){
		if (v_one.back() > v_two.back()) return true;
		else if (v_one.back() < v_two.back()) return false;
		v_one.pop_back();
		v_two.pop_back();
	}
//	cout << endl << "** I have been there **" << endl;
	if (v_one.empty()) return true;
	else {
		return false;
	}
}

struct num{
	long n;
};

bool operator>(num one, num two){
	vector<long> v_one, v_two;
//	cout << one.n << "   " << two.n << endl;
	if (one.n == 9) return true;
	while (one.n > 9){
		v_one.push_back(one.n % 10);
		one.n /= 10;
	}
	while (two.n > 9){
		v_two.push_back(two.n % 10);
		two.n /= 10;
	}
	v_one.push_back(one.n);
	v_two.push_back(two.n);


	while (!v_one.empty() && !v_two.empty()){
		if (v_one.back() > v_two.back()) return true;
		else if (v_one.back() < v_two.back()) return false;
		v_one.pop_back();
		v_two.pop_back();
	}
//	cout << endl << "** I have been there **" << endl;
	if (v_one.empty()) return true;
	else {
		return false;
	}
}



int main() {
/*
  long n, tmp;
  cin >> n;
  vector<long> nums;
  for (long i=0; i<n; i++){
	  cin >> tmp;
	  nums.push_back(tmp);
  }
  sort(nums.begin(), nums.end(), money);
  for (auto f:nums){
	  cout << f;
  }
*/



/*
	int i=0;
	while (true){
		long n = rand() % 100 +1 ;
		vector<long> brrr;
		for (int k=0; k<n; k++){
			long one = rand() % 1000 +1;
			brrr.push_back(one);
		}
		cout << "initial n:" << n << endl;
		for (auto& l:brrr){
					cout << l << "^";
		}
		cout << endl;
		sort(brrr.begin(), brrr.end(), money);
		cout << "secondary n" << n << endl;
		for (auto& r:brrr){
			cout << r << "*";
		}
		cout  << endl << endl << endl;
//		cout << one << "    " << two << "    " <<  money (one, two) << endl;

		i++;
		if (i == 10000) {
			cout << endl << "*****" << i  << "*****" << endl;
			i =0;
		}
	}
*/

//	vector<long> it = {766,660,279,746,489,482,410,804,181,456,681,690,836,981,464,432,539,312,677,742,361,76,793,118,515,51,356,9,79,458,898,844,469,528,941,957,9};
//	vector<long> it = {766,660,279,746,489,482,410,804,181,456,681,690,836,981,464};
//	vector<long> it = {766,660,279,746,489,482,410,804,181,456,681,690,836,981,464,432,539,312,677,742,361,76,793,118};
//	vector<long> it = {766,660,279,746,489,482,410,804,181,456,681,690,836,981,464,432,539,312,677,742,361,76,793,118,515,51,356,9,79,458};
//	vector<long> it = {766,660,279,746,489,482,410,804,181,456,681,690,836,981,464,432,539,312,677,742,361,76,793,118,515,51,356,9,79,458,898,844,469,528,941,957,9};
//	vector<long> it = {766,660,279,746,489,482,410,804,181,456,681,690,836,981,464,432,539,312,677,742,361,76,793,118,515,51,356,9,79,458,898,844,469,528};
//	vector<long> it = {766,660,279,746,489,482,410,804,181,9,456,681,690,9,836,981};
//	vector<long> it = {361,76,793,118,515,51,356,9,79,458,898,844,469,528,941,957,9};
//	vector<long> it = {766,660,279,746,489,482,410,804,181,456,681,690,836,981,464,432,539,312,677,742,361,76,793,118,515,51,356,9,79,458,898,844,469,528,941,957,9};
//	vector<long> it = {681,690,836,981,464,432,539,312,677,742,361,76,793,118,515,51,356,9,79,458,898,844,469,528,941,957,9};
//	vector<long> it = {746,489,482,410,804,181,456,681,690,836,981,464,432,539,312,677,742,361,76,793,118,515,51,356,9,79,458,898,844,469,528,941,957,9};
//	vector<long> it = {660,279,746,489,482,410,804,181,456,681,690,836,981,464,432,539,312,677,742,361,76,793,118,515,51,356,9,79,458,898,844,469,528,941,957,9};
	vector<long> it = {766,660,279,746,489,482,410,804,181,456,681,690,836,981,464,432,539,312,677,742,361,76,793,118,515,51,356,9,79,458,898,844,469,528,941,957, 9};
	/*set<long, greater<long>> its;
	for (long l:{766,660,279,746,489,482,410,804,181,456,681,690,836,981,464,432,539,312,677,742,361,76,793,118,515,51,356,9,79,458,898,844,469,528,941,957,9}){
		num tmp;
		tmp.n = l;
		its.insert(l);
	}*/
	cout << it.size() << endl;
	sort(it.begin(), it.end(), money);
//	for (int i)
	for (auto f:it){
		  cout << f << "*";
	  }

  return 0;
}
