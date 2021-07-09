#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <windows.h>
#include <string>
#include <conio.h>
#define MAXN 999999
using namespace std;
struct Users
{ //用户密码
    string UserName;
    string Telephone;
    string PassWord;
};
bool _boolUserLogin = false; //确定用户登录状态

bool checkPassword(char mid)
{
    if (((48 <= mid) && (mid <= 57)) || ((97 <= mid) && (mid <= 122)) || ((65 <= mid) && (mid <= 90)))
    {
        return true;
    }
    else
    {
        return false;
    }
}
string getpassword()
{ //*回显
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    int _KeyProblem = 0;
    string temp = "\0";
    do
    {
        fflush(stdin);
        int Lenth = 0;
        _KeyProblem = 0;
        char single = '\0';

        while (1)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            single = getch();
            if (single == 13) //回车
            {
                fflush(stdin);
                if (Lenth == 0)
                {

                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << endl;
                    cout << "				      		   输入密码为空！" << endl;
                    Sleep(300);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "				      		   请输入密码：";
                    continue;
                }
                else
                {
                    //有长度的密码
                    break; //回车符
                }
            }
            else if (single == 8)
            { //退格
                if (Lenth != 0)
                {
                    if (!checkPassword(temp[Lenth - 1]))
                    {
                        _KeyProblem--;
                    }
                    cout << "\b \b";
                    temp[Lenth - 1] = '\0';
                    Lenth--;
                }
            }
            else
            {
                if (!(((48 <= single) && (single <= 57)) || ((97 <= single) && (single <= 122)) || ((65 <= single) && (single <= 90))))
                {
                    _KeyProblem++;
                }
                Lenth++;
                temp += single;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                cout << "*";
            }
        }
        cout << endl;
        if (_KeyProblem)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		   非法字符！" << endl;
            Sleep(300);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		   输入密码：";
        }
    } while (_KeyProblem); //非法则重新输入
    return temp;
}

void _Register()
{ //注册
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "				      		   WELCOME TO REGISTER!" << endl;

    Users x, y; //y为检索工具
    FILE *fp;   //判断文件是否存在
    string PassWordAgain;
    Sleep(200);
    if ((fp = fopen("users.txt", "rb+")) == NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "				      		   即将创建文件!" << endl;
        Sleep(500);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "				      		   请输入用户名："; //创建文件后直接注册密码
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cin >> x.UserName;
        if ((fp = fopen("users.txt", "wb+")) == NULL)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		   创建文件错误！" << endl;
            fclose(fp);
            exit(0);
        }
    }
    else //文件已存在，则判断用户名是否重合
    {
        fclose(fp);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "				      		   请输入用户名:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cin >> x.UserName;
        ifstream output("users.txt");
        output >> y.UserName;
        output >> y.Telephone;
        output >> y.PassWord;
        do //判断是否重复用户名
        {
            if (x.UserName != y.UserName) //判断是否
            {
                if (!output.eof()) //尚未检索到文件末尾
                {
                    output >> y.UserName;
                    output >> y.Telephone;
                    output >> y.PassWord;
                }
                else //一直到文件结束也没有找到相同用户名
                {
                    break;
                }
            }
            else //找到相同用户名
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << "				      		   该用户名已被注册！";
                Sleep(500);
                output.close();
                return;
            }
        } while (1);
        output.close();
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "				      		   请输入电话号码："; //电话号码
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cin >> x.Telephone;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "				      		   请输入密码：";
    x.PassWord = getpassword();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "				      		   请再次确认密码：";
    PassWordAgain = getpassword();
    do
    {
        if (x.PassWord == PassWordAgain)
        {
            ofstream input("users.txt", ios::app);
            input << x.UserName << endl;
            input << x.Telephone << endl;
            input << x.PassWord << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		   注册成功" << endl;
            Sleep(500);
            cout << "				      		   即将返回登录界面！";
            Sleep(1000);
            input.close();
            return;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		   两次输入密码不一致" << endl;
            cout << "				      		   请输入密码:";
            x.PassWord = getpassword();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		   请再次确认密码：";
            PassWordAgain = getpassword();
        }
    } while (1);
}

