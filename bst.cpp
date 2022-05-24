#include <iostream>
#include<bits/stdc++.h>
#define MAX 100
using namespace std;

class Node{
	int data;
	Node* lchild;
	Node* rchild;
	friend class Tree;
//	friend class Tree;
	friend class Queue;
	friend class Stack;
public:
	Node(){
		data=0;
		lchild=rchild=NULL;
	}
	Node(int x){
		data=x;
		lchild=rchild=NULL;
	}
};
class Stack
{
	int top;
	Node *data[MAX];
	public:
	Stack()
	{	top=-1;	}
	void push(Node *p)
	{
		if(!full())
			data[++top]=p;
		else
			cout<<"Full\n";
	}
	Node *pop()
	{
		if(!empty())
			return data[top--];
		else
			return NULL;
	}
	bool empty()
	{
		if(top==-1)
			return true;
		return false;
	}
	bool full()
	{
		if(top==MAX-1)
			return true;
		return false;
	}
};
class Queue
{
	Node *data[MAX];
	int front,rear;
public:
	Queue()
	{
		front=rear=-1;
	}
	void push(Node*);
	Node * pop();
	bool empty();
	bool full();
	Node* first();
};
void Queue::push(Node *p)
{
	if(!full())
	{
		if(empty())
		{
			front=0;
		}
		rear=(rear+1)%MAX;
		data[rear]=p;
	}
}
Node * Queue::pop()
{
	if(!empty())
	{
		Node *p=data[front];
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front=(front+1)%MAX;
		}
		return p;
	}
	else
		return NULL;
}
bool Queue::empty()
{
	if(rear==-1)
		return 1;
	return 0;
}
bool Queue::full()
{
	if(front==(rear+1)%MAX)
		return 1;
	return 0;
}

Node* Queue::first()
  {
	return data[front];
  }
class Tree{
	Node *root;
public:
	Tree(){
		root=NULL;
	}
	void createnr();//Non-Recursive
	Node* creater();//Recursive
//	Node* insert(Node*);
	void inorderr(Node*);//Recursive
	void preorderr(Node*);//Recursive
	void postorderr(Node*);//Recursive
	Node* get_root();
	void set_root();
	void inordernr();//Non Recursive
	void preordernr();//Non Recursive
	void postordernr();//Non Recursive
	void deletenode(Node*);
	Node* copy(Node*);
	void operator=(Tree &);
	int equality(Node*,Node*);
	void create_mirror(Tree);
	Node* mirror(Node*,Node*);
	int internalnodes(Node*);
	int leafnodes(Node*);
	void print();


};

void Tree::deletenode(Node *p){
	if(p!=NULL){
		deletenode(p->lchild);
		deletenode(p->rchild);
		delete(p);
	}
}
void Tree::createnr()
{
	Queue obj;
	Node *p=NULL;
	int x;
	if(root==NULL)
	{
		cout<<"Enter Data or -1 to STOP\n";
		cin>>x;
		if(x==-1)
			return;
		root=new Node(x);
		obj.push(root);
	}
	p=root;
	while(!obj.empty())
	{
		p=obj.pop();
		cout<<"Enter Left of "<<p->data<<" OR -1 \n";
		cin>>x;
		if(x!=-1)
		{
			p->lchild=new Node(x);
			obj.push(p->lchild);
		}
		cout<<"Enter Right of "<<p->data<<" OR -1 \n";
		cin>>x;
		if(x!=-1)
		{
			p->rchild=new Node(x);
			obj.push(p->rchild);
		}
	}
}

void Tree::preordernr()
{
	cout<<"PREORDER TRAVERSAL\n";
	Stack S;
	Node *p=root;
	S.push(p);
	while(!S.empty())
	{
		p=S.pop();
		cout<<p->data<<"\t";
		if(p->rchild!=NULL)
			S.push(p->rchild);
		if(p->lchild!=NULL)
			S.push(p->lchild);
	}
	cout<<"\n";
}

void Tree::inordernr()
{
	cout<<"INORDER TRAVERSAL\n";
	Stack S;
	Node *p=root;
	while(p!=NULL)
	{
		S.push(p);
		p=p->lchild;
	}
	while(!S.empty())
	{
		p=S.pop();
		cout<<p->data<<"\t";
		p=p->rchild;
		while(p!=NULL)
		{
			S.push(p);
			p=p->lchild;
		}
	}
	cout<<"\n";
}

void Tree::postordernr()
{
	cout<<"POSTORDER TRAVERSAL\n";
	Stack S1,S2;
	Node *p=root;
	S1.push(p);
	while(!S1.empty())
	{
		p=S1.pop();
		S2.push(p);
		if(p->lchild!=NULL)
			S1.push(p->lchild);
		if(p->rchild!=NULL)
			S1.push(p->rchild);
	}
	while(!S2.empty())
	{
		p=S2.pop();
		cout<<p->data<<"\t";
	}
	cout<<"\n";
}

Node* Tree::creater(){
	int x;
	cout<<"Enter data else enter -1\n";
	cin>>x;
	if(x==-1){	return NULL;	}
	else{
		Node* p=new Node(x);
		p->data=x;
		cout<<"Enter data of left child of "<<x<<endl;;
		p->lchild=creater();
		cout<<"Enter data of right child of"<<x<<endl;
		p->rchild=creater();
		return p;
	}
}

void Tree::set_root(){
	root=creater();
}

Node* Tree::get_root(){
	return root;
}

void Tree::inorderr(Node* t){
	if(t!=NULL){
		inorderr(t->lchild);
		cout<<t->data<<"\t";
		inorderr(t-> rchild);
	}

}

