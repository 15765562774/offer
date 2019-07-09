//�������������ж�b�ǲ���a���ӽṹ
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
//˼·�����ҵ���A�к���B���ڵ�һ���Ľڵ㣬���ж���rΪ�ڵ�������ǲ��ǰ���bһ���Ľṹ
//�漰���������Ļ���֪ʶ������ʹ�õݹ�
//�������̾����ȣ�ǰ�к�������������ҵ����ڵ㣬û�ҵ�����false��Ȼ�����ҵ��Ľڵ�λ�õݹ���������ж��Ƿ���b���ṹ��ͬ��
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		if (pRoot1 != NULL && pRoot2 != NULL) {
			if (pRoot1->val == pRoot2->val) {
				//�������
				result = DoesTree1HasTree2(pRoot1, pRoot2);// �˺�������ΪѰ����A�к���B���ڵ�һ���Ľڵ㣬�ҵ����ж��Ƿ��������
			}
			if (!result) {
				result = HasSubtree(pRoot1->left, pRoot2);
			}
			if (!result) {
				result = HasSubtree(pRoot1->right, pRoot2);
			}
		}
		return result;
	}
	//���ڵ�
	bool DoesTree1HasTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot2 == NULL) {
			return true;
		}
		if (pRoot1 == NULL) {
			return false;
		}
		if (pRoot1->val != pRoot2->val) {
			return false;
		}
		return DoesTree1HasTree2(pRoot1->left, pRoot2->left) && DoesTree1HasTree2(pRoot1->right, pRoot2->right);
	}
};