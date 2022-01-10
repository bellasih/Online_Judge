#include <bits/stdc++.h>
#define g 9.80665
#define pi 3.14159
using namespace std;

int main(){
	double h,a,v;
	int p1,p2,n;
	while(scanf("%lf",&h)!=EOF){
		scanf("%d%d%d",&p1,&p2,&n);
		while(n--){
			double t,a1,b,c,x;
			scanf("%lf%lf",&a,&v);
			a = a*2*pi/360;
			a1=(0.5*g); b= -1*v*sin(a); c = -1*h;
			t = (-1*b + sqrt(b*b - 4*a1*c))/(2*a1);
			x = v*cos(a)*t;
			if(x>(double)p1 && x<=(double)p2) printf("%.5lf -> DUCK\n",x);
			else printf("%.5lf -> NUCK\n",x);
		}
	}
}