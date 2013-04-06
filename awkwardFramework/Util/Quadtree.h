#pragma once
#ifndef __QUADTREE_H__
#define __QUADTREE_H__
//https://github.com/veeableful/Adaptive_Quadtree_Minimal
#include <vector>
using std::vector;

class Collider;

class Quadtree {

enum Node {
	NW = 0,
	NE,
	SW,
	SE,
	NodeCount
};

public:
	Quadtree();

	Quadtree( double left, double right, double top, double down, unsigned int numObjectsToGrow = 3 );

	~Quadtree();

	void AddObject( Collider *object );

	void Clear();

	vector<Collider*> GetObjectsAt( double x, double y );

private:
	double left;

	double right;

	double top;

	double down;

	unsigned int numObjectsToGrow;

	vector<Collider*> objects;

	Quadtree * nodes;

	bool isLeaf;

	bool contains( Collider *object );

	bool contains( double x, double y );

	void createLeaves();

	void moveObjectsToLeaves();

};

#endif