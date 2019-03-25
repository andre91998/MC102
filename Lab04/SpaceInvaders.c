

#include <stdio.h>

int main()
{

	int n; /*tabuleiro*/
	int i1, j1, i2, j2, i3, j3, i4, j4, i5, j5; /*coordenadas*/
	int ship_j; /*nave mae*/
	int lasertip_i, laser_recoil, lowest_hit; /*variaveis laser*/
	int zigzag_incr; 
	int i, j, k; 
	const int GAME_STATES = 10; 
	int icon; 
	int boom; 
	int dead_aliens; 


	scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &n, &i1, &j1, &i2, &j2, &i3, &j3, &i4, &j4, &i5, &j5, &ship_j);

	lasertip_i= n; laser_recoil = n; lowest_hit = 0;
	zigzag_incr = 1;
	dead_aliens = 0;
	boom = 0;
	for(k=1; k<=GAME_STATES; k++) 
	{
		boom=0;
		for (i=1; i<=n; i++) 
		{
			for(j=1;j<=n;j++)  
			{
				if (i==n) 
				{
					if(j==ship_j) {icon=2;}
					else {icon=0;}
				}
				else 
				{
					icon=0;
					if( (i==i1) && (j==j1) ) { if (j!=ship_j) {icon=1;} else if (i>=lasertip_i) {icon=0; boom++; laser_recoil=i+1; j1=100;} else {icon=1;} }
					if( (i==i2) && (j==j2) ) { if (j!=ship_j) {icon=1;} else if (i>=lasertip_i) {icon=0; boom++; laser_recoil=i+1; j2=100;} else {icon=1;} }
					if( (i==i3) && (j==j3) ) { if (j!=ship_j) {icon=1;} else if (i>=lasertip_i) {icon=0; boom++; laser_recoil=i+1; j3=100;} else {icon=1;} }
					if( (i==i4) && (j==j4) ) { if (j!=ship_j) {icon=1;} else if (i>=lasertip_i) {icon=0; boom++; laser_recoil=i+1; j4=100;} else {icon=1;} }
					if( (i==i5) && (j==j5) ) { if (j!=ship_j) {icon=1;} else if (i>=lasertip_i) {icon=0; boom++; laser_recoil=i+1; j5=100;} else {icon=1;} }
					if((j==ship_j) && (boom==0) && (i>=lasertip_i) && (i>lowest_hit)) {icon=3;}
					if((j==ship_j) && (boom!=0) && (i>lowest_hit)) {if (i>=laser_recoil) {icon=3;} }
				}

				switch (icon)
				{
					case (0) : printf(". ");	
					break;
					case (1) : printf("* ");	
					break;
					case (2) : printf("X ");	
					break;
					case (3) : printf("| ");	
					break;
					default :printf(". "); 
				}

			} 
			printf("\n"); 
		} 

		if (boom !=0) {lasertip_i=laser_recoil-1;} else {lasertip_i--;}

		printf("\n"); 


		zigzag_incr = (((k)/2)%2*(-2))+1; 
		j1 = j1 + zigzag_incr; if ((j1>n)&&(j1<50)) {j1=n;}; if (j1<1) {j1=1;}
		j2 = j2 + zigzag_incr; if ((j2>n)&&(j2<50)) {j2=n;}; if (j2<1) {j2=1;}
		j3 = j3 + zigzag_incr; if ((j3>n)&&(j3<50)) {j3=n;}; if (j3<1) {j3=1;}    
		j4 = j4 + zigzag_incr; if ((j4>n)&&(j4<50)) {j4=n;}; if (j4<1) {j4=1;}
		j5 = j5 + zigzag_incr; if ((j5>n)&&(j5<50)) {j5=n;}; if (j5<1) {j5=1;}

		dead_aliens = dead_aliens + boom;



		lowest_hit = 0;
		for (i=1; i<n; i++) 
				{
					j = ship_j; 													
					if( (i==i1) && (j==j1) && (i>=lasertip_i) ) {if (i>lowest_hit) {lowest_hit = i;}}
					if( (i==i2) && (j==j2) && (i>=lasertip_i) ) {if (i>lowest_hit) {lowest_hit = i;}}
					if( (i==i3) && (j==j3) && (i>=lasertip_i) ) {if (i>lowest_hit) {lowest_hit = i;}}
					if( (i==i4) && (j==j4) && (i>=lasertip_i) ) {if (i>lowest_hit) {lowest_hit = i;}}
					if( (i==i5) && (j==j5) && (i>=lasertip_i) ) {if (i>lowest_hit) {lowest_hit = i;}}
				}



	} 

	return 0;
}

