#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
  int start, end;
};


Segment findmax(vector<Segment> &segments){
	Segment s;
	s.start = segments[0].start; s.end = segments[0].end;
	bool found = false;;
	for (size_t i=1; i < segments.size(); i++){
		if (segments[i].start <= s.end && segments[i].end >= s.start){
			s.start = max(segments[i].start, s.start);
			s.end = min(segments[i].end, s.end);
			found = true;
		}
		/*else if (s.start <= segments[i].end){
			s.start = min(s.start, segments[i].end);
			s.end = min(segments[i].end, s.end);
			found = true;
		}*/

	}

	if (found) return s;
	else {
		Segment emt;
		emt.start = -1; emt.end = -1;
		return emt;
	}
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  while (!segments.empty())
  {
  if (segments.size() == 1){
	  points.push_back(segments[0].end);
	  return points;
  }
  /*else
  if (segments.size() == 2){
	  if (segments[0].start <= segments[1].end ||
			  segments[1].start <= segments[0].end){
		  points.push_back(segments[0].end);
	  }
	  else {
		  points.push_back(segments[0].end);
		  points.push_back(segments[1].end);
	  }
	  return points;
  }*/
  else {
	  Segment l = findmax(segments);
	  if (l.end == -1 && l.start == -1){
		  points.push_back(segments[0].end);
		  segments.erase(segments.begin());

	  }
	  else{
		  vector<Segment> tmp;
		  for (size_t i = 0; i < segments.size(); i++){
			  if (!(segments[i].start <= l.end && segments[i].end >= l.end)){
				  tmp.push_back(segments[i]);

			  }
		  }
//		  n -= static_cast<int>(segments.size() - tmp.size());
		  segments = tmp;
		  points.push_back(l.end);
	  }
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


