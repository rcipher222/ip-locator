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
#include <iostream>
using namespace std;

/*
 * 
 */

char validIP (const char* tIP) { 
    struct sockaddr_in bIP;
    int ans = inet_pton(AF_INET, tIP, &(bIP.sin_addr)); 
    return ans==1;
}
void Error(int ans){
if (ans==-1 || ans==127 ) {
		cout<<"Location could not be resolved\n";
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[]) {
	if (argc==1) {
		//u donnt input ur ip so i am looking for computers ip..
         ("IP address is:\n");
	int ans=system("curl ipinfo.io/ip"); 
	if (ans==-1 || ans==127 ) {
		cout<<"IP could not be resolved\n";
		exit(EXIT_FAILURE);
	}
	cout<<"city:\n";
	ans=system("curl ipinfo.io/city");
	Error(ans);
        
	} 
        else {
		//looking for the inputed ip
		cout<<"Locating %s...\n"<< argv[1];
                
                if ( validIP(argv[1])!=1 ) {
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
		int ans=system(url);
                
		Error(ans);
                
		strcat(url2,"/country");
		ans=system(url2);
                
		Error(ans);
	}
	}
	return 0;
}