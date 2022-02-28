#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
int main() 
{
	int sd,sd2,nsd,cli_length, sport, length;
	int port;
	char sendmsg[100];
	char rcvmsg[100];
	struct sockaddr_in serv_address,cli_address;
	
	printf("Enter the server port:\n");
	scanf("%d" ,&sport);
	printf("%d" ,sport);
	sd=socket(AF_INET,SOCK_STREAM,0);
	
	if (sd<0)
		printf("Socket is not created \n");
	else
		printf("Socket is created\n");
	serv_address.sin_family=AF_INET;
	serv_address.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_address.sin_port=htons(sport);
	sd2=bind(sd,(struct sockaddr*) &serv_address,sizeof(serv_address));
	if (sd2<0)
		printf("Can't bind\n");
	else
		printf("Binded \n");
	listen(sd,5);
	cli_length=sizeof(cli_address);
	nsd=accept(sd,(struct sockaddr *)&cli_address,&cli_length);
	if (nsd<0)
		printf("Can't accept\n");
	else
		printf("Accepted\n");
		
	recv(nsd,rcvmsg,100,0);
	printf("Message has been recieved from the client side: \n");
	for(int k=0;k<strlen(rcvmsg) ;k++)
		printf("%c",rcvmsg[k]);
	char vow[] = "aeiou";
	
	for(int z=0; z<strlen(rcvmsg) ;z++)
	{
		int x=rcvmsg[z];
		if(x>=65 && x<=90) //a 97,e 101,i 105,0 111, u 117
		{
			rcvmsg[z]=x;
		}
		else
		{
			for(int q=0;q<strlen(vow);q++)
			{
				int nw1 = vow[q];
				if(x==nw1)
				{
					if (nw1!=117)
					{
						x=vow[q+1];
						break;
					}
					else
					x=97;
				}
			}
		}
		if(x>96 && x<123 && x!=97 && x!=101 && x!= 105 && x != 111 && x != 117)
		{
		    x = x+1;
		    if (x==97 || x==101 || x==105 || x==111 || x==117)
		        x = x+1;
		}
		rcvmsg[z] = x;
	}
	
	printf("\nlMessage sent is: \n");
	for(int k=0;k<strlen(rcvmsg) ;k++)
	{
		printf("%c" ,rcvmsg[k]);
	}
	printf("\n");
	send(nsd,rcvmsg, 100,0);
}
	
