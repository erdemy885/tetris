#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;
int num=0;
int level;
int counter;
int score=0;
int x0=10, y0=0, x1, x2, x3, x4, y1, y2, y3, y4;
int tetromino;
const int width=21;
const int height=20;
char field[19][19];
char cement[19][19];
int pos=0;
char full[19];
bool game0ver;
void Setup()
{
    game0ver=false;
    counter=0;
    level=0;
    tetromino=rand()%7;
    for (int i=0; i<20; ++i)
    {
        for(int j=0; j<20; j++)
        {
            if(j==10)
                field[i][j]=char(177);
            field[i][j]=' ';
        }
    }

}
void Draw()
{
    system("cls");
    for(int i=0; i<width; ++i)
    {
        cout<<char(220);
    }
    cout<<"\n";
    for(int i=0; i<height; ++i)
    {
        for(int j=0; j<width; ++j)
        {
            if(x1==j && y1==i || x2==j && y2==i || x3==j && y3==i || x4==j && y4==i)
            {
                cout<<char(177);


            }
            else if(j==0)
                cout<<char(221);
            else if(j==width-1)
                cout<<char(222);
            else
            {
                cout<<field[i][j];

            }
        }
        cout<<endl;
    }
    for(int i=0; i<width; ++i)
    {
        cout<<char(223);
    }
    cout<<"\nScore:"<<score;

}
void Input()
{
        if(_kbhit())
    {
        switch(_getch())
        {
        case 'a':
        if(x1!=1 && x2!=1 && x3!=1 && x4!=1 && field[y1][x1-1]==' ' && field[y2][x2-1]==' ' && field[y3][x3-1]==' ' && field[y4][x4-1]==' ')
        {
            x0--;
        }
            break;
        case 'd':
        if(x1!=19 && x2!=19 && x3!=19 && x4!=19 && field[y1][x1+1]==' ' && field[y2][x2+1]==' ' && field[y3][x3+1]==' ' && field[y4][x4+1]==' ')
        {
            x0++;
        }
            break;
        case ' ':
            ++pos;
            break;
        case 's':
            if(field[y1+1][x1]==' ' && field[y2+1][x2]==' ' && field[y3+1][x3]==' ' && field[y4+1][x4]==' ' && y1!=19 && y2!=19 && y3!=19 && y4!=19)
            {
                ++y0;
            }
            break;
        case 'x':
            game0ver = true;
            break;
        }
    }
}
void Game()
{
    for (int i=0; i<19; ++i)
    {
        if(field[0][i]==char(177))
        {
            game0ver=true;
            break;
        }
    }
}

