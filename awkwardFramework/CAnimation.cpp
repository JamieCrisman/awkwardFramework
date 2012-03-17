#include "CAnimation.h"

CAnimation::CAnimation()
{
	CurrentFrame = 0;
	MaxFrames = 0;
	FrameInc = 1;
	FrameRate = 100;
	OldTime = 0;
	Oscillate = false;

}

void CAnimation::OnAnimate()
{
	if(OldTime + FrameRate > SDL_GetTicks())
	{
		return;
	}

	OldTime = SDL_GetTicks();

	CurrentFrame += FrameInc;
	if(Oscillate)
	{
		if(FrameInc > 0)                 //if frame increment is positive
		{								// check if current has past the max
			if(CurrentFrame >= MaxFrames)
			{						  // flip increment to make it animate backwards
				FrameInc = -FrameInc;
			}
		}
		else
		{							//if its going backwards and hits 0
			if(CurrentFrame <= 0)
			{						//flip it so frame inc to go other direction
				FrameInc = -FrameInc;
			}
		}
	}else
	{								//repeats animation
		if(CurrentFrame >= MaxFrames)
			CurrentFrame = 0;
	}
}

void CAnimation::SetFrameRate(int Rate)
{
	FrameRate = Rate;
}

void CAnimation::SetCurrentFrame(int Frame)
{
	if(Frame < 0 || Frame >= MaxFrames)


	CurrentFrame = Frame;
}

int CAnimation::GetCurrentFrame()
{
	return CurrentFrame;
}