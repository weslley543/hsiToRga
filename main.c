#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926;

float menor (float r,float g, float b){
    return (r < ((g < b) ? g:b)) ? r:((g < b) ? g:b);
}

void rgbToHsi(float r, float g, float b){
   float R,G,B, h,s,i;
   R = r/255;
   G = g/255;
   B = b/255;
   i=(R+G+B)/3;
   if(r == g && g == b){
       s=h=0;
   }else{
       float theta;
       theta = (R - G + R - B) / sqrt((R - G) * (R - G) + (R - B) * (G - B)) / 2;
       h = acos(theta)*180/PI;
       if(B>G){
           h=360-h;
       }
       s = 1 - i*menor(R,G,B);
       
   }
   printf("H : %.2f, S : %.2f, I : %.2f\n", h,s,i);
}
void hsiToRgb(int h, float s, float i){
 float r,g,b, c,x,m;
 //m = L - C/2
 if((h>=0 && h<=360) && (s>=0 && s<=1.0) && (i>=0 && i<=1.0)){
     c = (1.0 - abs(2*i-1))*s;
     x = (1.0 - abs(((h/60)%2)-1.0))*c;
     m= i - c/2.0; 
     //printf("c %f, x%f ,m%f\n", c,x,m);
    if(h>=0 && h<60){
         printf("if 1\n");
         r = c;
         g = x;
         b = 0;
    }if(h>=60 && h<120){
         printf("if 2\n");
         r = x;
         g = c;
         b = 0;
    }if(h>=120 && h<180){
        printf("if 3\n");
        r = 0;
        g = c;
        b = x;
    }if(h >=180 && h <240){
        printf("if 4\n");
        r = 0;
        g = x;
        b = c;
    }if(h >=240 && h<300){
        printf("if 5\n");
        r=x;
        g=0;
        b=c;
    }if(h>=300 && h<360){
        printf("if 6\n");
        r=c;
        g=0;
        b=x;
    }
     r = (r+m)*255;
     g = (g+m)*255;
     b = (b+m)*255;

    printf("(r, g, b) (%.2f,%.2f,%.2f)\n", r,g,b);
 }else{
     printf("verifique os valores inseridos se estão corretos");
     return;
 }


}

int main (){
    float r,g,b, s,i;
    int h;
    printf("Introduza valores para conversão de rgb para hsi\n");
    printf("Valor de R\n");
    scanf("%f", &r);
    printf("Valor de g\n");
    scanf("%f", &g);
    printf("Valor de b\n");
    scanf("%f", &b);
    rgbToHsi(r,g,b);
    printf("Introduza valores para conversão de hsi para rgb\n");
    printf("Valor de h\n");
    scanf("%d", &h);
    printf("Valor de s\n");
    scanf("%f", &s);
    printf("Valor de i\n");
    scanf("%f", &i);
    hsiToRgb(h,s,i);
    return 0;

}