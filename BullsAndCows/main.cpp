
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
    srand(static_cast<unsigned int>(time(nullptr))); // 중복된 수는 안넣는다고 가정

    for (int i = 0; i < Num; ++i)
    {
        int tmp = (rand() % 9) + 1;
        RndBoard[i] = tmp;

        for (int j = 0; j < i; ++j)
        {

            if (RndBoard[j] == tmp)
            { //중복 검사
                --i;
                break;
            }
        }
    }

    cout << "맞춰야할 숫자 갯수 : " << Num << '\n';

    /*  cout << "맞춰야할 숫자: ";
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
            cout << Clear - Score << "점 만 더 얻으면 클리어 입니다" << '\n';
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
        cout << "숫자를 입력 하세요!! " << '\n' << "남은 Life :" << (Life - cnt) << '\n';
        ++cnt;

    }
    string MyNum;
    cin >> MyNum;
    int IntNum = stoi(MyNum);

    for (int i = Num - 1; i >= 0; --i)
    { //일의 자리수부터 들어가므로 끝부터 처음까지 넣어준다
        MyBoard[i] = IntNum % 10;
        IntNum /= 10;

    }
}

void Check()
{       //위치와 숫자가 같으면 Strike 
        // 위치는 다르지만 숫자가 존재하면 Ball 
        // 숫자가 없으면 Out
    Out = Num;
    Strike = 0;
    Ball = 0;

    for (int i = 0; i < Num; ++i)
    {
        if (RndBoard[i] == MyBoard[i])
        { //Strike 체크 
            ++Strike;
        }

        for (int j = 0; j < Num; ++j)
        { //Ball 체크
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


    /*   cout << "a " << a << '\n';*/ // 거짓정보를 주는 타이밍 언제 몇번을 줄지는 random 최대 MaxLie번까지
    if (Lie < MaxLie) // 단점 거짓정보를 줬을때 Out이 무조건 +가 된다 (수정사항)
    {
        ++Lie;
        if (cnt == a)
        {
            if (Ball > (rand() % 2) + 1)
            {
                Ball--;
                //cout << "거짓정보" << '\n';
            }
            if (Strike > (rand() % 2) + 1)
            {
                //cout << "거짓정보" << '\n';
                Strike--;
            }
        }

    }

    Out -= (Ball + Strike);// Num에서 볼과 스트라이크 수를 빼주면 아웃이 나온다


    cout << "Strike = " << Strike << '\n';
    cout << "Ball = " << Ball << '\n';
    cout << "Out = " << Out << '\n';
}

int main()
{
    cout << "남은 라이프만큼 점수를 얻습니다" << '\n';
    cout << Clear << "점을 획득하면 Clear 입니다" << '\n';
    cout << "거짓말을 최대: " << MaxLie << "번 합니다" << '\n';

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