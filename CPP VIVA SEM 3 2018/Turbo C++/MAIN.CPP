#include<stdlib.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>

//######################################### GAME CODDING #####################################
//#########################################              #####################################

/*
	Author : Vaitul Bhayani
	From Hns College.
*/

void preStart();

int l=4,i,score=0,life=3,tarX,tarY,closeFlag=1;
struct snkpos
{
	int x;
	int y;
};
struct snkpos snkpos[1500];
void startGame();
void ptsnk()
{
	for(i=l-1;i>=0;i--)
	{
		gotoxy(snkpos[i].x,snkpos[i].y);
		if(i==0)
		  printf("%c",2);
		else
		  printf("%c",4);
	}
}
void interchange()
{
	gotoxy(snkpos[l-1].x,snkpos[l-1].y);
	printf(" ");
	for(i=l-1;i>0;i--)
	{
		snkpos[i] = snkpos[i-1];
	}
	gotoxy(snkpos[0].x,snkpos[0].y);
}
void ptFrame()
{
    int x=2, y=2, w=75, h=22;
    gotoxy(1,1);
    printf("  %c The Snake Game \t\t\t\t  %c Score : %.3d   %c Life : %d",5,2,score,3,life);
    gotoxy(x+0,y+0);
    printf("%c",218);//top left corner
    for(i=1;i<=h;i++)
    {
	gotoxy(x+0,y+i);
	printf("%c",179);// |
    }
    gotoxy(x+0,y+1+h);
    printf("%c",192);//bottom left corner
    gotoxy(x+1,y+0);

    for(i=1;i<=1+w;i++)
	printf("%c",196);// -

    printf("%c",191);//top right corner

    for(i=1;i<=h;i++)
    {
	gotoxy(x+2+w,y+i);
	printf("%c",179);// |
    }

    gotoxy(x+1,y+1+h);
    for(i=1;i<=1+w;i++)
	printf("%c",196);// -
    printf("%c",217);//bottom right corner
}
void animatedWord(int x,int y,char  tmp[],int F,int speed)
{
    gotoxy(x,y);
    for(i=0;tmp[i]!='\0';i++)
    {
	delay(speed);
	if(F)
	    printf("%c", tmp[i]);
	else
	    printf(" ");
    }
}
void welcomeGame()
{
	closeFlag=1;
	char arr[20];
	for(i=0;i<=23;i++)
	  arr[i]=176;
	arr[23]='\0';
	animatedWord(29,10," Vaitul Bhayani Presents ",1,20);
	animatedWord(34,12,"The Snake Game",1,20);delay(500);
	gotoxy(37,18);printf("Loading..");
	animatedWord(29,20,arr,1,100);delay(1000);

	gotoxy(29,10);printf("                        ");
	gotoxy(29,12);printf("                        ");
	gotoxy(28,18);printf("                         ");
	gotoxy(28,20);printf("                         ");
	clrscr();
	ptFrame();
	animatedWord(28,12,"Game Starts In 3 Seconds ",1,20);delay(800);
	animatedWord(28,12,"Game Starts In 2 Seconds ",1,20);delay(800);
	animatedWord(28,12,"Game Starts In 1 Seconds ",1,20);delay(800);
	animatedWord(28,12,"Game Starts In 0 Seconds ",1,20);delay(100);
	gotoxy(28,12);printf("                           ");delay(0);
	startGame();
}
void generate()
{
	srand(time(0));
	tarX=rand()%75+3;
	tarY=rand()%22+3;
}
int flag=0;
void check()
{
	if(life!=-1)
	{
		if(tarX==snkpos[0].x&&tarY==snkpos[0].y)
		{
			l++;
			score = score + 5;
			ptFrame();
			generate();
		}
		if( snkpos[0].y<=2 || snkpos[0].y>=25 || snkpos[0].x<=2 || snkpos[0].x>=79)
		{
			flag=1;
		}
		else
		{
		      for(i=l-1;i>0;i--)
			{
				if(snkpos[i].x==snkpos[0].x && snkpos[i].y==snkpos[0].y)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==1)
		{
			flag=0;
			life--;
			l = 4;
			gotoxy(38,12);
			printf("OOPS !!!");
			delay(1500);
			clrscr();
			startGame();
		}
	}
	else
	{
		life=0;
		clrscr();
		ptFrame();
		animatedWord(30,12,"Game Over, Score : ",1,100);printf("%d",score);
		getch();
		closeFlag=0;
	}
}
void startGame()
{
	int ch;
	char dir='r';
	ptFrame();
	generate();
	for(i=l-1;i>=0;i--)
	{
		snkpos[i].x=10-i;
		snkpos[i].y=10;
	}
	ptsnk();
	while(closeFlag)
	{

		gotoxy(tarX,tarY);
		printf("%c",3);
		if(kbhit())
		{
			ch = getch();
			if(!((dir=='u'&&ch==80) || (dir=='d'&&ch==72) || (dir=='l'&&ch==77) || (dir=='r'&&ch==75)))
			switch(ch)
			{
				case 72: //up
				  interchange();
				  snkpos[0].y--;
				  dir = 'u';
				  break;
				case 80: //down
				  interchange();
				  snkpos[0].y++;
				  dir = 'd';
				  break;
				case 75: //left
				  interchange();
				  snkpos[0].x--;
				  dir = 'l';
				  break;
				case 77: //right
				  interchange();
				  snkpos[0].x++;
				  dir = 'r';
				  break;
				case 27:
				  clrscr();
				  closeFlag=0;
				  break;
				case 32:
				  gotoxy(38,12);
				  printf("PAUSED");
				  getch();
				  gotoxy(38,12);
				  printf("      ");
			}
		}
		else
		{
			switch(dir)
			{
				case 'u': //up
				  interchange();
				  snkpos[0].y--;
				  break;
				case 'd': //down
				  interchange();
				  snkpos[0].y++;
				  break;
				case 'l': //left
				  interchange();
				  snkpos[0].x--;
				  break;
				case 'r': //right
				  interchange();
				  snkpos[0].x++;
				  break;
			}
			if(dir=='u' || dir=='d')
				delay(180);
			else
				delay(150);
		}
		ptsnk();
		check();
	}
	preStart();
}


//##########################################################################################
//##########################################################################################


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      CLASSES       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int ID = 0;
class personalInfo
{
public:
    char name[30];
    char gender[7];
    char dob[15];
    char address[50];
    char contact[15];
};
class careerInfo:public personalInfo
{
public:
  char collegeName[30];
  char passedStream[20];
  char interestedStream[20];
};

class studentFormData:public careerInfo
{
public:
    int id;
    char date[15];

    void setData(char  Idate[],//property of studentFormData Class
		 char  Iname[],char  Igender[],char  Idob[],char  Iaddress[],char  Icontact[],//properties of personalInfo class
		 char  IcollegeName[],char  IpassedStream[],char  IinterestedStream[])//properties of careerInfo class
    {
	id = ++ID;
	strcpy(date,Idate);

	strcpy(	name , Iname);
	strcpy(	gender , Igender);
	strcpy(	dob , Idob);
	strcpy(	address , Iaddress);
	strcpy(	contact , Icontact);

	strcpy(	collegeName , IcollegeName);
	strcpy(	passedStream , IpassedStream);
	strcpy(	interestedStream , IinterestedStream);

	ofstream fout;
	fout.open("vb_forms.db",ios::app|ios::binary);
	fout.write((char*)this,sizeof(*this));
	fout.close();

    }
void putData(int i)
    {
	ifstream fin;
	fin.open("vb_forms.db",ios::in|ios::binary);
	if(fin)
	{
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
			if(id==i)
				break;
			fin.read((char*)this,sizeof(*this));
		}
	}
	fin.close();

    }

    void deleteForm(int formId)
    {
	if(formId>ID)
	{
		clrscr();
		cout<<"dev error : Id Not Found";
		getch();
		return;
	}
	if(!(formId==-1||formId==1&&ID==1))
	{
		ifstream fin;
		ofstream tmp;
		fin.open("vb_forms.db",ios::in|ios::binary);
		tmp.open("vb_temp.dat",ios::app|ios::binary);
		fin.read((char*)this,sizeof(*this));
		int tid=1;
		while(!fin.eof())
		{
			if(this->id!=formId)
			{
				this->id = tid;
				tmp.write((char*)this,sizeof(*this));
				tid++;
			}
			fin.read((char*)this,sizeof(*this));
		}
		fin.close();
		tmp.close();
		remove("vb_forms.db");
		rename("vb_temp.dat","vb_forms.db");
	}
	else
		remove("vb_forms.db");
	frame();
	animatedWord(25,13,"Form Deleted Successfuly.");
	delay(1500);
}
};


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     FUNTIONS      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


