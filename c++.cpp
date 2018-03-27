#include<iostream.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
#include<stdlib.h>
#define M 20
#define N 12
class Fphone                          //存储用户信息的类
{
private:
	char name[M];
	char phone_num[N];
public:
	Fphone(){}
	char *getname()
	{
		char *p;
		p=name;
		return p;   
	}

	char *getphone_num()              //传递指针的函数
	{
		char *p;
		p=phone_num;
		return p;	
	}

	void setname(char *namep1)
	{
		strcpy(name,namep1);
	}

	void setphone_num(char *phone_num1)
	{
		strcpy(phone_num,phone_num1);
	}

	void disp()
	{
		cout<<name<<'\t'<<phone_num<<endl;
	}
};
class UserDatabase                                 
{
private:
	int nElem;
	Fphone *user;
public:
	UserDatabase(int n)
	{
		user=new Fphone[50];            //给类的指针申请空间
	    char name[M],phone_num[N];
		fstream in;
		int i=0;
		in.open("user.txt",ios::in|ios::nocreate);               
		while(in>>name>>phone_num)               // 读取文件内容
		{
			user[i].setname(name);
			user[i].setphone_num(phone_num);
			i++;
		}
		nElem=i;
		in.close();
		cout<<"联系人总数:"<<nElem<<endl;
	}
	~UserDatabase()
	{
		int i;
		fstream out;
		out.open("user.txt",ios::out);
		for(i=0;i<nElem;i++)
		{
			user[i].getname();
			user[i].getphone_num();
			out<<user[i].getname()<<' '<<user[i].getphone_num()<<endl;
		}
		out.close();
	}
	void clear()
	{
		char name[M],phone_num[N];
		int i;
		strcpy(name,"");
		strcpy(phone_num,"");
		for(i=0;i<nElem;i++)
		{
            user[i].setname(name);
			user[i].setphone_num(phone_num);                //删除信息我直接赋的空字符
		}
		                                                          //析构时写入空字符
	}
	void add_record(char *na)
	{
		int i;
		for(i=0;i<nElem;i++)                           //判断用户是否已存在
		{
			if(strcmp(user[i].getname(),na)==0)
			{
				cout<<"该用户已存在添加失败"<<endl;
			    return;
			}
		}
	    user[nElem].setname(na);
		cout<<"输入用户的电话号码:"<<endl;
		char *phone_num,p[N];
		cin>>p;
		phone_num=p;
		user[nElem].setphone_num(phone_num);
		nElem++;
	}
    void delete_record(char *na)                     //删除功能：用后面覆盖
	{
		int i,j;
		char *t,sure[4];
		for(i=0;i<nElem;i++)  
			if(strcmp(user[i].getname(),na)==0)
		   {	
				cout<<"输入yes确定删除"<<endl;
				cin>>sure;
				if(strcmp(sure,"yes")==0)
				{
					for(j=i;j+1<nElem;j++)
					{
					  user[j].setname(user[j+1].getname());
					  user[j].setphone_num(user[j+1].getphone_num());
					}
				nElem--;
				return;
				}
				else return;
		   }
			cout<<"不存在此用户"<<endl;
	}


    void modify_record(char *na)                       //修改功能
	{
		int i;
		char phone_num[N],*p;
		for(i=0;i<nElem;i++)  
			if(strcmp(user[i].getname(),na)==0)
			{
				cout<<"原有号码"<<user[i].getphone_num()<<endl;
				cout<<"输入新号码"<<endl;
				cin>>phone_num;
				p=phone_num;
				user[i].setphone_num(p);
				return;
			}
		cout<<"该用户不存在"<<endl;
	}		
	void query(char *na)                              //查找联系人函数
	{
		int i;
		for(i=0;i<nElem;i++)                       
		{
			if(strcmp(user[i].getname(),na)==0)
			{
				cout<<user[i].getname()<<'\t'<<user[i].getphone_num()<<endl;
				return;
			}
		}
		cout<<"该用户不存在"<<endl;
	}

