#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

class AVLNode{
public:
	int v;
	AVLNode* left;
	AVLNode* right;
	int height,size;
	int frequence;
	AVLNode():left(NULL),right(NULL),height(0),v(0),size(0),frequence(1){}
};

class AVLTree{
private:
	AVLNode* root;
	AVLNode* insert(AVLNode* &T,int x);				//插入
	AVLNode* delete_x(AVLNode* &T,int x);			//删除 
	AVLNode* delete_node(AVLNode* &T,int x);		//删除整个节点 
   	int find_kth_big(AVLNode* &T,int k);			//查找第k大 
    int Height(AVLNode* &T);						//求树的高度
    int Size(AVLNode* &T);							//求树的大小 
    void Update(AVLNode* &T);						//更新节点信息 
    AVLNode* SingleRotateLeft(AVLNode* &k2);		//左左情况下的旋转
    AVLNode* SingleRotateRight(AVLNode* &k2);		//右右情况下的旋转
    AVLNode* DoubleRotateLR(AVLNode* &k3);			//左右情况下的旋转
    AVLNode* DoubleRotateRL(AVLNode* &k3);			//右左情况下的旋转
public:
	AVLTree():root(NULL){}
	void Insert(int x);//插入接口
	int Findk(int k);//查找第k大接口 
	void Delete(int x);//删除接口 
};

int AVLTree::Height(AVLNode* &T)
{
	if(T==NULL) return -1;
	return T->height;
}

int AVLTree::Size(AVLNode* &T)
{
	if(T==NULL) return 0;
	return T->size;
}

void AVLTree::Update(AVLNode* &T)
{
	T->height=max(Height(T->left),Height(T->right))+1;
	T->size=Size(T->left)+Size(T->right)+T->frequence;
}

AVLNode* AVLTree::SingleRotateLeft(AVLNode* &k2)
{
	AVLNode* k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	Update(k2);
	Update(k1);
	return k1;
}

AVLNode* AVLTree::SingleRotateRight(AVLNode* &k2)
{
	AVLNode* k1=k2->right;
	k2->right=k1->left;
	k1->left=k2;
	Update(k2);
	Update(k1);
	return k1;
}

AVLNode* AVLTree::DoubleRotateLR(AVLNode* &k3)
{
	AVLNode* k1=k3->left;
	k3->left=SingleRotateRight(k1);
	return SingleRotateLeft(k3);
}

AVLNode* AVLTree::DoubleRotateRL(AVLNode* &k3)
{
	AVLNode* k1=k3->right;
	k3->right=SingleRotateLeft(k1);
	return SingleRotateRight(k3);
}

AVLNode* AVLTree::insert(AVLNode* &T,int x)
{
	if(T==NULL){
		T=new AVLNode();
		T->v=x;
	}
	else{
		if(x<T->v){
			T->left=insert(T->left,x);
			if(Height(T->left)-Height(T->right)==2)
				if(x<T->left->v) T=SingleRotateLeft(T);
				else T=DoubleRotateLR(T);
		}
		else if(x>T->v){
			T->right=insert(T->right,x);
			if(Height(T->right)-Height(T->left)==2)
				if(x>T->right->v) T=SingleRotateRight(T);
				else T=DoubleRotateRL(T);
		}
		else (T->frequence)++;
	}
	Update(T);
	return T;
}

