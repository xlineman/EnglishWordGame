#include "stdafx.h"
#include "CardControl.h"


CCardControl::CCardControl()
{
}


CCardControl::~CCardControl()
{
}

BEGIN_MESSAGE_MAP(CCardControl, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()

BOOL CCardControl::CreateCard(CWnd* pParent, const CRect& rect, const CString& strWord)
{
	m_strWord = strWord;
	return Create(_T(""), WS_CHILD | WS_VISIBLE | SS_OWNERDRAW, rect, pParent, 1001); // 1001은 임의 ID
}

void CCardControl::OnPaint()
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	dc.FillSolidRect(rect, RGB(255, 255, 255));  // 흰 배경
	dc.DrawText(m_strWord, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void CCardControl::AnimateShow()
{
	// 초기 위치와 크기
	CRect rect;
	GetWindowRect(&rect);
	GetParent()->ScreenToClient(&rect);

	const int targetY = rect.top;
	int startY = targetY + 50; // 아래에서 올라오게

	// 0~255 Alpha를 지원하는 Layered Window 설정
	SetWindowLongPtr(this->GetSafeHwnd(), GWL_EXSTYLE,
		GetWindowLongPtr(this->GetSafeHwnd(), GWL_EXSTYLE) | WS_EX_LAYERED);

	for (int step = 0; step <= 10; ++step)
	{
		float ratio = step / 10.0f;

		// Y 위치 변경
		int y = startY - (int)((startY - targetY) * ratio);
		MoveWindow(rect.left, y, rect.Width(), rect.Height(), TRUE);

		// 투명도 변경
		BYTE alpha = (BYTE)(255 * ratio);
		::SetLayeredWindowAttributes(this->GetSafeHwnd(), 0, alpha, LWA_ALPHA);

		Sleep(15); // 너무 빠르면 효과가 안 보임
		UpdateWindow();
	}
}
