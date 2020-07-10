
// MFCApplication2View.h : CMFCApplication2View 类的接口
//

#pragma once

class CMFCApplication2Set;

class CMFCApplication2View : public CRecordView
{
protected: // 仅从序列化创建
	CMFCApplication2View();
	DECLARE_DYNCREATE(CMFCApplication2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFCAPPLICATION2_FORM };
#endif
	CMFCApplication2Set* m_pSet;
	void foo(CImage&img, int&sx, int&sy, int&w, int&h);

// 特性
public:
	CMFCApplication2Doc* GetDocument() const;

// 操作
public:
	CString filename;
// 重写
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMFCApplication2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString number;
	CString birthday;
	CString major;
	CString sex;
	CString phoneNum;
	CString address;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // MFCApplication2View.cpp 中的调试版本
inline CMFCApplication2Doc* CMFCApplication2View::GetDocument() const
   { return reinterpret_cast<CMFCApplication2Doc*>(m_pDocument); }
#endif