AVLNode* AVLTree::delete_x(AVLNode* &T,int x)
{
	if(T==NULL) return T;
	if(x<T->v){
		T->left=delete_x(T->left,x);
		if(Height(T->right)-Height(T->left)==2)
			if(T->right->left!=NULL&&(Height(T->right->left)>Height(T->right->right)) )
                T=DoubleRotateRL(T);
            else
                T=SingleRotateRight(T);
	}
	else if(x>T->v){
		T->right=delete_x(T->right,x);
		if(Height(T->left)-Height(T->right)==2)
			if(T->left->right!=NULL&& (Height(T->left->right)>Height(T->left->left) ))
                T=DoubleRotateLR(T);
            else
                T=SingleRotateLeft(T);
	}
	else{
		if(T->frequence>1){
			T->frequence--;
			return T;
		}
		else{
			if(T->left!=NULL&&T->right!=NULL){
				AVLNode *temp=T->right;
				while(temp->left!=NULL) temp=temp->left;
				T->v=temp->v;
				T->frequence=temp->frequence;
				T->right=delete_node(T->right,temp->v);
				if(Height(T->left)-Height(T->right)==2)
					if(T->left->right!=NULL&& (Height(T->left->right)>Height(T->left->left) ))
               			T=DoubleRotateLR(T);
            		else
                		T=SingleRotateLeft(T);
			}
			else{
				AVLNode *temp=T;
				if(T->left==NULL) T=T->right;
				else if(T->right==NULL) T=T->left;
				delete temp;
				temp=NULL;
			}
		}
	}
	if(T!=NULL) Update(T);
	return T;
}
        
AVLNode* AVLTree::delete_node(AVLNode* &T,int x)
{
	if(T==NULL) return T;
	if(x<T->v){
		T->left=delete_node(T->left,x);
		if(Height(T->right)-Height(T->left)==2)
			if(T->right->left!=NULL&&(Height(T->right->left)>Height(T->right->right)) )
                T=DoubleRotateRL(T);
            else
                T=SingleRotateRight(T);
	}
	else if(x>T->v){
		T->right=delete_node(T->right,x);
		if(Height(T->left)-Height(T->right)==2)
			if(T->left->right!=NULL&& (Height(T->left->right)>Height(T->left->left) ))
                T=DoubleRotateLR(T);
            else
                T=SingleRotateLeft(T);
	}
	else{
		if(T->left!=NULL&&T->right!=NULL){
			AVLNode *temp=T->right;
			while(temp->left!=NULL) temp=temp->left;
			T->v=temp->v;
			T->frequence=temp->frequence;
			T->right=delete_node(T->right,temp->v);
			if(Height(T->left)-Height(T->right)==2)
				if(T->left->right!=NULL&& (Height(T->left->right)>Height(T->left->left) ))
               		T=DoubleRotateLR(T);
            	else
                	T=SingleRotateLeft(T);
		}
		else{
			AVLNode *temp=T;
			if(T->left==NULL) T=T->right;
			else if(T->right==NULL) T=T->left;
			delete temp;
			temp=NULL;
		}
	}
	if(T!=NULL) Update(T);
	return T;
}

int AVLTree::find_kth_big(AVLNode* &T,int k)
{
	if(T->right==NULL){
		if(T->frequence>=k) return T->v;
		else return find_kth_big(T->left,k-(T->frequence));
	}
	else{
		if(Size(T->right)>=k) return find_kth_big(T->right,k);
		else if(Size(T->right)+T->frequence>=k) return T->v;
		else find_kth_big(T->left,k-(T->frequence)-Size(T->right));
	}
}

void AVLTree::Insert(int x)
{
	root=insert(root,x);
}

int AVLTree::Findk(int k)
{
	return find_kth_big(root,k);
}

void AVLTree::Delete(int x)
{
	delete_x(root,x);
}

int n;

void solve()
{
	AVLTree AVL;
	queue<int> qu;
	int i,x;
	char s[10];
	for(i=1;i<=n;i++){
		scanf("%s",s);
		if(s[0]=='i'){
			scanf("%d",&x);
			AVL.Insert(x);
			qu.push(x);
		}
		else if(s[0]=='q'){
			x=qu.size();
			printf("%d\n",AVL.Findk(x-x/2));
		}
		else{
			AVL.Delete(qu.front());
			qu.pop();
		}
	}
}

int main()
{
	int t=0;
	while(~scanf("%d",&n)){
		printf("Case #%d:\n",++t);
		solve();
	}
 return 0;
}

