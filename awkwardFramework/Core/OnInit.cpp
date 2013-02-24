#include "../Youkozo.h"

bool Youkozo::OnInit()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		//SDL_Init returns -1 if it fails so return false
		return false; 
	}

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE, 8);

	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 1);


	if((Surf_Display = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32, SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL)) == NULL)
	{
		return false;
	}
	//if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0){
	//	return false;
	//}


	glClearColor(0,0,0,0);
	glClearDepth(1.0f);
	glViewport(0,0, WWIDTH, WHEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, WWIDTH, WHEIGHT, 0, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();


	/*
	if((SoundA = CSoundBank::SoundControl.OnLoad("./music/sounda.wav")) == -1){
		return false;
	}
	if((SoundB = CSoundBank::SoundControl.OnLoad("./music/soundb.wav")) == -1){
		return false;
	}*/

	SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

	CAppStateManager::SetActiveAppState(APPSTATE_INTRO);



	return true;
}