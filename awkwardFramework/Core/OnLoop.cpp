#include "../Youkozo.h"

void Youkozo::OnLoop(){
	CAppStateManager::OnLoop();
	CFPS::FPSControl.OnLoop();

}