void Piece()
{
    if(tetromino==0)
    {
        if (pos%2==0)
        {
            x1=x0;
            y1=y0;
            x2=x1+1;
            y2=y1;
            x3=x2+1;
            y3=y1;
            x4=x3+1;
            y4=y1;


        }
        if (pos%2==1)
        {
            y1=y0;x1=x0;y2=y1+1;x2=x1;y3=y2+1;x3=x1;y4=y3+1;x4=x1;


        }
    }

    if(tetromino==1)
    {
    if (pos%4==0){
    x1=x0;
    y1=y0;
    x2=x1-1;
    y2=y1+1;
    x3=x1;
    y3=y2;
    x4=x1+1;
    y4=y2;}
    else if(pos%4==1)
    {
        x1=x0;
        y1=y0;
        x2=x1-1;
        y2=y1-1;
        x3=x1-1;
        y3=y1;
        x4=x1-1;
        y4=y1+1;
    }
    else if (pos%4==2)
    {
        x1=x0;
        y1=y0;
        x2=x1+1;
        y2=y1-1;
        x3=x2-1;
        y3=y2;
        x4=x3-1;
        y4=y2;
    }
    else if(pos%4==3)
    {
        x1=x0;
        y1=y0;
        x2=x1+1;
        y2=y1;
        x3=x2;
        y3=y2-1;
        x4=x2;
        y4=y2+1;
    }

    }
    if(tetromino==2)
    {
        x1=x0;
        y1=y0;
        x2=x1+1;
        y2=y1;
        x3=x1;
        y3=y1+1;
        x4=x1+1;
        y4=y3;
    }
    if (tetromino==3)
    {
        if(pos%2==0)
        {
            x1=x0;
            y1=y0;
            x2=x1-1;
            y2=y1;
            x3=x2;
            y3=y1+1;
            x4=x3-1;
            y4=y3;
        }
        if(pos%2==1)
        {
            x1=x0;
            y1=y0;
            x2=x1;
            y2=y1+1;
            x3=x1+1;
            y3=y2;
            x4=x3;
            y4=y3+1;
        }
    }
    if (tetromino==4)
    {
        if(pos%2==0)
        {
            x1=x0;
            y1=y0;
            x2=x1+1;
            y2=y1;
            x3=x2;
            y3=y2+1;
            x4=x3+1;
            y4=y3;
        }
        if(pos%2==1)
        {
            x1=x0;
            y1=y0;
            x2=x1;
            y2=y1+1;
            x3=x1-1;
            y3=y2;
            x4=x3;
            y4=y3+1;
        }
    }
    if(tetromino==5)
    {
        if(pos%4==0)
        {
            x1=x0;
            y1=y0;
            x2=x1;
            y2=y1+1;
            x3=x2+1;
            y3=y2;
            x4=x3+1;
            y4=y2;
        }
        if(pos%4==1)
        {
            x1=x0;
            y1=y0;
            x2=x1-1;
            y2=y1;
            x3=x2;
            x4=x2;
            y3=y2+1;
            y4=y3+1;
        }
        if(pos%4==2)
        {
            x1=x0;
            y1=y0;
            x2=x1;
            y2=y1-1;
            x3=x2-1;
            y3=y2;
            y4=y2;
            x4=x3-1;
        }
        if(pos%4==3)
        {
            x1=x0;
            x2=x1+1;
            x3=x2;
            x4=x2;
            y1=y0;
            y2=y1;
            y3=y2-1;
            y4=y3-1;


        }

    }
    if(tetromino==6)
    {
        if(pos%4==0)
        {
            x1=x0;
            y1=y0;
            x2=x1;
            y2=y1+1;
            y3=y2;
            y4=y2;
            x3=x2-1;
            x4=x3-1;
        }
        if(pos%4==1)
        {
            x1=x0;
            y1=y0;
            x2=x1-1;
            y2=y1;
            x3=x2;
            x4=x2;
            y3=y2-1;
            y4=y3-1;
        }
        if(pos%4==2)
        {
            x1=x0;
            y1=y0;
            x2=x1;
            y2=y1-1;
            y3=y2;
            y4=y2;
            x3=x2+1;
            x4=x3+1;
        }
        if(pos%4==3)
        {
            x1=x0;
            y1=y0;
            x2=x1+1;
            y2=y1;
            x3=x2;
            x4=x2;
            y3=y1+1;
            y4=y3+1;
        }
    }

if(field[y1][x1]==char(177) || field[y2][x2]==char(177) || field[y3][x3]==char(177) || field[y4][x4]==char(177) || x1==0 || x2==0 || x3==0 || x4==0 || x1==20 || x2==20 || x3==20 || x4==20 || y1==20 || y2==20 || y3==20 || y4==20){pos--;}

}
void Move()
{

        if(field[y1+1][x1]==' ' && field[y2+1][x2]==' ' && field[y3+1][x3]==' ' && field[y4+1][x4]==' ' && y1!=19 && y2!=19 && y3!=19 && y4!=19)
        {
            ++y0;
        }
        else
        {
            field[y1][x1]=char(177);
            field[y2][x2]=char(177);
            field[y3][x3]=char(177);
            field[y4][x4]=char(177);
            tetromino=rand()%7;
            x0=10;
            y0=0;
            pos=0;
            for (int i=19; i>0; --i)
            {
                if (field[i][1]==char(177) && field[i][2]==char(177) && field[i][3]==char(177) && field[i][4]==char(177) && field[i][5]==char(177) && field[i][6]==char(177) && field[i][7]==char(177) && field[i][8]==char(177) && field[i][9]==char(177) && field[i][10]==char(177) && field[i][11]==char(177) && field[i][12]==char(177) && field[i][13]==char(177) && field[i][14]==char(177) && field[i][15]==char(177) && field[i][16]==char(177) && field[i][17]==char(177) && field[i][18]==char(177) && field[i][19]==char(177))
                {


                        for (int x=19; x>0; x--)
                        {
                            for (int j=1; j<=19; j++)
                            {
                                field[x][j]=field[x-1][j];
                            }

                        }
                        i++;
                        counter++;




                }
            }

        }
}
void Score()
{
    if (counter==1)
    {


            score=score+100;

    }
    if (counter==2)
    {

            score=score+300;

    }
    if (counter==3)
    {


            score=score+600;

    }
    if (counter==4)
    {


            score=score+1000;

    }
    counter=0;
}
int main()
{
    Setup();
    while(!game0ver)
    {
        Sleep(500);
        Score();
        Input();
        Piece();
        Piece();
        Input();
        Piece();
        Piece();
        Input();
        Piece();
        Piece();
        Move();
        Draw();
        Game();
        Piece();
        Piece();


    }
    return 0;
}
