
// EnglishWordDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EnglishWord.h"
#include "EnglishWordDlg.h"
#include "afxdialogex.h"
#include "Global.h"
#include "RollDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CEnglishWordDlg dialog



CEnglishWordDlg::CEnglishWordDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ENGLISHWORD_DIALOG, pParent)
	, m_nMode(0)
	, m_nNounCnt(3)
	, m_nVerbCnt(1)
	, m_nAdjectiveCnt(1)
	, m_nAdverbCnt(1)
	, m_nOtherCnt(1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEnglishWordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_ET_NOUN, m_nNounCnt);
	DDX_Text(pDX, IDC_ET_VERB, m_nVerbCnt);
	DDX_Text(pDX, IDC_ET_ADJECDTIVE, m_nAdverbCnt);
	DDX_Text(pDX, IDC_ET_ADVERB, m_nAdjectiveCnt);
	DDX_Text(pDX, IDC_ET_OTHER, m_nOtherCnt);
	DDX_Radio(pDX, IDC_RD_WORD, m_nMode);

	DDV_MinMaxInt(pDX, m_nNounCnt, 1, 5); // 값 범위 제한
	DDV_MinMaxInt(pDX, m_nVerbCnt, 1, 5); // 값 범위 제한
	DDV_MinMaxInt(pDX, m_nAdjectiveCnt, 0, 5); // 값 범위 제한
	DDV_MinMaxInt(pDX, m_nAdverbCnt, 0, 5); // 값 범위 제한
	DDV_MinMaxInt(pDX, m_nOtherCnt, 0, 5); // 값 범위 제한
	DDX_Control(pDX, IDC_SPIN_NOUN, m_spinNounCount);
	DDX_Control(pDX, IDC_SPIN_VERB, m_spinVerbCount);
	DDX_Control(pDX, IDC_SPIN_ADVERB, m_spinAdverbCount);
	DDX_Control(pDX, IDC_SPIN_ADJECTIVE, m_spinAdjectiveCount);
	DDX_Control(pDX, IDC_SPIN_OTHER, m_spinOtherCount);
}

BEGIN_MESSAGE_MAP(CEnglishWordDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CEnglishWordDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CEnglishWordDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_RD_WORD, &CEnglishWordDlg::OnBnClickedRdWord)
	ON_BN_CLICKED(IDC_RD_CWORD, &CEnglishWordDlg::OnBnClickedRdCword)
	ON_BN_CLICKED(IDC_RD_SENTENCE, &CEnglishWordDlg::OnBnClickedRdSentence)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_NOUN, &CEnglishWordDlg::OnDeltaposSpinNoun)
END_MESSAGE_MAP()


// CEnglishWordDlg message handlers

BOOL CEnglishWordDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_spinNounCount.SetRange(1, 5);        // 범위 설정
	m_spinNounCount.SetPos(3);               // 초기값
	m_spinNounCount.SetBuddy(GetDlgItem(IDC_ET_NOUN));
	m_spinVerbCount.SetRange(1, 5);        // 범위 설정
	m_spinVerbCount.SetPos(1);               // 초기값
	m_spinVerbCount.SetBuddy(GetDlgItem(IDC_ET_VERB));
	m_spinAdverbCount.SetRange(0, 5);        // 범위 설정
	m_spinAdverbCount.SetPos(1);               // 초기값
	m_spinAdverbCount.SetBuddy(GetDlgItem(IDC_ET_ADVERB));
	m_spinAdjectiveCount.SetRange(0, 5);        // 범위 설정
	m_spinAdjectiveCount.SetPos(1);               // 초기값
	m_spinAdjectiveCount.SetBuddy(GetDlgItem(IDC_ET_ADJECDTIVE));
	m_spinOtherCount.SetRange(0, 5);        // 범위 설정
	m_spinOtherCount.SetPos(1);               // 초기값
	m_spinOtherCount.SetBuddy(GetDlgItem(IDC_ET_OTHER));

	ShowSettingsCtrls();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEnglishWordDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEnglishWordDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEnglishWordDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CEnglishWordDlg::OnBnClickedOk()
{
	TCHAR path[MAX_PATH];
	::GetModuleFileName(NULL, path, MAX_PATH);
	PathRemoveFileSpec(path); // 실행파일 경로 디렉토리만 추출

	CString iniPath = CString(path) + _T("\\WordDB.ini");
	LoadWordDB(iniPath);

	CRollDlg dlgRoll;
	dlgRoll.DoModal();
	
}


void CEnglishWordDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CEnglishWordDlg::OnBnClickedRdWord()
{
	m_nMode = 0;
	ShowSettingsCtrls();
}


void CEnglishWordDlg::ShowSettingsCtrls()
{
	BOOL bVisible = m_nMode > 1 ? TRUE : FALSE;

	GetDlgItem(IDC_ET_VERB)->ShowWindow(bVisible);
	GetDlgItem(IDC_ET_ADVERB)->ShowWindow(bVisible);
	GetDlgItem(IDC_ET_ADJECDTIVE)->ShowWindow(bVisible);
	GetDlgItem(IDC_ET_OTHER)->ShowWindow(bVisible);

	GetDlgItem(IDC_ST_VERB)->ShowWindow(bVisible);
	GetDlgItem(IDC_ST_ADJ)->ShowWindow(bVisible);
	GetDlgItem(IDC_ST_ADVERB)->ShowWindow(bVisible);
	GetDlgItem(IDC_ST_OTHER)->ShowWindow(bVisible);

	GetDlgItem(IDC_SPIN_VERB)->ShowWindow(bVisible);
	GetDlgItem(IDC_SPIN_ADVERB)->ShowWindow(bVisible);
	GetDlgItem(IDC_SPIN_ADJECTIVE)->ShowWindow(bVisible);
	GetDlgItem(IDC_SPIN_OTHER)->ShowWindow(bVisible);

	if (bVisible) {
		GetDlgItem(IDC_ST_NOUN)->SetWindowText(_T("Noun:"));
	}
	else {
		GetDlgItem(IDC_ST_NOUN)->SetWindowText(_T("Count:"));
	}
	
}


void CEnglishWordDlg::OnBnClickedRdCword()
{
	m_nMode = 1;
	ShowSettingsCtrls();
}


void CEnglishWordDlg::OnBnClickedRdSentence()
{
	m_nMode = 2;
	ShowSettingsCtrls();
}


void CEnglishWordDlg::OnDeltaposSpinNoun(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
