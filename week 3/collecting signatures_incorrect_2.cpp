#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
  int start, end;
};


int findmax(vector<Segment> &segments){
	Segment s;
	s.start =-1; s.end = -1;
	int start=0, end=0, index, global_max = 0;
	start = segments.front().start;
	for (auto& it:segments){
		start = it.start < start ? it.start:start;
		end = it.end > end ? it.end : end;
	}

	for (; start < end; start++){
		int max = 0 ;
		for (auto& it:segments){
			if (start >= it.start && start <= it.end)
				max++;
		}
		if (max > global_max){
			global_max = max;
			index = start;
		}
	}

	if (global_max <= 1){
		return -1;
	}
	else return index;


}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  int ma;
  while ((ma = findmax(segments)) != -1){
	  vector<Segment> tmp;
	  for (auto& it:segments){
		  if (!(ma >= it.start && ma <= it.end)){
			  tmp.push_back(it);
		  }
	  }
	  points.push_back(ma);
	  segments = tmp;
  }

  if (!segments.empty()){
	  for (auto& it:segments){
		  points.push_back(it.end);
	  }
  }

  return points;

}

void inp(vector<Segment>& segments){
	for (size_t i = 0; i < segments.size(); ++i) {
	    std::cin >> segments[i].start >> segments[i].end;
  }
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  inp(segments);
  vector<int> points = optimal_points(segments);
  sort(points.begin(), points.end());
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
