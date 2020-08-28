#include "TextView.h"

TextView *TextView::Create(HWND handle)
{
	TextView *self = new TextView();
	if (self && self->WinCreateWindow(0,
		TEXT("Scratch"), 
		WS_VSCROLL | WS_HSCROLL | WS_CHILD | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		handle, NULL)) {
		return self;
	}
	delete self;
	return NULL;
}

LRESULT TextView::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_PAINT:
		return OnPaint();
	case WM_CREATE:
		return OnCreate();
	case WM_NCDESTROY:
		// Death of the root window ends the thread
		PostQuitMessage(0);
		break;
	}
	return Window::HandleMessage(uMsg, wParam, lParam);
}

LRESULT TextView::OnCreate()
{
	return 0;
}