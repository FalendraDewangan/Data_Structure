#include<bits/stdc++.h>
#include<string.h>
#include<fstream>
using namespace std;
int len;

class AVL_Tree;

class avlNode
{
	private:
		string word;
		int count;
		int height;
		avlNode* left;
		avlNode* right;
		
		avlNode(string word)
		{
			this->word=word;
			count=1;
			height=0;
			this->left=0;
			this->right=0;
		}
		
		friend class AVL_Tree;
};

class AVL_Tree
{
	private:
		avlNode* root;
		avlNode* Insert(string word, avlNode* newnode);
		void Print_Rec(avlNode* node);
		avlNode* LR(avlNode* Pivot);
		avlNode* RR(avlNode* Pivot);

	public:
		AVL_Tree()
		{
			root=NULL;
		}
		
		int Max(int a, int b)
		{
			return a>b ? a:b;
		}

		void Insert(string word);
		int Compare(string word1, string word2);
		int Height(avlNode* node);
		void Display();
};

int AVL_Tree::Height(avlNode* node)
{
	return node==NULL ? 0:node->height;          
}

void AVL_Tree::Display()
{
	Print_Rec(root);
}

int AVL_Tree::Compare(string word1, string word2)
{
	int x=word1.length();
	int y=word2.length();
	int i=0;
	
	while(word1[i] && word2[i])
	{
		if(word1[i]!=word2[i])
		{
			return word1[i]-word2[i];
		}
		i++;
	}
	return x-y;
}

void AVL_Tree::Print_Rec(avlNode* node)
{
	if(node==NULL)
	{
		return;
	}

	Print_Rec(node->left);
	cout << node->word<<" : "<<node->count << "\n";
	Print_Rec(node->right);
}

void AVL_Tree::Insert(string word)
{
	root = Insert(word, root);
}

avlNode* AVL_Tree::Insert(string word, avlNode* newnode)
{
	if(newnode==NULL)
	{
		return newnode= new avlNode(word);
	}
	else if(word < newnode->word)
	{
		newnode->left = Insert(word, newnode->left);
	}
	else if(word > newnode->word)
	{
		newnode->right = Insert(word, newnode->right);
	}
	else
	{
		if(word == newnode->word)
		{
			newnode->count++;
		}
		return newnode;
	}

	int L_Height = Height(newnode->left);
	int R_Height = Height(newnode->right);
	newnode->height = Max(L_Height, R_Height)+1;
	int Balance = L_Height-R_Height;

	if(Balance>1)
	{
		if(Compare(word, newnode->left->word)<0)
		{
			return newnode = RR(newnode);
		}
		else
		{
			newnode->left = LR(newnode->left);
			return newnode = RR(newnode);
		}
	}
	else if(Balance<-1)
	{
		if(Compare(word, newnode->right->word)<0)
		{
			newnode->right = RR(newnode->right);
			return newnode = LR(newnode);
		}
		else
		{
			return newnode = LR(newnode);
		}
	}
	return newnode;
}

avlNode* AVL_Tree::RR(avlNode* Pivot)
{
	avlNode* newnode = Pivot->left;
	Pivot->left = newnode->right;
	newnode->right = Pivot;
	Pivot->height = Max(Height(Pivot->left), Height(Pivot->right))+1;
	newnode->height = Max(Height(newnode->left), Height(newnode->right))+1;
	return newnode;
}

avlNode* AVL_Tree::LR(avlNode* Pivot)
{
	avlNode* newnode = Pivot->right;
	Pivot->right = newnode->left;
	newnode->left = Pivot;
	Pivot->height = Max(Height(Pivot->left), Height(Pivot->right))+1;
	newnode->height = Max(Height(newnode->left), Height(newnode->right))+1;
	return newnode;
}

bool Validity(string word)
{
	len=word.length();
	
	for(int i=0; i<len; i++)
	{
		if(!(word[i]>='a' && word[i]<='z'))
		{
			return false;
		}
	}
	return true;
}

void file_to_tree(ifstream& file)
{
	AVL_Tree tree;
	string word="";

	while(file>>word)
	{
		len = word.length();
		
		for(int i=0; i<len; i++)
		{
			if(word[i]>='A' && word[i]<='Z')
			{
				word[i]=word[i]+32;
			}
		}
		
		if(word[len-1]=='.' || word[len-1]=='?' || word[len-1]==',' || word[len-1]=='!' || word[len-1]==';' || word[len-1]==':')
		{
			word.resize(word.size()-1);
		}
		if(Validity(word))
		{
			tree.Insert(word);
		}
	}

	tree.Display();
}

int main(int argc, char* argv[])
{
	ifstream file;
	file.open("avl_input.txt");
	if(!file)
		cout<<"File does not exists";
	
	file_to_tree(file);
	file.close();

	return 0;
}