void _UserLogin()
{               //登录
    Users m, n; //n为检索工具

    FILE *fp;
    if ((fp = fopen("users.txt", "r")) == NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << endl;
        cout << "				      		   尚未有用户注册！" << endl;
        cout << "				      	  	      即将返回！" << endl;
        Sleep(500);
        fclose(fp);
        return;
    }
    fclose(fp);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "				      		   请输入用户名：";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cin >> m.UserName;
    ifstream output("users.txt");
    output >> n.UserName;
    output >> n.Telephone;
    output >> n.PassWord;

    do
    {
        if (m.UserName == n.UserName) //判断是否注册
        {
            break; //跳入密码检验
        }
        else
        {
            if (!output.eof())
            { //一直读到文件末尾
                output >> n.UserName;
                output >> n.Telephone;
                output >> n.PassWord;
            }
            else
            { //
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << "				      		   该用户尚未注册！" << endl;
                cout << "				         	  即将返回初始界面";
                Sleep(600);
                output.close();
                return;
            }
        }
    } while (1);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "				      		   请输入密码：";
    m.PassWord = getpassword();
    do
    {
        if (m.PassWord == n.PassWord)
        {
            _boolUserLogin = true; //密码正确
            output.close();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout << "				      	  	     登录成功！" << endl;
            printf("				            即将进入成绩综合学生管理系统");
            Sleep(400);
            return;
        }
        else
        {
            int _try = 0;
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout << "       			    ____________________________________________________________" << endl;
            cout << "       			   |___________________________";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
            cout << "密码登录";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout << "_________________________|" << endl;
            cout << "       		   	   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |                         1.重新输入 			|" << endl;
            cout << "       			   |                         2.返回界面 			|" << endl;
            cout << "       		   	   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |____________________________________________________________|" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		   下一步指令：";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            cin >> _try;
            if (_try == 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                printf("				      		   请输入密码：");
                m.PassWord = getpassword();
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                printf("				      		   即将返回！\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                Sleep(600);
                output.close();
                return;
            }
        }
    } while (1);
}

void _ChangeKey()
{ //修改密码
    Users *CopyOld = new Users[50];
    Users a;
    ifstream output("users.txt");
    int i = 0;
    while (!output.eof())
    {
        output >> CopyOld[i].UserName;
        output >> CopyOld[i].Telephone;
        output >> CopyOld[i].PassWord;
        i++;
    }
    i--;
    output.close();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "				      		  请输入用户名：";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cin >> a.UserName;
    cout << endl;
    int ScanOld = 0;
    do //判断是否重复用户名
    {
        if (a.UserName == CopyOld[ScanOld].UserName) //判断是否
        {
            //找到相同用户名;
            break;
        }
        ScanOld++;
        if (ScanOld > i)
        { //未找到
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		   用户名不存在" << endl;
            Sleep(500);
            cout << "				      		      即将返回！";
            Sleep(500);
            return;
        }
    } while (1);

    int _check = 0;
    string CheckTele;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "				      		  请输入电话号码：";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cin >> CheckTele;
    cout << endl;
    do
    {
        if (CheckTele == CopyOld[ScanOld].Telephone)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		  修改密码：";
            a.PassWord = getpassword();
            cout << endl;
            CopyOld[ScanOld].PassWord = a.PassWord;
            ofstream input("users.txt", ios::in);
            for (int _New = 0; _New < i; _New++)
            {
                input << CopyOld[_New].UserName << endl;
                input << CopyOld[_New].Telephone << endl;
                input << CopyOld[_New].PassWord << endl;
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		  修改成功！" << endl;
            cout << endl;
            cout << "				      		  即将返回初始界面！" << endl;
            Sleep(500);
            return;
        }
        else
        {
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout << "       			    ____________________________________________________________" << endl;
            cout << "       			   |___________________________";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
            cout << "密码修改";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout << "_________________________|" << endl;
            cout << "       		   	   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |                         1.重新输入 			|" << endl;
            cout << "       			   |                         2.返回界面 			|" << endl;
            cout << "       		   	   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |____________________________________________________________|" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		   下一步指令：";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            cin >> _check;
            if (_check == 1)
            {
                cout << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << "				      		  请输入电话号码：";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                cin >> CheckTele;
                cout << endl;
            }
            else
            {
                cout << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << "				      		  即将返回！" << endl;
                Sleep(500);
                return;
            }
        }
    } while (1);
    delete[] CopyOld;
}

string Sexout[3] = {"女", "男"};

class student
{
public:
    static float math_max;
    static float chinese_max;
    static float english_max;
    static float score_max;
    static float compre_eval_max;
    static float math_max_i;
    static float chinese_max_i;
    static float english_max_i;
    static float score_max_i;
    static float compre_eval_max_i;
    static int stu_num;
    int uuid;
    string name;
    bool sex; //0 is girl, 1 is boy
    string address;
    string tel;
    float math_grade;
    float chinese_grade;
    float english_grade;
    float scores;
    int scores_rank;
    float stu_exch_score;
    float mod_score;
    float tea_off_score;
    float compre_eval; //comprehensive evaluation
    int compre_eval_rank;
    // student* next;

    student();                                                                           //
    student(int uuid, string name, bool sex, string address, string tel);                //
    ~student();                                                                          //
    friend student *search(int uuid);                                                    //
    student *set_student(int uuid, string name, bool sex, string address, string tel);   //
    friend student *change(int uuid, string name, bool sex, string address, string tel); //
    friend student *change2(int uuid, float chinese_grade, float math_grade, float english_grade, float stu_exch_score, float mod_score, float tea_off_score);
    friend student deleteit(int uuid);                                                     //
    student *loadscore(float chinese_grade, float math_grade, float english_grade);        //
    float cal_scores();                                                                    //
    student *load_compre_eval(float stu_exch_score, float mod_score, float tea_off_score); //
    float cal_compre_eval();                                                               //
    friend int get_score_rank(int uuid);                                                   //
    friend int get_compre_eval_rank(int uuid);                                             //
    friend int get_score_rank_by_i(int i);                                                 //
    friend int get_compre_eval_rank_by_i(int i);                                           //
    friend void show_all();
    void operator=(student STU2); //
    friend int searchbyi(int uuid);
    friend float get_ave_chinese_score();
    friend float get_ave_math_score();
    friend float get_ave_english_score();
    friend float get_ave_scores();
    friend float get_ave_full_scores();
};
student stu[MAXN];
int student::stu_num = 0;
float student::chinese_max = 0;
float student::math_max = 0;
float student::english_max = 0;
float student::score_max = 0;
float student::compre_eval_max = 0;
float student::chinese_max_i = 0;
float student::math_max_i = 0;
float student::english_max_i = 0;
float student::score_max_i = 0;
float student::compre_eval_max_i = 0;
float get_ave_chinese_score()
{
    float sum;
    for (int i = 0; i < student::stu_num; i++)
    {
        sum += stu[i].chinese_grade;
    }
    return sum / student::stu_num;
}
float get_ave_math_score()
{
    float sum;
    for (int i = 0; i < student::stu_num; i++)
    {
        sum += stu[i].math_grade;
    }
    return sum / student::stu_num;
}
float get_ave_scores()
{
    float sum;
    for (int i = 0; i < student::stu_num; i++)
    {
        sum += stu[i].scores;
    }
    return sum / student::stu_num;
}
float get_ave_english_score()
{
    float sum;
    for (int i = 0; i < student::stu_num; i++)
    {
        sum += stu[i].english_grade;
    }
    return sum / student::stu_num;
}
float get_ave_full_scores()
{
    float sum;
    for (int i = 0; i < student::stu_num; i++)
    {
        sum += stu[i].compre_eval;
    }
    return sum / student::stu_num;
}

student::~student()
{
}
student::student()
{
}
student::student(int uuid, string name, bool sex, string address, string tel) : uuid(uuid), name(name), sex(sex), address(address), tel(tel)
{
}
student *student::set_student(int uuid, string name, bool sex, string address, string tel)
{
    stu_num++;
    this->uuid = uuid;
    this->name = name;
    this->sex = sex;
    this->address = address;
    this->tel = tel;
    this->math_grade = 0;
    this->chinese_grade = 0;
    this->english_grade = 0;
    this->scores = 0;
    this->scores_rank = 0;
    this->stu_exch_score = 0;
    this->mod_score = 0;
    this->tea_off_score = 0;
    this->compre_eval = 0;
    this->compre_eval_rank = 0;
    return this; //
}
student *search(int uuid)
{
    student *S;
    for (int i = 0; i < student::stu_num; i++)
    {
        if (stu[i].uuid == uuid)
        {
            S = &stu[i];
            break;
        }
    }
    return S;
}
int searchbyi(int uuid)
{
    int j;
    for (int i = 0; i < student::stu_num; i++)
    {
        if (stu[i].uuid == uuid)
        {
            j = i;
            break;
        }
    }
    return j;
}
student *change2(int uuid, float chinese_grade, float math_grade, float english_grade, float stu_exch_score, float mod_score, float tea_off_score)
{
    student *S;
    int j;
    for (int i = 0; i < student::stu_num; i++)
    {
        if (stu[i].uuid == uuid)
        {
            S = &stu[i];
            j = i;
            break;
        }
    }
    if (stu[j].uuid == uuid)
    {
        if (S->chinese_grade != chinese_grade)
            S->chinese_grade = chinese_grade;
        if (S->math_grade != math_grade)
            S->math_grade = math_grade;
        if (S->english_grade != english_grade)
            S->english_grade = english_grade;
        if (S->stu_exch_score != stu_exch_score)
            S->stu_exch_score = stu_exch_score;
        if (S->mod_score != mod_score)
            S->mod_score = mod_score;
        if (S->tea_off_score != tea_off_score)
            S->tea_off_score != tea_off_score;
        if (chinese_grade > student::chinese_max)
        {
            student::chinese_max = chinese_grade;
            student::chinese_max_i = uuid;
        }
        if (math_grade > student::math_max)
        {
            student::math_max = math_grade;
            student::math_max_i = uuid;
        }
        if (english_grade > student::english_max)
        {
            student::english_max = english_grade;
            student::english_max_i = uuid;
        }
    }
    return S;
}

student *change(int uuid, string name, bool sex, string address, string tel)
{
    student *S;
    int j;
    for (int i = 0; i < student::stu_num; i++)
    {
        if (stu[i].uuid == uuid)
        {
            S = &stu[i];
            j = i;
            break;
        }
        else if (stu[i].uuid > uuid)
        {
            j = i;
            break;
        }
    }
    if (stu[j].uuid == uuid)
    {
        if (S->address != address)
            S->address = address;
        if (S->name != name)
            S->name = name;
        if (S->sex != sex)
            S->sex = sex;
        if (S->tel != tel)
            S->tel = tel;
    }
    else if (stu[j].uuid > uuid)
    {
        student::stu_num++;
        for (int i = student::stu_num - 1; i >= j + 1; i--)
        {
            stu[i] = stu[i - 1];
        }
        stu[j].uuid = uuid;
        stu[j].name = name;
        stu[j].sex = sex;
        stu[j].address = address;
        stu[j].tel = tel;
        S = &stu[j];
    }
    else
    {
        student::stu_num++;
        stu[student::stu_num - 1].uuid = uuid;
        stu[student::stu_num - 1].name = name;
        stu[student::stu_num - 1].sex = sex;
        stu[student::stu_num - 1].address = address;
        stu[student::stu_num - 1].tel = tel;
        S = &stu[j];
    }
    return S;
}
student deleteit(int uuid)
{
    student s;
    int j = -1;
    for (int i = 0; i < student::stu_num; i++)
    {
        if (stu[i].uuid == uuid)
        {
            j = i;
            s = stu[i];
            break;
        }
    }
    if (j != -1)
    {
        for (int i = j; i < student::stu_num - 1; i++)
        {
            stu[i] = stu[i + 1];
        }
        student::stu_num--;
    }
    //if uuid isn't existed, I don't care about it.
    return s;
}
void student::operator=(student STU2)
{
    this->uuid = STU2.uuid;
    this->name = STU2.name;
    this->sex = STU2.sex;
    this->address = STU2.address;
    this->tel = STU2.tel;
    this->math_grade = STU2.math_grade;
    this->chinese_grade = STU2.chinese_grade;
    this->english_grade = STU2.english_grade;
    this->scores = STU2.scores;
    this->scores_rank = STU2.scores_rank;
    this->stu_exch_score = STU2.stu_exch_score;
    this->mod_score = STU2.mod_score;
    this->tea_off_score = STU2.tea_off_score;
    this->compre_eval = STU2.compre_eval;
    this->compre_eval_rank = STU2.compre_eval_rank;
    return;
}
student *student::load_compre_eval(float stu_exch_score, float mod_score, float tea_off_score)
{
    this->stu_exch_score = stu_exch_score;
    this->mod_score = mod_score;
    this->tea_off_score = tea_off_score;
    return this;
}
student *student::loadscore(float chinese_grade, float math_grade, float english_grade)
{
    this->chinese_grade = chinese_grade;
    this->math_grade = math_grade;
    this->english_grade = english_grade;
    if (chinese_grade > student::chinese_max)
    {
        student::chinese_max = chinese_grade;
        student::chinese_max_i = uuid;
    }
    if (math_grade > student::math_max)
    {
        student::math_max = math_grade;
        student::math_max_i = uuid;
    }
    if (english_grade > student::english_max)
    {
        student::english_max = english_grade;
        student::english_max_i = uuid;
    }
    return this;
}
float student::cal_scores()
{
    this->scores = (chinese_grade + math_grade + english_grade) / 3;
    if (scores > student::score_max)
    {
        student::score_max = scores;
        student::score_max_i = uuid;
    }
    return scores;
}
float student::cal_compre_eval()
{
    this->compre_eval = scores * 0.6 + stu_exch_score * 0.1 + mod_score * 0.1 + tea_off_score * 0.2;
    if (this->compre_eval > student::compre_eval_max)
    {
        student::compre_eval_max = this->compre_eval;
        student::compre_eval_max_i = uuid;
    }
    return compre_eval;
}
int get_score_rank(int uuid)
{
    //from uuid get i
    int j = -1;
    for (int i = 0; i < student::stu_num; i++)
    {
        if (stu[i].uuid == uuid)
        {
            j = i;
            break;
        }
    }
    float this_score = stu[j].scores;
    int rank = 1;
    for (int i = 0; i < student::stu_num; i++)
    {
        if (stu[i].scores > this_score)
        {
            rank++;
        }
    }
    stu[j].scores_rank = rank;
    return rank;
}
int get_compre_eval_rank(int uuid)
{
    int j = -1;
    for (int i = 0; i < student::stu_num; i++)
    {
        if (stu[i].uuid == uuid)
        {
            j = i;
            break;
        }
    }
    float this_score = stu[j].compre_eval;
    int rank = 1;
    for (int i = 0; i < student::stu_num; i++)
    {
        if (stu[i].compre_eval > this_score)
        {
            rank++;
        }
    }
    stu[j].compre_eval_rank = rank;
    return rank;
}
int get_score_rank_by_i(int j)
{
    float this_score = stu[j].scores;
    int rank = 1;
    for (int i = 0; i < student::stu_num; i++)
    {
        if (stu[i].scores > this_score)
        {
            rank++;
        }
    }
    stu[j].scores_rank = rank;
    return rank;
}
int get_compre_eval_rank_by_i(int j)
{
    float this_score = stu[j].compre_eval;
    int rank = 1;
    for (int i = 0; i < student::stu_num; i++)
    {
        if (stu[i].compre_eval > this_score)
        {
            rank++;
        }
    }
    stu[j].compre_eval_rank = rank;
    return rank;
}
void show_all()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout
        << "学号"
        << "\t"
        << "姓名"
        << "\t"
        << "性别"
        << "\t"
        << "地址"
        << "\t"
        << "电话";
    cout << "\t"
         << "数学"
         << "\t"
         << "语文"
         << "\t"
         << "英语"
         << "\t"
         << "成绩"
         << "\t"
         << "成绩";
    cout << "\t"
         << "同学"
         << "\t"
         << "品德"
         << "\t"
         << "老师";
    cout << "\t"
         << "综合"
         << "\t"
         << "综合" << endl;
    cout << "\t\t\t\t\t成绩\t成绩\t成绩\t"
         << "均分"
         << "\t"
         << "排名\t互评\t成绩\t评分\t均分\t排名" << endl;
    cout << endl;
    for (int i = 0; i < student::stu_num; i++)
    {

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cout << "  " << stu[i].uuid;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        cout << "\t" << stu[i].name;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "\t" << Sexout[stu[i].sex] << "\t" << stu[i].address << "\t" << stu[i].tel << "\t" << stu[i].math_grade << "\t" << stu[i].chinese_grade << "\t" << stu[i].english_grade << "\t" << stu[i].scores << "\t" << stu[i].scores_rank << "\t" << stu[i].stu_exch_score << "\t" << stu[i].mod_score << "\t" << stu[i].tea_off_score << "\t" << stu[i].compre_eval << "\t" << stu[i].compre_eval_rank << endl;
    }
}
int main(void)
{
    while (1)
    {
        do
        {
            system("cls");
            fflush(stdin);
            while (!_boolUserLogin)
            {
                while (1)
                {
                    system("cls");
                    fflush(stdin);
                    cout << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << "       			    ____________________________________________________________" << endl;
                    cout << "       			   |___________________";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                    cout << "欢迎登录综合成绩管理系统";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << "_________________|" << endl;
                    cout << "       		   	   |                						|" << endl;
                    cout << "       			   |                						|" << endl;
                    cout << "       			   |                						|" << endl;
                    cout << "       			   |                         1.注册账号 			|" << endl;
                    cout << "       			   |                         2.账号登陆 			|" << endl;
                    cout << "       			   |                         3.密码修改 			|" << endl;
                    cout << "       			   |                         4.退出系统 			|" << endl;
                    cout << "       		   	   |                						|" << endl;
                    cout << "       			   |                						|" << endl;
                    cout << "       			   |____________________________________________________________|" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    输入指令：";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    char Login_Choice;
                    cin >> Login_Choice;

                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    Sleep(200);
                    if (Login_Choice == '1')
                    {
                        _Register();
                        break;
                    }
                    else if (Login_Choice == '2')
                    {
                        _UserLogin();
                        break;
                    }
                    else if (Login_Choice == '3')
                    {
                        FILE *fp;
                        if ((fp = fopen("users.txt", "r")) == NULL)
                        {
                            cout << endl
                                 << endl;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                            cout << "					   	  尚未有用户注册！" << endl;
                            cout << "					   	      即将返回！" << endl;
                            Sleep(500);
                            fclose(fp);
                            break;
                        }
                        fclose(fp);
                        _ChangeKey();
                        break;
                    }
                    else if (Login_Choice == '4')
                    {
                        char _QuitChoice;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	 确认退出(Y/N):";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        cin >> _QuitChoice;
                        if (_QuitChoice == 'Y' || _QuitChoice == 'y')
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                            cout << "					     即将退出！欢迎下次使用！" << endl;
                            Sleep(1000);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                            exit(0);
                        }
                        else
                        {
                            continue;
                        }
                    }
                    cout << "输入指令错误！" << endl;
                    Sleep(700);
                    fflush(stdin);
                }
            }
        } while (!_boolUserLogin);

        fflush(stdin);

        while (1)
        {
            system("cls");
            fflush(stdin);
            cout << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout << "       			    ____________________________________________________________" << endl;
            cout << "       			   |___________________";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
            cout << "欢迎登录综合成绩管理系统";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout << "_________________|" << endl;
            cout << "       		   	   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |                         1.学生信息处理                     |" << endl;
            cout << "       			   |                         2.学生数据处理                     |" << endl;
            cout << "       			   |                         3.学生综合信息输出                 |" << endl;
            cout << "       			   |                         4.退出登录 			|" << endl;
            cout << "       		   	   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |____________________________________________________________|" << endl;
            int choose1;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "					   	    输入指令：";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            scanf("%d", &choose1);

            if (choose1 == 1)
            {
                system("cls");
                fflush(stdin);
                int choose2;
                cout << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                cout << "       			    ____________________________________________________________" << endl;
                cout << "       			   |__________________________";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                cout << "学生信息处理";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                cout << "______________________|" << endl;
                cout << "       		   	   |                						|" << endl;
                cout << "       			   |                						|" << endl;
                cout << "       			   |                						|" << endl;
                cout << "       			   |                         0.从控制台输入                     |" << endl;
                cout << "       			   |                         1.从文件输入学生信息               |" << endl;
                cout << "       			   |                         2.插入（修改）同学信息             |" << endl;
                cout << "       			   |                         3.删除同学信息 			|" << endl;
                cout << "       			   |                         4.浏览学生信息 			|" << endl;
                cout << "       			   |                         5.返回上一级 			|" << endl;
                cout << "       		   	   |                						|" << endl;
                cout << "       			   |                						|" << endl;
                cout << "       			   |____________________________________________________________|" << endl;
                int choose1;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << "					   	    输入指令：";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                scanf("%d", &choose2);
                if (choose2 == 0)
                {
                    bool flag = true;
                    while (flag)
                    {
                        int uuid;
                        string name;
                        bool sex;
                        string address;
                        string tel;
                        int sexx;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    uuid:";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        cin >> uuid;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    name:";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        cin >> name;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    sex:";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        cin >> sexx;
                        if (sexx == 0)
                        {
                            sex = 0;
                        }
                        else
                        {
                            sex = 1;
                        }
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    address:";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        cin >> address;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    tel:";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        cin >> tel;
                        change(uuid, name, sex, address, tel);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    还需要输入么？[Y/N]:";
                        char ch;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        cin >> ch;
                        if (ch == 'N' || ch == 'n')
                        {
                            flag = false;
                        }
                    }
                }
                else if (choose2 == 1)
                {
                    ifstream output("studentdetail.txt");
                    int uuid;
                    string name;
                    bool sex;
                    string address;
                    string tel;
                    int sexx;
                    while (output >> uuid >> name >> sexx >> address >> tel)
                    {
                        // cin >> sexx;
                        if (sexx == 0)
                        {
                            sex = 0;
                        }
                        else
                        {
                            sex = 1;
                        }
                        //需要乱序输入，然后按照uuid顺序输出(未解决)f
                        change(uuid, name, sex, address, tel);
                    }
                    output.close();
                }
                else if (choose2 == 2)
                { //修改

                    int uuid;
                    string name;
                    bool sex;
                    int sexx;
                    string address;
                    string tel;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    uuid:";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    cin >> uuid;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    name:";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    cin >> name;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    sex:";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    cin >> sexx;
                    if (sexx == 0)
                    {
                        sex = 0;
                    }
                    else
                    {
                        sex = 1;
                    }
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    address:";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    cin >> address;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    tel:";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    cin >> tel;
                    change(uuid, name, sex, address, tel);
                }
                else if (choose2 == 3)
                {
                    int uuid;
                    show_all();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	 uuid you want to delete:";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%d", &uuid);
                    student *s = search(uuid);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                    cout << "					   	 uuid:" << s->uuid << " name：" << s->name << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	 do you want to delete(Y/N):";
                    getchar();
                    char i;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%c", &i);
                    if (i == 'Y' || i == 'y')
                    {
                        deleteit(uuid);
                        cout << "					   	 删除成功！" << endl;
                        Sleep(300);
                    }
                    //删除
                }
                else if (choose2 == 4)
                {
                    show_all();
                    system("Pause");
                    //浏览
                }
                else if (choose2 == 5)
                {
                    continue;
                }
            }
            else if (choose1 == 2)
            {
                system("cls");
                fflush(stdin);
                int choose2;
                cout << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                cout << "       			    ____________________________________________________________" << endl;
                cout << "       			   |__________________________";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                cout << "学生数据处理";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                cout << "______________________|" << endl;
                cout << "       		   	   |                						|" << endl;
                cout << "       			   |                						|" << endl;
                cout << "       			   |                						|" << endl;
                cout << "       			   |             1.录入学生成绩并计算考试成绩及其名次           |" << endl;
                cout << "       			   |            2.测评数据输入并计算综合测评总分及名次          |" << endl;
                cout << "       			   |                         3.学生数据管理 			|" << endl;
                cout << "       			   |                         4.学生数据查询 			|" << endl;
                cout << "       			   |                      5.查询最高分和平均分 			|" << endl;
                cout << "       		   	   |                         6.返回上一级			|" << endl;
                cout << "       			   |                						|" << endl;
                cout << "       			   |____________________________________________________________|" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << "					   	    输入指令：";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                scanf("%d", &choose2);
                if (choose2 == 1)
                {
                    for (int i = 0; i < student::stu_num; i++)
                    {
                        //输入语数英成绩输出排名和均分
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                        cout << "					   	       " << stu[i].name << endl;
                        float chinese_score;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    语文成绩：";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        scanf("%f", &chinese_score);
                        cout << "\n";
                        float math_score;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    数学成绩：";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        scanf("%f", &math_score);
                        cout << "\n";
                        float english_score;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    英语成绩：";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        scanf("%f", &english_score);
                        cout << "\n";
                        stu[i].loadscore(chinese_score, math_score, english_score);
                        stu[i].cal_scores();
                    }
                    for (int i = 0; i < student::stu_num; i++)
                    {
                        get_score_rank_by_i(i);
                        get_compre_eval_rank_by_i(i);
                    }
                }
                else if (choose2 == 2)
                {
                    //输入测评数据输入并计算综合测评总分及名次
                    for (int i = 0; i < student::stu_num; i++)
                    {
                        //输入语数英成绩输出排名和均分
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                        cout << "					   	       " << stu[i].name << endl;
                        float stu_ex_score;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    同学互评分：";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        scanf("%f", &stu_ex_score);
                        cout << "\n";
                        float mor_score;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    品德成绩：";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        scanf("%f", &mor_score);
                        cout << "\n";
                        float tea_score;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    任课老师评分：";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        scanf("%f", &tea_score);
                        cout << "\n";
                        stu[i].load_compre_eval(stu_ex_score, mor_score, tea_score);
                        stu[i].cal_compre_eval();
                    }
                    for (int i = 0; i < student::stu_num; i++)
                    {
                        get_score_rank_by_i(i);
                        get_compre_eval_rank_by_i(i);
                    }
                }
                else if (choose2 == 3)
                {
                    //输入学号，读出并显示该同学信息，输入新数据，将改后信息写入文件
                    int uuid;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	  输入UUID修改：";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%d", &uuid);
                    // student *S = search(uuid);
                    int stui = searchbyi(uuid);
                    cout << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					uuid：" << stu[stui].uuid << "  name:" << stu[stui].name << endl;
                    // int uuid;
                    float chinese_score;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    语文成绩：";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%f", &chinese_score);
                    cout << "\n";
                    float math_score;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    数学成绩：";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%f", &math_score);
                    cout << "\n";
                    float english_score;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    英语成绩：";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%f", &english_score);
                    cout << "\n";
                    stu[stui].loadscore(chinese_score, math_score, english_score);
                    stu[stui].cal_scores();
                    float stu_ex_score;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    同学互评分：";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%f", &stu_ex_score);
                    cout << "\n";
                    float mor_score;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    品德成绩：";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%f", &mor_score);
                    cout << "\n";
                    float tea_score;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    任课老师评分：";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%f", &tea_score);
                    cout << "\n";
                    stu[stui].load_compre_eval(stu_ex_score, mor_score, tea_score);
                    stu[stui].cal_compre_eval();
                    for (int i = 0; i < student::stu_num; i++)
                    {
                        get_score_rank_by_i(i);
                        get_compre_eval_rank_by_i(i);
                    }
                }
                else if (choose2 == 4)
                {
                    //输入学号或其他信息，即读出所有数据信息，并显示出来
                    int uuid;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    uuid to search:";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%d", &uuid);
                    student *S = search(uuid);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout
                        << "学号"
                        << "\t"
                        << "姓名"
                        << "\t"
                        << "性别"
                        << "\t"
                        << "地址"
                        << "\t"
                        << "电话";
                    cout << "\t"
                         << "数学"
                         << "\t"
                         << "语文"
                         << "\t"
                         << "英语"
                         << "\t"
                         << "成绩"
                         << "\t"
                         << "成绩";
                    cout << "\t"
                         << "同学"
                         << "\t"
                         << "品德"
                         << "\t"
                         << "老师";
                    cout << "\t"
                         << "综合"
                         << "\t"
                         << "综合" << endl;
                    cout << "\t\t\t\t\t成绩\t成绩\t成绩\t"
                         << "均分"
                         << "\t"
                         << "排名\t互评\t成绩\t评分\t均分\t排名" << endl;
                    cout << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    cout << "  " << S->uuid;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                    cout << "\t" << S->name;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << "\t" << Sexout[S->sex] << "\t" << S->address << "\t" << S->tel << "\t" << S->math_grade << "\t" << S->chinese_grade << "\t" << S->english_grade << "\t" << S->scores << "\t" << S->scores_rank << "\t" << S->stu_exch_score << "\t" << S->mod_score << "\t" << S->tea_off_score << "\t" << S->compre_eval << "\t" << S->compre_eval_rank << endl;
                    system("pause");
                }
                else if (choose2 == 6)
                {
                    continue;
                }
                else if (choose2 == 5)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                    cout << "					   	      最高分" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t语文  uuid:" << student::chinese_max_i << "\t成绩:" << student::chinese_max << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t数学  uuid:" << student::math_max_i << "\t成绩:" << student::math_max << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t英语  uuid:" << student::english_max_i << "\t成绩:" << student::english_max << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t总分  uuid:" << student::score_max_i << "\t成绩:" << student::score_max << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t综合  uuid:" << student::compre_eval_max_i << "\t成绩:" << student::compre_eval_max << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                    cout << endl << "					   	      平均分" << endl;
                    float ave_chi = get_ave_chinese_score();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t语文平均分：" << ave_chi << endl;
                    float ave_mat = get_ave_math_score();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t数学平均分：" << ave_mat << endl;
                    float ave_eng = get_ave_english_score();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t英语平均分：" << ave_eng << endl;
                    float ave_sc = get_ave_scores();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t总分平均分：" << ave_sc << endl;
                    float ave_fu_sc = get_ave_full_scores();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t综合平均分: " << ave_fu_sc << endl;
                    system("Pause");
                }
            }
            else if (choose1 == 3)
            {
                ofstream input("out.txt", fstream::out);
                for (int n = 0; n < student::stu_num; n++)
                {
                    input << stu[n].uuid << " " << stu[n].name << " " << stu[n].sex << " " << stu[n].address << " " << stu[n].tel << " ";
                    input << stu[n].math_grade << " " << stu[n].chinese_grade << " " << stu[n].english_grade << " " << stu[n].scores << " " << stu[n].scores_rank << " ";
                    input << stu[n].stu_exch_score << " " << stu[n].mod_score << " " << stu[n].tea_off_score << " " << stu[n].compre_eval << " " << stu[n].compre_eval_rank << endl;
                }
                input.close();

                cout << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << "					   	    输出  ---> out.txt" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

                show_all();
                system("pause");
                // freopen("out.txt", "w", stdout);
                // show_all();
                // freopen("con", "w", stdout);
                // cin.clear();
            }
            else if (choose1 == 4)
            {
                _boolUserLogin = false;
                break;
            }
            else
            {
                cout << "输入错误，请重新输入" << endl;
            }
        }
    }
    return 0;
}
