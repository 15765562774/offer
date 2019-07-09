//���������ǰ���������������Ľ�������ؽ��Ķ�����
#include<vector>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0) 
		{                    //���Ϊ�գ�����NULL
			return NULL;
		}
		int root = 0;
		//������ǰ�������������ǰ�����������������������������������������
		vector<int> left_pre, right_pre, left_vin, right_vin;
		//���������һ���ڵ�һ��Ϊ���ڵ�
		TreeNode* head = new TreeNode(pre[0]);
		for (int i = 0; i < vin.size(); i++)
		{
			if (pre[0] == vin[i])
			{
				root = i;
				break;
			}
		}
		for (int i = 0; i < root; i++)
		{
			left_vin.push_back(vin[i]);
			left_pre.push_back(pre[i + 1]);
		}
		for (int i = root+1; i <vin.size(); i++)//ע��root+1
		{
			right_vin.push_back(vin[i]);//ע����߶���i
			right_pre.push_back(pre[i]);
		}
		head->left = reConstructBinaryTree(left_pre, left_vin);
		head->right = reConstructBinaryTree(right_pre, right_vin);
		return head;

	}
};