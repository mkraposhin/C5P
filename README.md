C++ - powered personal page (C5P)
-------------------------------

The repository contains the source code for a personal site.

The source code is licensed under GNU GPLv3

GENERAL IDEA
------------
 
Main purpose of the project is management of a personal site using CGI
technology and C++ language. The program is divided into three parts:
1. CGI executable file (folder __executables__);
2. classes that produce HTML content (folder __classes__);
3. pages of the site itself (folder __pages__).

__Site__ class provides on demand HTML text for CGI via __std::ostream__
by requesting __Document__'s class virtual method __print__.

An object of __Document__ class owns:
- an instance of __Head__ class that contains HTML header;
- an instance of __Page__ class that contains HTML body.

Each page (__Document__ implementation) of a site is responsible to fill
contents of header and body elements. Instances of __Head__ and __Page__
classes should own objects that represent their nested HTML elements.
Therefore, each class, which represents HTML element should have means to
transfer it's ownership or to create copy of itself.

Classes __Head__ and __Page__ inherit from __Compound__ to ensure ownership
of nested HTML elements.

Child classes of __Document__ (such as __Contacts__, __Home__, __Education__,
etc) create HTML elements or corresponding web pages and pass their copies
to corresponding __Page__ instances.

Supports
--------

- Basic HTML element, .e.g. ```<a>, <p>, <div>, <jscript>, <meta>, <button>,
<image>, <header>```, etc.
- Simple CSS classes.
- Markdown language via external libraries.

USES
----

1. C++ STL library
2. [Maddy](https://github.com/progsource/maddy) for Markdown rendering
3. [CgiCC](https://gnu.org/software/cgicc) for CGI requests
4. [MD4C](https://github.com/mity/md4c) for Markdown 2 HTML rendering 
(fast version)

DEMO
----

You can play demo [http://kraposhin.online](http://kraposhin.online)
