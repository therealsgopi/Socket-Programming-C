#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
int main()
{
	int csd,cport,len;
	char sendmsg[100]="Please Switch Off the Lights and Fan When Not in Use";
	char revmsg[100];
	struct sockaddr_in serv_address;
	
	printf("Enter the port \n");
	scanf("%d" ,&cport);
	printf("%d" ,cport);
	csd=socket(AF_INET,SOCK_STREAM, 0);
	
	if(csd<0)
		printf("Socket cannot be created\n");
	else
		printf("Socket is created\n");
		
	serv_address.sin_family=AF_INET;
	serv_address.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_address.sin_port=htons(cport);
	
	if(connect(csd, (struct sockaddr *)&serv_address,sizeof(serv_address))<0)
		printf("Can't connect\n");
	else
		printf("Connected sucessfully\n");
		
	send(csd,sendmsg,100,0);
	printf("Message sent to server is:\n");
	for(int k=0;k<strlen(sendmsg) ;k++)
		printf("%c",sendmsg[k]);
	recv(csd,revmsg,100,0);
	printf("\n Message recieved from server is:\n");
	for(int k=0;k<strlen(revmsg) ;k++)
		printf("%c",revmsg[k]);
	printf("\n");
}


