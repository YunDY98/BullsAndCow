
#include <iostream>
#include <string>

#define Num 3
#define Life 10
#define Clear 10
#define MaxLie 3

using namespace std;

int Out = Num;
int Strike = 0;
int Ball = 0;
int cnt = 0;
int Score = 0;
int RndBoard[Num];
int MyBoard[Num];
int Lie = 0;



void RandNum()
{
    srand(static_cast<unsigned int>(time(nullptr))); // �ߺ��� ���� �ȳִ´ٰ� ����

    for (int i = 0; i < Num; ++i)
    {
        int tmp = (rand() % 9) + 1;
        RndBoard[i] = tmp;

        for (int j = 0; j < i; ++j)
        {

            if (RndBoard[j] == tmp)
            { //�ߺ� �˻�
                --i;
                break;
            }
        }
    }

    cout << "������� ���� ���� : " << Num << '\n';

    /*  cout << "������� ����: ";
      for (int i = 0; i < Num; ++i)
      {
          cout << RndBoard[i];
      }
      cout << '\n';*/

}


void GameOver()
{
    if (cnt == Life)
    {
        cout << "GameOver" << '\n';

    }

    if (Strike == Num)
    {

        Score += Life - cnt + 1;
        cout << "Score = " << Score << '\n';
        if (Clear > Score)
        {
            cout << Clear - Score << "�� �� �� ������ Ŭ���� �Դϴ�" << '\n';
        }
    }
    if (Score >= Clear)
    {
        cout << "Clear" << '\n';
    }


}

void MyNum()
{
    if (Strike != 3)
    {
        cout << "���ڸ� �Է� �ϼ���!! " << '\n' << "���� Life :" << (Life - cnt) << '\n';
        ++cnt;

    }
    string MyNum;
    cin >> MyNum;
    int IntNum = stoi(MyNum);

    for (int i = Num - 1; i >= 0; --i)
    { //���� �ڸ������� ���Ƿ� ������ ó������ �־��ش�
        MyBoard[i] = IntNum % 10;
        IntNum /= 10;

    }
}

void Check()
{       //��ġ�� ���ڰ� ������ Strike 
        // ��ġ�� �ٸ����� ���ڰ� �����ϸ� Ball 
        // ���ڰ� ������ Out
    Out = Num;
    Strike = 0;
    Ball = 0;

    for (int i = 0; i < Num; ++i)
    {
        if (RndBoard[i] == MyBoard[i])
        { //Strike üũ 
            ++Strike;
        }

        for (int j = 0; j < Num; ++j)
        { //Ball üũ
            if (RndBoard[i] == MyBoard[j])
            {
                if (RndBoard[i] != MyBoard[i])
                {
                    ++Ball;
                }
            }
        }
    }

    int a = (rand() % 9) + 1;


    /*   cout << "a " << a << '\n';*/ // ���������� �ִ� Ÿ�̹� ���� ����� ������ random �ִ� MaxLie������
    if (Lie < MaxLie) // ���� ���������� ������ Out�� ������ +�� �ȴ� (��������)
    {
        ++Lie;
        if (cnt == a)
        {
            if (Ball > (rand() % 2) + 1)
            {
                Ball--;
                //cout << "��������" << '\n';
            }
            if (Strike > (rand() % 2) + 1)
            {
                //cout << "��������" << '\n';
                Strike--;
            }
        }

    }

    Out -= (Ball + Strike);// Num���� ���� ��Ʈ����ũ ���� ���ָ� �ƿ��� ���´�


    cout << "Strike = " << Strike << '\n';
    cout << "Ball = " << Ball << '\n';
    cout << "Out = " << Out << '\n';
}

int main()
{
    cout << "���� ��������ŭ ������ ����ϴ�" << '\n';
    cout << Clear << "���� ȹ���ϸ� Clear �Դϴ�" << '\n';
    cout << "�������� �ִ�: " << MaxLie << "�� �մϴ�" << '\n';

    while (Score < Clear && cnt != Life)
    {
        Strike = 0;
        cnt = 0;
        RandNum();

        while ((Strike != 3) && (cnt != Life))
        {
            MyNum();

            Check();

            GameOver();

            cout << '\n';
        }
    }

    return 0;
}