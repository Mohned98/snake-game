import socket      #y7gez pot le socket
#from _thread import * # 3shan a recieve kaza client 
import _thread
def handle_client(conn,addr):     
    conn.send(str.encode('Welcome to the server')) #byb3t array of bytes bs fa b7tag a7welha le bytes
    while True:
        msg = conn.recv(1024).decode()
        if not msg or msg == 'close':
            print('lost connection with client', addr)  #lw fadia yb2a afl el connection
            conn.close()   # aflt el client
            break
        else:
            print('client %s says'%str(addr),msg)   #%s 3shan a7ot string gwa el string da el ktbah bara eni el add a7wlo string 


    
host='127.0.0.1'
port = 8082



s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)   #TCP SOCKET BYB3T message yt2kd enha wslt, UDP msh byt2kd
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind((host,port)) #lazm adi el socket el ip wel port el htshtghl 3laah
s.listen(5)     # lw geh akbr men 7emlo byd5lo fel queue fa da 3adad el queue


while True:
    print('listening for incoming connections')
    conn, addr= s.accept()    #add zy identefier el server bydeeh le kol client, el conn el object bymasel el client el bst5dmo 3shan anadi
    print('client',addr,'has been connected!')    #3laah function send aw recieve, lw 7gtan 3laa nfs el computer hytklmo 3laa nfs el ip
    _thread.start_new_thread(handle_client,(conn,addr, ))

#server 3l windows hktb fl host bt3 linux we fl client brdo hktb el host bt3 el server bs lazm yb2a 3la nfs el network
#server m3mool 3shan ye handle el clients fa el clients 3shan tklm b3d byt3mlo 3n tre2 el server aktb logic el server by5aod message men 2 clients
#we yb3t lel tani
    
