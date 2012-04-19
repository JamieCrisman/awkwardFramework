#include "CApp.h"
void CApp::OnRender()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//SDL_Flip(Surf_Display);
	CAppStateManager::OnRender(Surf_Display);
	SDL_GL_SwapBuffers();
}