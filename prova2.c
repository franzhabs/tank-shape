# include <allegro.h>

/*	forma del tank, con rubinetti
	non pieno e rub aperti
	tank trasparente solo su un lato, liquido visibile su tale superficie
*/

#define hTank 100
#define brx 30
#define bry 10



int main()
{
	int col_liq = 11, p0x = 300, p0y = 300;
	int p1x = p0x+brx, p1y = p0y;
	int p2x = p1x, p2y = p0y-hTank;
	int p3x = p0x+2*brx+1, p3y = p0y;
	int p4x = p0x, p4y = p0y-hTank-bry-10;
	int p3points [12] = {p3x, p3y, p3x, p3y-3, p3x+10, p3y-3, p3x+10, p3y+2, p3x+7, p3y+2, p3x+7, p3y};
	int p4points [12] = {p4x, p4y, p4x, p4y-3, p4x+10, p4y-3, p4x+10, p4y+2, p4x+7, p4y+2, p4x+7, p4y};

	allegro_init();
	install_keyboard();
	set_color_depth(8);

	set_gfx_mode(GFX_AUTODETECT,640,480,0,0); //full screen
	clear_to_color(screen, 15); //white background


	//rectfill(screen, 20, 20, 40, 40, 88);
	rect(screen, p0x, p0y, p0x+2*brx, p0y-hTank, 4);			//bordi laterali
	ellipse(screen, p1x, p1y, brx, bry, 4);						//bordo inferiore	
	rectfill(screen, p0x+1, p0y, p0x+2*brx-1, p0y-hTank, 11);	//riempimento centrale
	ellipsefill(screen, p1x, p1y, brx-1, bry-1, 11);			//riempimento inferiore
	ellipsefill(screen, p2x, p2y, brx-1, bry-1, 11);			//riempimento superiore
	ellipse(screen, p2x, p2y, brx, bry, 4);						//bordo superiore
	polygon(screen, 6, p3points, 7);							//rubinetto inferiore
	polygon(screen, 6, p4points, 7);							//rubinetto superiore

	readkey();
	allegro_exit();
	return 0;
}