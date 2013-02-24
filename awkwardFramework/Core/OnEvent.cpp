#include "../Youkozo.h"

void Youkozo::OnEvent(SDL_Event* Event)
{
	CEvent::OnEvent(Event);

	CAppStateManager::OnEvent(Event);
}

void Youkozo::OnExit()
{
	Running = false;
}
