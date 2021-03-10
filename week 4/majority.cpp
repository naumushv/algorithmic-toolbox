#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

//int findit(const vector<int>)

int srch(vector<int>& a, int elem, int left, int right){
	int res = 0;
	for (int i=left; i<=right; i++){
		if (a[i] == elem) res++;
	}
	return res;
}

int get_majority_element(vector<int> &a, int left, int right) {

	if (left == right) return a[left];
	int mid = left + (right - left)/2;
	int left_end = get_majority_element(a, left, mid);
	int right_end = get_majority_element(a, mid+1, right);
	if (left_end == right_end) return left_end;
	else if (left_end == right_end && left_end == -1) return -1;
	else if (left_end == -1) {
		int brr_left_cnt = srch(a, right_end, left, right);
		if (brr_left_cnt > (((right+1)-left)/2)) return right_end;
		else return -1;
	}
	else if (right_end == -1){
		int brr_right_cnt = srch(a, left_end, left, right);
		if (brr_right_cnt > (((right+1)-left)/2)) return left_end;
		else return -1;
	}
	int left_end_cnt = srch(a, left_end, left, right);
	int right_end_cnt = srch(a, right_end, left, right);
	if (left_end_cnt > (((right+1)-left)/2)) return left_end;
	else if ((((right+1)-left)/2 ) < right_end_cnt) return right_end;
	else return -1;

}


int naive_majority(const vector<int>& vec){
	int size = vec.size();
	for (int i=0; i < size; i++){
		int current = vec[i], cnt=0;
		for (int j=0; j < size; j++){
			if (vec[j] == current) cnt++;
			if (cnt > size/2) return current;
		}
	}
	return -1;
}


int main() {

	  int n;
	  std::cin >> n;
	  vector<int> a(n);
	  for (size_t i = 0; i < a.size(); ++i) {
	    std::cin >> a[i];
	  }
//	  vector<int> a = {2,3,9,2,2};
//	  vector<int> a = {2,1,0,1,2,1};
//	  vector<int> a = {1,2,2,0,1,1};
	  int res = (get_majority_element(a, 0, a.size()-1));
	  if (res == -1) cout << 0 << endl;
	  else cout << 1 << endl;
//	  std::cout << (get_majority_element(a, 0, a.size()-1)) << '\n';

/*	  while (true){
		  n = rand() % 10 +1;
		  vector<int> rr;
		  for (int i=0; i < n; i++){
			  int tmp = rand() % 3;
			  rr.push_back(tmp);
		  }
		  if (naive_majority(rr) != get_majority_element(rr, 0, rr.size()-1)){
			  cout << "naive majority: " << naive_majority(rr) << endl;
			  cout << "recursive majority: " << get_majority_element(rr, 0, rr.size()-1) << endl;
		  for (auto& d:rr){
			  cout << d << "," ;
		  }
		  cout << endl;
		  }

//		  std::cout << (get_majority_element(rr, 0, rr.size()-1)) << endl ;
  }*/

  return 0;
}


