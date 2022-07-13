#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

/*
*You are responsible for collecting signatures from all tenants of a certain building. For each
*tenant, you know a period of time when he or she is at home.
*You would like to collect all signatures by visiting the building as few times as possible.
*The mathematical model for this problem is the following. You are given a set of segments on a
*line and your goal is to mark as few points on a line as possible so that each segment contains
*at least one marked point.

Hint: Sort segments according to their end times, make end time of the first segment the first
point. Loop through all and add their end times to points if they're disjoint with the current point.
*/
struct Segment {
    int start, end;
};

bool sort_by_end(const Segment& a, const Segment& b) {
    return (a.end < b.end);
}

std::vector<int> optimal_points(std::vector<Segment>& segments) {
    std::vector<int> points;

    std::sort(segments.begin(), segments.end(), sort_by_end);

    int point = segments[0].end;
    points.push_back(point);
    for (auto segemnt : segments) {
        if (point < segemnt.start || point > segemnt.end) {
            point = segemnt.end;
            points.push_back(point);
        }
    }

    return points;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }
    
    std::vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }

    return 0;
}
