#include<iostream.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
#include<stdlib.h>
#define M 20
#define N 12
class Fphone                          //�洢�û���Ϣ����
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

	char *getphone_num()              //����ָ��ĺ���
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
		user=new Fphone[50];            //�����ָ������ռ�
	    char name[M],phone_num[N];
		fstream in;
		int i=0;
		in.open("user.txt",ios::in|ios::nocreate);               
		while(in>>name>>phone_num)               // ��ȡ�ļ�����
		{
			user[i].setname(name);
			user[i].setphone_num(phone_num);
			i++;
		}
		nElem=i;
		in.close();
		cout<<"��ϵ������:"<<nElem<<endl;
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
			user[i].setphone_num(phone_num);                //ɾ����Ϣ��ֱ�Ӹ��Ŀ��ַ�
		}
		                                                          //����ʱд����ַ�
	}
	void add_record(char *na)
	{
		int i;
		for(i=0;i<nElem;i++)                           //�ж��û��Ƿ��Ѵ���
		{
			if(strcmp(user[i].getname(),na)==0)
			{
				cout<<"���û��Ѵ������ʧ��"<<endl;
			    return;
			}
		}
	    user[nElem].setname(na);
		cout<<"�����û��ĵ绰����:"<<endl;
		char *phone_num,p[N];
		cin>>p;
		phone_num=p;
		user[nElem].setphone_num(phone_num);
		nElem++;
	}
    void delete_record(char *na)                     //ɾ�����ܣ��ú��渲��
	{
		int i,j;
		char *t,sure[4];
		for(i=0;i<nElem;i++)  
			if(strcmp(user[i].getname(),na)==0)
		   {	
				cout<<"����yesȷ��ɾ��"<<endl;
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
			cout<<"�����ڴ��û�"<<endl;
	}


    void modify_record(char *na)                       //�޸Ĺ���
	{
		int i;
		char phone_num[N],*p;
		for(i=0;i<nElem;i++)  
			if(strcmp(user[i].getname(),na)==0)
			{
				cout<<"ԭ�к���"<<user[i].getphone_num()<<endl;
				cout<<"�����º���"<<endl;
				cin>>phone_num;
				p=phone_num;
				user[i].setphone_num(p);
				return;
			}
		cout<<"���û�������"<<endl;
	}		
	void query(char *na)                              //������ϵ�˺���
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
		cout<<"���û�������"<<endl;
	}

    void sorta_name()                    //��������������                //�˴�������ѡ��û�ò��뷨
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
	void sorta_phonenum()                       //��������������ѡ��
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
						strcpy(t,user[i].getname());                    //ʵ�������ַ����Ľ���
						user[i].setname(user[p].getname());
						user[p].setname(t);
						strcpy(t,user[i].getphone_num());
						user[i].setphone_num(user[p].getphone_num());
						user[p].setphone_num(t);
						
					}
				}
			}
	}
	void sort_name()                         //��������������
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
	void sort_phonenum()           //���뽵��ð��
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
	void dispall()                       //��ʾ����
	{
		int i;
		for(i=0;i<nElem;i++)
		   cout<<user[i].getname()<<' '<<user[i].getphone_num()<<endl;
	}
};
	
	

void main()
{
	UserDatabase mydata(6);     //Ӧ�ö���һ��UserDatabase����
	int x;                           
	cout<<"��ѡ�����¹���"<<endl<<"1-���Ӽ�¼"<<endl<<"2-�޸ļ�¼"<<endl<<"3-ɾ����¼"<<endl<<"4-���ң���������"<<endl<<"5-����"<<endl<<"6-��ʾ��¼"<<endl<<"7-ȫɾ"<<endl<<"0-�˳�"<<endl;
    cin>>x;
	if(x==1)
	{
		system("cls");
		cout<<"*********************************"<<endl<<"           ���Ӽ�¼"<<endl<<"*********************************"<<endl;
		char name1[M];
		cout<<"1-���Ӽ�¼�˵�"<<endl<<"��������û������͵绰����"<<endl;
		cin>>name1;
		mydata.add_record(name1);
	}
    else if(x==2)
	{
		system("cls");
		char name2[M];
		cout<<"*********************************"<<endl<<"           �޸ļ�¼"<<endl<<"*********************************"<<endl;
		cout<<"�������û�����:"<<endl;
		cin>>name2;
		mydata.modify_record(name2);
		
	}		
    else if(x==3)
	{
		system("cls");
		cout<<"*********************************"<<endl<<"           ɾ����¼"<<endl<<"*********************************"<<endl;
		cout<<"�������û�����:"<<endl;
		char name3[M];
		cin>>name3;
	    mydata.delete_record(name3);
	}


	else if(x==4)
	{
		system("cls");
		char name4[M];
		cout<<"*********************************"<<endl<<"           ��ѯ��¼"<<endl<<"*********************************"<<endl;
		cout<<"�����û�����"<<endl<<"���в���";
		cin>>name4;
		mydata.query(name4);
	}
		
    else if(x==5)
	{
		system("cls");
		cout<<"��ѡ������ʽ"<<endl<<"1-������(����)"<<endl<<"2-���绰����(����)"<<endl<<"3-������(����)"<<endl<<"4-���绰����(����)"<<endl<<"������ѡ��:";
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
		cout<<"*********************************"<<endl<<"           ��ʾ��¼"<<endl<<"*********************************"<<endl;
		mydata.dispall();
	}
	else if(x==7)
	{
		system("cls");
		cout<<"*********************************"<<endl<<"           ȫ��ɾ����¼"<<endl<<"*********************************"<<endl;
		char shanchu[10];
		cout<<"����yesȷ��ɾ��"<<endl;
		cin>>shanchu;
		if(strcmp(shanchu,"yes")==0)
		mydata.clear();
	}
	else if(x==0)
		system("cls");
}
		









