#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <windows.h>
#include <string>
#include <conio.h>
#define MAXN 999999
using namespace std;
struct Users
{ //�û�����
    string UserName;
    string Telephone;
    string PassWord;
};
bool _boolUserLogin = false; //ȷ���û���¼״̬

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
{ //*����
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
            if (single == 13) //�س�
            {
                fflush(stdin);
                if (Lenth == 0)
                {

                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << endl;
                    cout << "				      		   ��������Ϊ�գ�" << endl;
                    Sleep(300);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "				      		   ���������룺";
                    continue;
                }
                else
                {
                    //�г��ȵ�����
                    break; //�س���
                }
            }
            else if (single == 8)
            { //�˸�
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
            cout << "				      		   �Ƿ��ַ���" << endl;
            Sleep(300);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		   �������룺";
        }
    } while (_KeyProblem); //�Ƿ�����������
    return temp;
}

void _Register()
{ //ע��
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "				      		   WELCOME TO REGISTER!" << endl;

    Users x, y; //yΪ��������
    FILE *fp;   //�ж��ļ��Ƿ����
    string PassWordAgain;
    Sleep(200);
    if ((fp = fopen("users.txt", "rb+")) == NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "				      		   ���������ļ�!" << endl;
        Sleep(500);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "				      		   �������û�����"; //�����ļ���ֱ��ע������
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cin >> x.UserName;
        if ((fp = fopen("users.txt", "wb+")) == NULL)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		   �����ļ�����" << endl;
            fclose(fp);
            exit(0);
        }
    }
    else //�ļ��Ѵ��ڣ����ж��û����Ƿ��غ�
    {
        fclose(fp);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "				      		   �������û���:";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        cin >> x.UserName;
        ifstream output("users.txt");
        output >> y.UserName;
        output >> y.Telephone;
        output >> y.PassWord;
        do //�ж��Ƿ��ظ��û���
        {
            if (x.UserName != y.UserName) //�ж��Ƿ�
            {
                if (!output.eof()) //��δ�������ļ�ĩβ
                {
                    output >> y.UserName;
                    output >> y.Telephone;
                    output >> y.PassWord;
                }
                else //һֱ���ļ�����Ҳû���ҵ���ͬ�û���
                {
                    break;
                }
            }
            else //�ҵ���ͬ�û���
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << "				      		   ���û����ѱ�ע�ᣡ";
                Sleep(500);
                output.close();
                return;
            }
        } while (1);
        output.close();
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "				      		   ������绰���룺"; //�绰����
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cin >> x.Telephone;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "				      		   ���������룺";
    x.PassWord = getpassword();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "				      		   ���ٴ�ȷ�����룺";
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
            cout << "				      		   ע��ɹ�" << endl;
            Sleep(500);
            cout << "				      		   �������ص�¼���棡";
            Sleep(1000);
            input.close();
            return;
        }
        else
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		   �����������벻һ��" << endl;
            cout << "				      		   ����������:";
            x.PassWord = getpassword();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		   ���ٴ�ȷ�����룺";
            PassWordAgain = getpassword();
        }
    } while (1);
}

