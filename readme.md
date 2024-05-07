https://youtu.be/2HrYIl6GpYg

$ man socket
$ man bind
$ man sockaddr_in

$ python3
>>> hex(8080)
'0x1f90'
        change it to oposit > '0x901f', thats how portnum and ip address is accsepted by the socket api

$ man listen
$ man accept
$ man recv
$ man strchr
$ man 2 open
$ man sendfile



# build
    $ gcc main.c
# run
    $ strace ./a.out


# navigate to some folder and run:
    $ wget localhost:8080/index.html
        index.html will be copied to navigated folder



# --------------------------------------------------------------------------------------
# 
# 



# try for 8000
    >>> hex(8000)
    '0x1f40'
    '0x401f'


# wsl linux $ ifconfig prints out:
    eth0: ...
            inet 172.23.130.212
    
    so, access link from Windows should be:
    	http://172.23.130.212:8000/index.html

        not the lockalhost

# build cpp
    $ c++ main.cpp
# run
    $ ./a.out


# from PowerShell gives error > wget http://172.23.130.212:8000/index.html
    The server committed a protocol violation. Section=ResponseStatusLine
    At line:1 char:1
        + CategoryInfo          : InvalidOperation: (System.Net.HttpWebRequest:HttpWebRequest) [Invoke-WebRequest], WebExc
    eption
        + FullyQualifiedErrorId : WebCmdletWebResponseException,Microsoft.PowerShell.Commands.InvokeWebRequestCommand

# from cmd seems ok but no html file returned >curl  http://172.23.130.212:8000/index.html




$ c++ main.cpp
$ strace ./a.out

from cmd
curl  http://172.23.130.212:8000/index.html
