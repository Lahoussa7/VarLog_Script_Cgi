#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ancre1(int nb,int anc);
int ancre2(int nb,int anc);
int nombreline();
void ancre(int nb);
void ancre3(int deb,int fin,int anc);
void dateAvenir(int m,int ans,int jour,int jp);
 int premierjan(int y);
 char**joursemaine();
 char*jourjan(int n,char**jour);
 int jourdumois(int m,int y);
 int nombreline();
 char*mois(int nb);
 int journ(int nb);
 int nombremois(char*m);
 int jour1dumois(int n,int mois,int*d,int y);
 char*jourtoday(int jo,char ca[7][200],int n,int u);
 int nombrelineAvecopen( FILE*file);
 typedef struct{
   
	char log[600];
	char date[600];
	char mois[700];
	char sess[600];
	char dy[600];
	
}tableau;
int main(){
		char*caro=getenv("QUERY_STRING");
		printf("Content-type: text/html\n\n");
	    printf("<html lang=\"fr\"><head><meta charset=UTF-8><title>Varlog_traitement</title></head>");printf("<body width=70%%> ");
   
	FILE*fi=NULL;
	FILE*fic=NULL;
    FILE*file=NULL;
    int l=0;
    int mark=0;		int k=0;
    
    fi=fopen("/home/misa/goout.csv","r");
	file=fopen("/var/log/auth.log","r");
	fic=fopen("/home/misa/regist.csv","r");
    
     char*ca4=malloc(120);  
     int num=nombrelineAvecopen(file);
     tableau*auth=(tableau*)malloc(sizeof(tableau)*num);
     int j=0;
     
     char*cont_fil=malloc(sizeof(char)*1000);
     
    int nbmois=0;
	int u=0;
	int jo=0;
	char day[7][200]={"Alahady","Alatsinainy","Talata","Alarobia","Alakamisy","Zoma","Asabotsy"};
	char**cal=malloc((sizeof(char*)*13));

///maka an le goout
	  while(feof(fi)!=1){		   
		     fgets(ca4,255,fi);
				l++;
	  }	
	  
	  fclose(fi);
	  
        printf("<p>%s<br></p>",ca4);
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
	       
		    int y=2023;int m=0;
		    int anc=0;

	       // int nbr=nombreline();
	       
	        int n=premierjan(y);
	        char*care=malloc(120);  
	        char*cara=malloc(120);  
	        char text[10];
            
	        sscanf(caro,"%[^=]=%s",text,cara);
	   
	   if(strcmp(text,"nbr")==0)
			anc=atoi(cara);
		if (strcmp(text,"log")==0){	
			 printf("<div style=\"background-color:red;width:50vw;height:4vw;color:cornsilk;text-align:center;\"><H1> Veuillez vous connecter :)</H1></div>");
		    printf("<br><div style=\"background-color:green;width:40vw;height:4vw;color:cornsilk;font-size:3vw;text-align:center;\"><A href=\"http://www.fock.com/login.html\" style=\"color:pink;\">Connectez-Vous!!</A></div>");		

		}
	       // printf("<H1> veuillez remplir la formulaire d'abord avant de voir les pages%s </H1>",ca4);
	    //~ if(strstr(ca4,"logout")!=NULL){			
		    //~ printf("<div style=\"background-color:red;width:50vw;height:4vw;color:cornsilk;text-align:center;\"><H1> Veuillez vous connecter :)</H1></div>");
		    //~ printf("<br><div style=\"background-color:green;width:40vw;height:4vw;color:cornsilk;font-size:3vw;text-align:center;\"><A href=\"http://www.fock.com/login.html\" style=\"color:pink;\">Connectez-Vous!!</A></div>");		
	    //~ }
	      	
	    else if (strcmp(text,"log")!=0){
			 printf("<A href=\"http://www.fock.com/cgi-bin/log.cgi?anni=logout\">logout</A>");
	  
			  int nb=nombreline();
				  ancre(nb);
			  int deb=ancre1(nb,anc);
			  int fin= ancre2(nb,anc);
			  printf("<div style=\"display:flex;flex-direction:row;\">");
			  printf("<div style=\"text-decoration:none;width:6vw;height:6vw;border-radius:50%%;display:flex;justify-content:center;flex-direction:row-reverse;align-items:center;background-color: violet;\"<H1>%s</H1></div>",cara);
		      ancre3(deb,fin,anc);
			  printf("</div>");
			  int i=0;
			 // printf("<H1> ici %d et fin est %d</H1>",deb,fin);
			   printf("<center><table border=\"2\" width=80%% height=70%% style=\"text-align:center;\">");
			   printf("<tr style=\"background-color:white;\"><th>DATE DE L'OUVERTURE ET DE FERMETURE</th><th>OUVERT/FERMER </th><th>UTILISATEUR</th></tr>");
			
			while(feof(file)!=1){
				  
				
				 fgets(cont_fil,255,file);
				 i++;	
				 if(strstr(cont_fil,"closed")!=NULL || strstr(cont_fil,"opened")!=NULL){
                 sscanf(cont_fil,"%[^ ] %[^ ] %[^ ] %*[^ ] %*[^ ] %*[^ ] %*[^ ] %[^ ] %*[^ ] %*[^ ] %[^ ]%*[^\n]\n",auth[j].mois,auth[j].dy,auth[j].date,auth[j].sess,auth[j].log);
	         //   printf("<P>%s</p>",ca7);
			     
					   jo=atoi(auth[j].dy);
			           nbmois= nombremois(auth[j].mois);
		
		               u=jourdumois( nbmois,y);
		               m= jour1dumois(n,nbmois,d,y);
		               strcpy(care,jourtoday(jo,day,m,u));
			    
			    	}  
			          				
					 if(i==deb){
						 if(deb<=fin){
								  if((strcmp(auth[j].sess,"closed")==0)){
								
								       printf("<tr style=\"background-color:rgb(214, 183, 135);text-decoration:none;color:black;\"><td> %s %d   %s tamin'ny  %s</td><td style=\"color:red;\">%s</td><td><A href=\"http://www.fock.com/cgi-bin/log.cgi?st=%s\">%s</A></td></tr>",care,jo,cal[nbmois],auth[j].date,auth[j].sess,auth[j].log,auth[j].log);
				                 }
								  if((strcmp(auth[j].sess,"opened")==0)){
								
								       printf("<tr style=\"background-color:rgb(214, 183, 135);text-decoration:none;color:black;\"><td> %s %d   %s tamin'ny  %s</td><td style=\"color:blue;\">%s</td><td><A href=\"http://www.fock.com/cgi-bin/log.cgi?st=%s\">%s</A></td></tr>",care,jo,cal[nbmois],auth[j].date,auth[j].sess,auth[j].log,auth[j].log);
				                 }
				                
				         }                    
						   
						 deb++;
					 }
						
					
					
				}
						  j++;

    
			}

		
	 printf("</body></html>");
		
	fclose(file);	
	fclose(fi);

	return 0;
	
}

void ancre(int nb){
	//int j=0;
	 for(int i=1;i<=10;i++){
		  printf("<A href=\"http://www.fock.com/cgi-bin/ess.cgi?nbr=%d\"></A>",i);	
	  }
	 
}

void ancre3(int deb,int fin,int anc){
		
	if(anc==(((deb+fin)/2)/10) && anc!=0){
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
