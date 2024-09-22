#pragma once
class __declspec(dllexport) FileUtils
{
public:
	static bool OpenFile(HWND hWnd, wchar_t* filePath);
};

