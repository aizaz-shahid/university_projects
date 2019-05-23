#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cstring>
using namespace std;
class node
{
public:
	int freq;
	char alph;
	int *code;
	int codelength;
	node * next;

public:
	node(char alpha,int inf, node* nxt)
	{
		freq = inf;
		next = nxt;
		alph = alpha;
		code = 0;
		codelength = 0;
	}
	int getfreq(int e1)
	{
		return freq;
	}
	int getAlpha()
	{
		return alph;
	}
};
class list
{
public:
	node * head;
	node * tail;
public:
	list()
	{
		head = NULL;
		tail = NULL;
	}

	/*int getNth(node*head, int indx)
	{
		if (head == 0)
		{
			cout << "list is empty" << endl;
			return -1;
		}
		else if (indx <= count || indx >= 0)
		{
			if (indx == 0)
			{
				return head->freq;
			}
			else if (indx == count)
			{
				return tail->freq;
			}
		}
		else
		{
			cout << "index is not valid" << endl;
			return -1;
		}
		node * temp = head;
		for (int i = 0; i <= indx; i++)
		{
			temp = temp->next;
			if (indx == temp->index)
			{
				return temp->freq;
			}
		}
	}*/

	void AddToHead(char ch,int e1)
	{
		if (head == NULL)
		{
			head = new node(ch,e1, NULL);
			tail = head;
		}
		else
		{
			head = new node(ch,e1, head);
		}

	}
	void AddToTail(char ch,int e1)
	{
		if (head == NULL)
		{
			head = new node(ch, e1, NULL);
			tail = head;
		}
		else
		{
			tail->next = new node(ch, e1, NULL);
			tail = tail->next;
		}

	}
	/*void AddNode(int e1, int e2)
	{
		count++;
		node * temp;
		if (head == NULL)
		{
			cout << "the list is empty" << endl;
		}
		else if (head == tail)
		{
			if (head->freq == e1)
			{
				tail->next = new node(e2, NULL, count);
				tail = tail->next;
			}
		}
		else if (tail->freq == e1)
		{
			tail->next = new node(e2, NULL, count);
			tail = tail->next;
		}
		else
		{
			for (temp = head; temp->freq != e1;)
			{
				temp = temp->next;
			}
			temp->next = new node(e2, temp->next, count);
		}
	}*/
	void SortedInsert(node * head, node * p)
	{
		node * temp;
		node * temp2;
		if (head == NULL)
		{
			cout << "the list is empty" << endl;
		}
		else if (head == tail)
		{
			if (head->freq <= p->freq)
			{
				tail->next = p;
				tail = tail->next;
			}
			else
			{
				p->next = head;
				head = p;
			}
		}
		else
		{
			for (temp = head, temp2 = head->next; temp->freq < p->freq && temp2->freq>p->freq;)
			{
				temp = temp->next;
				temp2 = temp2->next;
			}
			p->next = temp->next;
			temp->next = p;
		}
	}
	int DelFrmHead()
	{
		int c1 = 0;
		node * temp;
		if (head == NULL)
		{
			cout << "the list is empty" << endl;
		}
		else if (head == tail)
		{
			c1 = head->freq;
			delete head;
			head = tail = NULL;
		}
		else
		{
			c1 = head->freq;
			temp = head->next;
			delete head;
			head = temp;
		}
		return c1;
	}
	node* getnode()
	{
		return head;
	}
	int DelFrmTail()
	{
		int c1 = 0;
		node * temp;
		if (head == NULL)
		{
			cout << "the list is empty" << endl;
		}
		else if (head == tail)
		{
			c1 = tail->freq;
			delete tail;
			head = tail = NULL;
		}
		else
		{
			c1 = tail->freq;
			for (temp = head; temp->next->next != NULL;)
			{
				temp = temp->next;
			}
			delete temp->next;
			temp->next = NULL;
			tail = temp;
		}
		return c1;
	}
	/*int DelNode(int i)
	{
		int c1 = 0;
		node * temp;
		node * temp2;
		if (head == NULL)
		{
			cout << "the list is empty" << endl;
		}
		else if (head == tail)
		{
			if (head->index == i)
			{
				c1 = head->freq;
				delete head;
				head = 0;
				tail = 0;
			}

		}
		else
		{
			if (head->index == i)
			{
				c1 = DelFrmHead();
			}
			else if (tail->index == i)
			{
				c1 = DelFrmTail();
			}
			else
			{
				for (temp = head, temp2 = head->next; temp2->index != i;)
				{
					temp = temp->next;
					temp2 = temp2->next;
				}
				temp->next = temp2->next;
				c1 = temp2->freq;
				delete temp2;
				temp2 = NULL;
			}
		}
		return c1;
	}*/
	void display()
	{
		int i = 1;
		if (head == NULL)
		{
			cout << "list is empty" << endl;
		}
		else
		{
			node *n;
			n = head;
			for (n = head; n != 0; n = n->next,i++)
			{
				cout << n->alph <<" at "<<i<<" place with "<<n->freq<<" frequency "<< endl;
			}
			delete n;
			n = NULL;
		}
	}

	void uniques(list & l,char v1)
	{
		bool flag = false;
		node*temp;
		for (temp = l.head; temp->next != NULL; temp = temp->next)
		{
			if (temp->alph == v1)
			{
				temp->freq++;
				flag = true;
			}
		}
		if (temp->alph == v1)
		{
			temp->freq++;
			flag = true;
		}
		if (flag==false)
		{
			l.AddToTail(v1, 1);
		}
		
	}

