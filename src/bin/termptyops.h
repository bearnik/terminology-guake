typedef enum _Termpty_Clear
{
   TERMPTY_CLR_END,
   TERMPTY_CLR_BEGIN,
   TERMPTY_CLR_ALL
} Termpty_Clear;

void _termpty_text_copy(Termpty *ty, Termcell *cells, Termcell *dest, int count);
void _termpty_text_scroll(Termpty *ty);
void _termpty_text_scroll_rev(Termpty *ty);
void _termpty_text_scroll_test(Termpty *ty);
void _termpty_text_scroll_rev_test(Termpty *ty);
void _termpty_text_append(Termpty *ty, const Eina_Unicode *codepoints, int len);
void _termpty_clear_line(Termpty *ty, Termpty_Clear mode, int limit);
void _termpty_clear_screen(Termpty *ty, Termpty_Clear mode);
void _termpty_clear_all(Termpty *ty);
void _termpty_reset_att(Termatt *att);
void _termpty_reset_state(Termpty *ty);
void _termpty_cursor_copy(Termstate *state, Termstate *dest);

#define _term_txt_write(ty, txt) termpty_write(ty, txt, sizeof(txt) - 1)
