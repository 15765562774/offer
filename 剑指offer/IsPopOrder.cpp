//����һ������ջ������ѹջ˳���ж�ջ��Ԫ���ǲ��ǳ�ջ˳��ĵ�һ��Ԫ�أ�
//���Ǿͳ�ջ���粻�Ǿͼ���ѹջ��֪��ѹջԪ�غͳ�ջ˳��ĵ�һ����Ԫ����ȣ�
//���ջһ��Ԫ�أ�������ջ˳�������һλ��Ȼ������жϣ�ѭ��������ջ���գ�
//�������������в��Ǹ�վ����˳��
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() == 0) {
			return false;
		}
		for (int i = 0, j = 0; i < pushV.size(); i++) {
			stackData.push(pushV[i]);
			while (j < popV.size() && stackData.top() == popV[j]) {
				//��ʼд��ʱ��֪����ô����ѭ��������һ�ν�����һ���Ļ���
				//ѭ��������������ѭ������ǰ�������е�ʱ��ֻҪ��ջ��Ԫ�غͳ�ջ˳����ͬ�͵���
				stackData.pop();
				j++;
			}
		}
		return stackData.empty();
	}
private:
	stack<int> stackData;
};