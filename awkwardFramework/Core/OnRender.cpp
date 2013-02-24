#include "../Youkozo.h"
void Youkozo::OnRender()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//SDL_Flip(Surf_Display);
	CAppStateManager::OnRender();
	SDL_GL_SwapBuffers();
}