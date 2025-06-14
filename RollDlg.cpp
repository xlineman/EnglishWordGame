// CRollDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EnglishWord.h"
#include "RollDlg.h"
#include "afxdialogex.h"


// CRollDlg dialog

IMPLEMENT_DYNAMIC(CRollDlg, CDialogEx)

CRollDlg::CRollDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ROLL_DLG, pParent)
{

}

CRollDlg::~CRollDlg()
{
}

void CRollDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRollDlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CRollDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CRollDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CRollDlg message handlers


void CRollDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CRollDlg::OnBnClickedOk()
{
	CRect cardRect(50, 50, 200, 100); // x, y, width, height

	CCardControl* pCard = new CCardControl();
	if (pCard->CreateCard(this, cardRect, _T("Apple")))
	{
		pCard->AnimateShow();  // 등장 애니메이션 실행
	}
}


BOOL CRollDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();



	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
