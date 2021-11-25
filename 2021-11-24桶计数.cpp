
//������Ŀ���õ���Ͱ�����ķ���



//��Ч����ĸ��λ��    https://leetcode-cn.com/problems/valid-anagram/

class Solution {
public:
	bool isAnagram(string s, string t) {
		int a[26] = { 0 }, b[26] = { 0 };
		for (int i = 0; i<s.length(); i++)
		{
			a[s[i] - 97]++;
		}
		for (int i = 0; i<t.length(); i++)
		{
			b[t[i] - 97]++;
		}
		for (int i = 0; i<26; i++)
		{
			if (a[i] != b[i])
				return false;
		}
		return true;

	}
};



//�����    https://leetcode-cn.com/problems/ransom-note/

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int a[26] = { 0 }, b[26] = { 0 };
		for (int i = 0; i<ransomNote.length(); i++)
		{
			a[ransomNote[i] - 97]++;
		}
		for (int i = 0; i<magazine.length(); i++)
		{
			b[magazine[i] - 97]++;
		}
		for (int i = 0; i<26; i++)
		{
			if (a[i] != 0 && a[i]>b[i])
				return false;
		}
		return true;
	}
};


//�ַ����еĵ�һ��Ψһ�ַ�     https://leetcode-cn.com/problems/first-unique-character-in-a-string/


class Solution {
public:
	int firstUniqChar(string s) {
		int ch[26] = { 0 };
		for (int i = 0; i<s.length(); i++)
		{
			ch[s[i] - 97]++;
		}
		for (int i = 0; i<s.length(); i++)
		{
			if (ch[s[i] - 97] == 1)
				return i;
		}
		return -1;
	}
};