char  name[100];
int selection=1,re=8,WFLAG=0;

void Box();//print the border around th text.
void removeBox();//remove the border around th text.
void frame();//print the border around whole window and top panel.
void menu();//menu declaration & and there conding.
void welcome();//print the first text when we programm start.
void newForm();//make new admission form.
void showForm();//show form.
void help();//programm help section
void start(int);//starting function of all another functions
void animatedWord(int x,int y,char[] ,int=1);//print aimated string.


void Box(int x=0,int y=0,int w=0,int h=1)
{
    gotoxy(x+0,y+0);
    cout << char (218);//top left corner
    for(int i=1;i<=h;i++)
    {
	gotoxy(x+0,y+i);
	cout << char (179);// |
    }
    gotoxy(x+0,y+1+h);
    cout << char (192);//bottom left corner
    gotoxy(x+1,y+0);

    for(i=1;i<=1+w;i++)
	cout << char (196);// -

    cout << char (191);//top right corner

    for(i=1;i<=h;i++)
    {
	gotoxy(x+2+w,y+i);
	cout << char (179);// |
    }

    gotoxy(x+1,y+1+h);
    for(i=1;i<=1+w;i++)
	cout << char (196);// -
    cout << char (217);//bottom right corner
}

void removeBox(int x=0,int y=0,int w=0,int h=1)
{
    gotoxy(x+0,y+0);
    cout << " ";//top left corner
    for(int i=1;i<=h;i++)
    {
	gotoxy(x+0,y+i);
	cout << " ";// |
    }
    gotoxy(x+0,y+1+h);
    cout << " ";//bottom left corner
    gotoxy(x+1,y+0);

    for(i=1;i<=1+w;i++)
	cout << " ";// -

    cout << " ";//top right corner

    for(i=1;i<=h;i++)
    {
	gotoxy(x+2+w,y+i);
	cout << " ";// |
    }

    gotoxy(x+1,y+1+h);
    for(i=1;i<=1+w;i++)
	cout << " ";// -
    cout << " ";//bottom right corner
}

