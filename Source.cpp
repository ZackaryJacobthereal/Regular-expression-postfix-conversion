#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Node
{
	char c;
	Node* left;
	Node* right;
	
};
Node* node = new Node();
stack<Node*> Stack_operator;
stack<Node*> Stack_operand;


void reading(const string expr)
{
	cout << expr.length() << " letters "<<endl;
	for (int i = 0; i < expr.length(); i++)
	{
		Node* readTemp = new Node();

		if (expr[i] == '+' || expr[i] == '*' || expr[i] == '/' || expr[i] == '%' || expr[i] =='-')
		{
			readTemp->c = expr[i];
			readTemp->left = Stack_operand.top();
			readTemp->right = NULL;
			Stack_operator.push(readTemp);
		}
		else
		{
			readTemp->c = expr[i];
			readTemp->left = NULL;  readTemp->right = NULL;
			if (Stack_operator.size() == 0)
			{
				Stack_operand.push(readTemp);
			}
			else
			{
				Stack_operator.top()->right = readTemp;
				Stack_operand.push(Stack_operator.top());
				Stack_operator.pop();
			}
		}
	}
}

void post_order_traversing(Node* root)
{
	if(root->left) post_order_traversing(root->left);
	if(root->right) post_order_traversing(root->right);
	cout << root->c;
	return;
}


int main(int argc, char* argv[])
{
	string expr;
	cout << "Enter a regular expression" << endl;
	cin >> expr;

	reading(expr);	
	cout << expr << endl;

	node = Stack_operand.top();
	post_order_traversing(node);
	cout << endl;
	cin.ignore();
	return 0;
}