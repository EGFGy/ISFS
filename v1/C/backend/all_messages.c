#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include <ctype.h>

#include "CGI_functions.h"
#include "SQL_functions.h"

int main(int argc, char ** argv){
    cgi datCGI;
	person check_person;

	char * s_sid=NULL;
    getCGIdata(&datCGI);

    extractCOOKIEdata(&datCGI, "SID", &s_sid);
    extractCOOKIEdata(&datCGI, "EMAIL", &check_person.email);
    check_person.sid=atoi(s_sid);

	httpHeader(TEXT);
    if(verify_sid(&check_person)){
		printf("You are authorized to view da dataz!!\n");
    }else{
		printf("Go away!!");
    }



    //Prüfen ob Nutzer angemeldet ist

}
