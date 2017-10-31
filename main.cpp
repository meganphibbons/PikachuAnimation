#include "Pikachu.h"
#include <allegro.h>

void init();
void deinit();

int main()
{
	init();
	BITMAP *bmp;
    Pikachu player(50, 300);
    bmp = create_bitmap(640, 480);
	while (!key[KEY_ESC])
    {
          textout_centre(bmp, font, "Press and hold space bar to see an explosion and use the arrows to move!", SCREEN_W / 2, 0, makecol(255, 255, 255));
          if (key[KEY_RIGHT])
             player.runRight(bmp);
          else if (key[KEY_LEFT])
             player.runLeft(bmp);
          else
             player.stand(bmp);

          if(key[KEY_SPACE])
            player.explosion(bmp, key[KEY_SPACE]);

        blit (bmp, screen, 0, 0, 0, 0, 640, 480);
        clear_bitmap(bmp);
        rest(2);

	}

	deinit();
	return 0;
}
END_OF_MAIN()

void init()
{
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (res != 0)
    {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
}

void deinit() {
	clear_keybuf();
}
