//��ת����

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL || pHead->next == NULL)return pHead;
		ListNode*p = pHead;
		ListNode*pNode = NULL;
		while (p!=NULL)//����pʵ����ָ��������Ҫ��ԭ�����ϲ������Ľڵ㣬����ζ����ԭ����Ľڵ㣬��ԭ���������ĩβ�Ż�Ϊ��
		{
			ListNode *tmp = p->next;//��¼�Ͽ��Ľڵ�
			p->next = pNode;//��ԭ����ǰ�ߵĽڵ�ŵ���ǰ�ڵ�ĺ��
			pNode = p;//Ȼ�����ԭ����ǰ�ڵ��ǰһ���ڵ�
			p = tmp;//�ٽ��Ͽ��Ľڵ㸳��p��Ϊ��ǰ�ڵ�
		}
		return pNode;

	}
};