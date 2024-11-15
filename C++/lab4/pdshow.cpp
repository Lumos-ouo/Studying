#include "diary.h"
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
	cin >> date;
	vector<Diary>::size_type i;
	for (i=0;i<my_diary.size();i++)
		//找到日期则输出内容 
		if (my_diary[i].GetDate()==date) {
			cout<<my_diary[i].GetText()<<endl;
            break;
        }
	if (i==my_diary.size())
		cout<<"Failed"<<endl;
	return 0;
}