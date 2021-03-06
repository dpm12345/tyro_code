给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。（leetcode 题）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


第一种，使用map
class Solution {
public:
         vector<string>ans;
         string tmp;
         unordered_map<char,string>a={
             {'2',"abc"},
             {'3',"def"},
             {'4',"ghi"},
             {'5',"jkl"},
             {'6',"mno"},
             {'7',"pqrs"},
             {'8',"tuv"},
             {'9',"wxyz"},
        };
void  digui(vector<string>&ans,unordered_map<char,string>&a,int index,string &digits,string tmp)
        {
            if(digits.length()==0)return ;
            if(index==digits.length())
            {
                ans.push_back(tmp);
                return ;
            }
            for(int i=0;i<a[digits[index]].length();i++)
            {
                tmp.push_back((a[digits[index]])[i]);
                digui(ans,a,index+1,digits,tmp);
                tmp.pop_back();
            }
        }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
         digui(ans,a,0,digits,tmp);
         return ans;
    }
};







第二种，使用string
class Solution {
public:
         vector<string>ans;
         string tmp;
         vector<string>a={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void  digui(vector<string>&ans,vector<string>&a,int index,string &digits,string tmp)
        {
            if(digits.length()==0)return ;
            if(index==digits.length())
            {
                ans.push_back(tmp);
                return ;
            }
            int num=digits[index]-'0';
            for(int i=0;i<a[num].length();i++)
            {
                tmp.push_back(a[num][i]);
                digui(ans,a,index+1,digits,tmp);
                tmp.pop_back();
            }
        }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
         digui(ans,a,0,digits,tmp);
         return ans;
    }
};



总结：主体相同，但分别利用map和string的特性
