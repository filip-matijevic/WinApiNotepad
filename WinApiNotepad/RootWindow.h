#pragma once
#include "Window.h"
#include "TextView.h"
class RootWindow : public Window
{
public:
	virtual LPCTSTR ClassName() { return TEXT("Scratch"); }
	static RootWindow *Create();
protected:
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT OnCreate();
private:
	TextView *textView;
	HWND m_hwndChild;
};