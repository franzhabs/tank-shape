# include <allegro.h>

#define RADIUS 50

int main()
{
	int x = 100; int y = 100; int col = 14;
	allegro_init();
	install_keyboard();
	set_color_depth (8);


	set_gfx_mode(GFX_AUTODETECT,640,480,0,0);
	clear_to_color(screen, 0);
// black background

	circlefill(screen, x, y, RADIUS, col);
	readkey();
	allegro_exit();
	return 0;
}