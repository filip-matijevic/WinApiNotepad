#pragma once
#include <windows.h>
#include <windowsx.h>
#include "Window.h"
class RootWindow : public Window
{
public:
	virtual LPCTSTR ClassName() { return TEXT("Scratch"); }
	static RootWindow *Create();
protected:
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT OnCreate();
private:
	HWND m_hwndChild;
};