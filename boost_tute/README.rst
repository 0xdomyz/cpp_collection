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

libs
--------

`list of doco for libs <https://www.boost.org/doc/libs/?view=categorized>`_

`list of libs A-Z <https://www.boost.org/doc/libs/1_82_0/libs/libraries.htm>`_
