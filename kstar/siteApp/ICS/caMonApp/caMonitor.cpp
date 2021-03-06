/*caMonitor.cpp*/
/* This example accepts a file containing a list of pvs to monitor
 * It prints a message for all ca evemts: connection, access rights, data
 */
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

#include "cadef.h"
#include "dbDefs.h"

#define MAX_PV 1000
#define MAX_PV_NAME_LEN 40
using namespace std;

FILE		*g_pFile;
typedef struct{
	char		value[20];
	chid		mychid;
	evid		myevid;
} MYNODE;


static void printChidInfo(chid chid, char *message)
{
	printf("\n%s\n",message);
	printf("pv: %s  type(%d) nelements(%ld) host(%s)",
			ca_name(chid),ca_field_type(chid),ca_element_count(chid),
			ca_host_name(chid));
	printf(" read(%d) write(%d) state(%d)\n",
			ca_read_access(chid),ca_write_access(chid),ca_state(chid));
}

static void exceptionCallback(struct exception_handler_args args)
{
	chid	chid = args.chid;
	long	stat = args.stat; /* Channel access status code*/
	const char  *channel;
	static char *noname = "unknown";

	channel = (chid ? ca_name(chid) : noname);


	if(chid) printChidInfo(chid,"exceptionCallback");
	printf("exceptionCallback stat %s channel %s\n",
			ca_message(stat),channel);
}

static void connectionCallback(struct connection_handler_args args)
{
	chid	chid = args.chid;

	printChidInfo(chid,"connectionCallback");
}

static void accessRightsCallback(struct access_rights_handler_args args)
{
	chid	chid = args.chid;

	printChidInfo(chid,"accessRightsCallback");
}
/*static void eventCallback(struct event_handler_args eha)*/
void eventCallback(struct event_handler_args eha)
{
	chid	chid = eha.chid;
	MYNODE *pNode = (MYNODE *)ca_puser(eha.chid);
	char   tsString[30];

	if(eha.status!=ECA_NORMAL) 
	{
		printChidInfo(chid,"eventCallback");
	} 
	else 
	{
		//char	*pdata = (char *)eha.dbr;
		struct dbr_time_string *pvalue = (struct dbr_time_string*)eha.dbr;
		epicsTimeToStrftime(tsString,sizeof(tsString),
				"%Y/%m/%d %H:%M:%S.%06f",&pvalue->stamp);
		if(!g_pFile)
		{
			fprintf(stdout, "%s=%s:%s\n",ca_name(eha.chid),tsString,pvalue->value);
		}
		else
		{
			fprintf(g_pFile,"%s=%s:%s\n",ca_name(eha.chid),tsString,pvalue->value);
			fflush(g_pFile);
		};
	};
}

int main(int argc,char **argv)
{
	char *filename;
	char *outputfile;
	int		npv = 0; 
	MYNODE	*pmynode[MAX_PV];
	char	*pname[MAX_PV];
	int		i;
	char	tempStr[MAX_PV_NAME_LEN];
	char	*pstr;
	FILE	*fp;

	if(argc < 2 || argc > 3) {
		fprintf(stderr,"usage: caMonitor filename\n");
		exit(1);
	}
	filename = argv[1];
	fp = fopen(filename,"r");
	if( argc == 3 )
	{
		outputfile = argv[2];
		g_pFile = fopen(outputfile, "w");
	}
	if(!fp) {
		perror("fopen failed");
		return(1);
	}
	while(1) {
		if(npv >= MAX_PV ) break;
		pstr = fgets(tempStr,MAX_PV_NAME_LEN,fp);
		if(!pstr) break;
		if(strlen(pstr) <=1) continue;
		pstr[strlen(pstr)-1] = '\0'; /*strip off newline*/
		pname[npv] = (char*)calloc(1,strlen(pstr) + 1);
		strcpy(pname[npv],pstr);
		pmynode[npv] = (MYNODE *)calloc(1,sizeof(MYNODE));
		npv++;
	}
	SEVCHK(ca_context_create(ca_disable_preemptive_callback),"ca_context_create");
	SEVCHK(ca_add_exception_event(exceptionCallback,NULL),
			"ca_add_exception_event");
	for(i=0; i<npv; i++) {
		SEVCHK(ca_create_channel(pname[i],connectionCallback,
					pmynode[i],20,&pmynode[i]->mychid),
				"ca_create_channel");
		SEVCHK(ca_replace_access_rights_event(pmynode[i]->mychid,
					accessRightsCallback),
				"ca_replace_access_rights_event");
		//SEVCHK(ca_add_event(DBR_STRING,pmynode[i]->mychid,eventCallback,
		//pmynode[i],&pmynode[i]->myevid), "ca_add_event");
		SEVCHK(ca_add_event(DBR_TIME_STRING,pmynode[i]->mychid,eventCallback,
					pmynode[i],&pmynode[i]->myevid), "ca_add_event");
	}
	/*Should never return from following call*/
	SEVCHK(ca_pend_event(0.0),"ca_pend_event");
	fclose(fp);
	if(!g_pFile) fclose(g_pFile);
	return(0);
}
