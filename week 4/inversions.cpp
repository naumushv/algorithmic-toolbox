#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

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

long long get_inversions(vector<int> &a, vector<int> &b, size_t left, int ave, size_t right) {
    size_t i = left, j = ave, k = left;
    long long inv_count = 0;
    while (i <= ave - 1 && j <= right) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            inv_count += ave - i;
            j++;
        }
        k++;
    }
    while (i <= ave - 1) {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= right) {
        b[k] = a[j];
        j++;
        k++;
    }
    for (i = left; i <= right; i++) {
        a[i] = b[i];
    }
    return inv_count;
}

long long merge_sort(vector<int> &a, vector<int> &b, size_t left, size_t right) {
    long long inv_count = 0;
    if (right <= left) return inv_count;
    size_t ave = left + (right - left) / 2;
    inv_count += merge_sort(a, b, left, ave);
    inv_count += merge_sort(a, b, ave + 1, right);
    inv_count += get_inversions(a, b, left, ave + 1, right);
    return inv_count;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
//  vector<int> lecture = {7,2,5,3,7,13,1,6};
  for (int i=0; i < n; i++){
	  std::cin >> a[i];
  }
  vector<int> b(a.size());
  cout << merge_sort(a,b,0,a.size()-1) << endl;


  }