void frame()
{
    clrscr();
    Box(1,1,74,1);
    Box(1,1,74,23);
    gotoxy(2,2);
    cout<< " User : ";
    cout << (name);
    gotoxy(54,2);

    ifstream fin;
    fin.open("vb_forms.db",ios::in|ios::binary);
    if(fin)
    {
	char tmp[204];
	ID=0;
	fin.read(tmp,sizeof(studentFormData));
	while(!fin.eof()){
		fin.read(tmp,sizeof(studentFormData));
		ID++;
	}
	fin.close();
    }
    else
	ID=0;

    cout << "Completed Form(s) : ";cout << ID;cout;
}

void menu(int selection=0,int flag=0)
{
    if(!flag)
    {

	switch(selection)
	{
	    case 0:break;
	    case 1:Box(30,8,13,1);break;
	    case 2:Box(30,10,13,1);break;
	    case 3:Box(30,12,13,1);break;
	    case 4:Box(30,14,13,1);break;
	    case 5:Box(30,16,13,1);break;
	}
	gotoxy(32,9);
	cout << "NEW FORM";
	gotoxy(32,11);
	cout << "SHOW FORM";
	gotoxy(32,13);
	cout << "HELP & ABOUT";
	gotoxy(32,15);
	cout << "Feel Tired ?";
	gotoxy(32,17);
	cout << "EXIT";
	gotoxy(37,26);
    }
    else
    {
	switch(selection)
	{
	    case 0:break;
	    case 1:newForm();break;
	    case 2:showForm();break;
	    case 3:help();break;
	    case 4:clrscr();gotoxy(35,12);welcomeGame();break;
	    case 5:clrscr();gotoxy(35,12);cout<<"THANK YOU.\n\t\t\t\t      ";delay(2000);exit(1);break;
	}
	start(1);
    }
}

