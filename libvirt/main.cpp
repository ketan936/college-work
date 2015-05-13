#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	double old1=0,old2=0,mem1,mem2;
	int cnt=0;
	double new1=0,new2=0;
    while(true)
    {
    ofstream o1;
    o1.open("save.txt");
    o1<<""<<endl;
    o1.close();
	system("xl list > save.txt");
	ifstream i1;
	i1.open("save.txt");
	string s1;
	cnt=0;
	while(!i1.eof())
	{
		cnt++;
		i1>>s1;
		if(cnt%12==0)
		{
			cout<<"new1"<<s1<<endl;
			new1=atof(s1.c_str());
		}
		if(cnt%18==0)
	        {
	        cout<<"new2 = "<<s1<<endl;
			new2=atof(s1.c_str());
		}
	}
	i1.close();
	system("xl sched-credit > save.txt");
	i1.open("save.txt");
	cnt=0;
	while(!i1.eof())
	{
		cnt++;
		i1>>s1;
		//cout<<s1<<endl;
		if(cnt%11==0)
		{
			//cout<<s1<<endl;
			mem1=atof(s1.c_str());
		}
		if(cnt%15==0)
		{
			//cout<<s1<<endl;
			mem2=atof(s1.c_str());
		}
	}
	cout<<"Mem 1 : "<<mem1<<"\nmem2 : "<<mem2<<endl;
	double p1,p2;
	p1=(new1-old1)*100/(new1+new2-old1-old2);
	p2=(new2-old2)*100/(new1+new2-old1-old2);
        cout<<"==> "<<new1<<" "<<old1<<endl;
        cout<<">>> "<<new2<<" "<<old2<<endl;
	cout<<"Domain 0 : "<<setw(10)<<new1-old1<<" "<<setw(10)<<mem1<<" MB	"<<setw(5)<<p1<<"%"<<endl;
	cout<<"Domain 1 : "<<setw(10)<<new2-old2<<" "<<setw(10)<<mem2<<" MB	"<<setw(5)<<p2<<"%"<<endl;
	int finalw;
	char  temp[100];
	if(p1>p2)
	{
		if(mem1<65000)
		{
			// Change weight to min of 3500 and 150% of mem1
			finalw=min(65000,(int)(3*mem1));
		sprintf(temp,"xl sched-credit -d Domain-0 -w %d",finalw);
		}
		else
		{
			// Change weight to max of 256 and 75% of mem2
			finalw=max(256,(int)(0.50*mem2));
		sprintf(temp,"xl sched-credit -d fep1 -w %d",finalw);
		}
		//temp="xl sched-credit -d Domain-0 -w";
		//temp+=stoi(finalw);
		cout<<temp<<endl;
		//system(temp);
	}
	else
	{
		if(mem2<65000)
		{
			// Change weight to min of 3500 and 150% of mem1
			finalw=min(65000,(int)(3*mem2));
		sprintf(temp,"xl sched-credit -d fep1 -w %d",finalw);
		}
		else
		{
			// Change weight to max of 256 and 75% of mem2
			finalw=max(256,(int)(0.50*mem1));
		sprintf(temp,"xl sched-credit -d Domain-0 -w %d",finalw);
		}
		//temp="xl sched-credit -d fep1 -w";
		//temp+=finalw;
		//cout<<temp<<endl;
		//system((temp).c_str());
		//system(temp);
	}
        i1.close();
        old1=new1;
        old2=new2;
        system("sleep 30");
        //goto start;
	}
	return 0;
}
