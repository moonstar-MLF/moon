// EditDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "EditDlg.h"
#include "afxdialogex.h"


// EditDlg �Ի���

IMPLEMENT_DYNAMIC(EditDlg, CDialogEx)

EditDlg::EditDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EDIT, pParent)
	, num(0)
{

}

EditDlg::~EditDlg()
{
}

void EditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, num);
}


BEGIN_MESSAGE_MAP(EditDlg, CDialogEx)
END_MESSAGE_MAP()


// EditDlg ��Ϣ�������
