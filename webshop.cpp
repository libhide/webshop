/*
	Project: WebShop (codenamed Thingy)

	Lines of code: 1950+
	Switch statements used: 53
	For loops used: 35
	While loops used: 32
	If else clauses used: 49

*/

#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <string.h>
#include <stdio.h>
#include <process.h>
#include <dos.h>
#include <graphics.h>

int html_invoked=0, css_invoked=0;
int k=0;
int p=1,head=1, hyper=1,table=1,list=1;
char s_title[30], b[10000], ttl[50];

void css_nav(int type);
void html_nav();
void bg_css(int n);
void bg_html();

struct page
{
	char t[20];
	page *next;

}*front, *rear, *ptr, *del;

void create(char title[])
{
	ptr = new page;
	strcpy(ptr->t,title);
	ptr->next = NULL;
	if(front==NULL)
	{
		rear=ptr;
		front=ptr;
	}
	else
	{
		rear->next = ptr;
		rear = ptr;
	}
}


void fout(char txt[])
{
	int l=strlen(txt);
	for(int i=0;i<l;i++)
	{
		cout<<txt[i];
		delay(55);
	}
}


void intro()
{
	cout<<"WebShop v1.0";
	cout<<endl<<endl;
	fout("This is a tool that can be used to build beautiful websites within minutes. It can be used by amateurs, novices and even pros. Just follow the on screen instructions 'properly' and you'll have a running website in no time!");
	cout<<"\n\n\nBefore you proceed, please take a minute to collect all custom resouces(images,fonts etc.) which you plan to use on your website in a folder and place it wherever the .exe for this tool is present.";
	cout<<"\n\nOnce done, press ENTER to start building the site. ";
	getch();
}

void pages_intro()
{
	cout<<"Let's start with the creation of the first page of the website. Please enter it's name below";
}

class engine
{
	int i;
	public:
	void menu_code();
	void decision(int x);
	void head_menu();
	void elements_menu();
	int elements();
};

class html
{
	char title[50], bgcolor[15], img[100], a, txt[50], tag[50], name[40],nav_name[20],nav_link[20], frame_name[20],frame[30],nav[400];
	int z, n,height,width,t, col, row, cols,br,align,count,border;
	void html_code();
	void html_base(int k);
	public:
	void title_cpy()
	{
		strcpy(ttl,title);
	}
	int j;
	void html_buffer()
	{
		html_code();
		html_invoked++;
	}
};

class css
{
	int height,width,left,right,top,bottom;
	char color[10];
	void css_code(int x);
	public:
	void css_buffer(int y)
	{
		css_code(y);
		css_invoked++;
	}
};

//Objects

engine e;
html h;
css c;

int main()
{
	clrscr();
	intro();
	textcolor(WHITE);
	h.html_buffer();
	front=NULL;
	rear=NULL;
	cout << "Your website has been created!"<<endl;
	cout << endl << "Session Summary:"<<endl;
	cout << endl << "HTML code was written " <<k<< " time(s)."<< endl;
	cout << "CSS code was written " <<css_invoked<< " time(s)."<< endl;
	getch();
	return 0;
}

void bg_html()
{
	if(k==1)
	{
		int ch;
		cout<<endl<<"Here we create the page background for all pages of your website."<<endl<<endl;
		cout<<"What type of page ground do you want to use for your web pages? ";
		cout<<"\n\n1. Solid Color\n2. Image\n3. Gradients\n";
		cout<<"\n\nYour Choice: ";
		cin>>ch;
		bg_css(ch);
	}
}

void bg_css(int n)
{
	fstream bg;
	bg.open("Bg_css.txt",ios::out);
	clrscr();
	switch(n)
	{
		case 1:{int i;
			cout<<"Which color?"<<endl<<endl;
			cout<<"1. Red\n2. Blue\n3. Green\n4. Black\n5. White\n6. Grey\n7. Yellow\n8. Hex value(for web designers!)\n";
			cout<<endl<<"Choose: ";
			cin>>i;
			switch(i)
			{
				case 1:{bg<<"body{background:red;}"<<endl;
					break;}
				case 2:{bg<<"body{background:blue;}"<<endl;
					break;}
				case 3:{bg<<"body{background:green;}"<<endl;
					break;}
				case 4:{bg<<"body{background:black;}"<<endl;
					break;}
				case 5:{bg<<"body{background:white;}"<<endl;
					break;}
				case 6:{bg<<"body{background:grey;}"<<endl;
					break;}
				case 7:{bg<<"body{background:grey;}"<<endl;
					break;}
				case 8:{char hex[10];
					cout<<"\nYour hex: ";
					cin >> hex;
					bg<<"body{background:#"<<hex<<";}"<<endl;
					break;}
			}
			break;}
		case 2:{char bg_path[30];
			cout<<"Which image do you want to use for the background of your webpages? Please provide the correct directory of the image you placed in the folder before starting the building process. ";
			cin>>bg_path;
			bg<<"body{background-image: url("<<bg_path<<")}";
			break;}
		case 3:{int ch;
			char c1[10], c2[10];
			cout<<"We currently only support linear gradients that contain a maximum of 2 colors. Please enter the two colors: ";
			cout<<"\n\nName of first color or hex value (include the # sign if entering a hex value): ";
			cin>>c1;
			cout<<"\nName of second color or hex value (include the # sign if entering a hex value): ";
			cin>>c2;
			clrscr();
			cout<<"\n\nWhat alignment for gradient do you want? ";
			cout<<"\n1. Top to bottom\n2. Left to right\n3. Diagonal\n\nChoice: ";
			cin>>ch;
			switch(ch)
			{
				case 1:{bg<<"body{background: -webkit-linear-gradient("<<c1<<","<<c2<<");}";
					bg<<"\nbody{background: -o-linear-gradient("<<c1<<","<<c2<<");}";
					bg<<"\nbody{background: -moz-linear-gradient("<<c1<<","<<c2<<");}";
					bg<<"\nbody{background: linear-gradient("<<c1<<","<<c2<<");}";
					break;}
				case 2:{bg<<"body{background: -webkit-linear-gradient(left,"<<c1<<","<<c2<<");}";
					bg<<"\nbody{background: -o-linear-gradient(right,"<<c1<<","<<c2<<");}";
					bg<<"\nbody{background: -moz-linear-gradient(right,"<<c1<<","<<c2<<");}";
					bg<<"\nbody{background: linear-gradient(to right,"<<c1<<","<<c2<<");}";
					break;}
				case 3:{bg<<"body{background: -webkit-linear-gradient(left top,"<<c1<<","<<c2<<");}";
					bg<<"\nbody{background: -o-linear-gradient(bottom right,"<<c1<<","<<c2<<");}";
					bg<<"\nbody{background: -moz-linear-gradient(bottom right,"<<c1<<","<<c2<<");}";
					bg<<"\nbody{background: linear-gradient(to bottom right,"<<c1<<","<<c2<<");}";
					break;}
			}
			break;}
	}
}

void html_nav()
{
	if(k==1)
	{
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode," ");
	int c,i=1;
	char a, link[20],m_link[30],temp[20];
	h.title_cpy();
	cout<<endl<<endl<<endl;
	cout<<"At this stage, we create the navigation bar which is placed on all pages of your website.";
	cout<<"Websites usually need a navigation system to navigate between pages. Please choose from the following types of navigation bars we offer -\n\n";
	cout<<"1. Conventional Navbar\n"<<"This is a basic navigation bar shaped like a rectangle and will sit on top of each page you create. Color Scheme: Orange, Red, White\n\n";
	//Grpahics for Nav1
	setcolor(RED);
	cout<<endl;
	rectangle(0,175,360,205);
	line(15,190,45,190);
	line(80,190,110,190);
	line(150,190,180,190);
	line(220,190,250,190);
	line(290,190,320,190);
	cout<<"\n\n2. Tabbed Navbar\n"<<"This navigation bar contains tabs and beautiful indentation and will sit on top of each page you create. Color Scheme: Blue, Green, Creme\n\n";
	//Graphics for Nav2
	setcolor(BLUE);
	rectangle(0,300,75,330);
	rectangle(80,300,155,330);
	rectangle(160,300,230,330);
	rectangle(235,300,315,330);
	cout<<"\n\n\n\n3. Vertical navigation bar\n"<<"This is a vertical list that can be used to navigate between your pages. They also light up on hover. Color Scheme: Black, Grey, White\n\n";
	cout<<"\nYour choice: ";
	cin>>c;
	closegraph();
	fstream nav;
	nav.open("Nav_html.txt",ios::out);
	switch(c)
	{
		case 1:{char home[20];
			strcat(home,"PG_");
			strcat(home,ttl);
			strcat(home,".HTM");
			nav<<"<div id=\"Nav\">";
			nav<<"\n<ul id=\"n1\">";
			nav<<"\n<a id=\"a1\" href=\""<<home<<"\"><li id=\"l1\">"<<ttl<<"</li></a>";
			cout<<"Please provide names for your subsequent pages.\n";
			while(a!=27)
			{
				cout<<"\nPress ENTER to add another page or ESC to return to previous menu"<<endl<<endl;
				a=getch();
				if(a==13)
				{
					clrscr();
					cout<<"Please make sure the name of the page contains less than 6 characters. This is due to compiler restrictions.";
					cout<<"\n\nName of page "<<i+1<<": ";
					cin>>link;
					create(link);
					strcat(m_link,"PG_");
					strcat(m_link,link);
					strcat(m_link,".HTM");
					nav<<"\n<a id=\"a1\" href=\""<<m_link<<"\"><li id=\"l1\">"<<link<<"</li></a>";
					strcpy(link," ");
					strcpy(m_link," ");
					i++;
				}
				else if(a==27)
				{
					strcpy(link," ");
					break;
				}
			}
			nav<<"\n</ul>";
			nav<<"\n</div>";
			css_nav(1);
			break;}
		case 2:{nav<<"<div id=\"demo-container\">";
				nav<<"<ul id=\"simple-menu\">";
				nav<<"\n<a href=\"PG_"<<ttl<<".HTM\"><li id=\"current\">"<<ttl<<"</li></a>";
				cout<<"Please provide names for your subsequent pages.\n";
				while(a!=27)
				{
					cout<<"\nPress ENTER to add another page or ESC to return to previous menu"<<endl<<endl;
					a=getch();
					if(a==13)
					{
						clrscr();
						cout<<"Please make sure the name of the page contains less than 6 characters. This is due to compiler restrictions.";
						cout<<"\n\nName of page "<<i+1<<": ";
						cin>>link;
						create(link);
						strcat(m_link,"PG_");
						strcat(m_link,link);
						strcat(m_link,".HTM");
						nav<<"\n<a href=\""<<m_link<<"\"><li>"<<link<<"</li></a>";
						strcpy(link," ");
						strcpy(m_link," ");
						i++;
					}
					else if(a==27)
					{
						strcpy(link," ");
						break;
					}
				}
			nav<<"\n</ul>";
			nav<<"\n</div>";
			css_nav(2);
			break;}
		case 3:{nav<<"<div id=\"vertical-nav\">";
			nav<<"\n<ul id=\"n3\">";
			nav<<"\n<a id=\"a3\" href=\"PG_"<<ttl<<".HTM\"><li id=\"l3\">"<<ttl<<"</li></a>";
			cout<<"Please provide names for your subsequent pages.\n";
			while(a!=27)
			{
				cout<<"\nPress ENTER to add another page or ESC to return to previous menu"<<endl<<endl;
				a=getch();
				if(a==13)
				{
					clrscr();
					cout<<"Please make sure the name of the page contains less than 6 characters. This is due to compiler restrictions.";
					cout<<"\n\nName of page "<<i+1<<": ";
					cin>>link;
					create(link);
					strcat(m_link,"PG_");
					strcat(m_link,link);
					strcat(m_link,".HTM");
					nav<<"\n<a id=\"a3\" href=\""<<m_link<<"\"><li id=\"l3\">"<<link<<"</li></a>";
					strcpy(link," ");
					strcpy(m_link," ");
					i++;
				}
				else if(a==27)
				{
					strcpy(link," ");
					break;
				}
			}
			nav<<"\n</ul>";
			nav<<"\n</div>";
			css_nav(3);
			break;}
	}
	nav.close();
	}
}

void css_nav(int type)
{
		fstream nav;
		nav.open("Nav_css.txt",ios::out);
		switch(type)
		{
			case 1:{nav<<"\n@font-face {font-family: myFont; src: url(\"12/12_fonts/americanCaptain.ttf\");}";
				nav<<"\n#Nav{text-align: center;  position: fixed; top: 0px; left: 0px; width: 100%;}";
				nav<<"\n#n1{background: rgb(210,50,0); padding: 10px 0px 10px 0px;}";
				nav<<"\n#l1{display: inline; padding: 0px 40px 0px 35px;}";
				nav<<"\n#a1{color: white; text-decoration: none; font-size: 28px; font-family: myFont;}";
				nav<<"\n#a1:hover{color: rgba(255,255,255,0.5);}";
				nav<<"\n@media(max-width: 500px){l1{display: block; padding: 5px;}}";
				break;}
			case 2:{nav<<"#demo-container{padding:25px 15px 0 15px;background:#67A897;}"<<endl;
				nav<<"#simple-menu{list-style-type:none;width:100%;position:relative;height:27px;font-family:\"Trebuchet MS\",Arial,sans-serif;font-size:13px;font-weight:bold;margin:0;padding:11px 0 0 0;}"<<endl;
				nav<<"li{display:block;float:left;margin:0 0 0 4px;height:27px;}"<<endl;
				nav<<"li.left{margin:0;}"<<endl;
				nav<<"a{display:block;float:left;color:#fff;background:#4A6867;line-height:27px;text-decoration:none;padding:0 17px 0 18px;height:27px;}"<<endl;
				nav<<"a.right{padding-right:19px;}"<<endl;
				nav<<"a:hover{background:#2E4560;}"<<endl;
				nav<<"a.current{color:#2E4560;background:#fff;}"<<endl;
				nav<<"a.current:hover{color:#2E4560;background:#fff;}"<<endl;
				break;}
			case 3:{nav<<"@font-face{font-family: myFont; src: url('12/12_fonts/bebas.ttf');}";
				nav<<"\n#n3{list-style-type: none; margin-top: 40px;}";
				nav<<"\n#a3{font-size: 50px;font-family: myFont; text-decoration: none; color: rgba(192,192,192,0.7);}";
				nav<<"\n#a3:hover{color: rgba(255,255,255,0.9);}";
				break;}
		}
		nav.close();
}

void engine::decision(int x)
{
	switch(x)
	{
		case 1:{c.css_buffer(1);
			break;}
		case 2:{c.css_buffer(2);
			break;}
		case 3:{c.css_buffer(3);
			break;}
		case 4:{c.css_buffer(4);
			break;}
		case 5:{c.css_buffer(5);
			break;}
		case 6:{c.css_buffer(6);
			break;}
		case 7:{c.css_buffer(7);
			break;}
	}
}

void engine::head_menu()
{
	clrscr();
	cout<<"What size heading/sub-heading do you require?\n\n";
	cout<<"1. Heading 1\n2. Heading 2\n3. Heading 3\n4. Heading 4\n"<<"5. Heading 5\n"<<"6. Heading 6\n";
}

int engine::elements()
{
	cout<<"1. Text\n2. Add an image\n3. Add headings and sub headings\n4. Links to other pages or websites\n"<<"5. Tables\n"<<"6. Lists of things\n"<<"7. iFrames*\n"<<endl;
	cout<<"*iFrames let you put a certain website or another html page inside your current page for allowing the user to use them together"<<endl<<endl;
	cout<<"8. Create another page or EXIT\n";
	cout<<endl<<"Choice: ";
	cin>>i;
	switch(i)
	{
		case 1:{return 1;}
		case 2:{return 2;}
		case 3:{return 3;}
		case 4:{return 4;}
		case 5:{return 5;}
		case 6:{return 6;}
		case 7:{return 7;}
		case 8:{return 8;}
	}
}

void html::html_code()
{
	char a;
	while(a!=27)
	{
		if(k>=1)
		{
			if (front->next!=NULL)
			{
				del = front;
				front = front->next;
				delete del;
				cout<<"Press ENTER to create ";
				textcolor(GREEN);
				cout<<front->t;
				textcolor(WHITE);
				cout<<" or ESC to exit"<<endl<<endl;
				a=getch();
				if(a==27)
				{
					break;
				}
				cout << "Page "<<k<<endl<<endl;
				switch(a)
				{
					case 13: {h.html_base(k++);
						  break;}
				}
			}
			else
			{
				break;
			}
		}
		else
		{
			cout << "Page "<<k<<endl<<endl;
			h.html_base(k++);
		}
	}
}