void Tree::preorderr(Node* t){
	if(t!=NULL){
		cout<<t->data<<"\t";
		preorderr(t->lchild);
		preorderr(t->rchild);
	}
}

void Tree::postorderr(Node* t){
	if(t!=NULL){
		postorderr(t->lchild);
		postorderr(t->rchild);
		cout<<t->data<<"\t";
	}
}


Node* Tree::copy(Node*t){
	Node* n;
	n=NULL;
	if(t!=NULL){
		n=new Node(t->data);
		n->lchild=copy(t->lchild);
		n->rchild=copy(t->rchild);
	}
	return n;
}

void Tree::operator=(Tree &t){
	root=copy(t.root);
}



void Tree::print(){
    int c;
	cout<<"Internal Nodes \n";
	c=internalnodes(root);
	cout<<"\nNo.of Internal Nodes  "<<c<<"\n";
	cout<<"\nLeaf Nodes \n";
	c=leafnodes(root);
	cout<<"\nNo.of Leaf Nodes "<<c<<"\n";
}

int Tree::internalnodes(Node* p)
{   //cout<<"Internal Nodes are\n";
	if(p==NULL)
		return 0;
	if(p->lchild==NULL&&p->rchild==NULL)
		return 0;
	else
	{
		int l,r;
		cout<<p->data<<" ";
		l=internalnodes(p->lchild);
		r=internalnodes(p->rchild);
		return 1+l+r;
	}
}

int Tree::leafnodes(Node* p){
    if(p==NULL)
		return 0;
	if(p->lchild==NULL&&p->rchild==NULL)
	{
		cout<<p->data<<" ";
		return 1;
	}
	else
	{
		return leafnodes(p->lchild)+leafnodes(p->rchild);
	}
}

void Tree::create_mirror(Tree T)
{
	root=mirror(root,T.root);
}



Node* Tree::mirror(Node* p,Node *q)
{
	if(q==NULL)
		return NULL;
	else
	{
		p=new Node(q->data);
		p->lchild=mirror(p->lchild,q->rchild);
		p->rchild=mirror(p->rchild,q->lchild);
		return p;
	}
}


int Tree::equality(Node* p,Node* q)
{
	if(q==NULL&&p==NULL)
		{
			return true;
		}
		if(p==NULL||q==NULL)
		{
			return false;
		 }
		 Queue q1,q2;
		 q1.push(q);
		 q2.push(p);
		 while(!q1.empty()&&!q2.empty())
		 {
		 	Node* n1=q1.first();
		 	Node* n2=q2.first();
		 	if(n1->data!=n2->data)
		 	{
		 		return false;
			 }
			 q1.pop();
			 q2.pop();
			 if(n1->lchild&&n2->lchild)
			 {
			 	q1.push(n1->lchild);
			 	q2.push(n2->lchild);
			 }
			 else if(n1->lchild||n2->lchild)
			{
				return false;
			}
			if(n1->rchild&&n2->rchild)
	        {
	            q1.push(n1->rchild);
	            q2.push(n2->rchild);
	        }
	        else if(n1->rchild||n2->rchild)
	        {
			    return false;
			}

		 }
		 return true;
}

int main() {
	int a;
	char yn;
	Tree t,t1,obj,obj1,obj2,Mir;
	Node *l,*p;
//	Node* p=new Node();
	do{

		cout<<"\n1.Enter Tree Recursive\n2.Enter Tree Non-Recursive\n3.Delete All Nodes\n4.Clone the given tree\n5.Find Mirror Image\n6.No. of Internal & Leaf Nodes\n7.Check if given tree is equal or not\n";
		cin>>a;
		switch(a){
		case 1: t.set_root();
				p=t.get_root();
				cout<<"Inorder Traversal :"<<endl;
				t.inorderr(p);
				cout<<endl;
				cout<<"Preorder Traversal :"<<endl;
				t.preorderr(p);
				cout<<endl;
				cout<<"Postorder Traversal :"<<endl;
				t.postorderr(p);
				cout<<endl;
				break;
		/*case 2: p=t.get_root();
				t.inorderr(p);
				break;
		case 3: p=t.get_root();
				t.preorderr(p);
				break;
		case 4: p=t.get_root();
				t.postorderr(p);
				break;*/
		case 2:	t.createnr();
				t.inordernr();
				t.preordernr();
				t.postordernr();
				break;
	/*	case 6:	t.inordernr(p);
				break;
		case 7: t.preordernr(p);
				break;
		case 8: t.postordernr(p);
				break;		*/
		case 3: cout<<"Deleting all the nodes\n";
				t.deletenode(p);
				break;
		case 4:cout<<"Copying.....\n";
				t1=t;
				cout<<"Tree Copied\nNow Printing the copied Tree using Inorder Traversal\n";
				t1.inorderr(p);
				break;
		case 5:
			    cout<<"Mirror Image of Tree is\n";
			    Mir.create_mirror(t);
			    Mir.inordernr();
				Mir.preordernr();
				Mir.postordernr();
			    break;
		case 6://cout<<"Find Internal Nodes";
				p=t.get_root();
				t.print();
				break;
		case 7: cout<<"Enter First Tree\n";
				obj.set_root();
				l=obj.get_root();
				cout<<"Enter Second Tree\n";
				obj1.set_root();
				p=obj1.get_root();
				if(obj2.equality(l,p))
					cout<<"\nBoth trees are equal ";
				else
					cout<<"\nBoth trees are not equal ";
		        break;
		default: cout<<"Incorrect choice entered :\n";
		}
		cout<<"\nDo you want to continue(y/n)?        ";
		cin>>yn;
	}while(yn=='y'||yn=='Y');
}