/* 
 * File:   main.cpp
 * Author: rb
 *
 * Created on 6 July, 2015, 4:48 PM
 */

#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

using namespace std;

/*
 * 
 */

char Is_Valid_IP (const char* tIP) { 
    struct sockaddr_in bIP;
    int result = inet_pton(AF_INET, tIP, &(bIP.sin_addr)); 
    return result==1;
}

int main(int argc, char *argv[]) {
	if (argc==1) {
		//u donnt input ur ip so i am looking for computers ip..
        printf ("IP address is:\n");
	int result=system("curl ipinfo.io/ip"); 
	if (result==-1 || result==127 ) {
		printf("Error: IP could not be resolved\n");
		exit(EXIT_FAILURE);
	}
	printf ("city:\n");
	result=system("curl ipinfo.io/city");
	if (result==-1 || result==127 ) {
		printf("Location could not be resolved\n");
		exit(EXIT_FAILURE);
	}
        
	} 
        else {
		//looking for the inputed ip
		printf ("Locating %s...\n", argv [1]);
                
                if ( Is_Valid_IP(argv[1])!=1 ) {
		printf("Not a valid IP address\n");
	        }
                else 
                {
		char url[50]={0};
		strcpy(url,"curl ipinfo.io/");
		strcat(url, argv[1]);
                
		char url2[50]={0};
		strcpy(url2,url);
                
		strcat(url,"/city");
		int result=system(url);
                
		if (result==-1 || result==127 ) 
                {
			printf("Location could not be resolved\n");
			exit(EXIT_FAILURE);
		}
                
		strcat(url2,"/country");
		result=system(url2);
                
		if (result==-1 || result==127 ) {
			printf("Location could not be resolved\n");
			exit(EXIT_FAILURE);
		}
	}
	}
	return 0;
}