void html::html_base(int k)
{
	clrscr();
	if(k==0)
	{
		pages_intro();
		cout<<"\n\nPlease make sure the name of the page contains less than 6 characters. This is due to compiler restrictions.";
		cout<<"\n\nName for page "<<k+1<<": ";
		cin>>title;
		create(title);
		strcpy(title," ");
	}
	strcpy(title,front->t);
	strcpy(name,"PG_");
	strcat(name,title);
	strcat(name,".HTM");
	ofstream html;
	html.open(name);
	html<<"<!DOCTYPE html>"<< endl;
	html<<"<html>"<< endl;
	html<<"<head>"<< endl;
	clrscr();
	gotoxy(1,1);
	cout<<"Page "<<k+1<<" -- ";
	cout<<title;
	html<<"<title>"<<title<< "</title>"<<endl;
	strcpy(s_title,"s_");
	strcat(s_title,title);
	strcat(s_title,".css");
	html<<"<link rel=\"stylesheet\" type=\"text/css\" href=\""<<s_title<<"\">";
	html<<"</head>";
	html<<"<body>";
	bg_html();
	e.decision(7);
	html_nav();
	fstream nav;
	nav.open("nav_html.txt",ios::in);
	while(!nav.eof())
	{
		char a[75];
		nav.getline(a,75);
		html<<a;
	}
	nav.close();
	e.decision(1);
	html<<"<br><br><br>";
	clrscr();
	while(z!=8)
	{

		gotoxy(1,1);
		cout<<"Page "<<k+1<<" -- ";
		gotoxy(11,1);
		cout<<title<<endl;
		cout<<"What do you want to add to your website?"<<endl<<endl;
		z=e.elements();
		switch(z)
		{
			case 1:{int i;
				clrscr();
				gotoxy(1,1);
				cout<<"Page "<<k+1<<" -- ";
				gotoxy(11,1);
				cout<<title<<endl<<endl;
				char c;
				cout<<"Do you want to stylize the text? (y/n)";
				cin>>c;
				clrscr();
				switch(c)
				{
					case 'y':
					case 'Y':{gotoxy(1,1);
						  cout<<"Page "<<k<<endl<<endl;
						  html<<"<div id=p"<<p<<"><p>";
						  clrscr();
						  cout<<"Enter the text below: "<<endl<<endl;
						  while(txt[i]!=13)
						  {
							i=0;
							while(i<20)
							{

								txt[i]=getche();
								if(txt[i]==8)
								{
									i--;
									clrscr();
									cout<<"Enter your paragraph below: "<<endl<<endl;
									cout << b;
									for(int j=0; j<i;j++)
									cout << txt[j];
								}
								else if(txt[i]==13)
								{break;}
								else {i++;}
							}
						  strcat(b,txt);
						  strcpy(txt," ");
						  }
						  html<<b;
						  strcpy(b," ");
						  i=0;
						  clrscr();
						  html<< "</p></div>";
						  html<<"<br><br>";
						  e.decision(2);
						  break;}
					case 'n':
					case 'N':{gotoxy(1,1);
						  cout<<"Page "<<k<<endl<<endl;
						  html<<"<p>";
						  clrscr();
						  cout<<"Enter the text below: "<<endl<<endl;
						  while(txt[i]!=13)
						  {
							i=0;
							while(i<20)
							{
								txt[i]=getche();
								if(txt[i]==8)
								{
									i--;
									clrscr();
									cout<<"Enter your paragraph below: "<<endl<<endl;
									cout << b;
									for(int j=0; j<i;j++)
									cout << txt[j];
								}
								else if(txt[i]==13)
								{break;}
								else {i++;}
							}
						  strcat(b,txt);
						  strcpy(txt," ");
						  }
						  html<<b;
						  strcpy(b," ");
						  i=0;
						  clrscr();
						  html<< "</p>";
						  cout<<endl;
						  html<<"<br><br>";
						  break;}
					}
				break;}
			case 2:{int i;
				clrscr();
				gotoxy(1,1);
				cout<<"Page "<<k<<endl<<endl;
				char ch;
				cout << "Image directory: ";
				cin >> img;
				cout<<endl<<"Enter the height: ";
				cin>>height;
				cout<<"Enter the width: ";
				cin>>width;
				cout<<"Do you want make this image redirect to a website or page? (y/n)?";
				cin>>ch;
				if(ch=='y'||ch=='Y')
				{
					clrscr();
					cout << "Link to:";
					html<<"<a href=\"";
					do
					{
						a=getch();
						html<< a;
						cout<< a;
					}
					while(a!=13);
					clrscr();
					cout<<"\nDo you want to place the image in the center of your webpage?(y/n)";
					cin>>ch;
					if(ch=='y'||ch=='Y')
					{
						html<<"\"><center><img src=\""<< img<<"\"" <<"height=\""<<height<<"\""<<"width=\""<<width<<"\""<<"/>"<<"</center>"<<"</a>"<<endl;
					}
					else
					html<<"\"><img src=\""<< img<<"\"" <<"height=\""<<height<<"\""<<"width=\""<<width<<"\""<<"/>"<<"</a>"<<endl;
				}
				else
				{
					cout<<"\nDo you want to place the image in the center of your webpage?(y/n)";
					cin>>ch;
					if(ch=='y'||ch=='Y')
					{
						html<<"\"><center><img src=\""<< img<<"\"" <<"height=\""<<height<<"\""<<"width=\""<<width<<"\""<<"/>"<<"</center>"<<"</a>"<<endl;
					}
					else
					html<<"\"><img src=\""<< img<<"\"" <<"height=\""<<height<<"\""<<"width=\""<<width<<"\""<<"/>"<<"</a>"<<endl;
				}
				cout<<endl;
				html<<"<br><br>";
				break;}
			case 3:{int i;
				char c;
				clrscr();
				cout<<"Do you want to stylize this heading? (y/n)";
				cin>>c;
				clrscr();
				switch(c)
				{
					case 'y':
					case 'Y':{gotoxy(1,1);
						  cout<<"Page "<<k<<endl<<endl;
						  e.head_menu();
						  cout<<"\n\nEnter choice: ";
						  cin>>t;
						  html<<"<h"<<t<<">";
						  html<<"<div id=head"<<head<<">";
						  clrscr();
						  cout<<"Enter heading below: "<<endl<<endl;
						  while(txt[i]!=13)
						  {
							i=0;
							while(i<20)
							{
								txt[i]=getche();
								if(txt[i]==8)
								{
									i--;
									clrscr();
									cout<<"Enter heading below: "<<endl<<endl;
									cout << b;
									for(int j=0; j<i;j++)
									cout << txt[j];
								}
								else if(txt[i]==13)
								{break;}
								else {i++;}
							}
						  strcat(b,txt);
						  strcpy(txt," ");
						  }
						  html<<b;
						  strcpy(b," ");
						  i=0;
						  clrscr();
						  html<<"</div>"<<"</h"<<t<<">";
						  cout<<endl;
						  html<<"<br><br>";
						  e.decision(3);
						  break;}
					case 'n':
					case 'N':{gotoxy(1,1);
						  cout<<"Page "<<k<<endl<<endl;
						  e.head_menu();
						  cout<<"\n\nEnter choice: ";
						  cin>>t;
						  html<<"<h"<<t<<">";
						  clrscr();
						  cout<<"Enter heading below: "<<endl<<endl;
						  while(txt[i]!=13)
						  {
							i=0;
							while(i<20)
							{
								txt[i]=getche();
								if(txt[i]==8)
								{
									i--;
									clrscr();
									cout<<"Enter heading below: "<<endl<<endl;
									cout << b;
									for(int j=0; j<i;j++)
									cout << txt[j];
								}
								else if(txt[i]==13)
								{break;}
								else {i++;}
							}
						  strcat(b,txt);
						  strcpy(txt," ");
						  }
						  html<<b;
						  strcpy(b," ");
						  i=0;
						  clrscr();
						  html<<"</h"<<t<<">";
						  cout<<endl;
						  html<<"<br><br>";
						  break;}
					}
				break;}
			case 4:{clrscr();
				char c, link[50];
				cout<< "Do you want to make the link interactive on hover? (y/n)";
				cin>>c;
				switch(c)
				{
				case 'y':
				case 'Y':{clrscr();
					  gotoxy(1,1);
					  cout<<"Page "<<k<<endl<<endl;
					  cout << "Link to:";
					  html<<"<div id=hyper"<<hyper<<">";
					  html<< "<a href=\"";
					  cin>>link;
					  html<<link;
					  cout<<"Enter tag you want to hyperlink: ";
					  gets(tag);
					  html<<"\""<<">"<<tag<<"</a>";
					  html<<"</div>";
					  cout<<endl;
					  html<<"<br><br>";
					  e.decision(4);
					  break;}
				case 'n':
				case 'N':{clrscr();
					  gotoxy(1,1);
					  cout<<"Page "<<k<<endl<<endl;
					  cout << "Link to:";
					  html<< "<a href=\"";
					  cin>>link;
					  html<<link;
					  cout<<"Enter tag you want to hyperlink: ";
					  gets(tag);
					  html<<"\""<<">"<<tag<<"</a>";
					  cout<<endl;
					  html<<"<br><br>";
					  break;}
					}
				break;}
			case 5:{clrscr();
				char c, tab[100], name[20];
				cout<< "Do you want to stylize this table? (y/n)";
				cin>>c;
				clrscr();
				switch(c)
				{
					case 'y':
					case 'Y':{clrscr();
						  gotoxy(1,1);
						  cout<<"Page "<<k<<endl<<endl;
						  gotoxy(1,1);
						  cout<<"Page "<<k<<" -- ";
						  cout<<title<<endl<<endl;
						  cout<<"Number of rows: ";
						  cin>>row;
						  cout<<"\nNumber of columns: ";
						  cin>>col;
						  cout<<"\nBorder size: ";
						  cin >> border;
						  //html<<"<div id=tab"<<table<<">";
						  html<<"<table border=\""<<border<<"px\">";
						  cout<<"\n";
						  html << "<tr>" << endl;
						  for(int i=0; i< row; i++)
						  {
							cout<<"What do you want to call column "<<i+1<<"?";
							cin>>name;
							html<<"<th>"<<name<<"</th>";
						  }
						  html<<"</tr>";
						  for(i=0; i< col; i++)
						  {
							html << "<tr>" << endl;
							for(int j=0; j<row; j++)
							{
								cout << "Column " << i+1 << " Row " << j+1 << " Text: ";
								cin>>tab;
								html << "<td>"<<endl;
								html<< tab;
								html<< "</td>" << endl;
							}
						  }
						  html<< "</tr>"<<endl;
						  html<<"</table>";
						  html<<"</div>";
						  cout<<"Table created";
						  delay(600);
						  cout<<endl;
						  html<<"<br><br>";
						  e.decision(5);
						  break;}
					case 'n':
					case 'N':{clrscr();
						  gotoxy(1,1);
						  cout<<"Page "<<k<<" -- ";
						  //gotoxy(10,1);
						  cout<<title<<endl<<endl;
						  cout<< "Number of rows: ";
						  cin >> row;
						  cout << "\nNumber of columns: ";
						  cin >> col;
						  cout<<"\nBorder size: ";
						  cin >> border;
						  html<<"<table border=\""<<border<<"px\">";
						  cout<<"\n";
						  html << "<tr>" << endl;
						  for(int i=0; i< row; i++)
						  {
							cout<<"What do you want to call column "<<i+1<<"?";
							cin>>name;
							html<<"<th>"<<name<<"</th>";
						  }
						  html<<"</tr>";
						  for(i=0; i< col; i++)
						  {
							html << "<tr>" << endl;
							for(int j=0; j<row; j++)
							{
								cout << "Column " << i+1 << " Row " << j+1 << " Text: ";
								cin>>tab;
								html << "<td>"<<endl;
								html<< tab;
								html<< "</td>" << endl;
							}
						  }
						  html<< "</tr>"<<endl;
						  html<<"</th>";
						  html<<"</table>";
						  cout<<endl;
						  html<<"<br><br>";
						  cout<<"Table created";
						  delay(600);
						  break;}
					}
				break;}
			case 6:{int ch;
				int i=1;
				char item[20], boo,c;
				clrscr();
				cout<<"What type of list do you want to  create?\n\n";
				cout<<"1. Numbered list\n2. Bulleted list\n\nChoice: ";
				cin>>ch;
				switch(ch)
				{
					case 1:{clrscr();
						cout<< "Do you want to stylize this list? (y/n)";
						cin>>c;
						clrscr();
						switch(c)
						{
							case 'y':
							case 'Y':{html<<"<ol id=\"list"<<list<<"\">";
								  clrscr();
								  while(boo!=27)
								  {
									cout<<"List item "<<i<<": ";
									cin>>item;
									html<<"<li>"<<item<<"</li>";
									cout<<"\nPress ANY KEY to add another item or ESC to return to previous menu"<<endl<<endl;
									boo=getch();
									if(boo!=27)
									{
										clrscr();
										i++;
										strcpy(item," ");
									}
									else if(boo==27)
									{
										i++;
										strcpy(item," ");
										break;
									}
								  }
								  html<<"</ol>";
								  e.decision(6);
								  break;}
							case 'n':
							case 'N':{html<<"<ol id=\"list"<<list<<"\">";
								  clrscr();
								  while(boo!=27)
								  {
									cout<<"List item "<<i<<": ";
									cin>>item;
									html<<"<li>"<<item<<"</li>";
									cout<<"\nPress ANY KEY to add another item or ESC to return to previous menu"<<endl<<endl;
									boo=getch();
									if(boo!=27)
									{
										clrscr();
										i++;
										strcpy(item," ");
									}
									else if(boo==27)
									{
										i++;
										strcpy(item," ");
										break;
									}
								  }
								  html<<"</ol>";
								  break;}
						}
						break;}
					case 2:{clrscr();
						cout<< "Do you want to stylize this list? (y/n)";
						cin>>c;
						clrscr();
						switch(c)
						{
							case 'y':
							case 'Y':{html<<"<ul id=\"list"<<list<<"\">";
								  clrscr();
								  while(boo!=27)
								  {
									cout<<"List item "<<i<<": ";
									cin>>item;
									html<<"<li>"<<item<<"</li>";
									cout<<"\nPress ANY KEY to add another item or ESC to return to previous menu"<<endl<<endl;
									boo=getch();
									if(boo!=27)
									{
										clrscr();
										i++;
										strcpy(item," ");
									}
									else if(boo==27)
									{
										i++;
										strcpy(item," ");
										break;
									}
								  }
								  html<<"</ul>";
								  e.decision(6);
								  break;}
							case 'n':
							case 'N':{html<<"<ul id=\"list"<<list<<"\">";
								  clrscr();
								  while(boo!=27)
								  {
									cout<<"List item "<<i<<": ";
									cin>>item;
									html<<"<li>"<<item<<"</li>";
									cout<<"\nPress ANY KEY to add another item or ESC to return to previous menu"<<endl<<endl;
									boo=getch();
									if(boo!=27)
									{
										clrscr();
										i++;
										strcpy(item," ");
									}
									else if(boo==27)
									{
										i++;
										strcpy(item," ");
										break;
									}
								  }
								  html<<"</ul>";
								  break;}
							}
					break;}
				}
			break;}
			case 7:{gotoxy(1,1);
				cout<<"Page "<<k<<endl<<endl;
				char pre[]={"PG_"};
				cout<<"Inline page(with .htm extension):";
				cin>>frame;
				strcmp(pre,frame);
				cout<<"Height:";
				cin>>height;
				cout<<"Width:";
				cin>>width;
				html<<"<iframe src=\""<<frame<<"\""<<"height=\""<<height<<"\""<<"width=\""<<width<<"\""<<"/>"<<endl;
				cout<<endl;
				html<<"<br><br>";
				break;}
			case 8:{k++;
				z=8;
				break;}
	}
	clrscr();
	}
	html<<"</body>"<<endl;
	html<<"</html>";
	html.close();
	z=-1;
	strcpy(s_title," ");
}
void css::css_code(int x)
{
	clrscr();
	ofstream css;
	css.open(s_title,ios::app);
	switch(x)
	{
		case 1:{fstream nav;
			nav.open("nav_css.txt",ios::in);
			while(!nav.eof())
			{
				char a[75];
				nav.getline(a,75);
				css<<a;
			}
			nav.close();
			break;}
		case 2:{clrscr();
			int z;
			css << "#p"<<p<<endl<<"{"<<endl;
			while(z!=9)
			{
				clrscr();
				gotoxy(1,1);
				cout<<"Text: CSS\n\n";
				cout <<"What do you want to change?\n\n";
				cout<<"1. Color\n2. Background Color\n3. Height\n4. Width\n"<<"5. Position\n"<<"6. Margin\n"<<"7. Font & size\n"<<"8. Alignment & more!\n"<<"9. Return to previous menu\n";
				cout<<endl<<"Choice: ";
				cin>>z;
				switch(z)
				{
					case 1:{clrscr();
						int i;
						cout<<"Which color?"<<endl<<endl;
						cout<<"1. Red\n2. Blue\n3. Green\n4. Black\n5. White\n6. Grey\n7. Hex value(for web designers!)\n";
						cout<<endl<<"Choose: ";
						cin>>i;
						switch(i)
						{
							case 1:{css<<"color:red;"<<endl;
								break;}
							case 2:{css<<"color:blue;"<<endl;
								break;}
							case 3:{css<<"color:green;"<<endl;
								break;}
							case 4:{css<<"color:black;"<<endl;
								break;}
							case 5:{css<<"color:white;"<<endl;
								break;}
							case 6:{css<<"color:grey;"<<endl;
								break;}
							case 7:{char hex[10];
								cout<<"\nYour hex: ";
								cin >> hex;
								css<<"color:#"<<hex<<endl;
								break;}
							}
						break;}
					case 2:{clrscr();
						int i;
						cout<<"Which color?"<<endl<<endl;
						cout<<"1.Red\n2.Blue\n3.Green\n4.Black\n5.White\n6.Grey\n7.Hex value(for web designers!)\n";
						cout<<endl<<"Choose: ";
						cin>>i;
						switch(i)
						{
							case 1:{css<<"background-color:red;"<<endl;
								break;}
							case 2:{css<<"background-color:blue;"<<endl;
								break;}
							case 3:{css<<"background-color:green;"<<endl;
								break;}
							case 4:{css<<"background-color:black;"<<endl;
								break;}
							case 5:{css<<"background-color:white;"<<endl;
								break;}
							case 6:{css<<"background-color:grey;"<<endl;
								break;}
							case 7:{char hex[10];
								cout<<"\nYour hex: ";
								cin >> hex;
								css<<"background-color:#"<<hex<<endl;
								break;}
						}
						break;}
					case 3:{clrscr();
						int h;
						cout<<"Enter height (we currently only support measurements in pixels): ";
						cin>>h;
						css<<"height:"<<h<<"px;"<<endl;
						break;}
					case 4:{clrscr();
						int w;
						cout<<"Enter width (we currently only support measurements in pixels): ";
						cin>>w;
						css<<"width:"<<w<<"px;"<<endl;
						break;}
					case 5:{clrscr();
						int i;
						char type[20];
						cout<<"How do you want the positioning to work?"<<endl<<endl;
						cout<<"1. Fixed*\n2. Relative**\n\n";
						cout<<"*Posiiton remains fixed"<<endl;
						cout<<"**Position is relative to parent element(suggested method)";
						cout<<"\n\nChoice:";
						cin>>i;
						switch(i)
						{
							case 1:{strcpy(type,"fixed;");
								css<<"position:"<<type<<endl;
								break;}
							case 2:{strcpy(type,"relative;");
								css<<"position:"<<type<<endl;
								break;}
						}
						break;}
					case 6:{clrscr();
						int i;
						while(i!=5)
						{
							clrscr();
							cout<<"What margin do you want to edit?"<<endl<<endl;
							cout<<"1. Top\n2. Bottom\n3. Left\n4. Right\n\n\n"<<"5. Return to previous menu\n\n";
							cout<<"Choice: ";
							cin>>i;
							switch(i)
							{
								case 1:{clrscr();
									int value;
									cout<<"Pixels you want to shift element top by: ";
									cin>>value;
									css<<"margin-top:"<<value<<"px;"<<endl;
									break;}
								case 2:{clrscr();
									int value;
									cout<<"Pixels you want to shift element bottom by: ";
									cin>>value;
									css<<"margin-bottom:"<<value<<"px;"<<endl;
									break;}
								case 3:{clrscr();
									int value;
									cout<<"Pixels you want to shift element left by: ";
									cin>>value;
									css<<"margin-left:"<<value<<"px;"<<endl;
									break;}
								case 4:{clrscr();
									int value;
									cout<<"Pixels you want to shift element right by: ";
									cin>>value;
									css<<"margin-right:"<<value<<"px;"<<endl;
									break;}
								case 5:{i=5;
									break;}
							}
						}
						break;}
					case 7:{clrscr();
						int i;
						while(i!=4)
						{
							clrscr();
							cout<<"What font adjustment you want to make?"<<endl<<endl;
							cout<<"1. Font Type\n2. Font weight/style(bold, italics etc)\n3. Font size\n\n\n"<<"4. Return to previous menu\n\n";
							cout<<"Choice: ";
							cin>>i;
							switch(i)
							{
								case 1:{clrscr();
									int ch;
									cout<<"What do you want to change font to?\n\n";
									cout<<"1. Times New Roman\n2. Verdana\n3. Georgia\n4. Arial\n\n\n5.OR Return back\n\nChoice: ";
									cin>>ch;
									switch(ch)
									{
										case 1:{css<<"font-family: \"Times New Roman\";"<<endl;
											break;}
										case 2:{css<<"font-family: \"Verdana\";"<<endl;
											break;}
										case 3:{css<<"font-family: \"Georgia\";"<<endl;
											break;}
										case 4:{css<<"font-family: \"Arial\";"<<endl;
											break;}
										case 5:{ch=5;
											break;}
									}
									break;}
								case 2:{clrscr();
									int ch;
									clrscr();
									cout<<"How do you want the text to appear?\n\n";
									cout<<"1. Bold\n2. Italic\n3. Thickness\n\n4. OR Return back\n\nChoice: ";
									cin>>ch;
									switch(ch)
									{
										case 1:{css<<"font-weight: bold;"<<endl;
											break;}
										case 2:{css<<"font-style: italic;"<<endl;
											break;}
										case 3:{clrscr();
											int value;
											cout<<"Pixels you want to increase thickness by: ";
											cin>>value;
											css<<"font-weight:"<<value<<"px;"<<endl;
											break;}
										case 4:{ch=4;
											break;}
									}
									break;}
								case 3:{clrscr();
									int value;
									cout<<"Size in pixels: ";
									cin>>value;
									css<<"font-size:"<<value<<"px;"<<endl;
									break;}
								case 4:{i=4;
									break;}
							}
						}
						break;}
					case 8:{clrscr();
						int i;
						while(i!=4)
						{
							clrscr();
							cout<<"Which of the following do you want to edit?"<<endl;
							cout<<"1. Alignment\n2. Decoration\n3. Border\n4. Return to previous menu\n\nChoice: ";
							cin>>i;
							switch(i)
							{
								case 1:{clrscr();
									int ch;
									cout<<"1. Left align\n2. Right align\n3. Center align\n4. Return to previous menu\n\nChoice: ";
									cin>>ch;
									switch(ch)
									{
										case 1:{css<<"text-align: left;"<<endl;
											break;}
										case 2:{css<<"text-align: right;"<<endl;
											break;}
										case 3:{css<<"text-align: center;"<<endl;
											break;}
									}
									break;}
								case 2:{clrscr();
									int ch;
									cout<<"1. Underline\n2. Overline\n3. Line through\n4. Return to previous menu \n\nChoice: ";
									cin>>ch;
									switch(ch)
									{
										case 1:{css<<"text-decoration:underline;"<<endl;
											break;}
										case 2:{css<<"text-decoration:overline;"<<endl;
											break;}
										case 3:{css<<"text-decoration:line-through;"<<endl;
											break;}
									}
									break;}
								case 3:{clrscr();
									int value;
									char color[20];
									cout<<"What size border do you require(we only support measurements in pixels as of now!)";
									cin>>value;
									cout<<"Border color (red, blue, green, black, grey etc): ";
									cin>>color;
									css<<"border-width: "<<value<<"px;"<<endl;
									css<<"border-color: "<<color<<";"<<endl;
									break;}
								case 4:{i=4;
									break;}
							}
						}
						break;}
					case 9:{z=9;
						break;}
				}
			}
			css<<"}"<<endl;
			p++;
			break;}
		case 3:{clrscr();
			int z;
			css << "#head"<<head<<endl<<"{"<<endl;
			while(z!=9)
			{
				clrscr();
				gotoxy(1,1);
				cout<<"Headings: CSS\n\n";
				cout <<"What do you want to change?\n\n";
				cout<<"1. Color\n2. Background Color\n3. Height\n4. Width\n"<<"5. Position\n"<<"6. Margin\n"<<"7. Font\n"<<"8. Alignment & decoration\n"<<"9. OR Return to previous menu\n";
				cout<<endl<<"Choice: ";
				cin>>z;
				switch(z)
				{
					case 1:{clrscr();
						int i;
						cout<<"Which color?"<<endl<<endl;
						cout<<"1. Red\n2. Blue\n3. Green\n4. Black\n5. White\n6. Grey\n7. Hex value(for web designers!)\n\n\nChoice: ";
						cin>>i;
						switch(i)
						{
							case 1:{css<<"color:red;"<<endl;
								break;}
							case 2:{css<<"color:blue;"<<endl;
								break;}
							case 3:{css<<"color:green;"<<endl;
								break;}
							case 4:{css<<"color:black;"<<endl;
								break;}
							case 5:{css<<"color:white;"<<endl;
								break;}
							case 6:{css<<"color:grey;"<<endl;
								break;}
							case 7:{char hex[10];
								cout<<"Your hex value: ";
								cin >> hex;
								css<<"color:#"<<hex<<endl;
								break;}
							}
						break;}
					case 2:{clrscr();
						int i;
						cout<<"Which color? "<<endl<<endl;
						cout<<"1.Red\n2.Blue\n3.Green\n4.Black\n5.White\n6.Grey\n7.Hex value(for web designers!)\n";
						cout<<endl<<"Choose: ";
						cin>>i;
						switch(i)
						{
							case 1:{css<<"background-color:red;"<<endl;
								break;}
							case 2:{css<<"background-color:blue;"<<endl;
								break;}
							case 3:{css<<"background-color:green;"<<endl;
								break;}
							case 4:{css<<"background-color:black;"<<endl;
								break;}
							case 5:{css<<"background-color:white;"<<endl;
								break;}
							case 6:{css<<"background-color:grey;"<<endl;
								break;}
							case 7:{char hex[10];
								cout<<"Your hex value: ";
								cin >> hex;
								css<<"background-color:#"<<hex<<endl;
								break;}
						}
						break;}
					case 3:{clrscr();
						int h;
						cout<<"Enter height (we currently only support measurements in pixels): ";
						cin>>h;
						css<<"height:"<<h<<"px;"<<endl;
						break;}
					case 4:{clrscr();
						int w;
						cout<<"Enter width (we currently only support measurements in pixels): ";
						cin>>w;
						css<<"width:"<<w<<"px;"<<endl;
						break;}
					case 5:{clrscr();
						int i;
						char type[20];
						cout<<"How do you want the positioning to work?"<<endl<<endl;
						cout<<"1. Fixed*\n2. Relative**\n\n";
						cout<<"*Position remains fixed"<<endl;
						cout<<"**Position is relative to parent element(suggested method)";
						cout<<"\n\nChoice:";
						cin>>i;
						switch(i)
						{
							case 1:{strcpy(type,"fixed");
								css<<"position:"<<type<<endl;
								break;}
							case 2:{strcpy(type,"relative");
								css<<"position:"<<type<<endl;
								break;}
						}
						break;}
					case 6:{clrscr();
						int i;
						while(i!=5)
						{
							clrscr();
							cout<<"Which of the following do you want to edit?"<<endl<<endl;
							cout<<"1. Top\n2. Bottom\n3. Left\n4. Right\n\n\n"<<"5. OR Return back\n\n";
							cout<<"Choice: ";
							cin>>i;
							switch(i)
							{
								case 1:{clrscr();
									int value;
									cout<<"Pixels you want to shift element top by: ";
									cin>>value;
									css<<"margin-top:"<<value<<"px;"<<endl;
									break;}
								case 2:{clrscr();
									int value;
									cout<<"Pixels you want to shift element bottom by: ";
									cin>>value;
									css<<"margin-bottom:"<<value<<"px;"<<endl;
									break;}
								case 3:{clrscr();
									int value;
									cout<<"Pixels you want to shift element left by: ";
									cin>>value;
									css<<"margin-left:"<<value<<"px;"<<endl;
									break;}
								case 4:{clrscr();
									int value;
									cout<<"Pixels you want to shift element right by: ";
									cin>>value;
									css<<"margin-right:"<<value<<"px;"<<endl;
									break;}
								case 5:{i=5;
									break;}
							}
						}
						break;}
					case 7:{clrscr();
						int i;
						while(i!=4)
						{
							clrscr();
							cout<<"Which of the following do you want to edit?"<<endl<<endl;
							cout<<"1. Font Type\n2. Font weight/style(bold, italics etc)\n3. Font size\n\n\n"<<"4. OR Return back\n\n";
							cout<<"Choice: ";
							cin>>i;
							switch(i)
							{
								case 1:{clrscr();
									int ch;
									cout<<"What do you want to change the font to?\n\n";
									cout<<"1. Times New Roman\n2. Verdana\n3. Georgia\n4. Arial\n\n\\n5.OR Return back\n\nChoice: ";
									cin>>ch;
									switch(ch)
									{
										case 1:{css<<"font-family: \"Times New Roman\";"<<endl;
											break;}
										case 2:{css<<"font-family: \"Verdana\";"<<endl;
											break;}
										case 3:{css<<"font-family: \"Georgia\";"<<endl;
											break;}
										case 4:{css<<"font-family: \"Arial\";"<<endl;
											break;}
										case 5:{ch=5;
											break;}
									}
									break;}
								case 2:{clrscr();
									int ch;
									clrscr();
									cout<<"How do you want the text to appear?\n\n";
									cout<<"1. Bold\n2. Italic\n3. Thickness\n\n\n4. OR Return back\n\nChoice: ";
									cin>>ch;
									switch(ch)
									{
										case 1:{css<<"font-weight: bold;"<<endl;
											break;}
										case 2:{css<<"font-style: italic;"<<endl;
											break;}
										case 3:{clrscr();
											int value;
											cout<<"Pixels you want to increase thickness by: ";
											cin>>value;
											css<<"font-weight:"<<value<<"px;"<<endl;
											break;}
										case 4:{ch=4;
											break;}
									}
									break;}
								case 3:{clrscr();
									int value;
									cout<<"Size in pixels: ";
									cin>>value;
									css<<"font-size:"<<value<<"px;"<<endl;
									break;}
								case 4:{i=4;
									break;}
							}
						}
						break;}
					case 8:{clrscr();
						int i;
						while(i!=4)
						{
							clrscr();
							cout<<"Choose what you want to apply: "<<endl;
							cout<<"\n1. Alignment\n2. Decoration\n3. Border\n4. OR Return back\n\nChoice: ";
							cin>>i;
							switch(i)
							{
								case 1:{clrscr();
									int ch;
									cout<<"1. Left align\n2. Right align\n3. Center align\n4. OR Return back\n\nChoice: ";
									cin>>ch;
									switch(ch)
									{
										case 1:{css<<"text-align: left;"<<endl;
											break;}
										case 2:{css<<"text-align: right;"<<endl;
											break;}
										case 3:{css<<"text-align: center;"<<endl;
											break;}
									}
									break;}
								case 2:{clrscr();
									int ch;
									cout<<"1. Underline\n2. Overline\n3. Line through\n4. OR Return back\n\nChoice: ";
									cin>>ch;
									switch(ch)
									{
										case 1:{css<<"text-decoration:underline;"<<endl;
											break;}
										case 2:{css<<"text-decoration:overline;"<<endl;
											break;}
										case 3:{css<<"text-decoration:line-through;"<<endl;
											break;}
									}
									break;}
								case 3:{clrscr();
									int value;
									char color[20];
									cout<<"What size of border do you require(we only support measurements in pixels as of now!)";
									cin>>value;
									cout<<"Border color (red, blue, green, black, grey etc): ";
									cin>>color;
									css<<"border-width: "<<value<<"px;"<<endl;
									css<<"border-color: "<<color<<";"<<endl;
									break;}
								case 4:{i=4;
									break;}
							}
						}
						break;}
					case 9:{z=9;
						break;}
				}
			}
			css<<"}"<<endl;
			head++;
			break;}
		case 4:{clrscr();
			int i;
			css<<"#hyper"<<hyper<<":hover{"<<endl;
			while(i!=5)
			{
				clrscr();
				gotoxy(1,1);
				cout<<"CSS: Hyperlinks\n\n";
				cout<<"What do you want the link to do when the mouse is hovered over?"<<endl<<endl;
				cout<<"1. Highlight link on hover\n2. Color link on hover\n3. Change size on hover\n4. Underline link on hover\n5. Return to previous menu\n\nChoice: ";
				cin>>i;
				switch(i)
				{
					case 1:{clrscr();
						int ch;
						cout<<"Colors we offer: "<<endl<<endl;
						cout<<"1.Red\n2.Blue\n3.Green\n4.Black\n5.White\n6.Grey\n7.Hex value(for web designers!)\n\n\nChoice: ";
						cin>>ch;
						switch(ch)
						{
							case 1:{css<<"background: red;"<<endl;
								break;}
							case 2:{css<<"background: blue;"<<endl;
								break;}
							case 3:{css<<"background: green;"<<endl;
								break;}
							case 4:{css<<"background: black;"<<endl;
								break;}
							case 5:{css<<"background: white;"<<endl;
								break;}
							case 6:{css<<"background: grey;"<<endl;
								break;}
							case 7:{char hex[10];
								cout<<"Your hex: ";
								cin >> hex;
								css<<"background: #"<<hex<<";"<<endl;
								break;}
						}
						break;}
					case 2:{clrscr();
						int ch;
						cout<<"Colors we offer: "<<endl<<endl;
						cout<<"1.Red\n2.Blue\n3.Green\n4.Black\n5.White\n6.Grey\n7.Hex value(for web designers!)\n\n\nChoice: ";
						cin>>ch;
						switch(ch)
						{
							case 1:{css<<"color:red;"<<endl;
								break;}
							case 2:{css<<"color:blue;}"<<endl;
								break;}
							case 3:{css<<"color: green;"<<endl;
								break;}
							case 4:{css<<"color: black;"<<endl;
								break;}
							case 5:{css<<"color: white;"<<endl;
								break;}
							case 6:{css<<"color: grey;"<<endl;
								break;}
							case 7:{char hex[10];
								cout<<"Your hex: ";
								cin >> hex;
								css<<"color: #"<<hex<<";"<<endl;
								break;}
						}
						break;}
					case 3:{css<<"font-size:150%;"<<endl;
						cout<<"\nDone!";
						delay(500);
						break;}
					case 4:{css<<"text-decoration: underline;"<<endl;
						cout<<"\nDone!";
						delay(500);
						break;}
					case 5:{i=5;
						break;}
				}
			}
			css<<"}"<<endl;
			hyper++;
			break;}
		case 5:{clrscr();
			int i;
			while(i!=7)
			{
				clrscr();
				gotoxy(1,1);
				cout<<"CSS: Tables\n\n";
				cout<<"What part of your table's appearance do you want to change?"<<endl<<endl;
				cout<<"1. Header color\n2. Text color\n3. Height\n4. Width\n5. Alignment for table contents\n6. Set position for table caption\n7. Return to previous menu\n\nChoice: ";
				cin>>i;
				switch(i)
				{
					case 1:{clrscr();
						css<<"th"<<"{"<<endl;
						int z;
						cout<<"Which color?"<<endl<<endl;
						cout<<"1.Red\n2.Blue\n3.Green\n4.Black\n5.White\n6.Grey\n7.Hex value(for web designers!)\n";
						cout<<endl<<"Choose: ";
						cin>>z;
						switch(z)
						{
							case 1:{css<<"background-color:red;"<<endl;
								css<<"color: white;"<<endl;
								break;}
							case 2:{css<<"background-color:blue;"<<endl;
								css<<"color: white;"<<endl;
								break;}
							case 3:{css<<"background-color:green;"<<endl;
								css<<"color: white;"<<endl;
								break;}
							case 4:{css<<"background-color:black;"<<endl;
								css<<"color: white;"<<endl;
								break;}
							case 5:{css<<"background-color:white;"<<endl;
								css<<"color: white;"<<endl;
								break;}
							case 6:{css<<"background-color:grey;"<<endl;
								css<<"color: white;"<<endl;
								break;}
							case 7:{char hex[10];
								cout<<"\nYour hex value: ";
								cin >> hex;
								css<<"background-color:#"<<hex<<endl;
								css<<"color: white;"<<endl;
								break;}
						}
						css<<"}"<<endl;
					break;}
					case 2:{clrscr();
						css<<"table{";
						int z;
						cout<<"Which color?"<<endl<<endl;
						cout<<"1.Red\n2.Blue\n3.Green\n4.Black\n5.White\n6.Grey\n7.Hex value(for web designers!)\n";
						cout<<endl<<"Choose: ";
						cin>>z;
						switch(z)
						{
							case 1:{css<<"color:red;"<<endl;
								break;}
							case 2:{css<<"color:blue;"<<endl;
								break;}
							case 3:{css<<"color:green;"<<endl;
								break;}
							case 4:{css<<"color:black;"<<endl;
								break;}
							case 5:{css<<"color:white;"<<endl;
								break;}
							case 6:{css<<"color:grey;"<<endl;
								break;}
							case 7:{char hex[10];
								cout<<"\nYour hex value: ";
								cin >> hex;
								css<<"color:#"<<hex<<endl;
								break;}
						}
						css<<"}"<<endl;
						break;}
					case 3:{clrscr();
						css<<"table{";
						cout<<"How high do you want the table to be(in percentage)?";
						cin>>height;
						css<<"height: "<<height<<"%;";
						css<<"}"<<endl;
						break;}
					case 4:{clrscr();
						css<<"table{";
						cout<<"How wide do you want the table to be(in percentage)?";
						cin>>width;
						css<<"width: "<<width<<"%;";
						css<<"}"<<endl;
						break;}
					case 7:{i=7;
						break;}
				}
			}
			break;}
		case 6:{clrscr();
			int i;
			while(i!=6)
			{
				clrscr();
				gotoxy(1,1);
				cout<<"CSS: Lists\n\n";
				cout<<"What part of your List's appearance do you want to change?"<<endl<<endl;
				cout<<"1. Text color\n2. Remove bullets/numbers\n3. Font\n4. Display style(horizontal or vertical)\n5. Alignment\n6. Return to previous menu\n\nChoice: ";
				cin>>i;
				switch(i)
				{
					case 1:{clrscr();
						int ch;
						cout<<"Colors we offer: "<<endl<<endl;
						cout<<"1.Red\n2.Blue\n3.Green\n4.Black\n5.White\n6.Grey\n7.Hex value(for web designers!)\n\n\nChoice: ";
						cin>>ch;
						css<<"#list"<<list<<"{";
						switch(ch)
						{
							case 1:{css<<"color:red;"<<endl;
								break;}
							case 2:{css<<"color:blue;"<<endl;
								break;}
							case 3:{css<<"color: green;"<<endl;
								break;}
							case 4:{css<<"color: black;"<<endl;
								break;}
							case 5:{css<<"color: white;"<<endl;
								break;}
							case 6:{css<<"color: grey;"<<endl;
								break;}
							case 7:{char hex[10];
								cout<<"Your hex: ";
								cin >> hex;
								css<<"color: #"<<hex<<";"<<endl;
								break;}
						}
						break;}
					case 2:{css<<"list-style-type: none;";
						cout<<"\nDone!";
						delay(400);
						break;}
					case 3:{clrscr();
						int i;
						while(i!=4)
						{
							clrscr();
							cout<<"What font adjustment you want to make?"<<endl<<endl;
							cout<<"1. Font Type\n2. Font weight/style(bold, italics etc)\n3. Font size\n\n\n"<<"4. Return to previous menu\n\n";
							cout<<"Choice: ";
							cin>>i;
							switch(i)
							{
								case 1:{clrscr();
									int ch;
									cout<<"What do you want to change font to?\n\n";
									cout<<"1. Times New Roman\n2. Verdana\n3. Georgia\n4. Arial\n\n\n5.OR Return back\n\nChoice: ";
									cin>>ch;
									switch(ch)
									{
										case 1:{css<<"font-family: \"Times New Roman\";"<<endl;
											break;}
										case 2:{css<<"font-family: \"Verdana\";"<<endl;
											break;}
										case 3:{css<<"font-family: \"Georgia\";"<<endl;
											break;}
										case 4:{css<<"font-family: \"Arial\";"<<endl;
											break;}
										case 5:{ch=5;
											break;}
									}
									break;}
								case 2:{clrscr();
									int ch;
									clrscr();
									cout<<"How do you want the text to appear?\n\n";
									cout<<"1. Bold\n2. Italic\n3. Thickness\n\n4. OR Return back\n\nChoice: ";
									cin>>ch;
									switch(ch)
									{
										case 1:{css<<"font-weight: bold;"<<endl;
											break;}
										case 2:{css<<"font-style: italic;"<<endl;
											break;}
										case 3:{clrscr();
											int value;
											cout<<"Pixels you want to increase thickness by: ";
											cin>>value;
											css<<"font-weight:"<<value<<"px;"<<endl;
											break;}
										case 4:{ch=4;
											break;}
									}
									break;}
								case 3:{clrscr();
									int value;
									cout<<"Size in pixels: ";
									cin>>value;
									css<<"font-size:"<<value<<"px;"<<endl;
									break;}
								case 4:{i=4;
									break;}
							}
						}
						break;}
					case 4:{clrscr();
						int f;
						char type[20];
						cout<<"How do you want the list to be displayed?"<<endl<<endl;
						cout<<"1. Vertically\n2. Horizontaly\n\n";
						cout<<"\n\nChoice:";
						cin>>f;
						switch(f)
						{
							case 1:{strcpy(type,"block;");
								css<<"display: "<<type<<endl;
								break;}
							case 2:{strcpy(type,"inline;");
								css<<"display: "<<type<<endl;
								break;}
						}
						break;}
					case 5:{clrscr();
						int ch;
						cout<<"1. Left align\n2. Right align\n3. Center align\n4. Return to previous menu\n\nChoice: ";
						cin>>ch;									
						switch(ch)
						{
							case 1:{css<<"text-align: left;"<<endl;
								break;}
							case 2:{css<<"text-align: right;"<<endl;
								break;}
							case 3:{css<<"text-align: center;"<<endl;
								break;}
						}
						break;}
					case 6:{i=6;
						break;}
					}
				}
			css<<"}";
			list++;
			break;}
		case 7:{fstream bg;
			bg.open("bg_css.txt",ios::in);
			while(!bg.eof())
			{
				char a[75];
				bg.getline(a,75);
				css<<a;
			}
			bg.close();
			break;}
	}
	css.close();
}