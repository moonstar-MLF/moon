
// LibView.h : CLibView 类的接口
//

#pragma once


class CLibView : public CView
{
protected: // 仅从序列化创建
	CLibView();
	DECLARE_DYNCREATE(CLibView)

// 特性
public:
	CLibDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CLibView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // LibView.cpp 中的调试版本
inline CLibDoc* CLibView::GetDocument() const
   { return reinterpret_cast<CLibDoc*>(m_pDocument); }
#endif