    void sorta_name()                    //按姓名升序排序                //此处我用了选择法没用插入法
	{
		int i,j,p;
		char t[N];
		for(i=0;i<nElem;i++)
			for(j=i;j<nElem;j++)
			{
				p=i;
				if(strcmp(user[j].getname(),user[p].getname())==-1)
				{
					p=j;
					if(p!=i)
					{
						strcpy(t,user[i].getname());
						user[i].setname(user[p].getname());
						user[p].setname(t);
						strcpy(t,user[i].getphone_num());
						user[i].setphone_num(user[p].getphone_num());
						user[p].setphone_num(t);
					 
					}
				}
			}
	}
	void sorta_phonenum()                       //按号码升序排序选择法
	{
		int i,j,p;
		char t[N];
		for(i=0;i<nElem;i++)
			for(j=i;j<nElem;j++)
			{
				p=i;
				if(strcmp(user[j].getphone_num(),user[p].getphone_num())==-1)
				{
					p=j;
					if(p!=i)
					{
						strcpy(t,user[i].getname());                    //实现两个字符串的交换
						user[i].setname(user[p].getname());
						user[p].setname(t);
						strcpy(t,user[i].getphone_num());
						user[i].setphone_num(user[p].getphone_num());
						user[p].setphone_num(t);
						
					}
				}
			}
	}
	void sort_name()                         //按姓名降序排序
	{
		int i;
		char t[N];
		void sorta_name();
		for(i=0;i<nElem-i-1;i++)
		{
			strcpy(t,user[i].getname());
		    user[i].setname(user[nElem-i-1].getname());
			user[nElem-i-1].setname(t);
			strcpy(t,user[i].getphone_num());
			user[i].setphone_num(user[nElem-i-1].getphone_num());
			user[nElem-i-1].setphone_num(t);
		}
	}
	void sort_phonenum()           //号码降序冒泡
	{
		int i,j;
		char t[N];
		for(i=0;i<nElem;i++)
			for(j=0;j<nElem-i-1;j++)
			{
				if(strcmp(user[j].getphone_num(),user[j+1].getphone_num())==-1)
				{
					    strcpy(t,user[j].getname());
						user[j].setname(user[j+1].getname());
						user[j+1].setname(t);
						strcpy(t,user[j].getphone_num());
						user[j].setphone_num(user[j+1].getphone_num());
						user[j+1].setphone_num(t);
				}
			}
	}
	void dispall()                       //显示功能
	{
		int i;
		for(i=0;i<nElem;i++)
		   cout<<user[i].getname()<<' '<<user[i].getphone_num()<<endl;
	}
};
	
	

void main()
{
	UserDatabase mydata(6);     //应该定义一个UserDatabase对象
	int x;                           
	cout<<"请选择以下功能"<<endl<<"1-增加记录"<<endl<<"2-修改记录"<<endl<<"3-删除记录"<<endl<<"4-查找（按姓名）"<<endl<<"5-排序"<<endl<<"6-显示记录"<<endl<<"7-全删"<<endl<<"0-退出"<<endl;
    cin>>x;
	if(x==1)
	{
		system("cls");
		cout<<"*********************************"<<endl<<"           增加记录"<<endl<<"*********************************"<<endl;
		char name1[M];
		cout<<"1-增加记录菜单"<<endl<<"请输入该用户姓名和电话号码"<<endl;
		cin>>name1;
		mydata.add_record(name1);
	}
    else if(x==2)
	{
		system("cls");
		char name2[M];
		cout<<"*********************************"<<endl<<"           修改记录"<<endl<<"*********************************"<<endl;
		cout<<"请输入用户姓名:"<<endl;
		cin>>name2;
		mydata.modify_record(name2);
		
	}		
    else if(x==3)
	{
		system("cls");
		cout<<"*********************************"<<endl<<"           删除记录"<<endl<<"*********************************"<<endl;
		cout<<"请输入用户姓名:"<<endl;
		char name3[M];
		cin>>name3;
	    mydata.delete_record(name3);
	}


	else if(x==4)
	{
		system("cls");
		char name4[M];
		cout<<"*********************************"<<endl<<"           查询记录"<<endl<<"*********************************"<<endl;
		cout<<"输入用户姓名"<<endl<<"进行查找";
		cin>>name4;
		mydata.query(name4);
	}
		
    else if(x==5)
	{
		system("cls");
		cout<<"请选择排序方式"<<endl<<"1-按姓名(升序)"<<endl<<"2-按电话号码(升序)"<<endl<<"3-按姓名(降序)"<<endl<<"4-按电话号码(降序)"<<endl<<"请输入选择:";
		int m;
		cin>>m;
		if(m==1)
			mydata.sorta_name();
		else if(m==2)
			mydata.sorta_phonenum();
		else if(m==3)
			mydata.sort_name();
		else if(m==4)
			mydata.sort_phonenum();
	}
	else if(x==6)
	{
		system("cls");
		cout<<"*********************************"<<endl<<"           显示记录"<<endl<<"*********************************"<<endl;
		mydata.dispall();
	}
	else if(x==7)
	{
		system("cls");
		cout<<"*********************************"<<endl<<"           全部删除记录"<<endl<<"*********************************"<<endl;
		char shanchu[10];
		cout<<"输入yes确认删除"<<endl;
		cin>>shanchu;
		if(strcmp(shanchu,"yes")==0)
		mydata.clear();
	}
	else if(x==0)
		system("cls");
}
		









