#pragma once
#include "Window.h"
class TextView : public Window
{
public:
	virtual LPCTSTR ClassName() { return TEXT("Text View"); }
	static TextView *Create(HWND parentHandle);
protected:
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT OnCreate();
private:
	HWND m_hwndChild;

	int OnPaint();
};
