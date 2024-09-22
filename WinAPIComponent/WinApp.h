#pragma once
class __declspec(dllexport) WinApp
{
protected:
	HINSTANCE _hInstance;
	HINSTANCE _hPrevInstacne;
	int       _nCmdShow;

public:
	WinApp(HINSTANCE hInstance, HINSTANCE hPrevInstacne, int nCmdShow);

	int GetMessageDispatch();
	virtual void Init() abstract;
};