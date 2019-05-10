
// DlgAddViewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DlgAddView.h"
#include "DlgAddViewDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDlgAddViewDlg 对话框



CDlgAddViewDlg::CDlgAddViewDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgAddViewDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlgAddViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDlgAddViewDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CDlgAddViewDlg 消息处理程序

BOOL CDlgAddViewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//下面是方法1
	UINT TargetCtrlID = IDC_STATIC_VIEW;  
	CWnd *pWnd = this->GetDlgItem(TargetCtrlID);  
	CRect RectTargetCtrl;  
	pWnd->GetWindowRect(RectTargetCtrl);  
	this->ScreenToClient(RectTargetCtrl);  
	m_pView = (CMyView*)RUNTIME_CLASS(CMyView)->CreateObject();
	//在目标位置动态创建视图
	if (NULL==m_pView)  
	{  
		return FALSE;  
	}  
	m_pView->Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, RectTargetCtrl, this, TargetCtrlID); 
	////////////////////////////////////////////////
	//下面是方法二
	//UINT TargetCtrlID = IDC_STATIC_VIEW;  
	//CWnd *pWnd = this->GetDlgItem(TargetCtrlID);  
	//CRect RectTargetCtrl;  
	//pWnd->GetWindowRect(RectTargetCtrl);  
	//this->ScreenToClient(RectTargetCtrl);  
	//CCreateContext context;
	//context.m_pCurrentDoc = NULL;//不要文档为空
	//context.m_pCurrentFrame = (CFrameWnd *)this;//设置父窗体指针，将对话框指针强制转换
	//context.m_pLastView = NULL;//前一个视图为空
	//context.m_pNewDocTemplate = NULL;//文档模板为空
	//context.m_pNewViewClass = RUNTIME_CLASS(CMyView);
	////1.动态调用CreateObject创建一个对象并获得指针
	//m_pView = (CMyView*)context.m_pNewViewClass->CreateObject();//通过指针创建视图对象
	////以下代码参考CFrameWnd类中的CreateView函数
	//if (m_pView==NULL) {
	//	TRACE1("Warning: Dynamic create of view type %hs failed.\n",
	//		context.m_pNewViewClass->m_lpszClassName);
	//}
	//ASSERT_KINDOF(CWnd,m_pView);
	////2.真正创建视图窗口
	//if (!m_pView->Create(NULL,NULL,AFX_WS_DEFAULT_VIEW,RectTargetCtrl,this,
	//	AFX_IDW_PANE_FIRST,&context)) 
	//{
	//	TRACE0("Warning: Couldn't create view for frame.\n");
	//	return FALSE;
	//}

	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDlgAddViewDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDlgAddViewDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDlgAddViewDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

