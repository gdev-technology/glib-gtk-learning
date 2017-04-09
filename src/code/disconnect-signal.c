#include <glib-object.h>

typedef struct _MyTextView MyTextView;

struct _MyTextView
{
  GspellChecker *spell_checker;
  gulong word_added_to_personal_handler_id;
};

static void
word_added_to_personal_cb (GspellChecker *spell_checker,
                           const gchar   *word,
                           gpointer       user_data)
{
  MyTextView *text_view = user_data;

  g_message ("Word '%s' has been added to the user's personal "
             "dictionary. text_view=%p will be updated accordingly.",
             word,
             text_view);
}

MyTextView *
my_text_view_new (GspellChecker *spell_checker)
{
  MyTextView *text_view;

  g_return_val_if_fail (GSPELL_IS_CHECKER (spell_checker), NULL);

  text_view = g_new0 (MyTextView, 1);

  /* We store the spell_checker GObject in the instance variable, so
   * we increase the reference count to be sure that spell_checker
   * stays alive during the lifetime of text_view.
   *
   * Note that spell_checker is provided externally, so spell_checker
   * can live longer than text_view, hence the need to disconnect the
   * signal in my_text_view_free().
   */
  text_view->spell_checker = g_object_ref (spell_checker);

  text_view->word_added_to_personal_handler_id =
    g_signal_connect (spell_checker,
                      "word-added-to-personal",
                      G_CALLBACK (word_added_to_personal_cb),
                      text_view);

  return text_view;
}

void
my_text_view_free (MyTextView *text_view)
{
  if (text_view == NULL)
    return;

  if (text_view->spell_checker != NULL &&
      text_view->word_added_to_personal_handler_id != 0)
    {
      g_signal_handler_disconnect (text_view->spell_checker,
                                   text_view->word_added_to_personal_handler_id);

      /* Here resetting the value to 0 is not necessary because
       * text_view will anyway be freed, it is just to have a more
       * complete example.
       */
      text_view->word_added_to_personal_handler_id = 0;
    }

  /* The equivalent of:
   * if (text_view->spell_checker != NULL)
   * {
   *   g_object_unref (text_view->spell_checker);
   *   text_view->spell_checker = NULL;
   * }
   *
   * After decreasing the reference count, spell_checker may still be
   * alive if another part of the program still references the same
   * spell_checker.
   */
  g_clear_object (&text_view->spell_checker);

  g_free (text_view);
}
