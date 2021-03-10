#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>

using namespace std;

struct Segment {
  int start, end;
};

bool operator<(const Segment& one, const Segment& two){
	if (one.end < two.end) return true;
	return false;
}

bool sort_end(Segment& one, Segment two){
	if (one.end < two.end) return true;
	return false;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  int end;
  bool first = true;
  sort(segments.begin(), segments.end(), sort_end);
  for (auto& it:segments){
	  if (first){
		  end = it.end;
		  points.push_back(end);
		  first = false;
	  }
	  else {
		  if (end < it.start || end > it.end){
			  end = it.end;
			  points.push_back(end);
		  }
	  }
  }

  return points;

}


/*void inp(vector<Segment>& segments, int& n){
	for (int i = 0; i < n; ++i) {
		Segment tmp;
	    std::cin >> tmp.start >> tmp.end;
	    segments.insert(tmp);
  }
}*/

void out(set<Segment>& segments){
	for (auto& it:segments){
		cout << it.start << "  " << it.end << "  " << endl;
	}
}

void out(vector<Segment>& segments){
	for (auto& it:segments){
		cout << it.start << "  " << it.end << "  " << endl;
	}
}


int main() {
  int n;
  std::cin >> n;
  vector <Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
	  std::cin >> segments[i].start >> segments[i].end;
  }
//    out(segments);
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
