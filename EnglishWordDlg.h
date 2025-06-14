
// EnglishWordDlg.h : header file
//

#pragma once


// CEnglishWordDlg dialog
class CEnglishWordDlg : public CDialogEx
{
// Construction
public:
	CEnglishWordDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ENGLISHWORD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	DECLARE_MESSAGE_MAP()
public:
	
	int		m_nMode;
	int		m_nNounCnt;
	int		m_nVerbCnt;
	int		m_nAdverbCnt;
	int		m_nAdjectiveCnt;
	int		m_nOtherCnt;
	afx_msg void OnBnClickedRdWord();
	void ShowSettingsCtrls();
	afx_msg void OnBnClickedRdCword();
	afx_msg void OnBnClickedRdSentence();
	afx_msg void OnDeltaposSpinNoun(NMHDR *pNMHDR, LRESULT *pResult);
	CSpinButtonCtrl m_spinNounCount;
	CSpinButtonCtrl m_spinVerbCount;
	CSpinButtonCtrl m_spinAdverbCount;
	CSpinButtonCtrl m_spinAdjectiveCount;
	CSpinButtonCtrl m_spinOtherCount;
};
