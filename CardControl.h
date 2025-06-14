#pragma once
class CCardControl : public CStatic
{
public:
	CCardControl();
	~CCardControl();
	void AnimateShow();
	BOOL CreateCard(CWnd* pParent, const CRect& rect, const CString& strWord);


protected:
	CString m_strWord;
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

