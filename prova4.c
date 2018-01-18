# include <allegro.h>
# include <time.h>

/*	forma del tank rettangolare, con rubinetti aperti
	tank trasparente di fronte, liquido visibile da tale superficie
	piccola animazione che fa salire il livello del liquido
	inclusa la superficie superiore del liquido
*/

#define hTank 101
#define brx 30
#define bry 10



int main()
{
	int col_liq = 11, p0x = 300, p0y = 300;
	int sup_liq_col = 3, sup_int_col = 92, sup_est_col = 2;
	int p1x = p0x+2*brx, p1y = p0y;
	int p2x = p0x, p2y = p0y-hTank;
	int p3x = p1x, p3y = p1y;
	int p4x = p0x, p4y = p0y-hTank-bry-10;
	int hTankNow = 0;
	int tapOutPoints [12] = {p3x, p3y, p3x, p3y-3, p3x+10, p3y-3, p3x+10, p3y+2, p3x+7, p3y+2, p3x+7, p3y};
	int tapInPoints [12] = {p4x, p4y, p4x, p4y-3, p4x+10, p4y-3, p4x+10, p4y+2, p4x+7, p4y+2, p4x+7, p4y};
	int bord_sup_points [8] = {p2x, p2y, p1x, p2y, p1x+16, p2y-12, p2x+16, p2y-12};
	int sup_sup_points [8] = {p2x+1, p2y-1, p1x-1, p2y-1, p1x+16-1, p2y-12+1, p2x+16+1, p2y-12+1};
	int sup_lat_points [8] = {p1x, p1y, p1x, p2y, p1x+16, p2y-12, p1x+16, p1y-12};
	
	//int sup_liq_points [8] = {p0x+1, p0y-hTankNow, p1x-1, p1y-hTankNow, p1x-1, p1y-12-hTankNow, p0x+16+1, p0y-12+1-hTankNow};


	allegro_init();
	install_keyboard();
	set_color_depth(8);

	set_gfx_mode(GFX_AUTODETECT,640,480,0,0); //full screen
	clear_to_color(screen, 0); // background


	polygon(screen, 4, bord_sup_points, sup_est_col);						//bordi superficie superiore
	polygon(screen, 4, sup_sup_points, sup_int_col);						//superficie superiore senza liquido
	
	rectfill(screen, p0x+1, p0y-1, p0x+2*brx-1, p0y-hTank+1, sup_int_col);	//superficie interna frontale senza liquido
	
	polygon(screen, 6, tapOutPoints, 7);							//rubinetto inferiore
	polygon(screen, 6, tapInPoints, 7);							//rubinetto superiore

	while (hTankNow < hTank){
		
		rectfill(screen, p0x+7, p0y, p0x+7+3, p0y-hTank-bry-10+3, col_liq);		//flusso liquido dal tap in
		
		rectfill(screen, p0x+1, p0y-1, p0x+2*brx-1, p0y-hTankNow+1, col_liq);	//superficie interna frontale con liquido
		
		rectfill(screen, p0x+16, p0y-hTankNow, p1x-1, p0y-hTankNow-12, sup_liq_col);
		triangle(screen, p0x, p0y-hTankNow, p0x+16, p0y-hTankNow, p0x+16, p0y-hTankNow-12, sup_liq_col);
		triangle(screen, p1x-1, p1y-hTankNow, p1x-1, p1y-12-hTankNow, p1x-1+16, p1y-12-hTankNow, sup_liq_col);
		//polygon(screen, 4, sup_liq_points, sup_liq_col);						//superficie superiore del liquido
		

		rect(screen, p0x, p0y, p0x+2*brx, p0y-hTank, sup_est_col);				//bordi superficie frontale	
		polygon(screen, 4, sup_lat_points, sup_est_col);						//superficie laterale
		
		hTankNow+=5;
		sleep(1);
	}

	readkey();
	allegro_exit();
	
	return 0;
}