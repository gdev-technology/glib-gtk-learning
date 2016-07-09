#include "myapp-spell-checker.h"
#include <string.h>

struct _MyappSpellChecker
{
  gchar *language_code;

  /* Put here other data structures used to implement
   * the spell checking.
   */
};

static void
load_dictionary (MyappSpellChecker *checker)
{
  /* ... */
};

/**
 * myapp_spell_checker_new:
 * @language_code: the language code to use.
 *
 * Returns: a new #MyappSpellChecker object. Free with
 * myapp_spell_checker_free().
 */
MyappSpellChecker *
myapp_spell_checker_new (const gchar *language_code)
{
  MyappSpellChecker *checker;

  g_return_val_if_fail (language_code != NULL, NULL);

  checker = g_new0 (MyappSpellChecker, 1);
  checker->language_code = g_strdup (language_code);

  load_dictionary (checker);

  return checker;
}

/**
 * myapp_spell_checker_free:
 * @checker: a #MyappSpellChecker.
 *
 * Frees @checker.
 */
void
myapp_spell_checker_free (MyappSpellChecker *checker)
{
  if (checker == NULL)
    return;

  g_free (checker->language_code);
  g_free (checker);
}

/**
 * myapp_spell_checker_check_word:
 * @checker: a #MyappSpellChecker.
 * @word: the word to check.
 * @word_length: the byte length of @word, or -1 if @word is nul-terminated.
 *
 * Returns: %TRUE if @word is correctly spelled, %FALSE otherwise.
 */
gboolean
myapp_spell_checker_check_word (MyappSpellChecker *checker,
                                const gchar       *word,
                                gssize             word_length)
{
  g_return_val_if_fail (checker != NULL, FALSE);
  g_return_val_if_fail (word != NULL, FALSE);
  g_return_val_if_fail (word_length >= -1, FALSE);

  /* ... Check if the word is present in a dictionary. */

  return TRUE;
}

/**
 * myapp_spell_checker_get_suggestions:
 * @checker: a #MyappSpellChecker.
 * @word: a misspelled word.
 * @word_length: the byte length of @word, or -1 if @word is nul-terminated.
 *
 * Gets the suggestions for @word. Free the return value with
 * g_slist_free_full(suggestions, g_free).
 *
 * Returns: (transfer full) (element-type utf8): the list of suggestions.
 */
GSList *
myapp_spell_checker_get_suggestions (MyappSpellChecker *checker,
                                     const gchar       *word,
                                     gssize             word_length)
{
  GSList *suggestions = NULL;

  g_return_val_if_fail (checker != NULL, NULL);
  g_return_val_if_fail (word != NULL, NULL);
  g_return_val_if_fail (word_length >= -1, NULL);

  if (word_length == -1)
    word_length = strlen (word);

  if (strncmp (word, "punchness", word_length) == 0)
    suggestions = g_slist_prepend (suggestions,
                                   g_strdup ("punchiness"));

  return suggestions;
}