void _UserLogin()
{               //��¼
    Users m, n; //nΪ��������

    FILE *fp;
    if ((fp = fopen("users.txt", "r")) == NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << endl;
        cout << "				      		   ��δ���û�ע�ᣡ" << endl;
        cout << "				      	  	      �������أ�" << endl;
        Sleep(500);
        fclose(fp);
        return;
    }
    fclose(fp);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "				      		   �������û�����";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cin >> m.UserName;
    ifstream output("users.txt");
    output >> n.UserName;
    output >> n.Telephone;
    output >> n.PassWord;

    do
    {
        if (m.UserName == n.UserName) //�ж��Ƿ�ע��
        {
            break; //�����������
        }
        else
        {
            if (!output.eof())
            { //һֱ�����ļ�ĩβ
                output >> n.UserName;
                output >> n.Telephone;
                output >> n.PassWord;
            }
            else
            { //
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << "				      		   ���û���δע�ᣡ" << endl;
                cout << "				         	  �������س�ʼ����";
                Sleep(600);
                output.close();
                return;
            }
        }
    } while (1);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "				      		   ���������룺";
    m.PassWord = getpassword();
    do
    {
        if (m.PassWord == n.PassWord)
        {
            _boolUserLogin = true; //������ȷ
            output.close();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout << "				      	  	     ��¼�ɹ���" << endl;
            printf("				            ��������ɼ��ۺ�ѧ������ϵͳ");
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
            cout << "�����¼";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout << "_________________________|" << endl;
            cout << "       		   	   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |                         1.�������� 			|" << endl;
            cout << "       			   |                         2.���ؽ��� 			|" << endl;
            cout << "       		   	   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |____________________________________________________________|" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		   ��һ��ָ�";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            cin >> _try;
            if (_try == 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                printf("				      		   ���������룺");
                m.PassWord = getpassword();
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                printf("				      		   �������أ�\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                Sleep(600);
                output.close();
                return;
            }
        }
    } while (1);
}

void _ChangeKey()
{ //�޸�����
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
    cout << "				      		  �������û�����";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cin >> a.UserName;
    cout << endl;
    int ScanOld = 0;
    do //�ж��Ƿ��ظ��û���
    {
        if (a.UserName == CopyOld[ScanOld].UserName) //�ж��Ƿ�
        {
            //�ҵ���ͬ�û���;
            break;
        }
        ScanOld++;
        if (ScanOld > i)
        { //δ�ҵ�
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		   �û���������" << endl;
            Sleep(500);
            cout << "				      		      �������أ�";
            Sleep(500);
            return;
        }
    } while (1);

    int _check = 0;
    string CheckTele;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout << "				      		  ������绰���룺";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cin >> CheckTele;
    cout << endl;
    do
    {
        if (CheckTele == CopyOld[ScanOld].Telephone)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		  �޸����룺";
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
            cout << "				      		  �޸ĳɹ���" << endl;
            cout << endl;
            cout << "				      		  �������س�ʼ���棡" << endl;
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
            cout << "�����޸�";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout << "_________________________|" << endl;
            cout << "       		   	   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |                         1.�������� 			|" << endl;
            cout << "       			   |                         2.���ؽ��� 			|" << endl;
            cout << "       		   	   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |____________________________________________________________|" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "				      		   ��һ��ָ�";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            cin >> _check;
            if (_check == 1)
            {
                cout << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << "				      		  ������绰���룺";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                cin >> CheckTele;
                cout << endl;
            }
            else
            {
                cout << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << "				      		  �������أ�" << endl;
                Sleep(500);
                return;
            }
        }
    } while (1);
    delete[] CopyOld;
}

