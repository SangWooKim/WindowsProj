
// DialogBase.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CDialogBaseApp:
// �� Ŭ������ ������ ���ؼ��� DialogBase.cpp�� �����Ͻʽÿ�.
//

class CDialogBaseApp : public CWinAppEx
{
public:
	CDialogBaseApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CDialogBaseApp theApp;