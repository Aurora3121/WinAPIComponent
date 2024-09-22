#pragma once
class __declspec(dllexport) WndFrame
{
protected:
	HWND			_hwnd;
	HINSTANCE		_hInstance;
	wchar_t			_className[30];
	wchar_t			_titleName[30];
	int				_spawnX;
	int				_spawnY;
	int				_width;
	int				_height;
public:
	WndFrame(HINSTANCE hInstance, const wchar_t* className, const wchar_t* titleName, int spawnX, int spawnY, int width, int height);
	virtual ~WndFrame();

	virtual bool Init();
	virtual LRESULT MessageProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) abstract;
	static LRESULT  WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	HWND GetHWND() { return _hwnd; }
};

