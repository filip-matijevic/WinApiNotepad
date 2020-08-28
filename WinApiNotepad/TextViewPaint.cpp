#include "TextView.h"

int TextView::OnPaint() {

	HDC fontHDC = GetDC(m_hwnd);
	TEXTMETRIC tm;

	GetTextMetrics(fontHDC, &tm);
	SelectFont(fontHDC, (HFONT)GetStockObject(ANSI_FIXED_FONT));
	ReleaseDC(m_hwnd, fontHDC);



	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(m_hwnd, &ps);
	TextOut(hdc, 20, 20, TEXT("TEMP TEXT 2"), 9);
	EndPaint(m_hwnd, &ps);
	return 0;
}