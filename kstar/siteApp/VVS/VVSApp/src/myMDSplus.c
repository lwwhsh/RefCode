#include <errno.h>

#include <mdslib.h>
#include <mdsdescrip.h>
#include <mdsshr.h>

#include "drvNIDAQ.h"


int mds_directCreateNewShot(ST_STD_device *pSTDdev)
{
        int null = 0; /* Used to mark the end of the argument list */
        int status; /* Will contain the status of the data access operation */
        int shot, op;
        int tstat, len;
        char buf[128];
        int dtype_Long = DTYPE_LONG; /* The returned value of SIZE() is an      integer */
        int idesc = descr(&dtype_Long, &tstat, &null);


        shot = pSTDdev->ST_Base.shotNumber;
        op = pSTDdev->ST_Base.opMode;

		if( op == OPMODE_REMOTE ) {
			printf("_SFW %s: Must be Test mode run!!\n", pSTDdev->taskName);
			return WR_ERROR;
		} else {
			sprintf(buf, "TCL(\"set tree %s/shot=-1\")", "processed");
			status = MdsValue(buf, &idesc, &null, &len);
			if ( !((status) & 1) )
			{
				printf("Error TCL command: %s.\n",MdsGetMsg(status));
				return WR_ERROR;
			}
			sprintf(buf, "TCL(\"create pulse %d\")", shot);
			status = MdsValue(buf, &idesc, &null, &len);
			if ( !((status) & 1) )
			{
				printf("Error TCL command: create pulse: %s.\n",MdsGetMsg(status));
				return WR_ERROR;
			}
			status = MdsValue("TCL(\"close\")", &idesc, &null, &len);
			printf("\%s: Create new tree(\"%d\")... OK\n", pSTDdev->taskName, shot);
		}
		return WR_OK;
}

