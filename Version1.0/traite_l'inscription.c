#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char*inscription();
char*loglog();
void se_connecter();
int main(){
     printf("Content-type: text/html\n\n");
	 printf("<html lang=\"fr\"><head><meta charset=UTF-8><title>ce formulaire</title>");
	 printf("<link rel=\"stylesheet\" href=\"http://www.fock.com/style2.css\"></head>");

	         char*len=getenv("CONTENT_LENGTH");
		      
	         //~ FILE*file=NULL;
	         //~ file=fopen("/home/misa/logout.csv","w+");
	         	       
	         FILE*fil=NULL;
	         fil=fopen("/home/misa/regist.csv","a+");
	         	       
             //char*str=getenv("QUERY_STRING"); 	
     printf("<body class=\"bloc5\">");
            //printf("<div >");
            se_connecter();
            // printf(" </div>");
	        char*log=malloc(123);
	        char*log0=malloc(123);
	        char*pass=malloc(123);
			char*mai=malloc(123);
			char*ad=malloc(123);
			char*fulna=malloc(123);
        //~ if(str!=NULL){
					 
		        //~ sscanf(str,"%*[^=]=%[^ &]&%*[^=]=%[^\n]\n",log,log0);
	    //~ }
	    if(len!=NULL){
			int rlen=atoi(len);
			char*postdata=(char*)malloc(rlen+1);
			if(postdata!=NULL){
					fgets(postdata,rlen+1,stdin);
							 
					sscanf(postdata,"%*[^=]=%[^ &]&%*[^=]=%[^ &]& %*[^=]=%[^&]&%*[^=]=%[^\n]\n",fulna,pass,mai,ad);
			}
		}
	 fprintf(fil,"%s\t%s\t%s\t%s\n",fulna,pass,mai,ad);      
    // fprintf(file,"%s,%s",log,log0);
     //~ FILE*fic=NULL;
    //~ fic=fopen("/home/misa/logout.csv","r");
	//~ 
			char*login=malloc(200);
					strcpy(login,inscription());
			char*user=malloc(200);
					strcpy(user,loglog());
   // printf("<h1>%s VS %s</h1>",user,login);
	       // while( ){
	    if(strstr(user,login)!=NULL && strstr(login,user)!=NULL){
						printf("<A href=\"http://www.fock.com/cgi-bin/log.cgi\"></A>");
		}

		//}
			//fclose(file);
	fclose(fil);
			   
	printf("</body>");
	printf("</html>");
				 
	        
	
	return 0;
}
char*inscription(){
	  FILE*file=NULL;
      file=fopen("/home/misa/regist.csv","r");
		char*login=malloc(200);
		char*log=malloc(123);
		char*log0=malloc(123);
	      
		int i=0;
	while(feof(file)!=1){
		fgets(login,200,file);
		sscanf(login,"%[^,],%[^,],%*[^,],%*[\n]\n",log,log0);
	   // printf("<p>%s pourquoi tu n'existe pas</p>",login);
	
		i++;
    }
	  fclose(file);
	return login;
	
	}
char*loglog(){
	FILE*file=NULL;
    file=fopen("/home/misa/goout.csv","r");
	char*lo=malloc(200);
	int i=0;
	while(feof(file)!=1){
		fgets(lo,200,file);
		i++;
		// printf("<h2> je suis ici \"%s\" j' existes n'est ce pas</h2>",lo);
    }
   
	fclose(file);
	return lo;
	
	}
	void se_connecter(){
    
   
      printf(" <div class=\"bloc\"><form ACTION=\"http://www.fock.com/cgi-bin/log.cgi\" METHOD=\"GET\">");
      printf("Login<br>");
      printf("<br><input type=\"text\" name=\"nom\" class=\"bloc3\"><br>");
      printf(" <br>Password<br>");
      printf("  <br><input type=\"password\" name=\"anni\" class=\"bloc3\"><br>");
      printf(" <br><input type=\"submit\" class=\"bloc2\"value=\"se connecter\">");
      printf("</form>");
      printf("</div>");
     
    
}