	void sortlist(list &l)
	{
		char a;
		int f;
		for (node * temp=l.head; temp!=NULL; temp=temp->next)
		{
			for (node * temp2 = temp->next; temp2!= NULL; temp2 = temp2->next)
			{
				if (temp2->freq > temp->freq)
				{
					a = temp->alph;
					f = temp->freq;

					temp->alph = temp2->alph;
					temp->freq = temp2->freq;

					temp2->alph = a;
					temp2->freq = f;
				}
			}
		}
	}

	~list()
	{
		if (head == tail)
		{
			delete head;
			head = NULL;
			tail = NULL;
		}
		else
		{
			for (node*temp; head != tail;)
			{
				temp = head->next;
				delete head;
				head = temp;
			}
			delete head;
			head = NULL;
			tail = NULL;
		}
	}


};

/*class Tree
{
public:
	node*leaf;
	node*parent;
public:
	Tree()
	{
		leaf = NULL;
		parent = NULL;
	}
	void AddLeaf()
	{
		leaf = 
	}
};*/

void AssignBinaryCode(list &);
char* packBits(list &,int &);
void compressedFile(char*,int);

int main()
{
	ifstream fin;
	string filename;
	string space;
	list l1;
	cout << "what is the name of the file: ";
	cin >> filename;
	char v1=NULL;
	fin.open(filename);
	getline(fin, space, '$');
	int count=0;
	int duz = space.length();

	for (int i = 0; i <duz  ; i++)
	{
		if (space[i]==' ' && count==0)
		{
			l1.AddToHead(space[i], 1);
			count++;
		}

		else if (space[i] == ' ' && count>0)
		{
			l1.head->freq++;
		}
	}

	fin.close();
	fin.open(filename);
	fin >> v1;
	
	l1.AddToHead(v1, 1);
	do
	{
		fin >> v1;
		l1.uniques(l1, v1);
	} while (fin);
	
	cout << space << endl << endl;
	l1.display();
	l1.sortlist(l1);
	cout << endl << endl;
	l1.display();
	fin.close();
	AssignBinaryCode(l1);
	int sizeofPackedBytes=0;
	char* charPointer;
	charPointer = packBits(l1,sizeofPackedBytes);
	compressedFile(charPointer,sizeofPackedBytes);
	//l1.display();
	for (node*temp = l1.head; temp != NULL; temp = temp->next)
	{
		for (int i = 0; i < temp->codelength; i++)
		{
			cout << temp->code[i];
		}
		cout << endl;
	}

	cout << endl << sizeofPackedBytes;
	
	return 0;
}


void AssignBinaryCode(list &l)
{
	int inputsize = 2;
	int length = 0;
	int arr[8];
	int revArr[8];
	int num = 0;
	int num2 = 0;
	for (node*temp = l.head; temp != NULL; temp = temp->next, num2++)
	{
		num = num2;
		int i;
		i = 0;
		if (num > 1)
		{
			while (num != 1)
			{
				arr[i] = num % 2;
				num = num / 2;
				i++;
			}
			arr[i] = 1;
		}
		else if (num == 0)
		{
			arr[i] = 0;
			temp->code = new int[1];
			temp->code[0] = 0;
		}
		else if (num==1)
		{
			arr[i] = 1;
			temp->code = new int[1];
			temp->code[0] = 1;
		}
		for (int k = i, j = 0; j <= i; j++, k--)
		{
			revArr[j] = arr[k];
		}
		temp->codelength = (i+1);
		

		if (i>0)
		{
			temp->code = new int[i+1];
			for (int j = 0; j < i+1; j++)
			{
				temp->code[j] = revArr[j];
			}
		}

	}
	
	
}

char* packBits(list &l,int &CmpBits)
{
	int totalcodelength = 0;
	string read;
	ifstream fin;
	fin.open("compress.txt");
	for (node*temp = l.head; temp->next != NULL; temp = temp->next)
	{
		totalcodelength += (temp->codelength*temp->freq);
	}
	int*inputCode;
	inputCode = new int[totalcodelength];
	getline(fin, read, '$');
	int size;
	size = read.length();
	int j=0;
	for (int i = 0; i < size; i++)
	{
		for (node*temp = l.head; temp != NULL; temp = temp->next)
		{
			if (read[i]==temp->alph)
			{
				for (int k = 0; k < temp->codelength; k++,j++)
				{
					inputCode[j] = temp->code[k];
				}
			}

		}
	}
	fin.close();
	cout << endl << endl;
	for (int i = 0; i < totalcodelength; i++)
	{
		cout << inputCode[i];
	}
	cout << endl;
	CmpBits = totalcodelength / 8;
	if ((totalcodelength % 8) != 0)
	{
		CmpBits++;
	}

	char* compressedArray=new char[CmpBits];
	for (int k = 0; k<CmpBits; k++)
	{
		compressedArray[k] = 0x00;
	}
	int count = 0;
	for (int i = 0; i<CmpBits; i++)
	{
		unsigned char mask = 0x80;
		unsigned char ans = 0x00;
		for (int j = 0; j<8 && count < totalcodelength; j++, mask = mask >> 1, count++)
		{
			if (inputCode[count] == 1)
			{
				ans = ans | mask;
			}
		}
		compressedArray[i] = ans;
	}
	return compressedArray;

}


void compressedFile(char* ch,int s)
{
	ofstream fout;
	fout.open("compressed.txt");
	for (int i = 0; i < s; i++)
	{
		fout << ch[i];
	}
	
}




