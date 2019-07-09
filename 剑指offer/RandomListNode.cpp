
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};
//1.��������2.����random3.��ָ���ָ��
class Solution {
public:
	//��������
	void CloneNodes(RandomListNode* pHead) 
	{
		RandomListNode*p1 = pHead;
		while (p1 != NULL)
		{
			RandomListNode* pCloned = new RandomListNode(0);
			pCloned->next = p1->next;
			pCloned->label = p1->label;
			pCloned->random = NULL;

			p1->next = pCloned;
			p1 = pCloned->next;
		}
	}
	//�ڶ�����������ָ���random
	void ConnectSiblingNodes(RandomListNode* pHead)
	{
		RandomListNode*p1 = pHead;
		//��Ϊp1��߲�������null������ֱ���ж�p1��=null����
		while (p1 != NULL)
		{
			RandomListNode*pCloned = p1->next;
			//������Ҫ����p1->random;
			if (p1->random != NULL)
			{
				pCloned->random = p1->random->next;
			}
			p1 = pCloned->next;
		}
	}
	//����������ָ���ָ��
	RandomListNode* ReconnectNodes(RandomListNode* pHead) 
	{
		RandomListNode*p1 = pHead;
		RandomListNode*pHead2 = NULL;
		RandomListNode*p2 = NULL;
		//��ͷ����ó���
		if (p1 != NULL) {
			pHead2 = p2 = p1->next;
			p1->next = p2->next;
			p1 = p1->next;
		}
		while (p1 != NULL)
		{
			p2->next = p1->next;
			p2 = p2->next;
			p1->next = p2->next;
			p1 = p1->next;
		}
		return pHead2;
	}
	RandomListNode* Clone(RandomListNode* pHead)
	{
		CloneNodes(pHead);
		ConnectSiblingNodes(pHead);
		return ReconnectNodes(pHead);
	}
};