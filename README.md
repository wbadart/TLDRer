# tldrer

Generates TLDR files for UNIX commands

Instead of having to manually type out your whole .md file, tldrer
gives you a series of prompts to gather the information about the
command.  It then automatically writes to the specified file with
titles and markdown included.

Append to an existing tldr, or create a new one
Only one command at a time is supported

Running without a cmd will result in an error

  -d, --description        (Re)Set the TLDR description to user input
  -e, --examples=NUM       The user is prompted for NUM examples: descriptions
                           and code.
  -r, --references=NUM     The user is prompted for NUM references: titles and
                           urls.
  --help     display this help and exit
  --version  output version information and exit



Sample input:

        > ./tldrer -d -e3 -r2 git
        Type description below and press enter:
        Git is a distributed version control system.

        -- Example 1 of 3 --
        Type example description below and press enter:
        **Clone** a remote *repository*

        Type example code or statement below and press enter:
        $ git clone git@bitbucket.org:CSE-20189-SP16/assignments.git

        -- Example 2 of 3 --
        Type example description below and press enter:
        **Commit** local changes with a descriptive message:

        Type example code or statement below and press enter:
        $ git commit -m "the message"

        -- Example 3 of 3 --
        Type example description below and press enter:
        **Push** local changes to default remote *repository*:

        Type example code or statement below and press enter:
        $ git push

        -- Reference 1 of 2 --
        Type the text that should be displayed for the link and press enter:
        StackOverflow Answer

        Type the address that the link should target and press enter:
        http://stackoverflow.com/questions/927358/how-do-you-undo-the-last-commit

        -- Reference 2 of 2 --
        Type the text that should be displayed for the link and press enter:
        Pro Git

        Type the address that the link should target and press enter:
        https://git-scm.com/book/en/v2


Output file for above example (`time.md`):

TLDR - git
==========

Description
-----------

Git is a distributed version control system.

Examples
--------

- **Clone** a remote *repository*

        $ git clone git@bitbucket.org:CSE-20189-SP16/assignments.git

- **Commit** local changes with a descriptive message:

        $ git commit -m "the message"

- **Push** local changes to default remote *repository*:

        $ git push

References
----------

- [StackOverflow Answer](http://stackoverflow.com/questions/927358/how-do-you-undo-the-last-commit)

- [Pro Git](https://git-scm.com/book/en/v2)






<!--
48
113
414
-->
