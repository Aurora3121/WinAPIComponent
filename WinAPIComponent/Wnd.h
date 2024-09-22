#pragma once
#include "WndFrame.h"
class __declspec(dllexport) Wnd : public WndFrame
{
protected:
	HWND _frameWnd;

public:
	Wnd(HINSTANCE hInstance, const wchar_t* className, const wchar_t* titleName, int spawnX, int spawnY, int width, int height, HWND frameWnd);
	virtual ~Wnd();

	virtual bool Init();
	virtual LRESULT MessageProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) abstract;
};

