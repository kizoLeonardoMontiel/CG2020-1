#include<graphics.h>
#include<conio.h>
#include<math.h>

void mapeamento(int xtmax, int xtmin, int ytmax, int ytmin, int xumax, int xumin, int yumax, int yumin, float xu, float yu );

float xt, yt;

void mapeamento(int xtmax, int xtmin, int ytmax, int ytmin, int xumax, int xumin, int yumax, int yumin, float xu, float yu ) {
	
	xt = ((xtmax - xtmin) * (xu - xumin))/(xumax - xumin) + xtmin;
    yt = ((ytmin - ytmax) * (yu - yumin))/(yumax - yumin) + ytmax;

}

int draw(int c1x, int c2x, int c3x, int c4x, int c1y, int c2y, int c3y, int c4y){
   int maxx, maxy, poly[10], i, errorcode;
   int gd = DETECT, gm;
   initgraph(&gd,&gm,NULL);
   errorcode=graphresult();
   if(errorcode)
       exit(1);

   maxx = getmaxx();
   maxy = getmaxy();
   
   setviewport(0,0,maxx,maxy,1);
  
   
     
   float t=0, px, py;  //pow(variável, expoente)
   while(t<=1){
    px = pow((1-t),3) * 1 + c1x * t * pow((1-t),2) * 2 + c2x * pow(t,2) * (1-t) * c3x + pow(t,3) * c4x;
    py = pow((1-t),3) * 1 + c1y * t * pow((1-t),2) * 3 + c2y * pow(t,2) * (1-t) * c3y + pow(t,3) * c4y;
    
    mapeamento(maxx, 0, maxy, 0, 6, 0, 6, 0, px, py );
	
	putpixel(xt, yt,BLUE);
	t = t + 0.0001;
   	
   }
 
   getch();
   clearviewport();
   closegraph();
   return 0;
}

int drawNewSegment(int cx, int cy){
	
}

int main()
{
   int coord1x, coord2x, coord3x, coord4x, coord1y, coord2y, coord3y, coord4y;
   
   printf("Digite a primeira coordenada de x: \n");
   scanf("%i", &coord1x);
   printf("Digite a segunda coordenada de x: \n");
   scanf("%i", &coord2x);
   printf("Digite a terceira coordenada de x: \n");
   scanf("%i", &coord3x);
   printf("Digite a quarta coordenada de x: \n");
   scanf("%i", &coord4x);
   printf("Digite a primeira coordenada de y: \n");
   scanf("%i", &coord1y);
   printf("Digite a segunda coordenada de y: \n");
   scanf("%i", &coord2y);
   printf("Digite a terceira coordenada de y: \n");
   scanf("%i", &coord3y);
   printf("Digite a quarta coordenada de y: \n");
   scanf("%i", &coord4y);
   draw(coord1x, coord2x, coord3x, coord4x, coord1y, coord2y, coord3y, coord4y);
   
   //r = resposta se quer alterar ou nao; eixo = eixo a se alterar; nCoord = identificador da coordenada no eixo selecionado; newCoord = valor da alteracao
   char r, eixo;
   int nCoord, newCoord;
   r = 'y';
   while(r == 'y'){
	   printf("Alterar algum ponto? (y/n) \n");
	   scanf(" %c", &r);
	   if(r == 'y'){
	     printf("Digite a o eixo da coordenada a ser alterado: (x/y) \n");
	     scanf(" %c", &eixo);
	     printf("Digite o numero da coordenada a ser alterado: \n");
	     scanf("%i", &nCoord);
	     printf("Digite o valor da coordenada a ser alterada: \n");
	     scanf("%i", &newCoord);
	     if(eixo == 'x'){
	     	if(nCoord == 1){
	     		coord1x = newCoord;
			 }
			if(nCoord == 2){
	     		coord2x = newCoord;
			}
			if(nCoord == 3){
	     		coord3x = newCoord;
			}
			if(nCoord == 4){
	     		coord4x = newCoord;
			}
			draw(coord1x, coord2x, coord3x, coord4x, coord1y, coord2y, coord3y, coord4y);
		 }
	     if(eixo == 'y'){
	     	if(nCoord == 1){
	     		coord1y = newCoord;
			 }
	     	if(nCoord == 2){
	     		coord2y = newCoord;
			 }
	     	if(nCoord == 3){
	     		coord3y = newCoord;
			 }
	     	if(nCoord == 4){
	     		coord4y = newCoord;
			 }	     	
			 draw(coord1x, coord2x, coord3x, coord4x, coord1y, coord2y, coord3y, coord4y);
		 }
		 if(eixo != 'x' && eixo != 'y'){
		 	printf("Valor invalido detectado. Saindo...");
		 	return 0;
		 }
	   }else{
	     printf("Obrigado! \n");
	     getche();
	     return 0;
	   }
	}
}
