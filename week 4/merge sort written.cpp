#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}

vector<int> merge(vector<int>& one, vector<int>& two){
	/*for (auto& it:two){
		one.push_back(it);
	}*/
	vector<int> one_tmp = one, two_tmp = two, res;
	size_t i=0, k=0;
	while(i < one_tmp.size() && k < two_tmp.size()){
		if (one_tmp[i] <= two_tmp[k]){
			res.push_back(one_tmp[i]);
			i++;
		}
		else {
			res.push_back(two_tmp[k]);
			k++;
		}
	}

	while(i < one_tmp.size()){
			res.push_back(one_tmp[i]);
			i++;
	}
	while(k < two_tmp.size()){
			res.push_back(two_tmp[k]);
			k++;
	}

	return res;
}

vector<int> mergesort(vector<int>& a, int l, int h){
	if ((h - l) == 0){
		vector<int> tmp;
		tmp.push_back(a[h]);
		return tmp;
	}
	int mid = l + (h-l)/2;
	vector<int> b = mergesort(a, l, mid);
	vector<int> c = mergesort(a, ++mid, h);
	vector<int> mg = merge(b,c);

	return mg;
}


int main() {
  int n;
//  std::cin >> n;
  while (true){
  n = rand() % 30 +1;
  vector<int> a(n);
//  vector<int> lecture = {7,2,5,3,7,13,1,6};
  for (int i=0; i < n; i++){
	  a[i] = static_cast<int>(rand() % 10 +1);
  }
  vector<int> test = a, it = a;
  std::sort(test.begin(), test.end());
  vector<int> inter = mergesort(it, 0, it.size()-1);
  bool error = false;
  for (size_t i=0; i < test.size(); i++){

	  if (test[i] != inter[i]){
		  std::cout << "shit";
		  error = true;
		  std::cout << test[i] << "  " << inter[i] << std::endl;
	  }
  }
  if (error){
  for (size_t i=0; i < test.size(); i++){
	  std::cout << test[i] << ' ';
  }
  std::cout << std::endl;
  for (size_t i=0; i < inter.size(); i++){
  	  std::cout << inter[i] << ' ';
    }
  std::cout << std::endl;
  for (size_t i=0; i < a.size(); i++){
  	  std::cout << a[i] << ' ';
    }
  std::cout << std::endl;
  }
  }
  /*
  for (auto& it:inter){
	  std::cout << it << " ";

  }
  vector<int> mg = mergesort(lecture, 0, lecture.size()-1);
  for (auto& it:mg){
	  std::cout << it << std::endl;
  }
  for (size_t i = 0; i < a.size(); i++) {


//    std::cin >> a[i];
  }
  vector<int> b(a.size());
*/
//  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
