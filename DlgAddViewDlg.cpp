
// DlgAddViewDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DlgAddView.h"
#include "DlgAddViewDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CDlgAddViewDlg �Ի���



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


// CDlgAddViewDlg ��Ϣ�������

BOOL CDlgAddViewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//�����Ƿ���1
	UINT TargetCtrlID = IDC_STATIC_VIEW;  
	CWnd *pWnd = this->GetDlgItem(TargetCtrlID);  
	CRect RectTargetCtrl;  
	pWnd->GetWindowRect(RectTargetCtrl);  
	this->ScreenToClient(RectTargetCtrl);  
	m_pView = (CMyView*)RUNTIME_CLASS(CMyView)->CreateObject();
	//��Ŀ��λ�ö�̬������ͼ
	if (NULL==m_pView)  
	{  
		return FALSE;  
	}  
	m_pView->Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, RectTargetCtrl, this, TargetCtrlID); 
	////////////////////////////////////////////////
	//�����Ƿ�����
	//UINT TargetCtrlID = IDC_STATIC_VIEW;  
	//CWnd *pWnd = this->GetDlgItem(TargetCtrlID);  
	//CRect RectTargetCtrl;  
	//pWnd->GetWindowRect(RectTargetCtrl);  
	//this->ScreenToClient(RectTargetCtrl);  
	//CCreateContext context;
	//context.m_pCurrentDoc = NULL;//��Ҫ�ĵ�Ϊ��
	//context.m_pCurrentFrame = (CFrameWnd *)this;//���ø�����ָ�룬���Ի���ָ��ǿ��ת��
	//context.m_pLastView = NULL;//ǰһ����ͼΪ��
	//context.m_pNewDocTemplate = NULL;//�ĵ�ģ��Ϊ��
	//context.m_pNewViewClass = RUNTIME_CLASS(CMyView);
	////1.��̬����CreateObject����һ�����󲢻��ָ��
	//m_pView = (CMyView*)context.m_pNewViewClass->CreateObject();//ͨ��ָ�봴����ͼ����
	////���´���ο�CFrameWnd���е�CreateView����
	//if (m_pView==NULL) {
	//	TRACE1("Warning: Dynamic create of view type %hs failed.\n",
	//		context.m_pNewViewClass->m_lpszClassName);
	//}
	//ASSERT_KINDOF(CWnd,m_pView);
	////2.����������ͼ����
	//if (!m_pView->Create(NULL,NULL,AFX_WS_DEFAULT_VIEW,RectTargetCtrl,this,
	//	AFX_IDW_PANE_FIRST,&context)) 
	//{
	//	TRACE0("Warning: Couldn't create view for frame.\n");
	//	return FALSE;
	//}

	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDlgAddViewDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDlgAddViewDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

