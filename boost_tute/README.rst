installation
------------

`boost <https://www.boost.org/>`_

`boost install <https://www.boost.org/doc/libs/1_83_0/more/getting_started/unix-variants.html>`_

Install on linux::

    wget https://boostorg.jfrog.io/artifactory/main/release/1.82.0/source/boost_1_82_0.tar.bz2
    tar --bzip2 -xf boost_1_82_0.tar.bz2
    cp -r boost_1_82_0 /usr/local
    cd /usr/local/boost_1_82_0
    sudo ./bootstrap.sh
    sudo ./b2 install

Install specific bins::

    cd /usr/local/boost_1_82_0
    sudo ./bootstrap.sh --with-libraries=regex,thread,chrono,date_time --prefix=/usr/local
    sudo ./b2 install

    ls -l /usr/local/lib/libboost_*
    ls /usr/local/lib/libboost_*.a > bins.txt

Copy out examples::

    cp /usr/local/boost_1_82_0/libs/program_options/example/* .

Compile example::

    g++ -I /usr/local/boost_1_82_0 example.cpp -o example
    g++ -I /usr/local/boost_1_82_0 -o bin_example bin_example.cpp /usr/local/lib/libboost_regex.a

libs
--------

`list of doco for libs <https://www.boost.org/doc/libs/?view=categorized>`_

`list of libs A-Z <https://www.boost.org/doc/libs/1_82_0/libs/libraries.htm>`_

https://www.boost.org/doc/libs/1_83_0/libs/format/doc/format.html

https://www.boost.org/doc/libs/1_83_0/doc/html/program_options/tutorial.html#id-1.3.30.4.3

https://www.boost.org/doc/libs/1_83_0/doc/html/thread/thread_management.html#thread.thread_management.synopsis

https://www.boost.org/doc/libs/1_83_0/libs/tokenizer/doc/introduc.htm

https://www.boost.org/doc/libs/1_83_0/doc/html/boost_lexical_cast/examples.html

https://www.boost.org/doc/libs/1_83_0/doc/html/date_time/examples/general_usage_examples.html

https://www.boost.org/doc/libs/1_83_0/libs/python/doc/html/tutorial/tutorial/functions.html#tutorial.functions.overloading

https://www.boost.org/doc/libs/1_83_0/doc/html/process.html#boost_process.introduction

https://www.boost.org/doc/libs/1_83_0/doc/html/boost_asio/overview/basics.html

https://www.boost.org/doc/libs/1_83_0/libs/math/doc/html/math_toolkit/main_intro.html

https://www.boost.org/doc/libs/1_83_0/libs/assign/doc/index.html#list_of

https://www.boost.org/doc/libs/1_83_0/libs/core/doc/html/index.html

https://www.boost.org/doc/libs/1_83_0/libs/bimap/doc/html/boost_bimap/one_minute_tutorial.html

https://www.boost.org/doc/libs/1_83_0/libs/spirit/doc/html/index.html

https://www.boost.org/doc/libs/1_83_0/libs/spirit/doc/html/spirit/introduction.html

https://www.boost.org/doc/libs/1_83_0/libs/spirit/doc/html/spirit/lex/lexer_introduction.html

https://www.boost.org/doc/libs/1_83_0/libs/spirit/doc/html/spirit/qi/tutorials/warming_up.html

https://www.boost.org/doc/libs/1_83_0/libs/spirit/doc/html/spirit/karma/tutorials/quick_start.html

