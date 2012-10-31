#ifndef _CONFIG_H__
#define _CONFIG_H__ 1

typedef struct _Config Config;

/* TODO: separate config per terminal (tab, window) and global. */

struct _Config
{
   int version;
   struct {
      const char    *name;
      const char    *orig_name;
      int            size;
      int            orig_size;
      unsigned char  bitmap;
      unsigned char  orig_bitmap;
   } font;
   struct {
      const char    *email;
      struct {
         const char    *general;
         const char    *video;
         const char    *image;
      } url, local;
      Eina_Bool      inline_please;
   } helper;
   const char       *theme;
   const char       *background;
   const char       *wordsep;
   int               scrollback;
   int               vidmod;
   Eina_Bool         jump_on_keypress;
   Eina_Bool         jump_on_change;
   Eina_Bool         flicker_on_key;
   Eina_Bool         disable_cursor_blink;
   Eina_Bool         disable_visual_bell;
   Eina_Bool         translucent;
   Eina_Bool         mute;
   Eina_Bool         urg_bell;

/* Bind and Expand */
   Eina_Bool         bind;
   Eina_Bool         expand;
////////////////////////////////////////  
   Eina_Bool         temporary; /* not in EET */
   const char       *config_key; /* not in EET, the key that config was loaded */
};

void config_init(void);
void config_shutdown(void);
void config_save(Config *config, const char *key);
Config *config_load(const char *key);
void config_del(Config *config);

const char *config_theme_path_get(const Config *config);
const char *config_theme_path_default_get(const Config *config);

#endif
