//����ˮ   https://leetcode-cn.com/problems/trapping-rain-water/


//���巽��һ��λ���ܽӵ���ˮȡ��������������߶ȵ���Сֵ��ȥ��λ�õĸ߶�



//  ˫ָ��
//˼·��һ��λ���ܽӵ���ˮ��Ϊ������min(leftmax,rightmax)-height
//�ص����ڵ�height[left]<height[right]ʱ��leftmax<rightmax�س���
//��height[left]>=height[right]ʱ��leftmax>=rightmax�س���

class Solution {
public:
	int trap(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int leftmax = 0, rightmax = 0, ans = 0;
		while (left<right)
		{
			leftmax = max(leftmax, height[left]);
			rightmax = max(rightmax, height[right]);
			if (height[left]<height[right])
			{
				ans += leftmax - height[left];
				left++;
			}
			else
			{
				ans += rightmax - height[right];
				right--;
			}
		}
		return ans;

	}
};



 
//��̬�滮     ��˫ָ��������
//                           ���ҳ�ÿ��λ�õ�������߶Ⱥ��Ҳ�����߶ȣ�
//                           ������������λ�ã������ˮ�������ӵ�ans��

class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		if (n == 0) {
			return 0;
		}
		vector<int> leftMax(n);
		leftMax[0] = height[0];
		for (int i = 1; i < n; ++i) {
			leftMax[i] = max(leftMax[i - 1], height[i]);
		}

		vector<int> rightMax(n);
		rightMax[n - 1] = height[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			rightMax[i] = max(rightMax[i + 1], height[i]);
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans += min(leftMax[i], rightMax[i]) - height[i];
		}
		return ans;
	}
};




//����ջ   




class Solution {
public:
	int trap(vector<int>& height) {
		int ans = 0;
		stack<int> stk;
		int n = height.size();
		for (int i = 0; i < n; ++i) {
			while (!stk.empty() && height[i] > height[stk.top()]) {            //��ջ��Ϊ�գ��ҵ�ǰλ�ø߶ȴ���ջ��λ�õĸ߶�
				int top = stk.top();
				stk.pop();
				if (stk.empty()) {                    //��pop���Ϊ�գ���ô��ջ��ֻ��һ��Ԫ�أ�Ҳ����˵�Ӳ�����ˮ����ô�ɽ���λ��ɾ��
					                                  //��֮����pop��Ϊ�գ���ôջ������������Ԫ�أ�ջ����ǰһ��Ԫ��left������
					                                  //height[left]>=height[top],Ҳ����˵height[left]�������淽����leftmax[i],height[top]Ϊ
					                                  //height[i],height[i]Ϊrightmax[i]
					break;
				}
				int left = stk.top();
				int currWidth = i - left - 1;                     //������ͨ��ջʵ�֣�ÿ�μ��㶼ֻ����һ�У���ô��Ҫ�����䳤��
				int currHeight = min(height[left], height[i]) - height[top];                
				ans += currWidth * currHeight;
			}
			stk.push(i);                         //����λ���±�
		}
		return ans;
	}
};