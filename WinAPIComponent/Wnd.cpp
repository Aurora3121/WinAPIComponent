#include "pch.h"
#include "Wnd.h"

Wnd::Wnd(HINSTANCE hInstance, const wchar_t* className, const wchar_t* titleName, int spawnX, int spawnY, int width, int height, HWND parentHwnd)
    : WndFrame(hInstance, className, titleName, spawnX, spawnY, width, height), _frameWnd(parentHwnd)
{
}

Wnd::~Wnd()
{
}

bool Wnd::Init()
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = sizeof(LONG_PTR); // 여기 주의
	wcex.hInstance = _hInstance;
	wcex.hIcon = LoadIcon(_hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _className;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
	{
		int errorCode = GetLastError();
		return false;
	}

	_hwnd = CreateWindow(
		_className,
		_titleName,
		WS_CHILD | WS_VISIBLE, 
		_spawnX, _spawnY,
		_width, _height,
		_frameWnd,
		NULL,
		_hInstance,
		this
	);

	if (!_hwnd)
	{
		int errorCode = GetLastError();
		return false;
	}

	ShowWindow(_hwnd, 10);
	UpdateWindow(_hwnd);

	return true;
}