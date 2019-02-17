#include<iostream>
#include<conio.h>
#include<windows.h>
#include<algorithm> //transform function for convert upper case
#include<stdio.h>
#include<string>
using namespace std;

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      CLASSES       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

int ID = 0;
class personalInfo
{
public:
    string name;
    string gender;
    string dob;
    string address;
    string contact;
};
class careerInfo:public personalInfo
{
public:
  string collegeName;
  string passedStream;
  string interestedStream;
};

class studentFormData:public careerInfo
{
public:
    int id;
    string date;

    void setData(string  Idate,//property of studentFormData Class
                 string  Iname,string  Igender,string  Idob,string  Iaddress,string  Icontact,//properties of personalInfo class
                 string  IcollegeName,string  IpassedStream,string  IinterestedStream)//properties of careerInfo class
    {
        id = ++ID;
        date = Idate;

        name = Iname;
        gender = Igender;
        dob = Idob;
        address = Iaddress;
        contact = Icontact;

        collegeName = IcollegeName;
        passedStream = IpassedStream;
        interestedStream = IinterestedStream;
    }
    studentFormData showData()
    {
        studentFormData temp;

        temp.id = id;
        temp.date =date;

        temp.name = name;
        temp.gender = gender;
        temp.dob = dob;
        temp.address = address;
        temp.contact = contact;

        temp.collegeName = collegeName;
        temp.passedStream = passedStream;
        temp.interestedStream = interestedStream;

        return temp;

    }
};


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     FUNTIONS      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
string  name;
int selection=1,re=9,WFLAG=0;

void Box();//print the border around th text.
void removeBox();//remove the border around th text.
void frame();//print the border around whole window and top panel.
void menu();//menu declaration & and there conding.
void welcome();//print the first text when we programm start.
void newForm();//make new admission form.
void showForm();//show form.
void help();//programm help section
void start(int);//starting function of all another functions
void animatedWord(int x,int y,string ,int=1);//print aimated string.


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

    for(int i=1;i<=1+w;i++)
        cout << char (196);// -

    cout << char (191);//top right corner

    for(int i=1;i<=h;i++)
    {
        gotoxy(x+2+w,y+i);
        cout << char (179);// |
    }

    gotoxy(x+1,y+1+h);
    for(int i=1;i<=1+w;i++)
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

    for(int i=1;i<=1+w;i++)
        cout << " ";// -

    cout << " ";//top right corner

    for(int i=1;i<=h;i++)
    {
        gotoxy(x+2+w,y+i);
        cout << " ";// |
    }

    gotoxy(x+1,y+1+h);
    for(int i=1;i<=1+w;i++)
        cout << " ";// -
    cout << " ";//bottom right corner
}

void frame()
{
    system("cls");
    Box(0,0,74,1);
    Box(0,0,74,25);
    gotoxy(1,1);
    cout<< " User : ";
    cout << (name);
    gotoxy(49,1);
    cout << "Completed Form : ";cout << ID;cout << " of 100.";
}

void menu(int selection=0,int flag=0)
{
    if(!flag)
    {

        switch(selection)
        {
            case 0:break;
            case 1:Box(30,9,13,1);break;
            case 2:Box(30,11,13,1);break;
            case 3:Box(30,13,13,1);break;
            case 4:Box(30,15,13,1);break;
        }
        gotoxy(32,10);
        cout << "NEW FORM";
        gotoxy(32,12);
        cout << "SHOW FORM";
        gotoxy(32,14);
        cout << "HELP & ABOUT";
        gotoxy(32,16);
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
            case 4:system("cls");gotoxy(33,13);cout<<"THANK YOU.\n\n\n\n\n\n\n\n\n\n\n\n";Sleep(2000);exit(0);break;
        }
        start(0);
    }
}

void welcome()
{
    Box(0,0,74,26);
    gotoxy(0,0);
    Box(2,2,70);
    string  f = "Student Admission Form System by Vaitul Bhayani.";
    string  s = "- You can Create,Edit & See the Admssion Form(s).";
    string  t = "- Up/Down key for selection & press Enter.";
    string  fo = "- Goto Menu->Help section for a Trouble while Using this programm.";

    animatedWord(15,3,f);
    animatedWord(2,6,s);
    animatedWord(2,8,t);
    animatedWord(2,10,fo);

    string  rights = "MADE BY VAITUL BHAYANI. ALL RIGHTS RESERVED 2018.";
    animatedWord(13,15,rights);

    Box(30,19,10);
    gotoxy(31,20);
    string  btn = "Get Started|";
    cout << (btn);
    gotoxy(0,21);
    getch();
    gotoxy(43,20);

    //Getting name frome user.
    cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\bEnter Name Only";Box(28,19,15);
    gotoxy(44,20);Sleep(1500);gotoxy(29,20);cout << "                ";
    gotoxy(29,20);
    fflush(stdin);
    cin>>(name);
    transform(name.begin(), name.end(), name.begin(), ::toupper);
}

studentFormData addmisionForm[100];

