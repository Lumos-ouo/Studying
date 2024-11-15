#include"diary.h"
#include<stdlib.h>
//判断日期是否在两个日期之间
int between(string str,string upper,string low)
{
	if (str.compare(upper)<=0&&str.compare(low)>=0)	
		return 1;
	else	
		return 0;
}
 
int main()
{
	vector<Diary> my_diary;
	string str;
	Diary diary;
	string date;
	ifstream f_in(fpath);
	while (!f_in.eof())
	{
		getline(f_in,date);
		diary.SetDate(date);
		diary.ClearText();
		getline(f_in,str);
		while (str!=".")
		{
			diary.AddLine(str);
			getline(f_in,str);
		}
		my_diary.push_back(diary);
	}
	f_in.close();
	vector<Diary>::size_type i,Size;
	string cmd;
	//输入指令，是1则继续输入上下限
	cin >> cmd;
	if (cmd =="1")
	{
		string dUpper,dLow;
		cin >> dLow >> dUpper;
		for (i=0;i<my_diary.size();i++)
			//输出符合条件的日期
			if (between(my_diary[i].GetDate(),dUpper,dLow))
			{
				cout<<my_diary[i].GetDate()<<endl;
				cout<<my_diary[i].GetText()<<endl;
	
			}
	}
	else
	{
		//否则输出所有日期
		for (i=0;i<my_diary.size();i++)
		{
			cout<<my_diary[i].GetDate()<<endl;
			cout<<my_diary[i].GetText()<<endl;
		
		}
	}
	return 0;
}