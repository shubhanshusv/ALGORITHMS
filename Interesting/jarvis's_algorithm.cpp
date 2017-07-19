// Shubhanshu Verma

// Convex hull (jarvis algorithm)
// uses orientatiion to find the next point that should be added to the convex hull

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct point{

	int x;
	int y;

};

int orientation(point p, point q, point r);
void convex_hull(vector<point> set);

int main(){

	vector<point> points;

	point p = {0,3};
	points.push_back(p);
	p = {2,2};
	points.push_back(p);
	p = {1,1};
	points.push_back(p);
	p = {2,1};
	points.push_back(p);
	p = {3,0};
	points.push_back(p);
	p = {0,0};
	points.push_back(p);
	p = {3,3};
	points.push_back(p);

	convex_hull(points);

    return 0;
}

int orientation(point p, point q, point r){

	int value = (q.y - p.y)*(r.x-q.x) - (r.y - q.y)*(q.x - p.x);

	if(value < 0){

		return 2;

	}else if(value > 0){

		return 1;

	}else{

		return 0;

	}

}

void convex_hull(vector<point> set){

	int n = set.size();

	vector<point> result;

	if(n < 3){

		return;

	}

	int leftmost = 0;

	int i;

	for(i=1;i<n;i++){

		if(set[i].x < set[leftmost].x){

			leftmost = i;

		}

	}

	int p,q;
	p = leftmost;

	do{

		result.push_back(set[p]);

		q = (p+1)%n;

		for(i=0;i<n;i++){

			if(orientation(set[p],set[i],set[q]) == 2){

				q = i;

			}


		}

		p = q;

	}while(p != leftmost);

	for(i=0;i<result.size();i++){

		cout << result[i].x << " " << result[i].y << endl;

	}

}
