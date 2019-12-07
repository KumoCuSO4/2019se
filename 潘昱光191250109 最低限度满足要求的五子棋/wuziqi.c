#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
int x,y;
int l(char a[],int b,int c,int count){
	if(b>=1){
		if(a[c*15+b]==a[c*15+b-1]){
			return l(a,b-1,c,++count);
		}
	}
	return count;
}
int r(char a[],int b,int c,int count){
	if(b<=13){
		if(a[c*15+b]==a[c*15+b+1]){
			return r(a,b+1,c,++count);
		}
	}
	return count;
}
int u(char a[],int b,int c,int count){
	if(c>=1){
		if(a[c*15+b]==a[(c-1)*15+b]){
			return u(a,b,c-1,++count);
		}
	}
	return count;
}
int d(char a[],int b,int c,int count){
	if(c<=13){
		if(a[c*15+b]==a[(c+1)*15+b]){
			return d(a,b,c+1,++count);
		}
	}
	return count;
}
int lu(char a[],int b,int c,int count){
	if(b>=1&&c>=1){
		if(a[c*15+b]==a[(c-1)*15+b-1]){
			return lu(a,b-1,c-1,++count);
		}
	}
	return count;
}
int rd(char a[],int b,int c,int count){
	if(b<=13&&c<=13){
		if(a[c*15+b]==a[(c+1)*15+b+1]){
			return rd(a,b+1,c+1,++count);
		}
	}
	return count;
}
int ld(char a[],int b,int c,int count){
	if(b>=1&&c<=13){
		if(a[c*15+b]==a[(c+1)*15+b-1]){
			return ld(a,b-1,c+1,++count);
		}
	}
	return count;
}
int ru(char a[],int b,int c,int count){
	if(b<=13&&c>=1){
		if(a[c*15+b]==a[(c-1)*15+b+1]){
			return ru(a,b+1,c-1,++count);
		}
	}
	return count;
}
int sf(char a[],int b,int c){
	if(l(a,b,c,0)+r(a,b,c,0)>=4){
		return 1;
	}
	if(u(a,b,c,0)+d(a,b,c,0)>=4){
		return 1;
	}
	if(lu(a,b,c,0)+rd(a,b,c,0)>=4){
		return 1;
	}
	if(ld(a,b,c,0)+ru(a,b,c,0)>=4){
		return 1;
	}
	return 0;
}
int player1_in(char a[]){
	printf("player1 input x y\n");
	scanf("%d%d",&x,&y);
	if(x>=0&&x<=14&&y>=0&&y<=14){
		if(a[y*15+x]=='+'){
			a[y*15+x]='X';
			return 0;
		}
	}
	return 1;
}
int player2_in(char g,char a[]){
	if(g=='p'){
		printf("player2 input x y\n");
		scanf("%d%d",&x,&y);
		if(x>=0&&x<=14&&y>=0&&y<=14){
			if(a[y*15+x]=='+'){
				a[y*15+x]='O';
				return 0;
			}
		}
		return 1;
	}
	else{
		srand(time(NULL));
		x=rand()%15;
		y=rand()%15;
		if(x>=0&&x<=14&&y>=0&&y<=14){
			if(a[y*15+x]=='+'){
				a[y*15+x]='O';
				return 0;
			}
		}
		return 1;
	}
}
int main(){
    char board[225];
	for(int i=0;i<225;i++){
		board[i]='+';
	}
    char game_mode='\0';
    int count=1;
    printf("Please choose game mode press p to PVP and press e to PVE\n");
    while(1){
        if(kbhit()){
            char ch=getch();
            switch((char)tolower(ch)){
                case 'p':
                    game_mode='p';
                break;
                case 'e':
                    game_mode='e';
                break;
            }
            if(game_mode!='\0'){
                break;
            }
        }
    }
	system("cls");
    while(1){
        for(int i=0;i<15;++i){
            for(int j=0;j<15;++j){
                printf("%c",board[i*15+j]);
            }
            printf("\n");
        }
		if(count%2){
			if(player1_in(board)){
				system("cls");
				continue;
			}
			else{
				system("cls");
				if(sf(board,x,y)){
					break;
				}
				++count;
			}
		}
		else{
			if(player2_in(game_mode,board)){
				system("cls");
				continue;
			}
			else{
				system("cls");
				if(sf(board,x,y)){
					break;
				}
				++count;
			}
		}
        Sleep(50);
    }
	if(count%2){
		printf("Player1 win");
		system("pause");
	}
	else{
		if(game_mode=='p'){
			printf("Player2 win\n");
			system("pause");
		}
		else{
			printf("Computer win\n");
			system("pause");
		}
	}
    return 0;
}