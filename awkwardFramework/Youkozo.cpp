#include "Youkozo.h"

Youkozo::Youkozo()
{
	Running = true;
	//Surf_Display = NULL;
	
}

int Youkozo::OnExecute()
{
	if(OnInit() == false)
	{
		return -1;
	}

	SDL_Event Event;

	while(Running)
	{
		while(SDL_PollEvent(&Event))
		{
			OnEvent(&Event);
		}
		OnLoop();
		OnRender();
	}
	OnCleanup();
	
	return 0;
}


int main(int argc, char* argv[])
{
	Youkozo theApp;
	return theApp.OnExecute();
}