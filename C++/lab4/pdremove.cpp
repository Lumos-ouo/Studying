#include"Diary.h"
int main()
{
	vector<Diary> my_diary;
	string str;
	Diary diary;
	string date;
	ifstream fin(fpath);
	while (!fin.eof())
	{
		getline(fin,date);
		diary.SetDate(date);
		diary.ClearText();
		getline(fin,str);
		while (str!=".")
		{
			diary.AddLine(str);
			getline(fin,str);
		}
		my_diary.push_back(diary);
	}
	fin.close();
    cin >> date;
    vector<Diary>::size_type i,j;
    for(i=0;i<my_diary.size();i++)
	{
		//找到要删除的日期，并调整所有日期的顺序
        if(my_diary[i].GetDate()==date)
		{
			for (j=i;j<my_diary.size()-1;j++)
			{
				my_diary[j] = my_diary[j+1];
			}
			my_diary.pop_back();
			//写回文件
			ofstream f_out(fpath);
			for (i=0;i<my_diary.size();i++)
			{
				if(my_diary[i].GetDate()!=""){
				f_out<<my_diary[i].GetDate()<<endl;
				f_out<<my_diary[i].GetText()<<endl;
				f_out<<"."<<endl;
				}
			}
			cout<<"1"<<endl;
			return 0;
        }
    }
	//没找到日期
	if (i==my_diary.size())
		cout<<"0"<<endl;
    return 0;    
}