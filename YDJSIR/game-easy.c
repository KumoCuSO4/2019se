#define _CRT_SECURE_NO_WARNINGS 1
#include"game-easy.h"
char show_mine[row][col] = { 0 };
char real_mine[row][col] = { 0 };


void muen()
{
	system ("CLS");
	printf("Y88b   d88P 8888888b. 888888  d8888b.88888 8888888b.  \n\r");
	printf(" Y88b d88P  888   Y88b  88b d88P      888  888   Y88b  \n\r");
	printf("   Y888     888    888  888   88Y88b. 888  8888888P\n\r");
	printf("  . 888     888    888  888       888 888  888 T88b \n\r");
	printf("  . 888     888  .d88P  88P 88b  d88P 888  888  T88b \n\r");
	printf("    Y88     d88P888     Y88   88bd8  88Y88 888    888  \n\r");
	printf("                     .d88P\n");
	printf("************************************\n");
    printf("****按下键盘对应按键选择对应操作****\n");
	printf("************************************\n");
    printf("***1.Play-开始游戏   0.Exit-退出****\n");
    printf("************************************\n");
}


void init_mine()//初始化两个棋盘
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++) 
    {
        for (j = 0; j < col; j++)
        {
            show_mine[i][j] = '*';
            real_mine[i][j] = '0';
        }
    }
}


void print_player()//打印玩家棋盘
{
    int i = 0;
    int j = 0;
    system ("CLS");
    printf("0  ");
    for (i = 1; i <row-1; i++)
    {
        printf("%d ", i);//打印横标（0--10）
    }
    printf("\n");
    for (i = 1; i <row-2; i++)//打印竖标（1--10）
    {
        printf("%d  ", i);
        for (j = 1; j < col-1; j++)
        {
            printf("%c ", show_mine[i][j]);//玩家棋盘数组
        }
        printf("\n");
    }
    printf("10 ");//开始打印最后一行
    for (i = 1; i < row-1; i++)
    {
        printf("%c ", show_mine[10][i]);
    }
    printf("\n");
}


void print_mine()//打印设计者棋盘
{
    int i = 0;
    int j = 0;
    printf("0  ");
    for (i = 1; i <row - 1; i++)
    {
        printf("%d ", i);//打印横标（0--10）
    }
    printf("\n");
    for (i = 1; i <row - 2; i++)//打印竖标（1--10）
    {
        printf("%d  ", i);
        for (j = 1; j < col - 1; j++)
        {
            
			if(real_mine[i][j]=='0'){
            	printf("  ", real_mine[i][j]);
			}
			else{
				printf("X ", real_mine[i][j]);
			}
			
        }
        printf("\n");
    }
    printf("10 ");//开始打印最后一行
    for (i = 1; i < row - 1; i++)
    {
			if(real_mine[10][i]=='0'){
            	printf("  ", real_mine[10][i]);
			}
			else{
				printf("X ", real_mine[10][i]);
			}
			
    }
    printf("\n");
}



void set_mine()//给设计者棋盘布雷
{
    int x = 0;
    int y = 0;
    int count = COUNT;//雷总数
    while (count)//雷布完后跳出循环
    {
        int x = rand() % 10 + 1;//产生1到10的随机数，在数组下标为1到10的范围内布雷
        int y = rand() % 10 + 1;//产生1到10的随机数，在数组下标为1到10的范围内布雷
        if (real_mine[x][y] == '0')//找不是雷的地方布雷
        {
            real_mine[x][y] = '1';
            count--;
        }
    }
}


int count_mine(int x, int y)//检测周围8个区域雷的个数
{
    int count = 0;
    if (real_mine[x - 1][y - 1] == '1')
        count++;
    if (real_mine[x - 1][y] == '1')
        count++;    
    if (real_mine[x - 1][y + 1] == '1')
        count++;
    if (real_mine[x][y - 1] == '1')
        count++;    
    if (real_mine[x][y + 1] == '1')
        count++;    
    if (real_mine[x + 1][y - 1] == '1')
        count++;    
    if (real_mine[x + 1][y] == '1')
        count++;    
    if (real_mine[x + 1][y + 1] == '1')
        count++;
    return count;
}

