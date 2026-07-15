#include "DxLib.h"
#include<System/Application/Application.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	auto* app = Application::Get();
	app->Initialize({});
	app->Run();
	app->Finalize();
	return 0;
}