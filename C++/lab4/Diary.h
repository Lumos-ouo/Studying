#ifndef DIARY_H
#define DIARY_H
#include <string>
using namespace std;
class Diary
{
    private:
    string data="";
    string entity;
    public:
    void set(string data, string entity)
    {
        this->data=data;
        this->entity=entity;
    }
    string getData()
    {
        return data;
    }
    string getEntity()
    {
        return entity;
    }

};
Diary diaries[366];



#endif
