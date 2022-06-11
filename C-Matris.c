#include <stdio.h>
#include <time.h>
#define M 7
#define N 7
int main( void )
{
	int dizi[M][N];
	int rastgele; 
	int i=0 , j=0;
	srand(time(NULL)); 
// 1. MATRÝS
	for (i=0 ; i<M;i++)
	{
		for(j=0 ; j<N;j++)
		{
			rastgele=rand()%255;
			dizi[i][j]=rastgele;
			printf("%d ",dizi[i][j]);
		}
		printf("\n");
	}
	
	
	printf("\n\n");
	
// V MATRÝSÝ	
	int v[3][3] ;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			printf ("%d %d=",i,j);
			scanf("%d",&v[i][j]);
		}
		printf("\n");
	
	}
//V MATRÝS ÇIKTI
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
		printf("%d ", v[i][j]);}
		printf("\n");
	}
		printf("\n");

	int carpma ,toplam=0;
	int yenimatris[M][N];
	int yenimatris2[M][N];
	int a=0,b=0;
	int z=0,x=0;
	for (i=1 ; i<M-1;i++)
	{
		for(j=1 ; j<N-1;j++)
		{
			for(z=-1;z<2;z++){
				for(x=-1;x<2;x++){	
				carpma=dizi[i+z][j+x]*v[z+1][x+1];
				toplam=carpma+toplam;
				}
			}
			yenimatris[i][j]=toplam;
			toplam=0;
			printf("%d ",yenimatris[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	toplam=0;
	for (i=0 ; i<M;i++)
	{
		for(j=0 ; j<N ;j++)
		{
			if(i==0&&j==0){   // SOL ÜST KÖÞE
				for(z=0;z<2;z++){
					for(x=0;x<2;x++){	
					carpma=dizi[i+z][j+x]*v[z+1][x+1];
					toplam=carpma+toplam;
					}
				}
			}
			else if(i==0&&j!=0&&j!=N-1) // ÜST TARAF
			{
				for(z=1;z<3;z++){
					for(x=0;x<3;x++){	
					carpma=dizi[i+z-1][j+x-1]*v[z-1][x];
					toplam=carpma+toplam;
					}
				}
			}
			else if(j==0&&i!=0&&i!=M-1)  //SOL TARAF
			{
				for(z=0;z<3;z++){
					for(x=0;x<2;x++){	
					carpma=dizi[i+z-1][j+x]*v[z][x];
					toplam=carpma+toplam;
					}
				}
			}
			else if(i==M-1&&j==0){   // SOL ALT KÖÞE
				for(z=0;z<2;z++){
					for(x=0;x<2;x++){	
					carpma=dizi[i+z-1][j+x]*v[z+1][x];
					toplam=carpma+toplam;
					}
				}
			}
			else if(i==0&&j==N-1){   // SAÐ ÜST KÖÞE
				for(z=0;z<2;z++){
					for(x=0;x<2;x++){	
					carpma=dizi[i+z][j+x-1]*v[z+1][x];
					toplam=carpma+toplam;
					}
				}
			}
			else if(j==N-1&&i!=0&&i!=M-1)  //SAÐ TARAF
			{
				for(z=0;z<3;z++){
					for(x=0;x<2;x++){	
					carpma=dizi[i+z-1][j-x]*v[z][x+1];
					toplam=carpma+toplam;
					}
				}
			}
			else if(i==M-1&&j==N-1)//SAÐ ALT KÖÞE
			{
				for(z=1;z<3;z++){
					for(x=1;x<3;x++){	
					carpma=dizi[i+z-2][j+x-2]*v[z][x];
					toplam=carpma+toplam;
					}
				}
			}
			else if(j!=0&&j!=M-1&&i==N-1)// ALT TARAF
			{
				for(z=1;z<3;z++){
					for(x=0;x<3;x++){	
					carpma=dizi[i+z-2][j+x-1]*v[z][x];
					toplam=carpma+toplam;
					}
				}
			}
			else { //ORTA TARAFLAR
				for(z=0;z<3;z++){
					for(x=0;x<3;x++){	
					carpma=dizi[i+z-1][j+x-1]*v[z][x];
					toplam=carpma+toplam;
					}
				}
			}
			yenimatris2[i+1][j+1]=toplam;
			toplam=0;
			printf("%d ",yenimatris2[i+1][j+1]);
		}
		printf("\n");
	}
}

