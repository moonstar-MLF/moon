// AddDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "AddDlg.h"
#include "afxdialogex.h"


// AddDlg 对话框

IMPLEMENT_DYNAMIC(AddDlg, CDialogEx)

AddDlg::AddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADD, pParent)
	, num(0)
{

}

AddDlg::~AddDlg()
{
}

void AddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, num);
}


BEGIN_MESSAGE_MAP(AddDlg, CDialogEx)
END_MESSAGE_MAP()


// AddDlg 消息处理程序
