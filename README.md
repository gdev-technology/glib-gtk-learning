The GLib/GTK Development Platform – A Getting Started Guide
===========================================================

A small book about programming with the GLib/GTK platform.

License: Creative Commons BY SA (see the text for more details).

To compile the document to PDF:

```bash
$ cd src/
$ latexmk -pdf main.tex
```

To compile the document to ePub:

```bash
$ cd src/
$ tex4ebook -f epub3 main.tex
```

> ***Note:*** *ePub output has not been thoroughly verified; please open an issue or pull request for any inconsistencies.*

Both [`latexmk`](https://mg.readthedocs.io/latexmk.html) and [`tex4ebook`](https://www.ctan.org/pkg/tex4ebook) should be included in [TeX Live](https://tug.org/texlive/) or [MiKTeX](https://miktex.org/) on your platform.

[Website with a PDF download and links](https://informatique-libre.be/swilmet/glib-gtk-book/).
