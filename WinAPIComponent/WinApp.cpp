#include "pch.h"
#include "WinApp.h"

WinApp::WinApp(HINSTANCE hInstance, HINSTANCE hPrevInstacne, int nCmdShow) 
	: _hInstance(hInstance), _hPrevInstacne(hPrevInstacne), _nCmdShow(nCmdShow)
{
}

int WinApp::GetMessageDispatch()
{
	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}
