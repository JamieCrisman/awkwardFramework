#pragma once
#ifndef __QUADTREE_H__
	#define __QUADTREE_H__

#include <vector>

using namespace std;

class Quadtree;
class Collider;

class Quadtree {
public:
	Quadtree(float x, float y, float width, float height, int level, int maxLevel);

	~Quadtree();

	void AddObject(Collider *object);
	vector<Collider*> GetObjectsAt(float x, float y);
	void Clear();

private:
	float x;
	float y;
	float width;
	float height;
	int level;
	int maxLevel;
	vector<Collider*> objects;

	Quadtree * parent;
	Quadtree * NW;
	Quadtree * NE;
	Quadtree * SW;
	Quadtree * SE;

	bool contains(Quadtree *child, Collider *object);
};

#endif