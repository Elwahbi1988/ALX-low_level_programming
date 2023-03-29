#inclure <unistd.h>

/**
   * _putchar - écrit le caractère c en stdout
    * @c : Le personnage à imprimer
     *
      * Retour: Sur le succès 1.
       * En cas d’erreur, -1 est renvoyé et errno est défini de manière appropriée.
        */
int _putchar(char c)
{
		return (write(1, &c, 1));
}
