#ifndef _CCAMERA_H_
	#define _CCAMERA_H_

#include <SDL.h>
#include "../Core/Define.h"

enum {
	TARGET_MODE_NORMAL = 0,
	TARGET_MODE_CENTER
};

class CCamera{
public:
	static CCamera CameraControl;
	int TargetMode;

	CCamera();
	void OnMove(int MoveX, int MoveY);

	int GetX();
	int GetY();

	void SetPos(int X, int Y);
	void SetTarget(float* X, float* Y);

private:
	int X;
	int Y;

	float* TargetX;
	float* TargetY;



};



#endif