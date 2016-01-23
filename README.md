# TLDRer
Generates TLDR files for UNIX commands

##Warning: until the next release, please specify command name and file name from the command line (e.g. `tldrer ping ping.md`). Not doing so will cause the written file to be super wonky.

Instead of having to manually type out your whole .md file, TLDRer gives you a series of prompts to gather the information about the command.  It then automatically writes to the specified file with titles and markdown included.

Sample input:

    $ tldrer time time.md
    
    Using command <time>
    Using file name <time.md>
    
    Description: Time measures the run time of its arguments.
    
    How many examples would you like to give? 2
    Example 0 description: Time the execution of `ls`:
    Example 0 code: time ls
    Example 1 description: Time the execution of `rm -rf /*`:
    Example 1 code: time rm -rf /*
    
    How many resources would you like to give? 1
    Resource 0 name: Man7
    Resource 0 url: http://man7.org/linux/man-pages/man1/time.1.html
    
Output file for above example (`time.md`):

TLDR - time
=====

Overview
--------

[time] measures the run time of its arguments.

Examples
--------

- Time the execution of `ls`:

    time ls

- Time the execution of `rm -rf /*`:

    time rm -rf /* 

Resources
---------

- [Man7](http://man7.org/linux/man-pages/man1/time.1.html)
