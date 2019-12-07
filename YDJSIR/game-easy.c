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
    printf("****���¼��̶�Ӧ����ѡ���Ӧ����****\n");
	printf("************************************\n");
    printf("***1.Play-��ʼ��Ϸ   0.Exit-�˳�****\n");
    printf("************************************\n");
}


void init_mine()//��ʼ����������
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


void print_player()//��ӡ�������
{
    int i = 0;
    int j = 0;
    system ("CLS");
    printf("0  ");
    for (i = 1; i <row-1; i++)
    {
        printf("%d ", i);//��ӡ��꣨0--10��
    }
    printf("\n");
    for (i = 1; i <row-2; i++)//��ӡ���꣨1--10��
    {
        printf("%d  ", i);
        for (j = 1; j < col-1; j++)
        {
            printf("%c ", show_mine[i][j]);//�����������
        }
        printf("\n");
    }
    printf("10 ");//��ʼ��ӡ���һ��
    for (i = 1; i < row-1; i++)
    {
        printf("%c ", show_mine[10][i]);
    }
    printf("\n");
}


void print_mine()//��ӡ���������
{
    int i = 0;
    int j = 0;
    printf("0  ");
    for (i = 1; i <row - 1; i++)
    {
        printf("%d ", i);//��ӡ��꣨0--10��
    }
    printf("\n");
    for (i = 1; i <row - 2; i++)//��ӡ���꣨1--10��
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
    printf("10 ");//��ʼ��ӡ���һ��
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



void set_mine()//����������̲���
{
    int x = 0;
    int y = 0;
    int count = COUNT;//������
    while (count)//�ײ��������ѭ��
    {
        int x = rand() % 10 + 1;//����1��10����������������±�Ϊ1��10�ķ�Χ�ڲ���
        int y = rand() % 10 + 1;//����1��10����������������±�Ϊ1��10�ķ�Χ�ڲ���
        if (real_mine[x][y] == '0')//�Ҳ����׵ĵط�����
        {
            real_mine[x][y] = '1';
            count--;
        }
    }
}


int count_mine(int x, int y)//�����Χ8�������׵ĸ���
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

void safe_mine()//�����һ��ը��
{
    int x = 0;
    int y = 0;
    char ch = 0;
    int count = 0;
    int ret = 1;
    int operation = 1;
    printf("\n");
    printf("��������ɨ��,��ʽ���£������꣬������\n");
    printf("������ ������ ����\n");
    printf("���� 1 = �㿪����\n");
    printf("���� 2 = ��ǵ���\n");
        printf("Mines remained ʣ������:%d\n",10-count_found_mine());
    while (1)
    {	operation=1;
        scanf("%d%d%d", &x, &y,&operation);//ֻ������1��10�����������������
        if ((x >= 1 && x <= 10 && operation==1) && (y >= 1 && y <= 10 && operation==1))//�ж����������Ƿ�����
        {
            if (real_mine[x][y] == '1')//��һ�βȵ��׺󲹾�
            {
                real_mine[x][y] = '0';
                char ch = count_mine(x, y);
                show_mine[x][y] = ch + '0';//���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCIIֵ
                open_mine(x, y);
                while (ret)//�������пյĵط�����һ����
                {
                    int x = rand() % 10 + 1;//����1��10����������������±�Ϊ1��10�ķ�Χ�ڲ���
                    int y = rand() % 10 + 1;//����1��10����������������±�Ϊ1��10�ķ�Χ�ڲ���
                    if (real_mine[x][y] == '0')//�Ҳ����׵ĵط�����
                    {
                        real_mine[x][y] = '1';
                        ret--;
                        break;
                    }
                }break;//�����˺���  
            }
            if (real_mine[x][y] == '0')
            {
                char ch = count_mine(x, y);
                show_mine[x][y] = ch + '0';//���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCIIֵ
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
            printf("���������������\n");
        }
        
    }
}


int sweep_mine()//ɨ�׺������ȵ��׷���1��û�вȵ��׷���0
{
    int x = 0;
    int y = 0;
    int count = 0;
     int operation = 1;
    printf("\n");
    printf("��������ɨ��,��ʽ���£������꣬������\n");
    printf("������ ������ ����\n");
    printf("���� 1 = �㿪����\n");
    printf("���� 2 = ��ǵ���\n");
    printf("Mines remained ʣ������:%d\n",10-count_found_mine());
    scanf("%d%d%d", &x, &y,&operation);//ֻ������1��10�����������������
    if ((x >= 1 && x <= 10 && operation==1) && (y >= 1 && y <= 10 && operation==1))//�ж����������Ƿ�����
        {
            if (real_mine[x][y] == '0')//û�ȵ���
            {
                char ch = count_mine(x,y);
                show_mine[x][y] = ch+'0';//���ֶ�Ӧ��ASCIIֵ�������ַ���Ӧ��ASCIIֵ���48����'0'��ASCIIֵ
                open_mine(x, y);
                if (count_show_mine() == COUNT)//�ж�ʣ��δ֪����ĸ���������Ϊ����ʱ���Ӯ
                {
                    print_mine();
                    printf("���Ӯ��\n\n");
                    return 0;
                }
            }
            else if (real_mine[x][y]=='1')//�ȵ���
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
            printf("Input Error,Please Input again!���������������\n");
        }
        
    return 0;//û�ȵ���
}



void open_mine(int x, int y)//������Χչ������
{
    if (real_mine[x - 1][y - 1]== '0')
    {
        show_mine[x - 1][y - 1] = count_mine(x - 1, y - 1) + '0';//��ʾ��������Χ����
    }
    if (real_mine[x - 1][y] == '0')
    {
        show_mine[x - 1][y] = count_mine(x - 1, y) + '0';//��ʾ��������Χ����
    }
    if (real_mine[x - 1][y + 1] == '0')
    {
        show_mine[x - 1][y + 1] = count_mine(x - 1, y + 1) + '0';//��ʾ��������Χ����
    }
    if (real_mine[x][y - 1] == '0')
    {
        show_mine[x][y - 1] = count_mine(x, y - 1) + '0';//��ʾ��������Χ����
    }
    if (real_mine[x][y + 1] == '0')
    {
        show_mine[x][y + 1] = count_mine(x, y + 1) + '0';//��ʾ��������Χ����
    }
    if (real_mine[x + 1][y - 1] == '0')
    {
        show_mine[x + 1][y - 1] = count_mine(x + 1, y - 1) + '0';//��ʾ��������Χ����
    }
    if (real_mine[x + 1][y] == '0')
    {
        show_mine[x + 1][y] = count_mine(x + 1, y) + '0';//��ʾ��������Χ����
    }
    if (real_mine[x + 1][y + 1] == '0')
    {
        show_mine[x + 1][y + 1] = count_mine(x + 1, y + 1) + '0';//��ʾ��������Χ����
    }
}


int count_show_mine()//�ж�ʣ��δ֪����ĸ���������Ϊ����ʱ���Ӯ
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

int count_found_mine()//�������Ѿ��ҳ������׵ĸ��� 
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