string Sexout[3] = {"Ů", "��"};

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
        << "ѧ��"
        << "\t"
        << "����"
        << "\t"
        << "�Ա�"
        << "\t"
        << "��ַ"
        << "\t"
        << "�绰";
    cout << "\t"
         << "��ѧ"
         << "\t"
         << "����"
         << "\t"
         << "Ӣ��"
         << "\t"
         << "�ɼ�"
         << "\t"
         << "�ɼ�";
    cout << "\t"
         << "ͬѧ"
         << "\t"
         << "Ʒ��"
         << "\t"
         << "��ʦ";
    cout << "\t"
         << "�ۺ�"
         << "\t"
         << "�ۺ�" << endl;
    cout << "\t\t\t\t\t�ɼ�\t�ɼ�\t�ɼ�\t"
         << "����"
         << "\t"
         << "����\t����\t�ɼ�\t����\t����\t����" << endl;
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
                    cout << "��ӭ��¼�ۺϳɼ�����ϵͳ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << "_________________|" << endl;
                    cout << "       		   	   |                						|" << endl;
                    cout << "       			   |                						|" << endl;
                    cout << "       			   |                						|" << endl;
                    cout << "       			   |                         1.ע���˺� 			|" << endl;
                    cout << "       			   |                         2.�˺ŵ�½ 			|" << endl;
                    cout << "       			   |                         3.�����޸� 			|" << endl;
                    cout << "       			   |                         4.�˳�ϵͳ 			|" << endl;
                    cout << "       		   	   |                						|" << endl;
                    cout << "       			   |                						|" << endl;
                    cout << "       			   |____________________________________________________________|" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    ����ָ�";
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
                            cout << "					   	  ��δ���û�ע�ᣡ" << endl;
                            cout << "					   	      �������أ�" << endl;
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
                        cout << "					   	 ȷ���˳�(Y/N):";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        cin >> _QuitChoice;
                        if (_QuitChoice == 'Y' || _QuitChoice == 'y')
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                            cout << "					     �����˳�����ӭ�´�ʹ�ã�" << endl;
                            Sleep(1000);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                            exit(0);
                        }
                        else
                        {
                            continue;
                        }
                    }
                    cout << "����ָ�����" << endl;
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
            cout << "��ӭ��¼�ۺϳɼ�����ϵͳ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout << "_________________|" << endl;
            cout << "       		   	   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |                         1.ѧ����Ϣ����                     |" << endl;
            cout << "       			   |                         2.ѧ�����ݴ���                     |" << endl;
            cout << "       			   |                         3.ѧ���ۺ���Ϣ���                 |" << endl;
            cout << "       			   |                         4.�˳���¼ 			|" << endl;
            cout << "       		   	   |                						|" << endl;
            cout << "       			   |                						|" << endl;
            cout << "       			   |____________________________________________________________|" << endl;
            int choose1;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "					   	    ����ָ�";
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
                cout << "ѧ����Ϣ����";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                cout << "______________________|" << endl;
                cout << "       		   	   |                						|" << endl;
                cout << "       			   |                						|" << endl;
                cout << "       			   |                						|" << endl;
                cout << "       			   |                         0.�ӿ���̨����                     |" << endl;
                cout << "       			   |                         1.���ļ�����ѧ����Ϣ               |" << endl;
                cout << "       			   |                         2.���루�޸ģ�ͬѧ��Ϣ             |" << endl;
                cout << "       			   |                         3.ɾ��ͬѧ��Ϣ 			|" << endl;
                cout << "       			   |                         4.���ѧ����Ϣ 			|" << endl;
                cout << "       			   |                         5.������һ�� 			|" << endl;
                cout << "       		   	   |                						|" << endl;
                cout << "       			   |                						|" << endl;
                cout << "       			   |____________________________________________________________|" << endl;
                int choose1;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << "					   	    ����ָ�";
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
                        cout << "					   	    ����Ҫ����ô��[Y/N]:";
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
                        //��Ҫ�������룬Ȼ����uuid˳�����(δ���)f
                        change(uuid, name, sex, address, tel);
                    }
                    output.close();
                }
                else if (choose2 == 2)
                { //�޸�

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
                    cout << "					   	 uuid:" << s->uuid << " name��" << s->name << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	 do you want to delete(Y/N):";
                    getchar();
                    char i;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%c", &i);
                    if (i == 'Y' || i == 'y')
                    {
                        deleteit(uuid);
                        cout << "					   	 ɾ���ɹ���" << endl;
                        Sleep(300);
                    }
                    //ɾ��
                }
                else if (choose2 == 4)
                {
                    show_all();
                    system("Pause");
                    //���
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
                cout << "ѧ�����ݴ���";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                cout << "______________________|" << endl;
                cout << "       		   	   |                						|" << endl;
                cout << "       			   |                						|" << endl;
                cout << "       			   |                						|" << endl;
                cout << "       			   |             1.¼��ѧ���ɼ������㿼�Գɼ���������           |" << endl;
                cout << "       			   |            2.�����������벢�����ۺϲ����ּܷ�����          |" << endl;
                cout << "       			   |                         3.ѧ�����ݹ��� 			|" << endl;
                cout << "       			   |                         4.ѧ�����ݲ�ѯ 			|" << endl;
                cout << "       			   |                      5.��ѯ��߷ֺ�ƽ���� 			|" << endl;
                cout << "       		   	   |                         6.������һ��			|" << endl;
                cout << "       			   |                						|" << endl;
                cout << "       			   |____________________________________________________________|" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << "					   	    ����ָ�";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                scanf("%d", &choose2);
                if (choose2 == 1)
                {
                    for (int i = 0; i < student::stu_num; i++)
                    {
                        //��������Ӣ�ɼ���������;���
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                        cout << "					   	       " << stu[i].name << endl;
                        float chinese_score;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    ���ĳɼ���";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        scanf("%f", &chinese_score);
                        cout << "\n";
                        float math_score;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    ��ѧ�ɼ���";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        scanf("%f", &math_score);
                        cout << "\n";
                        float english_score;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    Ӣ��ɼ���";
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
                    //��������������벢�����ۺϲ����ּܷ�����
                    for (int i = 0; i < student::stu_num; i++)
                    {
                        //��������Ӣ�ɼ���������;���
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                        cout << "					   	       " << stu[i].name << endl;
                        float stu_ex_score;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    ͬѧ�����֣�";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        scanf("%f", &stu_ex_score);
                        cout << "\n";
                        float mor_score;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    Ʒ�³ɼ���";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        scanf("%f", &mor_score);
                        cout << "\n";
                        float tea_score;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                        cout << "					   	    �ο���ʦ���֣�";
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
                    //����ѧ�ţ���������ʾ��ͬѧ��Ϣ�����������ݣ����ĺ���Ϣд���ļ�
                    int uuid;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	  ����UUID�޸ģ�";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%d", &uuid);
                    // student *S = search(uuid);
                    int stui = searchbyi(uuid);
                    cout << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					uuid��" << stu[stui].uuid << "  name:" << stu[stui].name << endl;
                    // int uuid;
                    float chinese_score;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    ���ĳɼ���";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%f", &chinese_score);
                    cout << "\n";
                    float math_score;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    ��ѧ�ɼ���";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%f", &math_score);
                    cout << "\n";
                    float english_score;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    Ӣ��ɼ���";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%f", &english_score);
                    cout << "\n";
                    stu[stui].loadscore(chinese_score, math_score, english_score);
                    stu[stui].cal_scores();
                    float stu_ex_score;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    ͬѧ�����֣�";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%f", &stu_ex_score);
                    cout << "\n";
                    float mor_score;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    Ʒ�³ɼ���";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%f", &mor_score);
                    cout << "\n";
                    float tea_score;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    �ο���ʦ���֣�";
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
                    //����ѧ�Ż�������Ϣ������������������Ϣ������ʾ����
                    int uuid;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "					   	    uuid to search:";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    scanf("%d", &uuid);
                    student *S = search(uuid);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout
                        << "ѧ��"
                        << "\t"
                        << "����"
                        << "\t"
                        << "�Ա�"
                        << "\t"
                        << "��ַ"
                        << "\t"
                        << "�绰";
                    cout << "\t"
                         << "��ѧ"
                         << "\t"
                         << "����"
                         << "\t"
                         << "Ӣ��"
                         << "\t"
                         << "�ɼ�"
                         << "\t"
                         << "�ɼ�";
                    cout << "\t"
                         << "ͬѧ"
                         << "\t"
                         << "Ʒ��"
                         << "\t"
                         << "��ʦ";
                    cout << "\t"
                         << "�ۺ�"
                         << "\t"
                         << "�ۺ�" << endl;
                    cout << "\t\t\t\t\t�ɼ�\t�ɼ�\t�ɼ�\t"
                         << "����"
                         << "\t"
                         << "����\t����\t�ɼ�\t����\t����\t����" << endl;
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
                    cout << "					   	      ��߷�" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t����  uuid:" << student::chinese_max_i << "\t�ɼ�:" << student::chinese_max << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t��ѧ  uuid:" << student::math_max_i << "\t�ɼ�:" << student::math_max << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \tӢ��  uuid:" << student::english_max_i << "\t�ɼ�:" << student::english_max << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t�ܷ�  uuid:" << student::score_max_i << "\t�ɼ�:" << student::score_max << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t�ۺ�  uuid:" << student::compre_eval_max_i << "\t�ɼ�:" << student::compre_eval_max << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                    cout << endl << "					   	      ƽ����" << endl;
                    float ave_chi = get_ave_chinese_score();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t����ƽ���֣�" << ave_chi << endl;
                    float ave_mat = get_ave_math_score();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t��ѧƽ���֣�" << ave_mat << endl;
                    float ave_eng = get_ave_english_score();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \tӢ��ƽ���֣�" << ave_eng << endl;
                    float ave_sc = get_ave_scores();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t�ܷ�ƽ���֣�" << ave_sc << endl;
                    float ave_fu_sc = get_ave_full_scores();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout << "			   	       \t�ۺ�ƽ����: " << ave_fu_sc << endl;
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
                cout << "					   	    ���  ---> out.txt" << endl;
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
                cout << "�����������������" << endl;
            }
        }
    }
    return 0;
}
