
// DlgAddView.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDlgAddViewApp:
// �йش����ʵ�֣������ DlgAddView.cpp
//

class CDlgAddViewApp : public CWinApp
{
public:
	CDlgAddViewApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDlgAddViewApp theApp;