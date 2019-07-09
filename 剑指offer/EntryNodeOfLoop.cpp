//�ҵ��������

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	int Findcount(ListNode* pHead)
	{
		//���ĳ���Ϊcount
		ListNode*pFast = pHead;
		ListNode*pSlow = pHead;
		int count = 1;
		//������Ҫע������ж�pfast��pslow�Ƿ�Ϊ��
		//��ʱ��ѭ����pfast�жϵ���pfast->next->next�Ƿ�Ϊ��
		//��ߵ�if�жϵ���pfast->next�Ƿ�Ϊ��
		//Ϊ��ʡȥѭ����ߵ�pslow��pfast�ж�Ϊ�������null
		//�����ŵ�ѭ�������
		while (pFast!=NULL&&pSlow!=NULL)
		{		
			pSlow = pSlow->next;
			pFast = pFast->next;
			if (pFast != NULL)pFast = pFast->next;
			if (pSlow == NULL || pFast == NULL)return NULL;
			if (pFast==pSlow)break;
			
		}
		ListNode*pNode = pSlow->next;
		while (pNode!=pSlow)
		{
			count++;
			pNode = pNode->next;
		}
		return count;
	}
	//��֪���ĳ���n���趨һ��ָ�����߳���n��Ȼ��ͳ��һ��ָ��һ���������������غϵ�λ�ñ�Ϊ�������
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead==NULL)
		{
			return NULL;
		}
		if (pHead->next==NULL)
		{
			return NULL;
		}
		ListNode*p1 = pHead;
		ListNode*p2 = pHead;
		int count = Findcount(pHead);
		while (count--)
		{
			p2 = p2->next;
		}
		while (p1 != p2)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	}
};	