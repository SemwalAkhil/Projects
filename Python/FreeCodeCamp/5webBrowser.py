import socket

mysock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
mysock.connect(("data.pr4e.org",80)) # connect to server
cmd = 'GET http://data.pr4e.org/romeo.txt HTTP/1.0\r\n\r\n'.encode() # page request
mysock.send(cmd) # send command across network

while True:
    data = mysock.recv(512) # recieve 512 characters at a time
    if len(data) < 1: # if zero character => end of the string
        break
    print(data.decode(),end='')
mysock.close()

# Output
'''
HTTP/1.1 200 OK
Date: Thu, 06 Jun 2024 11:30:43 GMT
Server: Apache/2.4.52 (Ubuntu)
Last-Modified: Sat, 13 May 2017 11:22:22 GMT
ETag: "a7-54f6609245537"
Accept-Ranges: bytes
Content-Length: 167
Cache-Control: max-age=0, no-cache, no-store, must-revalidate
Pragma: no-cache
Expires: Wed, 11 Jan 1984 05:00:00 GMT
Connection: close
Content-Type: text/plain

But soft what light through yonder window breaks
It is the east and Juliet is the sun
Arise fair sun and kill the envious moon
Who is already sick and pale with grief
'''
# first half is metadata and second half is actual data

