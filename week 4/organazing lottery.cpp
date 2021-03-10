/*#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>


using std::vector;
using std::swap;
using std::min;

enum points{
	l,
	p,
	e
};

struct pnt{
	int p;
	points type;
	int index;
};

bool operator==(vector<int>& a, vector<int>& b){
	if (a.size() != b.size()) return false;
	for (size_t i=0; i < a.size(); i++){
		if (a[i] != b[i]) return false;
	}
	return true;
}


vector<int> fast_count_segments(vector<pnt>& v, int m) {
	int j=0;
	vector<int> res(m);
	for (int i=0; i < v.size(); i++){
		if (v[i].type == points::l) ++j;
		else if (v[i].type == points::e) --j;
		else if (v[i].type == points::p){
			res[v[i].index] = j;
		}
	}
	return res;
}


//point and quantity
void print_pq(vector<pnt>& a){
	for (size_t i=0; i < a.size(); i++){
	  	  std::cout << a[i].p << " " << a[i].q;
	  	  std::cout << std::endl;
	    }
	    std::cout << std::endl;
}


void print_ptype(vector<pnt>& a){
	for (size_t i=0; i < a.size(); i++){
		  std::cout << a[i].p << " " << a[i].type;
		  std::cout << std::endl;
	  }
	  std::cout << std::endl;
}


void print_answ(vector<pnt>& a){
    for (size_t i=0; i < a.size(); i++){
    	  std::cout << a[i].q << " " ;
      }
      std::cout << std::endl;
}

//copied shit-------------------------------------------------------
struct coords
{
  int point;
  char role;
  int actualIndex;
};

void print_vector(vector<int> a)
{
  for (auto x : a)
  {
    std::cout << x << " ";
  }
}

void print(vector<coords> a)
{
  for (auto x : a)
  {
    std::cout << "start:" << x.point << ", role:" << x.role << "\n";
  }
}

bool compare(pnt a, pnt b)
{
  if (a.p == b.p)
  {
    if (a.type == points::l)
    {
      return true;
    }
    else if (b.type == points::l)
    {
      return false;
    }
    else if (a.type == points::p)
    {
      return true;
    }
    else if (b.type == points::p)
    {
      return false;
    }
    else if (a.type == points::e)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (a.p < b.p)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool compareFunc(coords a, coords b)
{
  if (a.point == b.point)
  {
    if (a.role == 'l')
    {
      return true;
    }
    else if (b.role == 'l')
    {
      return false;
    }
    else if (a.role == 'p')
    {
      return true;
    }
    else if (b.role == 'p')
    {
      return false;
    }
    else if (a.role == 'r')
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else if (a.point < b.point)
  {
    return true;
  }
  else
  {
    return false;
  }
}



vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
  vector<int> cnt(points.size());
  vector<coords> all_points;
  for (size_t i = 0; i < starts.size(); i++)
  {
    coords c;
    c.point = starts[i];
    c.role = 'l';
    all_points.push_back(c);
  }
  for (size_t i = 0; i < ends.size(); i++)
  {
    coords c;
    c.point = ends[i];
    c.role = 'r';
    all_points.push_back(c);
  }
  for (size_t i = 0; i < points.size(); i++)
  {
    coords c;
    c.point = points[i];
    c.role = 'p';
    c.actualIndex = i;
    all_points.push_back(c);
  }
  std::sort(all_points.begin(), all_points.end(), compareFunc);

//  print(all_points);
  int segments = 0;
  for (size_t i = 0; i < all_points.size(); i++)
  {
    if (all_points[i].role == 'l')
    {
      segments++;
    }
    else if (all_points[i].role == 'p')
    {
      cnt[all_points[i].actualIndex] = segments;
    }
    else
    {
      segments--;
    }
  }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++)
  {
    for (size_t j = 0; j < starts.size(); j++)
    {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}
//end ------------------------------------------------------------------

void porint_answ(vector<int>& a){
	for (size_t i = 0; i < a.size(); i++) {
		  std::cout << a[i] << ' ';
	  }
	std::cout << std::endl;
}

int main() {

	int brr=0, sh=0;
	while(brr < 300){
  int n, m;
//  std::cin >> n >> m;
  n = rand() % 1000 +10;
  m = rand() % (n - (rand() % n));
  vector<pnt> v(n+n+m);
  vector<int> starts(n), ends(n);
  vector<int> points(m);
  for (int i =0; i < n; i++){
	  int num1, num2;
	  num1 = rand() % 150000 +1;
	  num2 = num1 + (rand() % 100000);
//	  std::cin >>
	  v[i].p = num1;
	  v[i].type = points::l;
//	  std::cin >>
	  v[n+i].p = num2;
	  v[n+i].type = points::e;
	  starts[i] = v[i].p;
	  ends[i] = v[n+i].p;
  }
  for(int i=n+n, j=0; i < n+n+m; j++,i++){
	  int num;
	  num = rand() % 250000;
	  //	  std::cin >>
	  v[i].p = num;
	  v[i].type = points::p;
	  v[i].index = j;
	  points[j] = v[i].p;
  }


  auto steal_start = std::chrono::steady_clock::now();
  vector<int> cnt = fast_count_segments(starts, ends, points);
//  porint_answ(cnt);
  auto steal_end = std::chrono::steady_clock::now();

  auto me_start = std::chrono::steady_clock::now();
//  randomized_quick_sort(v, 0, v.size()-1);
//  order(v);

  std::sort(v.begin(), v.end(), compare);

  vector<int> r_v = fast_count_segments(v);

//  randomized_quick_sort_ix(r, 0, r.size()-1);
//  print_answ(r);
  auto me_end = std::chrono::steady_clock::now();

  //vector for r
//  vector<int> r_v = give(r);



  auto naive_start = std::chrono::steady_clock::now();
  vector<int> shit = naive_count_segments(starts, ends, points);
//  porint_answ(shit);
  auto naive_end = std::chrono::steady_clock::now();

  naive_count_segments(starts, ends, points);

  std::chrono::duration<double> me_elapsed_seconds = me_end- me_start;
  std::chrono::duration<double> steal_elapsed_seconds = steal_end- steal_start;
  std::chrono::duration<double> naive_elapsed_seconds = naive_end- naive_start;

//  if (! (cnt == shit) || ! (cnt == r_v) || ! (shit == r_v)){
  if (me_elapsed_seconds < steal_elapsed_seconds * 5 || me_elapsed_seconds < naive_elapsed_seconds * 2){
	  sh++;
	  std::cout << "---------shit----------" << std::endl;
	  porint_answ(r_v);
	  porint_answ(cnt);
	  porint_answ(shit);
  }
  if (me_elapsed_seconds > steal_elapsed_seconds * 3){
  std::cout << "me time: " << me_elapsed_seconds.count() << "s\n";
  std::cout << "steal time: " << steal_elapsed_seconds.count() << "s\n";
  std::cout << "naive time: " << naive_elapsed_seconds.count() << "s\n";
  }


  ++brr;
	}
	std::cout << std::endl << sh << " shits out of " << brr << std::endl;

	int n, m;
  std::cin >> n >> m;
  vector<pnt> v(n+n+m);
  for (int i =0; i < n; i++){
  	  std::cin >> v[i].p;
  	  v[i].type = points::l;
  	  std::cin >> v[n+i].p;
  	  v[n+i].type = points::e;
    }
    for(int i=n+n, j=0; i < n+n+m; j++,i++){
	  std::cin >> v[i].p;
  	  v[i].type = points::p;
  	  v[i].index = j;
    }

    std::sort(v.begin(), v.end(), compare);

    vector<int> r_v = fast_count_segments(v, m);

    porint_answ(r_v);


    return 0;
}*/


#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::vector;
vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
    vector<int> cnt(points.size());
    int n = starts.size();
    int m = points.size();

    sort(starts.begin(),starts.end());
    sort(ends.begin(),ends.end());
    for(int i = 0; i < m; ++i){
        auto it1 = upper_bound(starts.begin(),starts.end(),points[i]);
        auto it2 = lower_bound(ends.begin(),ends.end(),points[i]);
        int x = it1 - starts.begin();
        int y = it2 - ends.begin();
        cnt[i] = x - y;
    }

    return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