void safe_mine()//避免第一次炸死
{
    int x = 0;
    int y = 0;
    char ch = 0;
    int count = 0;
    int ret = 1;
    int operation = 1;
    printf("\n");
    printf("输入坐标扫雷,格式如下：横坐标，纵坐标\n");
    printf("横坐标 纵坐标 操作\n");
    printf("操作 1 = 点开方块\n");
    printf("操作 2 = 标记地雷\n");
        printf("Mines remained 剩余雷数:%d\n",10-count_found_mine());
    while (1)
    {	operation=1;
        scanf("%d%d%d", &x, &y,&operation);//只能输入1到10，输入错误重新输入
        if ((x >= 1 && x <= 10 && operation==1) && (y >= 1 && y <= 10 && operation==1))//判断输入坐标是否有误
        {
            if (real_mine[x][y] == '1')//第一次踩到雷后补救
            {
                real_mine[x][y] = '0';
                char ch = count_mine(x, y);
                show_mine[x][y] = ch + '0';//数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
                open_mine(x, y);
                while (ret)//在其余有空的地方设置一个雷
                {
                    int x = rand() % 10 + 1;//产生1到10的随机数，在数组下标为1到10的范围内布雷
                    int y = rand() % 10 + 1;//产生1到10的随机数，在数组下标为1到10的范围内布雷
                    if (real_mine[x][y] == '0')//找不是雷的地方布雷
                    {
                        real_mine[x][y] = '1';
                        ret--;
                        break;
                    }
                }break;//跳出此函数  
            }
            if (real_mine[x][y] == '0')
            {
                char ch = count_mine(x, y);
                show_mine[x][y] = ch + '0';//数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
                open_mine(x, y);
                break;
            }
        }
    		if((x >= 1 && x <= 10 && operation==2) && (y >= 1 && y <= 10 && operation==2)){
    			show_mine[x][y] = 'X';
    			break;
				}
        else
        {
            printf("输入错误重新输入\n");
        }
        
    }
}


int sweep_mine()//扫雷函数，踩到雷返回1，没有踩到雷返回0
{
    int x = 0;
    int y = 0;
    int count = 0;
     int operation = 1;
    printf("\n");
    printf("输入坐标扫雷,格式如下：横坐标，纵坐标\n");
    printf("横坐标 纵坐标 操作\n");
    printf("操作 1 = 点开方块\n");
    printf("操作 2 = 标记地雷\n");
    printf("Mines remained 剩余雷数:%d\n",10-count_found_mine());
    scanf("%d%d%d", &x, &y,&operation);//只能输入1到10，输入错误重新输入
    if ((x >= 1 && x <= 10 && operation==1) && (y >= 1 && y <= 10 && operation==1))//判断输入坐标是否有误
        {
            if (real_mine[x][y] == '0')//没踩到雷
            {
                char ch = count_mine(x,y);
                show_mine[x][y] = ch+'0';//数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
                open_mine(x, y);
                if (count_show_mine() == COUNT)//判断剩余未知区域的个数，个数为雷数时玩家赢
                {
                    print_mine();
                    printf("玩家赢！\n\n");
                    return 0;
                }
            }
            else if (real_mine[x][y]=='1')//踩到雷
            {
                return 1;
            }
        }
    if((show_mine[x][y]=='*') && (x >= 1 && x <= 10 && operation==2) && (y >= 1 && y <= 10 && operation==2)){
    show_mine[x][y] = 'X';
    return 0;
				}
        else
        {
            printf("Input Error,Please Input again!输入错误重新输入\n");
        }
        
    return 0;//没踩到雷
}



void open_mine(int x, int y)//坐标周围展开函数
{
    if (real_mine[x - 1][y - 1]== '0')
    {
        show_mine[x - 1][y - 1] = count_mine(x - 1, y - 1) + '0';//显示该坐标周围雷数
    }
    if (real_mine[x - 1][y] == '0')
    {
        show_mine[x - 1][y] = count_mine(x - 1, y) + '0';//显示该坐标周围雷数
    }
    if (real_mine[x - 1][y + 1] == '0')
    {
        show_mine[x - 1][y + 1] = count_mine(x - 1, y + 1) + '0';//显示该坐标周围雷数
    }
    if (real_mine[x][y - 1] == '0')
    {
        show_mine[x][y - 1] = count_mine(x, y - 1) + '0';//显示该坐标周围雷数
    }
    if (real_mine[x][y + 1] == '0')
    {
        show_mine[x][y + 1] = count_mine(x, y + 1) + '0';//显示该坐标周围雷数
    }
    if (real_mine[x + 1][y - 1] == '0')
    {
        show_mine[x + 1][y - 1] = count_mine(x + 1, y - 1) + '0';//显示该坐标周围雷数
    }
    if (real_mine[x + 1][y] == '0')
    {
        show_mine[x + 1][y] = count_mine(x + 1, y) + '0';//显示该坐标周围雷数
    }
    if (real_mine[x + 1][y + 1] == '0')
    {
        show_mine[x + 1][y + 1] = count_mine(x + 1, y + 1) + '0';//显示该坐标周围雷数
    }
}


int count_show_mine()//判断剩余未知区域的个数，个数为雷数时玩家赢
{
    int count = 0;
    int i = 0;
    int j = 0;
    for (i = 1; i <= row - 2; i++)
    {
        for (j = 1; j <= col - 2; j++)
        {
            if ((show_mine[i][j] == '*')|| (show_mine[i][j] == 'X'))
            {
                count++;
            }
        }

    }
    return count;
}

int count_found_mine()//计算你已经找出来的雷的个数 
{
    int count = 0;
    int i = 0;
    int j = 0;
    for (i = 1; i <= row - 2; i++)
    {
        for (j = 1; j <= col - 2; j++)
        {
            if (show_mine[i][j] == 'X')
            {
                count++;
            }
        }

    }
    return count;
}
