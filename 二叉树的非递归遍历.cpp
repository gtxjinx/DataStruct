// 二叉树的非递归遍历.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

typedef struct Tree
{
	int num;
	Tree* lchild;
	Tree* rchild;
	Tree* parent;
}*MyTree;



class MyClass
{
public:




	void MakeRTree(MyTree head)
	{
		int n;
		cin >> n;
		MyTree rchild;
		rchild = (MyTree)malloc(sizeof(Tree));
		rchild->num = n;
		rchild->parent = head;
		rchild->lchild = NULL;
		rchild->rchild = NULL;
		head->rchild = rchild;
		char c;
		c = getchar();
		if (c == ')')
		{
			MakeParent(head);
		}
		else if (c == '(')
		{
			MakeLTree(head->rchild);
		}
		else
		{
			cout << "error" << endl;
			return;
		}
	}

	void MakeParent(MyTree head)
	{
		char c;
		c = getchar();
		if (c == ')')
		{
			MakeParent(head->parent);
		}
		else if (c == ',')
		{
			MakeRTree(head->parent);
		}
		else
		{
			return;
		}
	}

	void MakeLTree(MyTree head)
	{
		int n;
		cin >> n;
		MyTree lchild;
		lchild = (MyTree)malloc(sizeof(Tree));
		lchild->num = n;
		lchild->parent = head;
		lchild->lchild = NULL;
		lchild->rchild = NULL;
		head->lchild = lchild;
		char c;
		c = getchar();
		if (c == '(')
		{
			MakeLTree(lchild);
		}
		else if (c == ',')
		{
			MakeRTree(head);
		}
		else if (c == ')')
		{
			MakeParent(head);
		}
		else
			return;
	}

	void MakeTree(MyTree head)
	{
		int n;
		cin >> n;
		head->num = n;
		head->lchild = NULL;
		head->rchild = NULL;
		head->parent = NULL;
		char c;
		c = getchar();
		if (c == '(')
		{
			MakeLTree(head);
		}
		else
		{
			cout << "error!" << endl;
			return;
		}
	}

	void PrintMTree(MyTree head)
	{
		vector<MyTree> Stack;
		MyTree p = head;
		while (p!=NULL||!Stack.empty())
		{
			while (p!= NULL)
			{
				Stack.push_back(p);
				p = p->lchild;
			}
			p= Stack[Stack.size() - 1];
			Stack.pop_back();
			cout << p->num;
			p = p->rchild;
		}
	}



	void PrintFTree(MyTree head)
	{
		vector<MyTree> Stack;
		MyTree p = head;
		while (p != NULL || !Stack.empty())
		{
			while (p != NULL)
			{
				cout << p->num;
				Stack.push_back(p);
				p = p->lchild;
			}
			p = Stack[Stack.size() - 1];
			Stack.pop_back();
			p = p->rchild;
		}
	}



	void PrintATree(MyTree head)
	{
		vector<MyTree> Stack;
		MyTree p = head;
		while (p != NULL || !Stack.empty())
		{
			while (p != NULL)
			{
				Stack.push_back(p);
				p = p->lchild;
			}
			p = Stack[Stack.size() - 1];
			Stack.pop_back();
			p = p->rchild;
		}
	}


};

int main()
{
	MyTree head;
	head = (MyTree)malloc(sizeof(Tree));
	cout << "请输入二叉树" << endl;
	MyClass mclass;
	mclass.MakeTree(head);
	mclass.PrintMTree(head);
	cout <<endl;
	mclass.PrintFTree(head);
	cout << endl;
	mclass.PrintATree(head);
	system("pause");
    return 0;
}

