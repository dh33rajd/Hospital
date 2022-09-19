#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
int global,t,size_p,empty=0,choiced=0;
class doctor
{char name[15];
 int age;
 int pno;
 int dept;
 char qualif[10];
 char instit[25];
 char gender;
 public:
 void disp()
 {cout<<" NAME : "<<name<<"\t\t QUALIFICATION : "<<qualif<<"\n";
 };
 void add()
 {clrscr();
  cout<<"\n ENTER DOCTOR NAME                     :";
  cin>>name;
  cout<<"\n ENTER AGE                             :";
  cin>>age;
  clrscr();
  cout<<"\n\t\t\t SELECT THE DEPARTMENT     \n";
  cout<<"\n 1.  ANESTHETICS";
  cout<<"\n 2.  CARDIOLOGY";
  cout<<"\n 3.  EAR, NOSE , THROAT ";
  cout<<"\n 4.  ELDERLY SERVICES ";
  cout<<"\n 5.  GASTREOENTEROLOGY ";
  cout<<"\n 6.  GENERAL SURGERY";
  cout<<"\n 7.  GYNAECOLOGY";
  cout<<"\n 8.  HEMATOLOGY";
  cout<<"\n 9.  NEONATAL UNIT";
  cout<<"\n 10. NEUROLOGY";
  cout<<"\n 11. NUTRITION AND DIATETICS";
  cout<<"\n 12. OBSTETRRICS AND GYNECOLOGY UNITS";
  cout<<"\n 13. ONCOLOGY";
  cout<<"\n 14. OPHTHALMOLOGY";
  cout<<"\n 15. ORTHOPEDICS";
  cout<<"\n 16. PHYSIOTHERAPY";
  cout<<"\n\n select your choice : ";
  cin>>dept;
  global=dept;
  clrscr();
  cout<<"\n ENTER THE QUALIFICATION            :";
  cin>>qualif;
  cout<<"\n ENTER THE INSTITUTION -GRADUATED   :";
  cin>>instit;
  cout<<"\n ENTER GENDER (M/F)                 :";
  cin>>gender;
 }
 void modify()
 {clrscr();
  cout<<"\n ENTER DOCTOR NAME                     :";
  cin>>name;
  cout<<"\n ENTER AGE                             :";
  cin>>age;
  cout<<"\n ENTER THE QUALIFICATION               :";
  cin>>qualif;
  cout<<"\n ENTER THE INSTITUTION -GRADUATED      :";
  cin>>instit;
  cout<<"\n ENTER GENDER (M/F)                    :";
  cin>>gender;
 }
};
class patient
{
 int idno;
 char name[15];
 char gender;
 int age;
 char bldgp[5];
 char address[150];
 int roomno;
 int tkno;
 doctor *d;
 char disease[15];
 public:
 int getid()
 {
  return idno;
 }
 void add()
 {
  clrscr();
  cout<<"\n ENTER THE PATIENT NAME            : ";
  gets(name);
  cout<<"\n ENTER THE GENDER (M / F)          : ";
  cin>>gender;
  cout<<"\n ENTER THE AGE                     : ";
  cin>>age;
  cout<<"\n ENTER THE BLOOD GROUP (o+,o-,...) : ";
  cin>>bldgp;
  cout<<"\n ENTER THE ADDRESS                 : ";
  gets(address);
  cout<<"\n ENTER THE ROOM NO                 : ";
  cin>>roomno;
  cout<<"\n ENTER THE DISEASE                 : ";
  gets(disease);
  fstream finout;
  finout.open("idno.dat",ios::in|ios::out);
  finout.seekg(0,ios::end);
  if(finout.tellg()<=0)
  {t=1000;
   finout<<t<<"\n";
  }
  finout.seekg(0);
  finout>>t;
  remove("idno.dat");
  idno=t;
  t++;
  finout.close();
  ofstream fin("idno.dat",ios::out);
  fin<<t;
  fin.close();
  cout<<"\n IDNO IS : "<<idno;
  getch();
 }
 void disp()
 {cout<<"\n\n\n\t\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
  cout<<"\n\n\t\t   T E X T  M E D I C A L  I N S T I T U T E";
  cout<<"\n\t\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
  cout<<"\n\n\t\t               PATIENT DETAILS";
  cout<<"\n ID NO  : "<<idno<<"\n NAME   : "<<name;
  cout<<"\n AGE    : "<<age;
 }
};
void disp_doc(int choice,int check);
void add_doc(doctor d,int n);
void main()
{int c,choice,choice1,choice2,choice3,p_id;
 doctor d;
 clrscr();
 cout<<"\n\n_________________________________W E L C O M E__________________________________\n\n";
 cout<<"\n\n\n\t\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
 cout<<"\n\n\t\t   T E X T  M E D I C A L  I N S T I T U T E";
 cout<<"\n\t\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n ";
 textcolor(RED+BLINK);
 cprintf("\n\n\n\n\n\n                         PRESS ANY KEY TO CONTINUE");
 textcolor(WHITE);
 getch();
 do
 {
 clrscr();
 cout<<"\n\n\t\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
 cout<<"\n\n\t\t   T E X T  M E D I C A L  I N S T I T U T E";
 cout<<"\n\t\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
 cout<<"\n\n\t\t\t _________________________\n ";
 cout<<"\n\t\t\t A C C O U N T   L O G I N";
 cout<<"\n\t\t\t _________________________ ";
 cout<<"\n\n\n\n   1. ADMIN\n\n";
 cout<<"   2. USER\n\n";
 cout<<"   3. EXIT";
 cout<<"\n\n ENTER YOUR CHOICE : ";
 cin>>c;
 clrscr();
 if(c!=3)
 {
 cout<<"\n\n\n\t\t\t\t W A R N I N G ";
 cout<<"\n\n\n      if you forgot your password, enter 0000 to exit the program";
 cout<<"\n\n\n\n\n LOADING ";
 for(int x=1;x<70;x++)
 {cout<<char(219);
  delay(50);
 }
 }
 clrscr();
 switch(c)
  {
    case 1:char pass[5];
	   do
	   {cout<<"\n\t\t\t PASSWORD : ";
	    for(int i=0;i<4;i++)
	    {pass[i]=getch();
	     cout<<"* ";
	    }
	    pass[i]='\0';
	    if(strcmp(pass,"0000")==0)
	    exit(0);
	    else if(strcmp(pass,"1234")==0)
	    {
	     do
	     {
	     clrscr();
	     cout<<"\n\n\n\t\t\t    W  E  L  C  O  M  E  ";delay(200);
	     cout<<"\n\n_____________________________M A I N   M E N U_____________________________";
	     cout<<"\n\n\n\n 1. ADD A DOCTOR";
	     cout<<"\n\n 2. LIST DOCTORS";
	     cout<<"\n\n 3. MODIFY A DOCTOR";
	     cout<<"\n\n 4. DELETE A DOCTOR";
	     cout<<"\n\n 5. EXIT";
	     cout<<"\n\n Enter The Choice : ";
	     cin>>choice1;
	     clrscr();
	     switch(choice1)
	     {case 1:d.add();
		     add_doc(d,global);
		     break;
	      case 2:clrscr();
		     cout<<"\n\t\t\t SELECT THE DEPARTMENT     \n";
		     cout<<"\n 1.  ANESTHETICS";
		     cout<<"\n 2.  CARDIOLOGY";
		     cout<<"\n 3.  EAR, NOSE , THROAT ";
		     cout<<"\n 4.  ELDERLY SERVICES ";
		     cout<<"\n 5.  GASTREOENTEROLOGY ";
		     cout<<"\n 6.  GENERAL SURGERY";
		     cout<<"\n 7.  GYNAECOLOGY";
		     cout<<"\n 8.  HEMATOLOGY";
		     cout<<"\n 9.  NEONATAL UNIT";
		     cout<<"\n 10. NEUROLOGY";
		     cout<<"\n 11. NUTRITION AND DIATETICS";
		     cout<<"\n 12. OBSTETRRICS AND GYNECOLOGY UNITS";
		     cout<<"\n 13. ONCOLOGY";
		     cout<<"\n 14. OPHTHALMOLOGY";
		     cout<<"\n 15. ORTHOPEDICS";
		     cout<<"\n 16. PHYSIOTHERAPY";
		     cout<<"\n\n select your choice : ";
		     cin>>choice;
		     disp_doc(choice,0);
		     cout<<"\n press enter to continue.......";
		     getch();
		     break;
	      case 3:cout<<"\n\t\t\t SELECT THE DEPARTMENT     \n";
		     cout<<"\n 1.  ANESTHETICS";
		     cout<<"\n 2.  CARDIOLOGY";
		     cout<<"\n 3.  EAR, NOSE , THROAT ";
		     cout<<"\n 4.  ELDERLY SERVICES ";
		     cout<<"\n 5.  GASTREOENTEROLOGY ";
		     cout<<"\n 6.  GENERAL SURGERY";
		     cout<<"\n 7.  GYNAECOLOGY";
		     cout<<"\n 8.  HEMATOLOGY";
		     cout<<"\n 9.  NEONATAL UNIT";
		     cout<<"\n 10. NEUROLOGY";
		     cout<<"\n 11. NUTRITION AND DIATETICS";
		     cout<<"\n 12. OBSTETRRICS AND GYNECOLOGY UNITS";
		     cout<<"\n 13. ONCOLOGY";
		     cout<<"\n 14. OPHTHALMOLOGY";
		     cout<<"\n 15. ORTHOPEDICS";
		     cout<<"\n 16. PHYSIOTHERAPY";
		     cout<<"\n\n 17. EXIT";
		     cout<<"\n\n select your choice : ";
		     cin>>choiced;
		     disp_doc(choiced,2);
		     break;
	      case 4:cout<<"\n\t\t\t SELECT THE DEPARTMENT     \n";
		     cout<<"\n 1.  ANESTHETICS";
		     cout<<"\n 2.  CARDIOLOGY";
		     cout<<"\n 3.  EAR, NOSE , THROAT ";
		     cout<<"\n 4.  ELDERLY SERVICES ";
		     cout<<"\n 5.  GASTREOENTEROLOGY ";
		     cout<<"\n 6.  GENERAL SURGERY";
		     cout<<"\n 7.  GYNAECOLOGY";
		     cout<<"\n 8.  HEMATOLOGY";
		     cout<<"\n 9.  NEONATAL UNIT";
		     cout<<"\n 10. NEUROLOGY";
		     cout<<"\n 11. NUTRITION AND DIATETICS";
		     cout<<"\n 12. OBSTETRRICS AND GYNECOLOGY UNITS";
		     cout<<"\n 13. ONCOLOGY";
		     cout<<"\n 14. OPHTHALMOLOGY";
		     cout<<"\n 15. ORTHOPEDICS";
		     cout<<"\n 16. PHYSIOTHERAPY";
		     cout<<"\n\n 17. EXIT";
		     cout<<"\n\n select your choice : ";
		     cin>>choiced;
		     disp_doc(choiced,3);
		     break;
	      case 5:exit(0);
	     default:clrscr();
		     cout<<"\n\n   I N V A L I D   E N T R Y"<<"\n\n  press enter to continue..";
		     getch();

	     };
	     clrscr();
	     cout<<"\n\n\t\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
	     cout<<"\n\n\t\t   T E X T  M E D I C A L  I N S T I T U T E";
	     cout<<"\n\t\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
	     cout<<"\n\n 1. ADMIN MAIN MENU";
	     cout<<"\n\n 2. ADMIN LOG OUT";
	     cout<<"\n\n 3. EXIT..";
	     cout<<"\n\n ENTER CHOICE : ";
	     cin>>choice3;
	     if(choice3==3)
	     exit(0);
	     }while(choice3==1);
	    }
	    else
	    {for(i=5;i>0;i--)
	     {clrscr();
	      cout<<"\n\n\n\n\n\n\t\t\tTRY AGAIN IN "<<i<<" SECONDS";
	      delay(1000);
	     }
	     clrscr();
	    }
	   } while(strcmp(pass,"1234")!=0);
	   break;

    case 2:char c1[5];
	   do
	   {cout<<"\n\t\t\t PASSWORD :";
	    for(int i=0;i<4;i++)
	    {c1[i]=getch();
	     cout<<"* ";
	    }
	    c1[i]='\0';
	    if(strcmp(c1,"0000")==0)
	     exit(0);
	    else if(strcmp(c1,"1234")==0)
	    {do
	     {
	     clrscr();
	     cout<<"\n\n\n\t\t\t    W  E  L  C  O  M  E  ";delay(200);
	     cout<<"\n\n_____________________________M A I N   M E N U_____________________________";
	     cout<<"\n\n\n 1. ADD A PATIENT";
	     cout<<"\n\n 2. FIND A PATIENT";
	     cout<<"\n\n 3. MODIFY A PATIENT";
	     cout<<"\n\n 4. DISCHARGE A PATIENT";
	     cout<<"\n\n 5. EXIT";
	     cout<<"\n\n Enter The Choice : ";
	     cin>>choice2;
	     clrscr();
	     switch(choice2)
	     {case 1:cout<<"\n\t\t\t SELECT THE DEPARTMENT     \n";
		     cout<<"\n 1.  ANESTHETICS";
		     cout<<"\n 2.  CARDIOLOGY";
		     cout<<"\n 3.  EAR, NOSE , THROAT ";
		     cout<<"\n 4.  ELDERLY SERVICES ";
		     cout<<"\n 5.  GASTREOENTEROLOGY ";
		     cout<<"\n 6.  GENERAL SURGERY";
		     cout<<"\n 7.  GYNAECOLOGY";
		     cout<<"\n 8.  HEMATOLOGY";
		     cout<<"\n 9.  NEONATAL UNIT";
		     cout<<"\n 10. NEUROLOGY";
		     cout<<"\n 11. NUTRITION AND DIATETICS";
		     cout<<"\n 12. OBSTETRRICS AND GYNECOLOGY UNITS";
		     cout<<"\n 13. ONCOLOGY";
		     cout<<"\n 14. OPHTHALMOLOGY";
		     cout<<"\n 15. ORTHOPEDICS";
		     cout<<"\n 16. PHYSIOTHERAPY";
		     cout<<"\n\n 17. EXIT";
		     cout<<"\n\n select your choice : ";
		     cin>>choice;
		     disp_doc(choice,1);
		     break;
	      case 2:cout<<"\n Enter the patient ID : ";
		     cin>>p_id;
		     int found2=0;
		     ifstream fin1;
		     fin1.open("patient.dat",ios::binary);
		     fin1.seekg(0);
		     patient p;
		     while(!fin1.eof())
		     {fin1.read((char*)&p,sizeof(p));
		      cout<<"idno is "<<p.getid(); delay(1000);
		      clrscr();
		      if(p.getid()==p_id)
		      {
		       p.disp();
		       found2=1;
		       getch();
		      }
		     }
		     fin1.close();
		     if(found2==0)
		     {cout<<"\n\n	    Such a record does not exist";
		      cout<<"\n\n\n press enter to continue.....";
		      getch();
		     }
		     break;
	      case 3:cout<<"\n Enter the patient id no:";
		     cin>>p_id;
		     patient p1,p2;
		     fstream inout;
		     inout.open("patient.dat",ios::in|ios::out);
		     int found1=0,count=0;
		     while(!inout.eof()&&found1==0)
		     { count++;
		       inout.read((char*)&p2,sizeof(p2));
		       if (p2.getid()==1)
		       clrscr();
		       cout<<"\n\t\t\t ...........CURRENT DETAILS.........\n\n";
		       p2.disp();
		       cout<<"\n\n press enter to continue";
		       getch();
		       clrscr();
		       cout<<"\n\n\n\n\n\t\t\t ENTER THE NEW DETAILS ";
		       delay(700);
		       p1.add();
		       inout.seekp((count-1)*sizeof(patient));
		       inout.write((char*)&p1,sizeof(p1));
		       found1=1;
		       cout<<"\n\n      EARLIER RECORD DELETED YOU CAN USE NEW IDNO";
		       cout<<"\n\n           ......  RECORD MODIFIED..........";
		       cout<<"\n\n\n\n\n               press enter to continue ";
		       getch();
		     }
		    if(found1==0)
		    cout<<"\n\n	    Such a record does not exist";
		    inout.close();
		    break;
	      case 4:cout<<"\n\n Enter the patient id no : ";
		    cin>>p_id;
		    patient p9;
		    int count1=0;
		    fstream inout1("patient.dat",ios::in|ios::out);
		    inout1.seekg(0,ios::end);
		    int size=inout1.tellg();
		    int records= size/sizeof(patient);
		    fstream inouttemp("temp.dat",ios::out);
		    inout1.seekg(0,ios::beg);
		    inouttemp.seekp(0,ios::beg);
		    while (inout1&&count1<records)
		    {inout1.read((char*)&p,sizeof(p));
		     if(p.getid()==p_id)
		     inouttemp.write((char*)&p,sizeof(p));
		     count1++;
		    }
		    cout<<"\n ALL RECORDS OF PATIENT DELETED.............";
		    getch();
		    inout1.close();
		    inouttemp.close();
		    remove("patient.dat");
		    rename("temp.dat","patient.dat");
		    break;
	      case 5:exit(0);
	      default:clrscr();
		      cout<<"\n\n   I N V A L I D   E N T R Y"<<"\n\n  press enter to continue..";
		      getch();
	     };
	     empty=0;
	     clrscr();
	     cout<<"\n\n\t\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
	     cout<<"\n\n\t\t   T E X T  M E D I C A L  I N S T I T U T E";
	     cout<<"\n\t\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
	     cout<<"\n\n 1. USER MAIN MENU";
	     cout<<"\n\n 2. USER LOG OUT";
	     cout<<"\n\n 3. EXIT..";
	     cout<<"\n\n ENTER CHOICE : ";
	     cin>>choice3;
	     if(choice3==3)
	     exit(0);
	     }while(choice3==1);
	    }
	    else
	    {for(i=5;i>0;i--)
	     {clrscr();
	      cout<<"\n\n\n\n\n\n\t\t\tTRY AGAIN IN "<<i<<" SECONDS";
	      delay(1000);
	     }
	     clrscr();
	    }
	   }while(strcmp(c1,"1234")!=0);
	   break;
    case 3:exit(0);

  };
}while(choice3==2);
getch();
}
void add_doc(doctor d,int n)
{ofstream fout;
 switch(n)
 {
 case 1:fout.open("dept1.dat",ios::out|ios::app);
	fout.write((char*)&d,sizeof(d));
	break;
 case 2:fout.open("dept2.dat",ios::app);
	fout.write((char*)&d,sizeof(d));
	break;
 case 3:fout.open("dept3.dat",ios::app);
	fout.write((char*)&d,sizeof(d));
	break;
 case 4:fout.open("dept4.dat",ios::app);
	fout.write((char*)&d,sizeof(d));
	break;
 case 5:fout.open("dept5.dat",ios::app);
	fout.write((char*)&d,sizeof(d));
	break;
 case 6:fout.open("dept6.dat",ios::app);
	fout.write((char*)&d,sizeof(d));
	break;
 case 7:fout.open("dept7.dat",ios::app|ios::binary);
	fout.write((char*)&d,sizeof(d));
	break;
 case 8:fout.open("dept8.dat",ios::app);
	fout.write((char*)&d,sizeof(d));
	break;
 case 9:fout.open("dept9.dat",ios::app);
	fout.write((char*)&d,sizeof(d));
	break;
 case 10:fout.open("dept10.dat",ios::app);
	 fout.write((char*)&d,sizeof(d));
	 break;
 case 11:fout.open("dept11.dat",ios::app);
	 fout.write((char*)&d,sizeof(d));
	 break;
 case 12:fout.open("dept12.dat",ios::app);
	 fout.write((char*)&d,sizeof(d));
	 break;
 case 13:fout.open("dept13.dat",ios::app);
	 fout.write((char*)&d,sizeof(d));
	 break;
 case 14:fout.open("dept14.dat",ios::app);
	 fout.write((char*)&d,sizeof(d));
	 break;
 case 15:fout.open("dept15.dat",ios::app);
	 fout.write((char*)&d,sizeof(d));
	 break;
 case 16:fout.open("dept16.dat",ios::app);
	 fout.write((char*)&d,sizeof(d));
	 break;
 };
 fout.close();
};
void disp_doc(int choice,int check)
{clrscr();
 if(check==0)
 {cout<<"\n\n\n\t\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
  cout<<"\n\n\t\t   T E X T  M E D I C A L  I N S T I T U T E";
  cout<<"\n\t\t   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
 }
 cout<<"\n\n________________________________LIST OF DOCTORS_________________________________\n\n";
 fstream fin;
 int a=1,records,count2=0,size;
 switch(choice)
 {doctor d;
 case 1:fin.open("dept1.dat",ios::in|ios::out);
	fin.seekg(0,ios::end);
	if(fin.tellg()<=0)
	{cout<<"\n NO DOCTORS IN THIS DEPARTMENT";
	 empty=1;
	 getch();
	 fin.close();
	 break;
	}
	fin.seekg(0,ios::end);
	size=fin.tellg();
	records= size/sizeof(d);
	fin.seekg(0);
	while(!fin.eof()&&count2<=(records-1))
	{cout<<"\n  "<<a<<" . ";
	 fin.read((char*)&d,sizeof(d));
	 d.disp();
	 a++;
	 count2++;
	}
	break;
 case 2:fin.open("dept2.dat",ios::in|ios::out);
	fin.seekg(0,ios::end);
	if(fin.tellg()<=0)
	{cout<<"\n NO DOCTORS IN THIS DEPARTMENT";
	 empty=1;
	 getch();
	 fin.close();
	 break;
	}
	fin.seekg(0,ios::end);
	size=fin.tellg();
	records= size/sizeof(d);
	fin.seekg(0);
	while(!fin.eof()&&count2<=(records-1))
	{cout<<"\n  "<<a<<" . ";
	 fin.read((char*)&d,sizeof(d));
	 d.disp();
	 a++;
	 count2++;
	}
	break;
 case 3:fin.open("dept3.dat",ios::in|ios::out);
	fin.seekg(0,ios::end);
	if(fin.tellg()<=0)
	{cout<<"\n NO DOCTORS IN THIS DEPARTMENT";
	 empty=1;
	 getch();
	 fin.close();
	 break;
	}
	fin.seekg(0,ios::end);
	size=fin.tellg();
	records= size/sizeof(d);
	fin.seekg(0);
	while(!fin.eof()&&count2<=(records-1))
	{cout<<"\n  "<<a<<" . ";
	 fin.read((char*)&d,sizeof(d));
	 d.disp();
	 a++;
	 count2++;
	}
	break;
 case 4:fin.open("dept4.dat",ios::in|ios::out);
	fin.seekg(0,ios::end);
	if(fin.tellg()<=0)
	{cout<<"\n NO DOCTORS IN THIS DEPARTMENT";
	 empty=1;
	 getch();
	 fin.close();
	 break;
	}
	fin.seekg(0,ios::end);
	size=fin.tellg();
	records= size/sizeof(d);
	fin.seekg(0);
	while(!fin.eof()&&count2<=(records-1))
	{cout<<"\n  "<<a<<" . ";
	 fin.read((char*)&d,sizeof(d));
	 d.disp();
	 a++;
	 count2++;
	}
	break;
 case 5:fin.open("dept5.dat",ios::in|ios::out);
	fin.seekg(0,ios::end);
	if(fin.tellg()<=0)
	{cout<<"\n NO DOCTORS IN THIS DEPARTMENT";
	 empty=1;
	 getch();
	 fin.close();
	 break;
	}
	fin.seekg(0,ios::end);
	size=fin.tellg();
	records= size/sizeof(d);
	fin.seekg(0);
	while(!fin.eof()&&count2<=(records-1))
	{cout<<"\n  "<<a<<" . ";
	 fin.read((char*)&d,sizeof(d));
	 d.disp();
	 a++;
	 count2++;
	}
	break;
 case 6:fin.open("dept6.dat",ios::in|ios::out);
	fin.seekg(0,ios::end);
	if(fin.tellg()<=0)
	{cout<<"\n NO DOCTORS IN THIS DEPARTMENT";
	 empty=1;
	 getch();
	 fin.close();
	 break;
	}
	fin.seekg(0,ios::end);
	size=fin.tellg();
	records= size/sizeof(d);
	fin.seekg(0);
	while(!fin.eof()&&count2<=(records-1))
	{cout<<"\n  "<<a<<" . ";
	 fin.read((char*)&d,sizeof(d));
	 d.disp();
	 a++;
	 count2++;
	}
	break;
 case 7:fin.open("dept7.dat",ios::in|ios::out);
	fin.seekg(0,ios::end);
	if(fin.tellg()<=0)
	{cout<<"\n NO DOCTORS IN THIS DEPARTMENT";
	 getch();
	 empty=1;
	 fin.close();
	 break;
	}
	fin.seekg(0,ios::end);
	size=fin.tellg();
	records= size/sizeof(d);
	fin.seekg(0);
	while(!fin.eof()&&count2<=(records-1))
	{cout<<"\n  "<<a<<" . ";
	 fin.read((char*)&d,sizeof(d));
	 d.disp();
	 a++;
	 count2++;
	}
	break;
 case 8:fin.open("dept8.dat",ios::in|ios::out);
	fin.seekg(0,ios::end);
	if(fin.tellg()<=0)
	{cout<<"\n NO DOCTORS IN THIS DEPARTMENT";
	 empty=1;
	 fin.close();
	 getch();
	 break;
	}
	fin.seekg(0,ios::end);
	size=fin.tellg();
	records= size/sizeof(d);
	fin.seekg(0);
	while(!fin.eof()&&count2<=(records-1))
	{cout<<"\n  "<<a<<" . ";
	 fin.read((char*)&d,sizeof(d));
	 d.disp();
	 a++;
	 count2++;
	}
	break;
 case 9:fin.open("dept9.dat",ios::in|ios::out);
	fin.seekg(0,ios::end);
	if(fin.tellg()<=0)
	{cout<<"\n NO DOCTORS IN THIS DEPARTMENT";
	 getch();
	 empty=1;
	 fin.close();
	 break;
	}
	fin.seekg(0,ios::end);
	size=fin.tellg();
	records= size/sizeof(d);
	fin.seekg(0);
	while(!fin.eof()&&count2<=(records-1))
	{cout<<"\n  "<<a<<" . ";
	 fin.read((char*)&d,sizeof(d));
	 d.disp();
	 a++;
	 count2++;
	}
	break;
 case 10:fin.open("dept10.dat",ios::in|ios::out);
	fin.seekg(0,ios::end);
	if(fin.tellg()<=0)
	{cout<<"\n NO DOCTORS IN THIS DEPARTMENT";
	 getch();
	 empty=1;
	 fin.close();
	 break;
	}
	fin.seekg(0,ios::end);
	size=fin.tellg();
	records= size/sizeof(d);
	fin.seekg(0);
	while(!fin.eof()&&count2<=(records-1))
	{cout<<"\n  "<<a<<" . ";
	 fin.read((char*)&d,sizeof(d));
	 d.disp();
	 a++;
	 count2++;
	}
	break;
 case 11:fin.open("dept11.dat",ios::in|ios::out);
	fin.seekg(0,ios::end);
	if(fin.tellg()<=0)
	{cout<<"\n NO DOCTORS IN THIS DEPARTMENT";
	 empty=1;
	 getch();
	 fin.close();
	 break;
	}
	fin.seekg(0,ios::end);
	size=fin.tellg();
	records= size/sizeof(d);
	fin.seekg(0);
	while(!fin.eof()&&count2<=(records-1))
	{cout<<"\n  "<<a<<" . ";
	 fin.read((char*)&d,sizeof(d));
	 d.disp();
	 a++;
	 count2++;
	}
	break;
 case 12:fin.open("dept12.dat",ios::in|ios::out);
	fin.seekg(0,ios::end);
	if(fin.tellg()<=0)
	{cout<<"\n NO DOCTORS IN THIS DEPARTMENT";
	 getch();
	 empty=1;
	 fin.close();
	 break;
	}
	fin.seekg(0,ios::end);
	size=fin.tellg();
	records= size/sizeof(d);
	fin.seekg(0);
	while(!fin.eof()&&count2<=(records-1))
	{cout<<"\n  "<<a<<" . ";
	 fin.read((char*)&d,sizeof(d));
	 d.disp();
	 a++;
	 count2++;
	}
	break;
 case 13:fin.open("dept13.dat",ios::in|ios::out);
	fin.seekg(0,ios::end);
	if(fin.tellg()<=0)
	{cout<<"\n NO DOCTORS IN THIS DEPARTMENT";
	 empty=1;
	 fin.close();
	 getch();
	 break;
	}
	fin.seekg(0,ios::end);
	size=fin.tellg();
	records= size/sizeof(d);
	fin.seekg(0);
	while(!fin.eof()&&count2<=(records-1))
	{cout<<"\n  "<<a<<" . ";
	 fin.read((char*)&d,sizeof(d));
	 d.disp();
	 a++;
	 count2++;
	}
	break;
 case 14:fin.open("dept14.dat",ios::in|ios::out);
	fin.seekg(0,ios::end);
	if(fin.tellg()<=0)
	{cout<<"\n NO DOCTORS IN THIS DEPARTMENT";
	 getch();
	 empty=1;
	 fin.close();
	 break;
	}
	fin.seekg(0,ios::end);
	size=fin.tellg();
	records= size/sizeof(d);
	fin.seekg(0);
	while(!fin.eof()&&count2<=(records-1))
	{cout<<"\n  "<<a<<" . ";
	 fin.read((char*)&d,sizeof(d));
	 d.disp();
	 a++;
	 count2++;
	}
	break;
 case 15:fin.open("dept15.dat",ios::in|ios::out);
	fin.seekg(0,ios::end);
	if(fin.tellg()<=0)
	{cout<<"\n NO DOCTORS IN THIS DEPARTMENT";
	 empty=1;
	 getch();
	 fin.close();
	 break;
	}
	fin.seekg(0,ios::end);
	size=fin.tellg();
	records= size/sizeof(d);
	fin.seekg(0);
	while(!fin.eof()&&count2<=(records-1))
	{cout<<"\n  "<<a<<" . ";
	 fin.read((char*)&d,sizeof(d));
	 d.disp();
	 a++;
	 count2++;
	}
	break;
 case 16:fin.open("dept16.dat",ios::in|ios::out);
	fin.seekg(0,ios::end);
	if(fin.tellg()<=0)
	{cout<<"\n NO DOCTORS IN THIS DEPARTMENT";
	 getch();
	 empty=1;
	 fin.close();
	 break;
	}
	fin.seekg(0,ios::end);
	size=fin.tellg();
	records= size/sizeof(d);
	fin.seekg(0);
	while(!fin.eof()&&count2<=(records-1))
	{cout<<"\n  "<<a<<" . ";
	 fin.read((char*)&d,sizeof(d));
	 d.disp();
	 a++;
	 count2++;
	}
	break;
 case 17:exit(0);
 };
 if(check==1&&empty==0)
 {int doc_no,size;
  cout<<"\n Choose your doctor number : ";
  cin>>doc_no;
  doctor doc_pat;
  size=sizeof(doc_pat);
  fin.seekg(0);
  fin.seekg(size*(doc_no-1));
  fin.read((char*)&doc_pat,sizeof(doc_pat));
  patient p;
  p.add();
  fin.close();
  ofstream pout;
  pout.open("patient.dat",ios::app,ios::binary);
  pout.write((char*)&p,sizeof(p));
  pout.close();
 }
 if(check==2&&empty==0)
 {
  int doc_no,size;
  cout<<"\n choose your doctor number : ";
  cin>>doc_no;
  doctor d;
  size=sizeof(d);
  d.modify();
  fin.seekp(0,ios::beg);
  fin.seekp(size*(doc_no-1));
  fin.write((char*)&d,sizeof(d));
  clrscr();
  cout<<"\n\n\n RECORD MODIFIED...........";
  cout<<"\n\n\n press enter to continue";
  getch();
 }
 if(check==3&&empty==0)
 {int doc_no,size;
  cout<<"\n choose your doctor number : ";
  cin>>doc_no;
  doctor d;
  fin.seekg(0,ios::end);
  size=fin.tellg();
  int records=size/sizeof(d);
  fstream inouttemp("temp.dat",ios::out);
  fin.seekg(0,ios::beg);
  inouttemp.seekp(0,ios::beg);
  int count2=0;
  while(!fin.eof()&&count2<=(records-1))
  {count2++;
   fin.read((char*)&d,sizeof(d));
   if(count2!=doc_no)
   inouttemp.write((char*)&d,sizeof(d));
  }
  clrscr();
  cout<<"\n RECORD DELETED.............";
  getch();
  inouttemp.close();
  switch(choiced)
  {case 1:remove("dept1.dat");
	  rename("temp.dat","dept1.dat");
	  break;
   case 2:remove("dept2.dat");
	  rename("temp.dat","dept2.dat");
	  break;
   case 3:remove("dept3.dat");
	  rename("temp.dat","dept3.dat");
	  break;
   case 4:remove("dept4.dat");
	  rename("temp.dat","dept4.dat");
	  break;
   case 5:remove("dept5.dat");
	  rename("temp.dat","dept5.dat");
	  break;
   case 6:remove("dept6.dat");
	  rename("temp.dat","dept6.dat");
	  break;
   case 7:remove("dept7.dat");
	  rename("temp.dat","dept7.dat");
	  break;
   case 8:remove("dept8.dat");
	  rename("temp.dat","dept8.dat");
	  break;
   case 9:remove("dept9.dat");
	  rename("temp.dat","dept9.dat");
	  break;
   case 10:remove("dept10.dat");
	  rename("temp.dat","dept10.dat");
	  break;
   case 11:remove("dept11.dat");
	  rename("temp.dat","dept11.dat");
	  break;
   case 12:remove("dept12.dat");
	  rename("temp.dat","dept12.dat");
	  break;
   case 13:remove("dept13.dat");
	  rename("temp.dat","dept13.dat");
	  break;
   case 14:remove("dept14.dat");
	  rename("temp.dat","dept14.dat");
	  break;
   case 15:remove("dept15.dat");
	  rename("temp.dat","dept15.dat");
	  break;
   case 16:remove("dept16.dat");
	  rename("temp.dat","dept16.dat");
	  break;
  };
 }
  fin.close();
};


