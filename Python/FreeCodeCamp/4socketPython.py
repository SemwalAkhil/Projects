import socket

# basic socket connection
mySock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
# socket.AF_INET -> socket across internet
# socket.SOCK_STREAM -> series of characters one after another in stream
mySock.connect(('data.pr4e.org',80))
# data.pr4e.org -> HOST
# 80 -> port

'''
URL
http://www.dr-chuck.com//page1.html

protocol      host         document           
'''
"""
Getting Data From The Server

->  Each the user clicks on an anchor tag with an href= value to switch
to a new page, the browser makes a connection to the web server
and issues a "GET" request - to GET the content of the page at the
specified URL

->  The server returns the HTML document to the Browser which
formats and displays the document to the user.
"""