#ifndef _CFPS_H_
	#define _CFPS_H_

#include <SDL.h>

class CFPS{
public:
	static CFPS FPSControl;
	CFPS();

	void OnLoop();

	int GetFPS();

	float GetSpeedFactor();

private:
	int OldTime;
	int LastTime;
	float SpeedFactor;
	int NumFrames;
	int Frames;


};


#endif