int mds_ParamDataPut(ST_STD_device *pSTDdev, int i)
{
	ST_NIDAQ	*pNIDAQ	= (ST_NIDAQ *)pSTDdev->pUser;
        int null = 0; /* Used to mark the end of the argument list */
        int status; /* Will contain the status of the data access operation */
	char mdsNodeParam1[60];
	char mdsNodeParam2[60];
	char mdsNodeParam3[60];
	char mdsNodeParam4[60];
	char mdsNodeParam5[60];
        char tdiBuffer[60];

	sprintf(mdsNodeParam1, "\\%s:P_GAIN", pNIDAQ->ST_Ch[i].inputTagName);
	kLog (K_MON, "%s\n", &mdsNodeParam1);
	sprintf(mdsNodeParam2, "\\%s:P_OFFSET", pNIDAQ->ST_Ch[i].inputTagName);
	kLog (K_MON, "%s\n", &mdsNodeParam2);
	sprintf(mdsNodeParam3, "\\%s:A", pNIDAQ->ST_Ch[i].inputTagName);
	kLog (K_MON, "%s\n", &mdsNodeParam3);
	sprintf(mdsNodeParam4, "\\%s:B", pNIDAQ->ST_Ch[i].inputTagName);
	kLog (K_MON, "%s\n", &mdsNodeParam4);
	sprintf(mdsNodeParam5, "\\%s:C", pNIDAQ->ST_Ch[i].inputTagName);
	kLog (K_MON, "%s\n", &mdsNodeParam5);

	if(4<=i && i<=9 ) {
		sprintf(tdiBuffer, "FS_FLOAT(%f)", pNIDAQ->ST_Ch[i].mdsParam3);
		status = MdsPut(mdsNodeParam3, tdiBuffer, &null);
		if ( !((status) & 1) )
		{
			printf("Error TCL command: create pulse: %s.\n",MdsGetMsg(status));
			return WR_ERROR;
		}
		kLog (K_MON, "[proc_sendData2Tree mds_ParamDataPut] MDSNode (%s), Put Value:%f \n",
				&mdsNodeParam3, pNIDAQ->ST_Ch[i].mdsParam3);

		sprintf(tdiBuffer, "FS_FLOAT(%f)", pNIDAQ->ST_Ch[i].mdsParam4);
		status = MdsPut(mdsNodeParam4, tdiBuffer, &null);
		if ( !((status) & 1) )
		{
			printf("Error TCL command: create pulse: %s.\n",MdsGetMsg(status));
			return WR_ERROR;
		}
		kLog (K_MON, "[proc_sendData2Tree mds_ParamDataPut] MDSNode (%s), Put Value:%f \n",
				&mdsNodeParam4, pNIDAQ->ST_Ch[i].mdsParam4);

		sprintf(tdiBuffer, "FS_FLOAT(%f)", pNIDAQ->ST_Ch[i].mdsParam5);
		status = MdsPut(mdsNodeParam5, tdiBuffer, &null);
		if ( !((status) & 1) )
		{
			printf("Error TCL command: create pulse: %s.\n",MdsGetMsg(status));
			return WR_ERROR;
		}
		kLog (K_MON, "[proc_sendData2Tree mds_ParamDataPut] MDSNode (%s), Put Value:%f \n",
				&mdsNodeParam5, pNIDAQ->ST_Ch[i].mdsParam5);

	} else if(0<=i && i<=3){
		sprintf(tdiBuffer, "FS_FLOAT(%f)", pNIDAQ->ST_Ch[i].mdsParam1);
		status = MdsPut(mdsNodeParam1, tdiBuffer, &null);
		if ( !((status) & 1) )
		{
			printf("Error TCL command: create pulse: %s.\n",MdsGetMsg(status));
			return WR_ERROR;
		}
		kLog (K_MON, "[proc_sendData2Tree mds_ParamDataPut] MDSNode (%s), Put Value:%f \n",
				&mdsNodeParam1, pNIDAQ->ST_Ch[i].mdsParam1);
		sprintf(tdiBuffer, "FS_FLOAT(%f)", pNIDAQ->ST_Ch[i].mdsParam2);
		status = MdsPut(mdsNodeParam2, tdiBuffer, &null);
		if ( !((status) & 1) )
		{
			printf("Error TCL command: create pulse: %s.\n",MdsGetMsg(status));
			return WR_ERROR;
		}
		kLog (K_MON, "[proc_sendData2Tree mds_ParamDataPut] MDSNode (%s), Put Value:%f \n",
				&mdsNodeParam2, pNIDAQ->ST_Ch[i].mdsParam2);
	}
	return WR_OK;
}
int proc_sendData2Tree (ST_STD_device *pSTDdev)
{
	int 	_null = 0;	/* Used to mark the end of the argument list */
	int 	status;		/* Will contain the status of the data access operation */

	ST_NIDAQ	*pNIDAQ	= (ST_NIDAQ *)pSTDdev->pUser;
	int 	dypte_Short		= DTYPE_SHORT;
	int 	dypte_Long		= DTYPE_LONG;
	int 	dtype_Float64	= DTYPE_DOUBLE; /* We are going to read a signal made of float values */
	int 	nTrueSampleCnt	= getTotSampsChan (pNIDAQ);
	//int 	nDataBufSize	= sizeof(intype) * nTrueSampleCnt;
	int 	nDataBufSize	= sizeof(int32) * nTrueSampleCnt;
	float64 fStartTime		= getStartTime (pSTDdev);
	float64	fEndTime		= nTrueSampleCnt -1; /* match the data counts and time counts */
	float64	fRealTimeGap	= 1.0 / (float64)pSTDdev->ST_Base_fetch.nSamplingRate;			
	float64 fVoltRange		= EU_GRADIENT18;

	int		rateDesc		= descr(&dtype_Float64, &fRealTimeGap, &_null);
	int		startDesc		= descr(&dtype_Float64, &fStartTime, &_null);
	int		endDesc			= descr(&dtype_Float64, &fEndTime, &_null);
	int		voltRangeDesc	= descr(&dtype_Float64, &fVoltRange, &_null);

	FILE	*fpRaw			= NULL;	
	int32	*databuf		= NULL;	/* for read bulk data */
	//intype	*databuf		= NULL;	/* for read bulk data */
	int		rawDataDesc;			/* Signal descriptor */
	int32	i, j;
	
	int		shotNumber;
	
	int	chanNum;
	/* TGLee change from INIT_SAMPLE_RATE to chanNum(ellCount) */
    	chanNum = ellCount(pSTDdev->pList_Channel);

	shotNumber = pSTDdev->ST_Base_fetch.shotNumber;

	kLog (K_MON, "[proc_sendData2Tree] T0(%f) T1(%f) Blip(%f) Rate(%d)\n",
			pSTDdev->ST_Base_fetch.dT0[0], pSTDdev->ST_Base_fetch.dT1[0],
			pSTDdev->ST_Base_fetch.fBlipTime, pSTDdev->ST_Base_fetch.nSamplingRate);

	kLog (K_INFO, "[proc_sendData2Tree] start(%d) end(%d) gap(%f) samples(%d)\n",
			(int)fStartTime, (int)fEndTime, fRealTimeGap, (int)nTrueSampleCnt);

	//if (NULL == (databuf = (intype *)malloc(nDataBufSize)))
	if (NULL == (databuf = (int32 *)malloc(nDataBufSize))) {
		kLog (K_ERR, "[proc_sendData2Tree] %s : malloc(%d) failed\n", pSTDdev->taskName, (int)nTrueSampleCnt);
		notify_error (1, "malloc*%d) failed", (int)nTrueSampleCnt);
		return WR_ERROR;
	}

	kLog (K_MON, "[proc_sendData2Tree] connect : task(%s) mode(%s) mdsip(%s)\n",
			pSTDdev->taskName,
			getModeMsg(pSTDdev->ST_Base.opMode),
			pSTDdev->ST_mds.treeIPport[pSTDdev->ST_Base.opMode]);
	if( pSTDdev->ST_Base.opMode == OPMODE_REMOTE ){
		if (mds_Connect(pSTDdev) == WR_ERROR) {
			kLog (K_ERR, "[proc_sendData2Tree] connect fail : task(%s) mode(%s) mdsip(%s) tree(%s) shot(%d)\n",
					pSTDdev->taskName, getModeMsg(pSTDdev->ST_Base.opMode), 
					pSTDdev->ST_mds.treeIPport[pSTDdev->ST_Base.opMode], 
					pSTDdev->ST_mds.treeName[pSTDdev->ST_Base.opMode],
					pSTDdev->ST_Base_fetch.shotNumber);
			notify_error (1, "MdsConnet(%s) failed\n", pSTDdev->ST_mds.treeIPport[pSTDdev->ST_Base.opMode]);

			free(databuf);
			return WR_ERROR;
		}
	} else
	{
		kLog (K_MON, "[proc_sendData2Tree] LocalMode : tree (%s) \n",pSTDdev->ST_mds.treeName[pSTDdev->ST_Base.opMode]);
		pSTDdev->ST_mds.StatusMds |= MDS_CONNECTED;
	}

	kLog (K_MON, "[proc_sendData2Tree] open : task(%s) tree(%s) shot(%d)\n",
			pSTDdev->taskName,
			pSTDdev->ST_mds.treeName[pSTDdev->ST_Base.opMode], pSTDdev->ST_Base_fetch.shotNumber);

	epicsThreadSleep(2.0);		

	if (mds_Open_withFetch(pSTDdev) == WR_ERROR) {
		kLog (K_ERR, "[proc_sendData2Tree] open fail : task(%s) mode(%s) mdsip(%s) tree(%s) shot(%d)\n",
				pSTDdev->taskName, getModeMsg(pSTDdev->ST_Base.opMode), 
				pSTDdev->ST_mds.treeIPport[pSTDdev->ST_Base.opMode], 
				pSTDdev->ST_mds.treeName[pSTDdev->ST_Base.opMode],
				pSTDdev->ST_Base_fetch.shotNumber);

		notify_error (1, "MdsOpen(%s/%d) failed\n",
			pSTDdev->ST_mds.treeName[pSTDdev->ST_Base.opMode], pSTDdev->ST_Base_fetch.shotNumber);

		if( pSTDdev->ST_Base.opMode == OPMODE_REMOTE ){
			mds_Disconnect(pSTDdev);
		} else  pSTDdev->ST_mds.StatusMds &= ~MDS_CONNECTED;

		free(databuf);
		return WR_ERROR;
	}

	for (i = 0; i<chanNum; i++) {
		if (NULL == (fpRaw = pNIDAQ->ST_Ch[i].write_fp)) {
			continue;
		}

		kLog (K_INFO, "[proc_sendData2Tree] path(%s) mdsNode(%s) fp(%p) size(%d)\n",
				pNIDAQ->ST_Ch[i].path_name, pNIDAQ->ST_Ch[i].strTagName, pNIDAQ->ST_Ch[i].write_fp, nDataBufSize);

		// rewind
		fseek (fpRaw, 0L, SEEK_SET);

		if (1 != fread (databuf, nDataBufSize, 1, fpRaw)) {
			kLog (K_ERR, "[proc_sendData2Tree] %s : fread failed (%s)\n", pNIDAQ->ST_Ch[i].file_name, strerror(errno));
			notify_error (1, "%s read failed\n", pNIDAQ->ST_Ch[i].file_name);

			fclose(fpRaw);
			pNIDAQ->ST_Ch[i].write_fp = NULL;
			continue;
		}

		if (TRUE == isPrintDebugMsg (K_DEL)) {
			for (j=0;j<nTrueSampleCnt;j++) {
				if (! (j % 10)) printf ("\n(%04d) ", j);
				printf ("%5d ", databuf[j]);
			}
			printf ("\n");
		}


		rawDataDesc = descr(&dypte_Long, databuf, &nTrueSampleCnt, &_null);

		status = MdsPut(pNIDAQ->ST_Ch[i].strTagName,
				"BUILD_SIGNAL(BUILD_WITH_UNITS($*$,\"V\"),,MAKE_DIM(MAKE_WINDOW(0,$,$),MAKE_SLOPE(MAKE_WITH_UNITS($,\"s\"))))", 
				&voltRangeDesc, &rawDataDesc, &endDesc, &startDesc, &rateDesc, &_null);
		if ( !((status) & 1) ) {
			kLog (K_ERR, "[proc_sendData2Tree] %s : Error tag\"%s\", ch%d: %s\n",
					pSTDdev->taskName, pNIDAQ->ST_Ch[i].strTagName, (int)i, MdsGetMsg(status));
			notify_error (1, "MdsPut(%s) failed", pNIDAQ->ST_Ch[i].strTagName);
		} 
		else {
			scanIoRequest(pSTDdev->ioScanPvt_userCall);
		}
		epicsThreadSleep(0.5);
		fclose(fpRaw);
		pNIDAQ->ST_Ch[i].write_fp = NULL;

		kLog (K_INFO, "[proc_sendData2Tree] path(%s) put ok...\n", pNIDAQ->ST_Ch[i].path_name);
	}
	kLog (K_MON, "[proc_sendData2Tree] %s : Tree Put Done!\n", pSTDdev->taskName);
	free(databuf);
	databuf=NULL;
	mds_Close_withFetch(pSTDdev);

	if( pSTDdev->ST_Base.opMode == OPMODE_REMOTE ){
		mds_Disconnect(pSTDdev);
//		status = completeDataPut();   /* MDS Data Store complated Event Put in the Data Analysis server */
	} else  pSTDdev->ST_mds.StatusMds &= ~MDS_CONNECTED;
	return WR_OK;
}

int completeDataPut()
{
	int null = 0; /* Used to mark the end of the argument list */
	int status; /* Will contain the status of the data access operation */
	int socket; /* Will contain the handle to the remote mdsip server */
	int dtype_Long = DTYPE_LONG; /* The returned value of SIZE() is an      integer */
	char buf[512];

	int tstat, len;
	int idesc = descr(&dtype_Long, &tstat, &null);

	/* Connect to MDSplus */
	socket = MdsConnect("172.17.100.200:8300");
	if ( socket == -1 )
	{
		epicsPrintf("Error connecting to mdsip server(%s).\n", "172.17.100.200:8300");
		return 0;
	}
	epicsPrintf("\nMDSplus >>> MdsConnect(\"%s\")... OK\n", "172.17.100.200:8300");

	sprintf(buf, "TCL(\"setevent VVS\")");
	status = MdsValue(buf, &idesc, &null, &len);
	if( !((status) & 1 ))
	{
		epicsPrintf("Error TCL command : create pulse: %s.\n", MdsGetMsg(status));
		return 0;
	}
	MdsDisconnect("172.17.100.200:8300");
	return WR_OK;
}
