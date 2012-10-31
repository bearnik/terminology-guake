#include "private.h"

#include <Elementary.h>
#include "config.h"
#include "termio.h"
#include "options.h"
#include "options_bind.h"

static Evas_Object *op_bind, *op_expand;

static void
_cb_op_bind_toggle_chg(void *data, Evas_Object *obj, void *event __UNUSED__)
{
   Evas_Object *term = data;
   Config *config = termio_config_get(term);
   config->bind = elm_check_state_get(obj);
   main_bind_toggle_update(config);
   config_save(config, NULL);
}


static void
_cb_op_bind_expand_chg(void *data, Evas_Object *obj, void *event __UNUSED__)
{
   Evas_Object *term = data;
   Config *config = termio_config_get(term);
   config->expand = elm_check_state_get(obj);
   main_bind_expand_update(config);
   config_save(config, NULL);
}

void
options_bind(Evas_Object *opbox, Evas_Object *term __UNUSED__)
{
   Evas_Object *o, *bi, *sc, *bx0;
   Config *config = termio_config_get(term);

   bi = o = elm_frame_add(opbox);
   evas_object_size_hint_weight_set(o, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(o, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_object_text_set(o, "Binding to the Workspace");
   elm_box_pack_end(opbox, o);
   evas_object_show(o);

   sc = o = elm_scroller_add(opbox);
   elm_scroller_content_min_limit(sc, EINA_TRUE,EINA_FALSE);
   evas_object_size_hint_weight_set(o, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(o, EVAS_HINT_FILL, EVAS_HINT_FILL);
   elm_object_content_set(bi, o);
   evas_object_show(o);
   
   
   bx0 = o = elm_box_add(opbox);
   evas_object_size_hint_weight_set(o, EVAS_HINT_EXPAND, 0.0);
   evas_object_size_hint_align_set(o, EVAS_HINT_FILL, 0.0);
   elm_object_content_set(sc, o);
   evas_object_show(o);
   
   o = elm_separator_add(bx0);
   evas_object_size_hint_weight_set(o, EVAS_HINT_EXPAND, 0.0);
   evas_object_size_hint_align_set(o, EVAS_HINT_FILL, 0.5);
   elm_separator_horizontal_set(o, EINA_TRUE);
   elm_box_pack_end(bx0, o);
   evas_object_show(o);
   
  /*
   * Bind Option to toggle Show / Hide - Guake Functionality
   */
   //op_bind = o = elm_check_add(opbox);
   op_bind = o = elm_check_add(bx0);
   evas_object_size_hint_weight_set(o, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(o, EVAS_HINT_FILL, EVAS_HINT_FILL);
   evas_object_show(o);

   evas_object_size_hint_weight_set(o, EVAS_HINT_EXPAND, 0.0);
   evas_object_size_hint_align_set(o, EVAS_HINT_FILL, 0.5);
   elm_object_text_set(o, "Bind Show/Hide with F12 key (Guake Functionality ) ");
   elm_check_state_set(o, config->bind);
   elm_box_pack_end(bx0, o);
   evas_object_show(o);
   evas_object_smart_callback_add(o, "changed",
                                 _cb_op_bind_toggle_chg , term);

   //o = elm_separator_add(opbox);
   o = elm_separator_add(bx0);
   evas_object_size_hint_weight_set(o, EVAS_HINT_EXPAND, 0.0);
   evas_object_size_hint_align_set(o, EVAS_HINT_FILL, 0.5);
   elm_separator_horizontal_set(o, EINA_TRUE);
   elm_box_pack_end(bx0, o);
   evas_object_show(o);

   /*
    * Expand option to toggle Show Twice - almost fullscreen
    */
   
   //op_expand = o = elm_check_add(opbox);
   op_expand = o = elm_check_add(bx0);
   evas_object_size_hint_weight_set(o, EVAS_HINT_EXPAND, 0.0);
   evas_object_size_hint_align_set(o, EVAS_HINT_FILL, 0.5);
   elm_object_text_set(o, "Expand the terminal to 100% height before closing");
   elm_check_state_set(o, config->expand);
   elm_box_pack_end(bx0, o);
   evas_object_show(o);
   evas_object_smart_callback_add(o, "changed",
                                  _cb_op_bind_expand_chg, term);
   
   //o = elm_separator_add(opbox);
   o  = elm_separator_add(bx0);
   evas_object_size_hint_weight_set(o, EVAS_HINT_EXPAND, 0.0);
   evas_object_size_hint_align_set(o, EVAS_HINT_FILL, 0.5);
   elm_separator_horizontal_set(o, EINA_TRUE);
   elm_box_pack_end(bx0, o);
   evas_object_show(o);
   
   //o = elm_label_add(opbox);
   o = elm_label_add(bx0);
   evas_object_size_hint_weight_set(o, 0.0, 0.0);
   evas_object_size_hint_align_set(o, 0.0, 0.5);
   elm_object_text_set(o, "Additional Options");
   elm_box_pack_end(bx0, o);
   evas_object_show(o);

   evas_object_size_hint_weight_set(opbox, EVAS_HINT_EXPAND, 0.0);
   evas_object_size_hint_align_set(opbox, EVAS_HINT_FILL, 0.0);
   evas_object_show(o);

   evas_object_size_hint_weight_set(opbox, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
   evas_object_size_hint_align_set(opbox, EVAS_HINT_FILL, EVAS_HINT_FILL);
   evas_object_show(o);


}
