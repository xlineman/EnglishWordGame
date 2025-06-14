#pragma once
#include <vector>
#include "CardControl.h"


// CRollDlg dialog

class CRollDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRollDlg)

public:
	CRollDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CRollDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ROLL_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();


	std::vector<CCardControl*> m_cards;
	std::vector<CString> m_loadedWords;
	virtual BOOL OnInitDialog();
};