void welcome()
{
 ifstream fin;
 fin.open("vb_user.db");
 if(!fin)
 {
    Box(1,1,74,23);
    gotoxy(0,0);
    Box(2,2,72);
    char  f[] = "Student Admission Form System by Vaitul Bhayani.";
    char  s[] = "- You can Create,Edit & See the Admssion Form(s).";
    char  t[] = "- Up/Down key for selection & press Enter.";
    char  fo[] = "- Goto Menu->Help section for a Trouble while Using this programm.";

    animatedWord(16,3,f);
    animatedWord(5,6,s);
    animatedWord(5,8,t);
    animatedWord(5,10,fo);

    char  rights[] = "MADE BY VAITUL BHAYANI. ALL RIGHTS RESERVED 2018.";
    animatedWord(13,15,rights);

    Box(30,19,10);
    gotoxy(31,20);
    char  btn[] = "Get Started";
    cout << (btn);
    gotoxy(0,21);
    getch();
    gotoxy(43,20);

    //Getting name from user.
    cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\bEnter Name Only";Box(28,19,15);
    gotoxy(44,20);delay(1500);gotoxy(29,20);cout << "                ";
    gotoxy(29,20);
    fflush(stdin);
    cin>>(name);
    strcpy(name,strupr(name));

    ofstream fout;
    fout.open("vb_user.db");
    fout.write(name,sizeof(name));
    fout.close();
 }
 else
 {
	fin.read(name,sizeof(name));
	fin.close();
 }
}

studentFormData addmisionForm;

