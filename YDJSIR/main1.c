#define _CRT_SECURE_NO_WARNINGS 1
#include"game-easy.h"
double  start, finish;
void game()
{

    int ret = 0;
    init_mine();//��ʼ��������̺����������
    set_mine();//����������̲���
    printf("\n");
    system ("CLS");
    print_mine();
    print_player();//��ӡ�������
    start = clock();
    safe_mine();//�����һ�α�ը��

    if (count_show_mine() == COUNT)//һ����Ӯ�����
    {
        print_mine();
        printf("���Ӯ��\n\n");
        return ;
    }print_player();////��ӡ�������

    while (1)//ѭ��ɨ��
    {
        int ret=sweep_mine();//ɨ��,�ȵ��׷���1��û�вȵ��׷���0
        if (count_show_mine() == COUNT)//��������̵�'*'����Ϊ����ʱ��ɨ����ɣ���Ϸʤ��
        {
            print_mine();//��ӡ���������
            printf("You Win����Ӯ�ˣ�\n\n");
            finish = clock();//ȡ����ʱ��
            printf("��ʱ%d ��\n",(int) (finish - start) / CLOCKS_PER_SEC);
            break;
        }
        if (ret)//�ж��Ƿ�ȵ���
        {
        	    system ("CLS");
            	printf("  _   _   _     _   _   _   _     _  \n\r");
				printf(" / \ / \ / \   / \ / \ / \ / \   / \ \n\r");
				printf("( Y | o | u ) ( L | o | s | e ) ( ! )\n\r");
				printf(" \_/ \_/ \_/   \_/ \_/ \_/ \_/   \_/ \n\r");
				printf(" 1 - A new one -����һ��\n\r");
            finish = clock();//ȡ����ʱ��
            printf("��ʱ%d ��\n", (int)(finish - start) / CLOCKS_PER_SEC);
            print_mine();//��ӡ���������鿴�׵ķֲ�
            system("pause");
            break;
        }print_player();//��ӡ�������
    }
}


int main()
{
    srand((unsigned int)time(NULL));//���������������
    int input = 0;
    muen();//�˵�
    /*extern int row=12;
    extern int col=12;
    extern int COUNT=12;*/
    //extern char show_mine[row][col];//չʾ����
    //extern char real_mine[row][col];//��������
    do
    {
        scanf("%d", &input);
        switch (input)
        {
        case 1:
			/*scanf("%d",&row);
			scanf("%d",&col);
			scanf("%d",&COUNT);*/
			game();
            break;
        case 0:exit(1);//�˳���Ϸ
            break;
        default:
            printf("���������������\n");
            break;
        }
        muen();
        printf("Contiue?����һ����\n");
    } while (1);//ѭ������Ϸ
    system("pause");
    return 0;
}

