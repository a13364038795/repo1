# include<iostream>
# include<thread>
# include<windows.h>
using namespace std;
//�Լ��������̴߳Ӻ�����ʼ����
class TA
{
public:
	TA(int i) :m_a(i) 
		//�ȼ��� m_a=i;
	{
		cout << "TA���캯����ִ��" << endl;
	};
	TA(const TA& ta) :m_a(ta.m_a)
		//�ȼ��� this->m_a=m_a;
	{
		cout << "TA�������캯����ִ��" << endl;
	}
	~TA()
	{
		cout << "~TA����������ִ��" << endl;
	}
	void operator()()  //���ܴ�����
	{
		//cout << "�ҵ��߳�operator()��ʼִ����" << endl;
		//cout << "�ҵ��߳�operator()ִ�н�����" << endl;
		cout << "m_a1��ֵΪ" << m_a <<endl;
		//һ�����߳�ִ���꣬m_a�е�ֵ�ͱ��ͷ��ˣ�
		//�����޷���ӡm_a�е�ֵ
		//Ҫ������BUG�����ù��캯���Ĳ�����Ҫ������
		//ֱ�Ӹ�ֵ
		cout << "m_a2��ֵΪ" << m_a<< endl;
		cout << "m_a3��ֵΪ" << m_a<< endl;
		cout << "m_a4��ֵΪ" << m_a<< endl;
		cout << "m_a5��ֵΪ" << m_a<< endl;
		cout << "m_a6��ֵΪ" << m_a<< endl;
	}
	int m_a;

};
void MyPrint()
{
	cout << "�Լ��������߳̿�ʼִ��1" << endl;
	cout << "�Լ��������߳�ִ�н���1" << endl;
	cout << "�Լ��������߳̿�ʼִ��2" << endl;
	cout << "�Լ��������߳�ִ�н���2" << endl;
}
int main()
{
	//thread mytobj(MyPrint);    //mytobj�ҵ��̶߳���
	//if (mytobj.joinable())
	//{
	//	cout << "����ʹ��join����detach" << endl;
	//}
	//else
	//{
	//	cout<< "������ʹ��join����detach" << endl;
	//}
	////�������̣߳��̵߳������MyPrint();
	////mytobj.join();
	////�����ϣ������������������̣߳������̵߳ȴ��ӽ���ִ�����
	////Ȼ�����̺߳����̻߳��
	//mytobj.detach();
	////��ͳ�Ķ��̳߳������߳�Ҫ�ȴ����߳�ִ���꣬��Ҳ������
	////��detach һ��detach֮����������߳��������thread����
	////�ͻ�ʧȥ�����̵߳Ĺ���
	////ʧȥ���������߳��൱�ڱ�C++����ʱ��ӹܣ������߳�����
	////��Ϻ�������ʱ��������߳���ص���Դ���ػ��̣߳�
	//cout << "���߳���β�����հ�ȫ�˳�1" << endl;
	//Sleep(500);
	//cout << "���߳���β�����հ�ȫ�˳�2" << endl;
	//cout << "���߳���β�����հ�ȫ�˳�3" << endl;
	//int myi = 6;
	//TA ta(myi);
	//thread mtobj2(ta);
	//mtobj2.join();
	////mtobj2.detach();
	//cout << "���߳̽���" << endl;
	auto mylamthread = []() {     //�����������û�в���
		cout << "�Լ�����lambda�߳̿�ʼִ��" << endl;
		cout << "�Լ�����lambda�߳�ִ�н���" << endl;
	};
	thread mytobj(mylamthread);
	mytobj.join();
	cout << "���߳̽���" << endl;
	return 0;
}