void newForm()
{
	frame();
	char  f[]="Please fill up all fields.";animatedWord(26,13,f);delay(1000);animatedWord(26,13,f,0);
	gotoxy(1,3);

	date d1;
	getdate(&d1);
	char fdate[100];
	sprintf(fdate," DATE(dd/mm/yyyy) : %d/%d/%d",d1.da_day,d1.da_mon,d1.da_year);

	char data[10][100];
	strcpy(data[0] ,fdate);
	strcpy(data[1] , "     Student Name : ");
	strcpy(data[2] , "           Gender : ");
	strcpy(data[3] , "  DOB(dd/mm/yyyy) : ");
	strcpy(data[4] , "          Address : ");
	strcpy(data[5] , "          Contact : ");
	strcpy(data[6] , "     College Name : ");
	strcpy(data[7] , "    Passed Stream : ");
	strcpy(data[8] , "Interested Stream : ");

	for(int i=0,j=5;i<=8;i++,j+=2)
	{
	    animatedWord(3,j,data[i]);
	}

	gotoxy(35,23);
	cout<<"SUBMIT.";

	for(i=2,j=1;i<=16,j<=8;i+=2,j++)
	{
	    Box(22,4+i,50);
	    gotoxy(23,4+1+i);
	    fflush(stdin);
	    gets(data[j]);
	    removeBox(22,4+i,50);
	    strupr(data[j]);
	}

	int flag=1;
	for(i=1;i<=8;i++)
	{
	    if(!data[i][0])
	    {
		flag = 0;
		break;
	    }

	}
	Box(33,22,8);
	if(!flag)
	{
		gotoxy(35,23);
		cout<<"ERROR.";
		getch();
		frame();
		char  f[] ="Your Form not submited.";animatedWord(26,13,f);delay(2300);animatedWord(26,13,f,0);
		return;
	}
	getch();
	sprintf(data[0],"%d/%d/%d",d1.da_day,d1.da_mon,d1.da_year);
	addmisionForm.setData(data[0],
				 data[1],data[2],data[3],data[4],data[5],
				 data[6],data[7],data[8]);
	frame();
	gotoxy(19,13);cout << "ID "<<ID<<":";
	char  f1[]=" Your Form successfully submited.          ";animatedWord(25,13,f1);delay(2000);animatedWord(19,13,f1,0);

}
int flag_showform = 1;
void showForm()
{
    ifstream fin;
    fin.open("vb_forms.db");
    if(!fin)
    {
	frame();
	char  f[] ="Sorry ,Form not Found !!";animatedWord(27,13,f);delay(1500);animatedWord(27,13,f,0);
	return;
    }
    if(flag_showform)
    {
	frame();
	gotoxy(8,8);
	cout<<char(17)<<" NOTE "<<char(16);
	gotoxy(13,10);
	cout<<char(26)<<" Up / Down Keys to navigate";
	gotoxy(13,12);
	cout<<char(26)<<" Delete key to delete that selected form";
	gotoxy(13,14);
	cout<<char(26)<<" Ctrl + delete key to delete all the saved forms";
	gotoxy(13,16);
	cout<<char(26)<<" TAB key to search form by id";
	gotoxy(13,18);
	cout<<char(26)<<" Esc key to exit";
	getch();
	flag_showform = 0;
    }

    studentFormData form;
    int sel=0;

    if(ID<1)
    {
	frame();
	char  f[] ="Sorry ,Form not Found !!";animatedWord(27,13,f);delay(1500);animatedWord(27,13,f,0);
	return;
    }
    else if(ID<2)
    {
	frame();
	char  f[]="    One Form Found.";animatedWord(27,13,f);delay(1500);animatedWord(27,13,f,0);
	sel = 1;
    }
    else
    {
	frame();
	int i=1,x=5,y=6,step=10,flag = 1,c;
	sel = 5;

	gotoxy(5,4);cout << "ID           Name          ";
	RESTART:
	for(i;i<=step;i++)
	{
	    if(i<=ID)
	    {
		gotoxy(x,y);
		form.putData(i);
		printf("%.3d     ",form.id);
		if(i == step || sel < 10)
		    animatedWord(x+8,y,strcat(form.name,"                  "));
		else
		    cout << form.name;
		y+=2;
	    }
	}
	i--;
	if((i-step) == 0)
	{
	    while(1)
	    {
		if(flag)
		{
		   Box(x-2,sel,68);
		   c = getch();
		   if(c == 224 || c==0)
		    c = getch();
		   if(c == 80)
		   {
		       if(sel<7){char f[] = "                                        ";gotoxy(36,3);cout << f;}
		       removeBox(x-2,sel,68);
		       if((sel-3)/2<ID)
		       sel += 2;
		       Box(x-2,sel,68);
		   }
		   if(c == 72)
		   {
		       if(sel<7){char f[] = "                                        ";gotoxy(36,3);cout << f;}
		       removeBox(x-2,sel,68);
		       if((sel-3)/2<ID)
		       sel += 2;
		       Box(x-2,sel,68);
		   }
		   gotoxy(36,3);for(int k=1;k<=40;k++){cout<<char(196);}
		}
	       if((sel-3)/2 == step)
	       {
		   flag = 0;
		    c = getch();
		   if(c == 224)
		   c = getch();
		   if(c == 80)
		   {
			sel+=2;
			x=5;y=6;
			gotoxy(x,y);
			step++;
			i = step - 10;
			i++;
			if((sel-3)/2 <= ID)
			goto RESTART;

		   }
	       }
	       if(c == 83)
	       {
		form.deleteForm((sel-3)/2);
		return;
	       }
	       if(c == 147)
	       {
		form.deleteForm(-1);
		return;
	       }
	       if(c == 27)
		return;
	       if(c == 13)
	       {
		sel = (sel-3)/2;
		if(sel>=ID)
		    sel = ID;
		   break;
	       }
	       if(c == 9)
	       {
		   frame();
		   char f[] = "Enter ID Number : ";
		   animatedWord(19,13,f);
		   Box(37,12,4);
		   char s[] = " And press enter.";
		   animatedWord(44,13,s);
		   gotoxy(39,13);
		   int q;
		   cin >> q;
		   if(q>ID)
		   {
		       frame();
		       char t[] = "Entered ID has not found !";
		       animatedWord(25,13,t);
		       delay(2000);
		       animatedWord(25,13,f,0);
		       showForm();
		       return;
		   }
		   sel = q;
		   break;
	       }
	    }
	}
    }
    frame();
    gotoxy(36,4);
    printf("ID:%.3d",sel);

    form.putData(sel);
    int x = 23;
    for(int i=16;i>=0;i-=2)
    {
	Box(x+1,i+5,46,1);
	Box(x-18,i+5,17,1);
    }
    int y = 6;
    gotoxy(6,y);cout<<"             Date";
    gotoxy(6,y+2);cout<<"             Name";
    gotoxy(6,y+4);cout<<"           Gender";
    gotoxy(6,y+6);cout<<"              DOB";
    gotoxy(6,y+8);cout<<"          Address";
    gotoxy(6,y+10);cout<<"          Contact";
    gotoxy(6,y+12);cout<<"     College Name";
    gotoxy(6,y+14);cout<<"    Passed Stream";
    gotoxy(6,y+16);cout<<"Interested Stream";

    x=26;
    y=6;
    gotoxy(x,y);cout<<form.date;
    gotoxy(x,y+2);cout<<form.name;
    gotoxy(x,y+4);cout<<form.gender;
    gotoxy(x,y+6);cout<<form.dob;
    gotoxy(x,y+8);cout<<form.address;
    gotoxy(x,y+10);cout<<form.contact;
    gotoxy(x,y+12);cout<<form.collegeName;
    gotoxy(x,y+14);cout<<form.passedStream;
    gotoxy(x,y+16);cout<<form.interestedStream;
    gotoxy(x+12,y+20);
    int c = getch();
    if(c==0 && getch()== 83)
	form.deleteForm(sel);
    if(ID<2)
	return;
    showForm();
}
void animatedWord(int x,int y,char  tmp[],int F)
{
    gotoxy(x,y);
    for(int i=0;tmp[i]!='\0';i++)
    {
	delay(7);
	if(F)
	    cout << tmp[i];
	else
	    cout << " ";
    }
}
void help()
{
    frame();

    cout << "\n\n\n|   Help:";
    char  f[] = " - Press Up/Down key for move the cursor.";
    char  s[] = " - Enter key for select option.";
    char  t[] = " - BackSpace key for Calcel the operation & goto the main menu.";

    animatedWord(6,7,f);
    animatedWord(6,9,s);
    animatedWord(6,11,t);


    cout << "\n\n\n\n|  About:";
    char  f1[] = " - A VIVA model project SEM-3 2018.";
    char  s1[] = " - A programm developed by Vaitul Bhayani from BCA HNS College.";
    char  t1[] = " - For any query contact : 9904021519/vaitulb@gmail.com.";

    animatedWord(6,17,f1);
    animatedWord(6,19,s1);
    animatedWord(6,21,t1);

    getch();
}

void start(int f)
{
    WFLAG = f;
    if(WFLAG!=0){frame(); char  c[] ="MADE BY VAITUL BHAYANI. ALL RIGHTS RESERVED 2018.";animatedWord(15,22,c);}
    while(WFLAG)
    {
	menu(selection);
	if(getch() == 13){menu(selection,1);}
	else
	{
	    removeBox(30,re,13,1);
	    switch(getch())
	    {
	    case 72:
		selection--;
		re -= 2;
		break;
	    case 80:
		selection++;
		re += 2;
		break;
	    }
	    if(selection>5){selection--; re -= 2;}
	    if(selection<1){selection++; re += 2;}
	}
    }
}
void preStart()
{
	while(1)
    {
		fflush(stdin);
		start(1);
    }
}
void main()
{
    clrscr();
    welcome();
    preStart();
}
