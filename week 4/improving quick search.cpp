#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <chrono>

using std::vector;
using std::swap;
using std::cout;
using std::cin;
using std::endl;
using std::min;
using namespace std::chrono;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

struct ret3{
	int lx, hx;
};


ret3 partition3(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  int r_h = r;
  int i = l;
  while(i <= r_h) {
	if (a[i] < x) {
		swap(a[j], a[i]);
		j++;
		i++;
	} else if (a[i] == x) {
		i++;
	} else {
		swap(a[i], a[r_h]);
		r_h -= 1;
	}
  }
  ret3 ret;
  ret.lx = j;
  ret.hx = r_h;
  return ret;
}

void quick3(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  ret3 tmp = partition3(a, l, r);

  auto one_start = steady_clock::now();
  quick3(a, l, tmp.lx - 1);
  auto one_end = steady_clock::now();
  auto two_start = steady_clock::now();
  quick3(a, tmp.hx + 1, r);
  auto two_end = steady_clock::now();

  std::chrono::duration<double> time_one = one_end - one_start;
  std::chrono::duration<double> time_two = two_end - two_start;
}


int main() {
  int n;
  std::cin >> n;
//  while(true){
//  n = rand() % 100000 +1;
//  cout << endl << n << endl;
  vector<int> init(n);
    for (size_t i = 0; i < n; ++i) {
//	  int tmp = rand() % 100 +1;
//	  init[i] = tmp;
//	  init.push_back(tmp);
	  std::cin >> init[i];
  }
//  vector<int> clone = init;
//  vector<int> a = init;

  auto rand_start = steady_clock::now();
//  randomized_quick_sort(a, 0, a.size() - 1);
  auto rand_end = steady_clock::now();
  auto quick_start = steady_clock::now();
  quick3(init, 0, init.size()-1);
  auto quick_end = steady_clock::now();
  for (size_t i = 0; i < init.size(); ++i) {
//  if (i % 30 == 0) cout << endl;
    std::cout << init[i] << ' ';
  }

  auto sort_start = steady_clock::now();
//  sort(clone.begin(), clone.end());
  auto sort_end = steady_clock::now();
  //  for (size_t i = 0; i < clone.size(); ++i) {
//	  if (i % 30 == 0) cout << endl;
//    std::cout << clone[i] << ' ';
//  }
/*
  bool err = false;
  	for (size_t i = 0; i < a.size(); i++){
  		if (a[i] != clone[i]) {
  			err = true;
  		}
  	}
  	if (err){
  		for (size_t i = 0; i < a.size(); ++i) {
  			  if (i % 30 == 0) cout << endl;
  		    std::cout << a[i] << ' ';
  		  }
  		  cout << endl;
  		for (size_t i = 0; i < clone.size(); ++i) {
  			  if (i % 30 == 0) cout << endl;
  		    std::cout << clone[i] << ' ';
  		  }
  		  cout << endl;

  	}

*/
/*

  std::chrono::duration<double> elaps_quick = quick_end - quick_start;
  std::chrono::duration<double> elaps_sort = sort_end - sort_start;
  std::chrono::duration<double> rand_sort = rand_end - rand_start;

  cout << endl << endl << rand_sort.count()  << endl << elaps_quick.count() << endl << elaps_sort.count() ;
//  cout << endl << endl << elaps_sort.count();
*/

//  }
}
