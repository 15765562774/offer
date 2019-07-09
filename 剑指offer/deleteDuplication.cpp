
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
//��һ��pre���治�뵱ǰֵ�ظ���ǰһ��ֵ
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead==NULL)
		{
			return NULL;
		}
		ListNode*pNode = pHead;
		ListNode*pre = pHead;
		while (pNode->next!=NULL)
		{
			if (pNode->val == pre->val)//�����ǰ�ڵ��pre��ͬ����ζ���ظ��������������pnode����
			{
				pNode = pNode->next;
			}
			else//�����ǰ�ڵ㲻ͬ��pre������Ҫ����pre��pnode
			{
				if(pNode!=NULL)pre->next = pNode;
				pre = pre->next;
				pNode = pNode->next;
			}	
		}
		return pHead;
	}
};
//�ϱ�������������Ϊ��Ҫ�޳��ظ��ڵ�


//�±�Ϊ������ֻҪ�ظ������122334->14
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL) {
			return NULL;
		}
		// ָ��ǰ���ǰ������ʹ��Ĳ��ظ����
		ListNode* pPre = NULL;
		// ָ��ǰ����Ľ��
		ListNode* pCur = pHead;
		// ָ��ǰ������Ľ��
		ListNode* pNext = NULL;

		while (pCur != NULL) {
			// �����ǰ�������һ�������ͬ
			if (pCur->next != NULL && pCur->val == pCur->next->val) {
				pNext = pCur->next;
				// �ҵ����ظ������һ�����λ��
				while (pNext->next != NULL && pNext->next->val == pCur->val) {
					pNext = pNext->next;
				}
				// ���pCurָ�������е�һ��Ԫ�أ�pCur -> ... -> pNext ->... 
				// Ҫɾ��pCur��pNext, ��ָ�������һ��Ԫ�ص�ָ��pHeadָ��pNext->next��
				if (pCur == pHead) {
					pHead = pNext->next;
				}
				// ���pCur��ָ�������е�һ��Ԫ�أ�pPre -> pCur ->...->pNext ->... 
				// Ҫɾ��pCur��pNext����pPre->next = pNext->next
				else {
					pPre->next = pNext->next;
				}
				// ��ǰ�ƶ�
				pCur = pNext->next;
			}
			// �����ǰ�������һ����㲻��ͬ
			else {
				pPre = pCur;
				pCur = pCur->next;
			}
		}
		return pHead;
	}
};