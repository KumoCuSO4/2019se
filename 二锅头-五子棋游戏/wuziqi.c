#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
	int playerback[17][17] = {0};
	int mineback[17][17] = {0};
	
void printFunc();
void printtip();
void p2pplay();
void p2mplay(); 
void newbackprint();//每次下棋子后的棋盘打印 
int isWin(int x,int y,int turn);

int main(){

    printFunc();
    printtip();
    int index = 0;
    scanf("%d",&index);
    if(index==1)
    	p2pplay();//人人对战 
	else
	    p2mplay();//人机对战 
    
	system("pause");
	return 0;
}
void p2pplay(){
	printf("输入成功，人人对战开始，记得找你的好基友一块玩哦！\n");
	int turn =2;
	while(turn){
	printf("第%d位玩家请输入您的棋子的坐标，先行后列哦！\n",turn%2+1);
	int x = 0;
	int y = 0;
	scanf("%d %d",&x,&y);
	if(x<1||x>15||y<1||y>15){
		printf("您的输入有误，请重新输入哦！\n");
		continue;
	}
	if(playerback[x][y]!=0){
		printf("这儿已经有棋子啦！请重新输入哦！\n");
		continue;
	}
	playerback[x][y] = turn%2+1;
	newbackprint();
	int result = isWin(x,y,turn%2+1);
	if(result ==4){
		printf("第%d位玩家获得了胜利！撒花！！！\n",turn%2+1);
		break;
	}
	turn++;
	}
}


void p2mplay(){
	printf("输入成功，人机对战开始，求下手轻点\n");
	int turn =2;
	while(turn){
	printf("玩家请输入您的棋子的坐标，先行后列哦！\n");
	int x = 0;
	int y = 0;
	scanf("%d %d",&x,&y);
    if(x<1||x>15||y<1||y>15){
		printf("您的输入有误，请重新输入哦！\n");
		continue;
	}
	if(playerback[x][y]!=0){
		printf("这儿已经有棋子啦！请重新输入哦！\n");
		continue;
	}
	playerback[x][y] = 1;
	int result = isWin(x,y,1);
	if(result ==4){
		printf("玩家获得了胜利！撒花！！！\n");
		break;}

	srand( (unsigned)time( NULL ) );
	while(1){
		int a=rand()%15+1;
		int b=rand()%15+2;
		if(playerback[a][b]!=0)
		continue;
		else{
		playerback[a][b] =2;
		newbackprint();
		}
		int result = isWin(a,b,2);
	    if(result ==4){
		printf("机器竟然获得了胜利！您一定是用脚玩的!\n");
		break;}
		break;
		}
	
	} 
	newbackprint();
}





int isWin(int x,int y,int turn){
	//左右判断 
	
	int c = 0;
	for(int i =1;i<=4;i++){
	if(playerback[x-i][y]==turn)
	   c++;
	else 
	   break; 
	} 
	for(int i =1;i<=4;i++){
	if(playerback[x+i][y]==turn)
	   c++;
	else 
	   break; 
	} 
	if(c ==4)
	return c;
	//上下判断 
	 c = 0;
	for(int i =1;i<=4;i++){
	if(playerback[x][y-i]==turn)
	   c++;
	else 
	   break; 
	} 
	for(int i =1;i<=4;i++){
	if(playerback[x][y+i]==turn)
	   c++;
	else 
	   break; 
	} 
	if(c ==4)
	return c;
	//左斜判断 
	c =0;
	for(int i =1;i<=4;i++){
	if(playerback[x-i][y-i]==turn)
	   c++;
	else 
	   break; 
	} 
	for(int i =1;i<=4;i++){
	if(playerback[x+i][y+i]==turn)
	   c++;
	else 
	   break; 
	} 
	if(c ==4)
	return c;
	//右斜判断 
	c =0;
	for(int i =1;i<=4;i++){
	if(playerback[x-i][y+i]==turn)
	   c++;
	else
	   break; 
	} 
	for(int i =1;i<=4;i++){
	if(playerback[x+i][y-i]==turn)
	  c++;
	else 
	   break; 
	} 
	if(c ==4)
	return c;
	else 
	return 0; 
}
void printFunc(){
		for(int m =0;m<=15;m++){
		if(m==0)
		printf("0   ");
		else if(m >=10)
		printf("%d ",m);
		else
		printf("%d  ",m);
		
	}
	printf("\n");
	for(int i =1;i<=15;i++){
		if(i<10)
		printf("%d   ",i);
		else 
		printf("%d  ",i);
		for(int j =0;j<15;j++){
	      printf("%c  ",'*');
		}
		printf("\n");
	}
	
}
void  printtip(){
	printf("您好，欢迎来到王者荣耀，啊不是，有趣的五子棋世界，以上是一张15*15的经典五子棋棋盘，您要开始吗？\n好的，人人对战请输入1，人机对战请输入2\nP.S.机器比较傻请不要恶意欺负哦!\n");
}

void newbackprint(){
	for(int m =0;m<=15;m++){
		if(m==0)
		printf("0   ");
		else
		printf("%d ",m);
		
	}
	printf("\n");
	for(int i =1;i<=15;i++){
		if(i<10)
		printf("%d   ",i);
		else 
		printf("%d  ",i);
		for(int j =1;j<15;j++){
			if(j>=9)
			printf("%d  ",playerback[i][j]);
			else
			printf("%d ",playerback[i][j]);
		}
		printf("\n");
	}
}




