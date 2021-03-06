# include <allegro.h>
# include <time.h>
#include <stdio.h>

/*	forma del tank, base ovale, con rubinetti
	tank trasparente, liquido visibile su tutta la superficie
	superficie superiore del liquido più scura, indica il livello
	piccola animazione, parte da metà fino a riempirsi
	il sensore in alto a dx del tank lampeggia mentre il liquido sale

*/

#define hTank 101
#define brx 30
#define bry 10



int main()
{
	int col_liq = 11, p0x = 300, p0y = 300;
	int p1x = p0x+brx, p1y = p0y;
	int p2x = p1x, p2y = p0y-hTank;
	int p3x = p0x+2*brx+1, p3y = p0y;
	int p4x = p0x, p4y = p0y-hTank-bry-10;
	int p5x = p3x, p5y = p2y;
	int p3points [12] = {p3x, p3y, p3x, p3y-3, p3x+10, p3y-3, p3x+10, p3y+2, p3x+7, p3y+2, p3x+7, p3y};
	int p4points [12] = {p4x, p4y, p4x, p4y-3, p4x+10, p4y-3, p4x+10, p4y+2, p4x+7, p4y+2, p4x+7, p4y};
	int hTankNow = 50;
	char s[20];
	int sens_col = 3;

	allegro_init();
	install_keyboard();
	set_color_depth(8);

	set_gfx_mode(GFX_AUTODETECT,640,480,0,0); //full screen
	clear_to_color(screen, 15); //background

		//elementi FISSI
		rect(screen, p0x, p0y, p0x+2*brx, p0y-hTank, 4);			//bordi laterali
		rectfill(screen, p0x+1, p0y, p0x+2*brx-1, p0y-hTank, 90);	//sfondo centrale
		ellipsefill(screen, p2x, p2y, brx-1, bry-1, 90);			//sfondo superiore
		ellipse(screen, p1x, p1y, brx, bry, 4);						//bordo inferiore	
		ellipsefill(screen, p1x, p1y, brx-1, bry-1, 11);			//riempimento inferiore
		polygon(screen, 6, p3points, 7);							//rubinetto inferiore
		polygon(screen, 6, p4points, 7);							//rubinetto superiore

		//elementi MOBILI

		while (hTankNow < hTank) {

			rectfill(screen, p4x+7, p4y+2, p4x+10, p0y, 11);			//flusso tap in
			rectfill(screen, p0x+1, p0y, p0x+2*brx-1, p0y-hTankNow, 11);//liquido centrale
			ellipsefill(screen, p1x, p1y-hTankNow, brx-1, bry-1, 3);	//superficie top liquido
			ellipse(screen, p2x, p2y, brx, bry, 4);						//bordo superiore
			hTankNow+=5;

			sens_col = 13 + (hTankNow%2);								//sensore liquido
			ellipsefill(screen, p5x, p5y, 8, 4, sens_col);			

			ellipsefill(screen, 100, 100, 80, 20, sens_col);			//altezza del liquido
			sprintf(s, "h liquid = %d\n", hTankNow);
			textout_ex (screen, font, s, 50, 100, 1, -1);
			

			sleep(1);

		}
		
	readkey();
	allegro_exit();
	return 0;
}