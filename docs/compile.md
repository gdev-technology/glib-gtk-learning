glib-gtk-book :: compile
========================

To compile the document to PDF
------------------------------

```bash
$ cd src/
$ latexmk -pdf main.tex
```

To compile the document to ePub
-------------------------------

```bash
$ cd src/
$ tex4ebook -f epub3 main.tex
```

**Note:** ePub output has not been thoroughly verified; please open an issue or pull request for any inconsistencies.

Required programs
-----------------

Both [`latexmk`](https://mg.readthedocs.io/latexmk.html) and [`tex4ebook`](https://www.ctan.org/pkg/tex4ebook) should be included in [TeX Live](https://tug.org/texlive/) or [MiKTeX](https://miktex.org/) on your platform.
