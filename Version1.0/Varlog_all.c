#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 void dateAvenir(int m,int ans,int jour,int jp);
 int premierjan(int y);
 char**joursemaine();
 char*jourjan(int n,char**jour);
 int jourdumois(int m,int y);
 int nombreline();
// int nombremois(char*m,char**car);
 char*mois(int nb);
 int journ(int nb);
 int nombremois(char*m);
 int jour1dumois(int n,int mois,int*d,int y);
 char*jourtoday(int jo,char ca[7][200],int n,int u);
 int nombrelineAvecopen( FILE*file);
 void ancre(int nb);
 int ancre1(int nb,int anc);
 int ancre2(int nb,int anc);
 void ancre3(int deb,int fin,int anc);
 //int nombrelineAvecopen( FILE*file);
 typedef struct{
   
	char log[600];
	char date[600];
	char mois[700];
	char sess[600];
	char dy[600];
	
}tableau;
 void recherche();
int main(){

	char*str=getenv("QUERY_STRING");
	char*caro=getenv("QUERY_STRING");
	char*string=getenv("QUERY_STRING");
	//char*connexion=getenv("
	printf("Content-type: text/html\n\n");
	printf("<html>");
	printf("<head><title>varlog</title><head>");
	printf("<body style=\"background-color:rgba(255, 105, 180, 0.493);\">");
//	printf("<div align=\"center\"><B><font color=\" blanchedalmond\" size=20>Les 100 derniers authentification dans /var/log/auth.log </font></B></div>");
	
	printf("<header style=\"background-color:darkslategray;color:white;font-size:3vw;\">");
	printf(" <h2 style=\"text-align:center;color:white;font-size:4vw;\">De quel utilisateur voulez vous savoir son authentification</h2><br>");

    printf(" <form ACTION=\"/cgi-bin/log.cgi\" METHOD=\"GET\" >");
    printf(" <center>Nom de l'utilisateur &agrave; chercher<br><input style=\"width:15vw;height:6vw;border-radius:30vw;text-align:center;\"type=\"text\" name=\"st\" placeholder=\"mirella\">");
    printf("<br><br><input style=\"width:8vw;height:3vw;border-radius:30vw;\"type=\"submit\" class=\"block\"value=FIND></div>");
    printf(" </center> </form></header></div>"); 
    
	
	//printf("<div align=\"center\"><B><font color=\" blanchedalmond\" size=20>Les 100 derniers authentification dans /var/log/auth.log </font></B></div>");
	printf("<center><table border=2vw width=80%% height=70%% style=\"text-align:center;\">");
	printf("<tr style=\"background-color:white;\"><th>DATE DE L'OUVERTURE ET DE FERMETURE</th><th>OUVERT/FERMER </th><th>UTILISATEUR</th></tr>");
	char*st=malloc(234);
	sscanf(str,"st=%s",st);
	char*cara=malloc(45);
	sscanf(caro,"nbr=%s",cara);
	 FILE*fil=NULL;
	 fil=fopen("/home/misa/goout.csv","w+");

	      char*log=malloc(123);
	      char*log0=malloc(123);
	      char*log1=malloc(123);
          sscanf(string,"%*[^=]=%[^ &]&%*[^=]=%[^\n]\n",log,log0);
	       printf("<body>");
	       //  int anc=atoi(cara);
	         
	
	//printf("<P>%s</p>\n",st);
	
		//recherche();
	FILE*fic=NULL;
	fic=fopen("/var/log/auth.log.1","r");
	if(fic==NULL){
	    printf("<h2>erreur de l'ouverture</h2>");	
	}
	
	int nbmois=0;
	int u=0;
	int jo=0;
	char day[7][200]={"Alahady","Alatsinainy","Talata","Alarobia","Alakamisy","Zoma","Asabotsy"};
	char**cal=malloc((sizeof(char*)*13));
	for(int i=0;i<13;i++){
		cal[i]=(char*)malloc(100);
	}
	
		strcpy(cal[1],"Janoary");
		strcpy(cal[2],"Febroary");strcpy(cal[12],"Desambra");
		strcpy(cal[3],"Martsa");strcpy(cal[11],"Novambra");
		strcpy(cal[4],"Aprily");strcpy(cal[10],"Oktobra");
		strcpy(cal[5],"May");strcpy(cal[9],"Septembra");
		strcpy(cal[6],"Jona");strcpy(cal[7],"Jolay");strcpy(cal[8],"Aogositra");
		

			int d[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	        int num=nombrelineAvecopen(fic);
	       // printf("<h1>%d</h1>",num);
		    int y=2023;int m=0;

	       // int nbr=nombreline();
	        int n=premierjan(y);
	        char*car=malloc(120);
	       
            tableau*auth=(tableau*)malloc(sizeof(tableau)*num);
		    int i=0,j=0;
		    char*cont_fil=malloc(sizeof(char)*1000);
		   
	           printf("<div style=\"width:55vw;height:5vw;font-size:3vw;background-color:gray;\"><A href=\"http://www.fock.com/cgi-bin/ess.cgi\" style=\"color:bisque;\">Voir le contenue en page par page</A></div>");
	           fprintf(fil,"%s\t%s\n",log,log0);
		 while (fgets(cont_fil,255,fic)!=NULL){
			 	
	           i++; 
               if(strstr(cont_fil,"closed") || strstr(cont_fil,"opened")){	
	           sscanf(cont_fil,"%[^ ] %[^ ] %[^ ] %*[^ ] %*[^ ] %*[^ ] %*[^ ] %[^ ] %*[^ ] %*[^ ] %[^ ]%*[^\n]\n",auth[j].mois,auth[j].dy,auth[j].date,auth[j].sess,auth[j].log);
	           //}
				
		       jo=atoi(auth[j].dy);
			   nbmois= nombremois(auth[j].mois);
		
		       u=jourdumois( nbmois,y);
		       m= jour1dumois(n,nbmois,d,y);
		       strcpy(car,jourtoday(jo,day,m,u));
		    //  printf("<h1>%d</h1><br>",j);
		      if((strcmp(auth[j].sess,"closed")==0 || strcmp(auth[j].sess,"opened")==0 ) ){
				  if(strstr(auth[j].log,st)!=NULL){
					   
		          //  printf("<tr style=\"background-color:rgb(214, 183, 135);\"><td> %s %d   %s tamin'ny  %s</td><td>%s</td><td><A href=\"http://www.fock.com/cgi-bin/log.cgi?st=%s\"</A>%s</td></tr>",car,jo,cal[nbmois],auth[j].date,auth[j].sess,auth[j].log,auth[j].log);
				    
		            
		           
		            //~ if(j==deb){
						    //~ if(deb<=fin){
						      if((strcmp(auth[j].sess,"closed")==0)){
								 printf("<tr style=\"background-color:rgb(214, 183, 135);text-decoration:none;color:black;\"><td> %s %d   %s tamin'ny  %s</td><td style=\"color:red;\">%s</td><td><A href=\"http://www.fock.com/cgi-bin/log.cgi?st=%s\">%s</A></td></tr>",car,jo,cal[nbmois],auth[j].date,auth[j].sess,auth[j].log,auth[j].log);
				              }
				             
						      if((strcmp(auth[j].sess,"opened")==0)){
								 printf("<tr style=\"background-color:rgb(214, 183, 135);text-decoration:none;colo:black;\"><td> %s %d   %s tamin'ny  %s</td><td style=\"color:blue;\">%s</td><td><A href=\"http://www.fock.com/cgi-bin/log.cgi?st=%s\"style=\"color:black;\">%s</A></td></tr>",car,jo,cal[nbmois],auth[j].date,auth[j].sess,auth[j].log,auth[j].log);
				              }
				             
						 //~ deb++;
				    //~ } 
				}
				//~ else{
					  //~ if(j==deb){
						    //~ if(deb<=fin){
								 //~ if(strstr(auth[j].log,st)!=NULL){
								 //~ printf("<tr style=\"background-color:rgb(214, 183, 135);\"><td> %s %d   %s tamin'ny  %s</td><td>%s</td><td><A href=\"http://www.fock.com/cgi-bin/ess.cgi?st=%s\"</A>%s</td></tr>",car,jo,cal[nbmois],auth[j].date,auth[j].sess,auth[j].log,auth[j].log);
				             //~ }
						 //~ deb++;
				    //~ } 
				//~ }
				//~ }
		        j++;
		      }  
		     }
	
           }

	fclose(fic);fclose(fil);
	
	//free(ca);free(ca0);free(ca1);free(car);free(ca3);free(ca6);free(ca8);free(ca9);free(ca7);  
	return 0;
}

int premierjan(int y){
	float k=4.0;
	float b=400.0;
	float t=100.0;
	float u=36+(y-1);
	float r=7.0;
	float l=((y-1)/k);float lu=((y-1)/(t));float la=((y-1)/b);
	float s=((u+l)-(lu+la));
	int n=s-((s/r)*r);
	return n;
}
int jourdumois(int m,int y){
	int jour=0;
	if((m%2==1 && m<=7 && m!=2) || (m%2==0 && m>7)){
		jour=31;
	}
	 else if((m%2==0 && m<7) || (m%2==1 && m>7)){
		 jour=30;
	 }
     if(m==2){
		 if(y%4==0 && y%100!=0){
			 jour=29;
		 }
		 else{
			 jour=28;
		 }
	 }
	return jour;
}

char*jourjan(int n,char**jour){
	char*car=malloc(120);
	
	  strcpy(car,jour[n]);
	
   return car;	
}
int nombremois(char*m){
    char**cal=malloc((sizeof(char*)*13));
	
		for(int i=0;i<13;i++){
			cal[i]=(char*)malloc(100);}
	
			strcpy(cal[1],"Janoary");
			strcpy(cal[2],"Febroary");strcpy(cal[12],"Desambra");
			strcpy(cal[3],"Martsa");strcpy(cal[11],"Novambra");
			strcpy(cal[4],"Aprily");strcpy(cal[10],"Octobra");
			strcpy(cal[5],"May");strcpy(cal[9],"Septembra");
			strcpy(cal[6],"June");strcpy(cal[7],"July");strcpy(cal[8],"August");

	    int n=1;
		for(int i=1;i<13;i++){
			if(strstr(cal[i],m)!=NULL){
			n=i;
		    }
        }
			//printf(" %s\n",car[n]);
		 
		 return n;
}

int nombrelineAvecopen( FILE*file){
	char *car =(char*)malloc(sizeof(char)*1000);

	char *cont_fil =(char*)malloc(sizeof(char)*1000);
	
	int nbl=0;
	
	while(!feof(file)){
		fgets(cont_fil,255,file);
		if(strstr(cont_fil,"opened")!=NULL || strstr(cont_fil,"closed")!=NULL){
			sscanf(cont_fil,"%[^ ] %*[^\n]\n",car);
				
			nbl++;	
		}
	}
	rewind(file);
	return nbl;
}

int jour1dumois(int n,int mois,int*d,int y){
	int new=0;
	
	new=(31+n)%7;
	for(int i=0,j=0;i<12;i++,j++){
		
		if(i==(mois-1)){
		    if(i==0){
	           new =n;
            }
	        if(i==1){
	           new =(28+(n+31)%7)%7;
          
            }  
	        if (i==2){
	            new=(31+(28+n)%7)%7;
	     
            }  
   
	        if(i==3){
	           new =(30+(31+(28+n)%7)%7)%7;

            }
	        if(i==4){
		
              new =(31+(30+(31+(28+n)%7)%7)%7)%7;
     
            }
	       if(i==5){
              new =(30+(31+(30+(31+(28+n)%7)%7)%7)%7)%7;
           }
	       if(i==6){
	          new =(31+(30+(31+(30+(31+(28+n)%7)%7)%7)%7)%7)%7;
           }
	       if(i==7){
              new =(31+(31+(30+(31+(30+(31+(28+n)%7)%7)%7)%7)%7)%7)%7;
           }
	       if(i==8){
	          new =(30+(31+(31+(30+(31+(30+(31+(28+n)%7)%7)%7)%7)%7)%7)%7)%7;
           }
	       if(i==9){
	          new=(31+(30+(31+(31+(30+(31+(30+(31+(28+n)%7)%7)%7)%7)%7)%7)%7)%7)%7;
           }
	       if(i==10){
	          new =(30+(31+(30+(31+(31+(30+(31+(30+(31+(28+n)%7)%7)%7)%7)%7)%7)%7)%7)%7)%7;
           }
	       if(i==11){
	          new=(31+(30+(31+(30+(31+(31+(30+(31+(30+(31+(28+n)%7)%7)%7)%7)%7)%7)%7)%7)%7)%7)%7;
	
           }
           if(d[i]==30){
	          new= (new+1)%7;	
		
	       }
      }
 	
	}
    
return new;	
}
char*jourtoday(int jo,char ca[7][200],int n,int u){
	char*car=malloc(123);
	int l=0;
	for(int i=n,j=1;i<u+n;i++,j++){
		 
			  if(j==jo){
		      if(i>=7){
			  
			   l=i%7;
			       strcpy(car,ca[l]);
		      }
		      else{
				  strcpy(car,ca[i]);
	          }
	  
         }
	}
	return car;
}
void ancre(int nb){
	//int j=0;
	 for(int i=1;i<=10;i++){
		  printf("<A href=\"http://www.fock.com/cgi-bin/ess.cgi?nbr=%d\"></A>",i);	
	  }
	 
		
	
}
void ancre3(int deb,int fin,int anc){
		
	if(anc==(((deb+fin)/2)/10)){
	  for(int i=(fin/10);i<=(fin/10)+5;i++){
			
		 printf("<div style=\"text-decoration:none;width:6vw;height:6vw;border-radius:50%%;display:flex;justify-content:center;flex-direction:row-reverse;align-items:center;background-color: darksalmon;\"><A href=\"http://www.fock.com/cgi-bin/ess.cgi?nbr=%d\" style=\"text-decoration:none;\"><font color=\"black\">%d  &nbsp;</font></A></div>",i,i);	
	       	
		}	
	}
	else if(anc==(fin/10)){
		for(int i=anc+1;i<=(fin/10)+10;i++){
			
		 printf("<div style=\"text-decoration:none;width:6vw;height:6vw;border-radius:50%%;display:flex;justify-content:center;flex-direction:row-reverse;align-items:center;background-color: darksalmon;\"><A href=\"http://www.fock.com/cgi-bin/ess.cgi?nbr=%d\" style=\"text-decoration:none;\"><font color=\"black\">%d  &nbsp;</font></A></div>",i,i);	
	       		     
		}
	}
	else{
		 for(int i=1;i<=(10);i++){
			
		 printf("<div style=\"text-decoration:none;width:6vw;height:6vw;border-radius:50%%;display:flex;justify-content:center;flex-direction:row-reverse;align-items:center;background-color: darksalmon;\"><A href=\"http://www.fock.com/cgi-bin/ess.cgi?nbr=%d\" style=\"text-decoration:none;\"><font color=\"black\">%d  &nbsp;</font></A></div>",i,i);	
	       		     
		}
	}     
			int pageReturn =0;
			
	     if(anc<10){
			 pageReturn = 1;
			  //printf("<div style=\"text-decoration:none;width:6vw;height:6vw;border-radius:50%%;display:flex;justify-content:center;flex-direction:row-reverse;align-items:center;background-color: violet;\"><A href=\"http://www.fock.com/cgi-bin/ess.cgi?nbr=1\" style=\"text-decoration:none;\"><font color=\"black\"></font></A></div>");	
	     }
	     else{
			 pageReturn = anc - 10;
		 }
			 
	      printf("<div style=\"text-decoration:none;width:6vw;height:6vw;border-radius:50%%;display:flex;justify-content:center;flex-direction:row-reverse;align-items:center;background-color: violet;\"><A href=\"http://www.fock.com/cgi-bin/ess.cgi?nbr=%d\" style=\"text-decoration:none;\"><font color=\"white\" size=\"4\">return &nbsp;</font></A></div>",pageReturn );	
	       	
	
	
}
int nombreline(){
	char *car =(char*)malloc(sizeof(char)*1000);
	FILE*file;
	file=fopen("/var/log/auth.log","r");
	
	if(file==NULL){
		printf("on n'a pas pu ouvrir le fichier\n");
	}
	int nbl=0;
	
	while(!feof(file)){
		fgets(car,1000,file);	
		nbl++;	
	}
	fclose(file);
	return nbl;
}
int ancre1(int nb,int anc){
	int  debut=0;
	 for(int i=1;i<(nb/10);i++){
	  if(i==anc){
		 debut=(i-1)*10+1;
		  
		  
	  }
	 }
		
	return debut;
}
int ancre2(int nb,int anc){
	int  fin=0;
	 for(int i=1;i<(nb/10);i++){
	  if(i==anc){
		 fin=i*10;
		 // 10
		  
	  }
	 }
		
	return fin;
}



