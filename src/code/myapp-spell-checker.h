#ifndef MYAPP_SPELL_CHECKER_H
#define MYAPP_SPELL_CHECKER_H

#include <glib.h>

G_BEGIN_DECLS

typedef struct _MyappSpellChecker MyappSpellChecker;

MyappSpellChecker *
  myapp_spell_checker_new             (const gchar *language_code);

void
  myapp_spell_checker_free            (MyappSpellChecker *checker);

gboolean
  myapp_spell_checker_check_word      (MyappSpellChecker *checker,
                                       const gchar       *word,
                                       gssize             word_length);

GSList *
  myapp_spell_checker_get_suggestions (MyappSpellChecker *checker,
                                       const gchar       *word,
                                       gssize             word_length);

G_END_DECLS

#endif /* MYAPP_SPELL_CHECKER_H */
