#include "CFPS.h"
#define MIN(a, b) (((a) < (b)) ? (a) : (b)) 
#define MAX_DELTA_TIME 1.0/30.0
CFPS CFPS::FPSControl;

CFPS::CFPS(){
	OldTime = 0;
	LastTime = 0;

	SpeedFactor = 0;
	deltaTime = 0.0;
	Frames = 0;
	NumFrames = 0;
}


void CFPS::OnLoop(){
	if(OldTime + 1000 < SDL_GetTicks()){
		OldTime = SDL_GetTicks();

		NumFrames = Frames;

		Frames = 0;
	}

	SpeedFactor = ((SDL_GetTicks() - LastTime)/1000.0f) * 32.0f;
	deltaTime = MIN(((SDL_GetTicks() - LastTime)/1000.0f), MAX_DELTA_TIME);
	LastTime = SDL_GetTicks();
	Frames++;
}

int CFPS::GetFPS(){
	return NumFrames;
}

float CFPS::GetSpeedFactor(){
	return SpeedFactor;
}

float CFPS::GetDeltaTime(){
	return deltaTime;
}