void newForm()
{
        frame();
        string  f="Please fill up all fields.";animatedWord(26,13,f);Sleep(1000);animatedWord(26,13,f,0);
        gotoxy(1,3);

        string data[10];
        data[0] = " DATE(dd/mm/yyyy) : ";
        data[1] = "     Student Name : ";
        data[2] = "           Gender : ";
        data[3] = "  DOB(dd/mm/yyyy) : ";
        data[4] = "          Address : ";
        data[5] = "          Contact : ";
        data[6] = "     College Name : ";
        data[7] = "    Passed Stream : ";
        data[8] = "Interested Stream : ";

        for(int i=0,j=5;i<=8;i++,j+=2)
        {
            animatedWord(3,j,data[i]);
        }

        gotoxy(35,24);
        cout<<"SUBMIT.";

        for(int i=0,j=0;i<=16,j<=8;i+=2,j++)
        {
            Box(22,4+i,50);
            gotoxy(23,4+1+i);
            fflush(stdin);
            getline(cin,data[j]);
            removeBox(22,4+i,50);
            transform(data[j].begin(), data[j].end(), data[j].begin(), ::toupper);
        }

        int flag=1;
        for(int i=0;i<=8;i++)
        {
            if(!data[i][0])
            {
                flag = 0;
                break;
            }

        }
        Box(33,23,8);
        if(!flag)
        {
                gotoxy(35,24);
                cout<<"ERROR.";
                getch();
                frame();
                string  f="Your Form not submited.";animatedWord(26,13,f);Sleep(3000);animatedWord(26,13,f,0);
                return;
        }
        getch();
        addmisionForm[ID].setData(data[0],
                                 data[1],data[2],data[3],data[4],data[5],
                                 data[6],data[7],data[8]);
        frame();
        gotoxy(19,13);cout << "ID "<<ID<<":";
        string  f1=" Your Form successfully submited.          ";animatedWord(25,13,f1);Sleep(2000);animatedWord(19,13,f1,0);

        /*system("cls");
        for(int i=0;i<=8;i++)
            cout << "\n" << data[i];
        getch();*/
}

void showForm()
{
    studentFormData form;
    int sel=0;

    if(ID<1)
    {
        frame();
        string  f="Sorry ,Form not Found !!";animatedWord(27,13,f);Sleep(1500);animatedWord(27,13,f,0);
        return;
    }
    else if(ID<2)
    {
        frame();
        string  f="    One Form Found.";animatedWord(27,13,f);Sleep(1500);animatedWord(27,13,f,0);
        sel = 1;
    }
    else
    {
        frame();
        int i=1,x=5,y=6,step=10,flag = 1,c;
        sel = 5;

        string f = "Note : Escape to Exit. / TAB to search.";
        animatedWord(36,3,f);

        gotoxy(5,4);cout << "ID           Name          ";
        RESTART:
        for(i;i<=step;i++)
        {
            if(i<=ID)
            {
                gotoxy(x,y);
                form = addmisionForm[i-1].showData();
                printf("%.3d     ",form.id);
                if(i == step || sel < 10)
                    animatedWord(x+8,y,form.name);
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
                   if(c == 224)
                    c = getch();
                   if(c == 80)
                   {
                       if(sel<7){string f = "                                        ";gotoxy(36,3);cout << f;}
                       removeBox(x-2,sel,68);
                       if((sel-3)/2<ID)
                       sel += 2;
                       Box(x-2,sel,68);
                   }
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
                   string f = "Enter ID Number : ";
                   animatedWord(17,13,f);
                   Box(35,12,4);
                   f = " And press enter.";
                   animatedWord(42,13,f);
                   gotoxy(37,13);
                   int q;
                   cin >> q;
                   if(q>ID)
                   {
                       frame();
                       f = "Entered ID has not found !";
                       animatedWord(25,13,f);
                       Sleep(2000);
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

    form = addmisionForm[sel-1].showData();
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
    getch();
    if(ID<2)
        return;
    showForm();
}

void animatedWord(int x,int y,string  tmp,int F)
{
    gotoxy(x,y);
    for(int i=0;tmp[i]!='\0';i++)
    {
        Sleep(1);
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
    string  f = " - Press Up/Down key for move the cursor.";
    string  s = " - Enter key for select option.";
    string  t = " - BackSpace key for Calcel the operation & goto the main menu.";

    animatedWord(6,9,f);
    animatedWord(6,10,s);
    animatedWord(6,11,t);


    cout << "\n\n\n|  About:";
    string  f1 = " - A VIVA model project SEM-3 2018.";
    string  s1 = " - A programm developed by Vaitul Bhayani from BCA HNS College.";
    string  t1 = " - For any query contact : 9904021519/vaitulb@gmail.com.";

    animatedWord(6,16,f1);
    animatedWord(6,17,s1);
    animatedWord(6,18,t1);

    getch();
}

void start(int f)
{
    WFLAG = f;
    if(WFLAG!=0){frame(); string  c="MADE BY VAITUL BHAYANI. ALL RIGHTS RESERVED 2018.";animatedWord(15,24,c);}
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
            if(selection>4){selection--; re -= 2;}
            if(selection<1){selection++; re += 2;}
        }
    }
}
